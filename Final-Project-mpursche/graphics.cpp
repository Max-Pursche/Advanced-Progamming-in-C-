#include "graphics.h"
#include "Button.h"
#include "snake.h"
#include <iostream>
#include <time.h>
#include <vector>
using namespace std;
GLint width, height;
int wd;
bool upMov, downMov, leftMov, rightMov;

color snakeGreen{26/255.0, 176/255.0, 56/255.0};
color bodyGreen{45/255.0, 176/255.0, 65/255.0};
color brickRed{201/255.0, 20/255.0, 20/255.0};
color black{0, 0, 0};
color white{1,1,1};

Quad playScreen(black, {360, 270}, 700, 520);
Snake snake(snakeGreen,{100, 100}, 15,15,0);
vector<Quad> tail;
vector<Quad> apples;

void spawnApple() {
    apples.push_back(Quad(brickRed, {rand()%((int)playScreen.getWidth()-20) + 30, rand()%((int)playScreen.getHeight()-20) + 30}, 15, 15));
}
void grow(){
    tail.push_back(Quad(bodyGreen, tail[tail.size()-1].getCenter(), 15,15));
}
void initSnake(){
    tail.push_back(Quad(bodyGreen,{snake.getCenterX()-5, snake.getCenterY()-5}, 15,15));
    tail.push_back(Quad(bodyGreen,{snake.getCenterX()-5, snake.getCenterY()-5}, 15,15));
    tail.push_back(Quad(bodyGreen,{snake.getCenterX()-5, snake.getCenterY()-5}, 15,15));
}
void init() {
    width = 720;
    height = 540;
    srand(time(0));
    gameState = STATE1;
    initSnake();
    spawnApple();
}

/* Initialize OpenGL Graphics */
void initGL() {
    // Set "clearing" or background color
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // White and opaque
}

/* Handler for window-repaint event. Call back when the window first appears and
 whenever the window needs to be re-painted. */
void display() {
    // tell OpenGL to use the whole window for drawing
    glViewport(0, 0, width, height);
    
    // do an orthographic parallel projection with the coordinate
    // system set to first quadrant, limited by screen/window size
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, width, height, 0.0, -1.f, 1.f);
    
    glClear(GL_COLOR_BUFFER_BIT);   // Clear the color buffer with current clearing color
    
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    
    /*
     * Draw here
     */
    if (gameState == STATE1) {
        playScreen.draw();
        char str[] = "Press 'S' to start";
        glColor3f(1,1,1);
        glRasterPos2i(width/2.5, height/2);
        for (const char &letter : str) {
            glutBitmapCharacter(GLUT_BITMAP_8_BY_13, letter);
        }
    }
    //main game
    if(gameState == STATE2) {
        playScreen.draw();
        string score = "Score:" + to_string(snake.getAmtEaten());
        int len = score.length();
        glColor3f(1,1,1);
        glRasterPos2i(width/2.5, height/2);
        for (int i = 0; i < len; i++) {
            glutBitmapCharacter(GLUT_BITMAP_8_BY_13, score[i]);
        }
        snake.draw();
        //Checking to see if boxes draw on the same x,y ends game if the are
        for (int i = 1; i < tail.size(); i++){
            if (snake.getCenterX() == tail[i].getCenterX() && snake.getCenterY() == tail[i].getCenterY()){
                gameState = STATE3;
            }
        }
        if(!snake.isOverlapping(apples[0])) {
            snake.closeMouth();
        }
        if(snake.isOverlapping(apples[0])) {
            snake.openMouth();
        }
        if(snake.getTopY() < playScreen.getTopY() || snake.getLeftX() < playScreen.getLeftX() || snake.getRightX() > playScreen.getRightX() || snake.getBottomY() > playScreen.getBottomY()){
            gameState = STATE3;
        }
        for (const Quad &body : tail){
            body.draw();
        }
        for (const Quad &piece : apples){
            piece.draw();
        }
    }
    if(gameState == STATE3) {
        playScreen.draw();
        apples.clear();
        char str2[] = "Snek!";
        glColor3f(1,1,1);
        glRasterPos2i(width/2, height/2);
        for (const char &letter : str2) {
            glutBitmapCharacter(GLUT_BITMAP_8_BY_13, letter);
        }
    }
    glFlush();  // Render now
}

// http://www.theasciicode.com.ar/ascii-control-characters/escape-ascii-code-27.html
void kbd(unsigned char key, int x, int y) {
    // escape
    switch(key) {
        case 27: {
            // escape
            glutDestroyWindow(wd);
            exit(0);
        }
        case 's': {
            if (gameState != STATE3){
                gameState = STATE2;
            }
            break;
        }
    }
    glutPostRedisplay();
}

void kbdS(int key, int x, int y) {
    switch(key) {
        case GLUT_KEY_DOWN:
            downMov = true;
            upMov = false;
            leftMov = false;
            rightMov = false;
            break;
        case GLUT_KEY_LEFT:
            leftMov = true;
            rightMov = false;
            downMov = false;
            upMov = false;
            break;
        case GLUT_KEY_RIGHT:
            rightMov = true;
            leftMov = false;
            downMov = false;
            upMov = false;
            break;
        case GLUT_KEY_UP:
            upMov = true;
            downMov = false;
            rightMov = false;
            leftMov = false;
            break;
    }
    glutPostRedisplay();
}

void cursor(int x, int y) {
    glutPostRedisplay();
}

// button will be GLUT_LEFT_BUTTON or GLUT_RIGHT_BUTTON
// state will be GLUT_UP or GLUT_DOWN
void mouse(int button, int state, int x, int y) {
    glutPostRedisplay();
}

void timer(int dummy) {
    //update position of first block of tail
    if (upMov || downMov || leftMov || rightMov) {
        tail[0].setCenter(snake.getCenter());
//        debugging prints
//        cout << "snake center:" << snake.getCenterX() << " " << snake.getCenterY() << endl;
//        cout << tail[0].getCenterX() << " " << tail[0].getCenterY() << endl;
//        cout << tail[1].getCenterX() << " " << tail[1].getCenterY() << endl;
        //update positions of the rest of the tail
        for (int i = tail.size()-1; i > 0; i--) {
            tail[i].setCenter(tail[i-1].getCenter());
        }
    }
    //Movement Handling
    if(upMov){
        snake.moveY(-4);
    }
    if(downMov){
        snake.moveY(4);
    }
    if(leftMov){
        snake.moveX(-4);
    }
    if(rightMov){
        snake.moveX(4);
    }
    //If the snake is overlapping the apple functionality
    if(snake.isOverlapping(apples[0])){
        apples.clear();
        int tempScore = snake.getAmtEaten();
        snake.eat();
        int scoreDiff = snake.getAmtEaten() - tempScore;
        if (scoreDiff > 1){
            if(tempScore == 0 && scoreDiff == 2){
                snake.setAmtEaten(tempScore);
            }
            snake.setAmtEaten(tempScore+1);
        }
        //add a quad to the tail
        grow();
        //add a new apple
        spawnApple();
    }
    glutPostRedisplay();
    glutTimerFunc(30, timer, dummy);
}

/* Main function: GLUT runs as a console application starting at main()  */
int main(int argc, char** argv) {
    
    init();
    
    glutInit(&argc, argv);          // Initialize GLUT
    
    glutInitDisplayMode(GLUT_RGBA);
    
    glutInitWindowSize((int)width, (int)height);
    glutInitWindowPosition(100, 200); // Position the window's initial top-left corner
    /* create the window and store the handle to it */
    wd = glutCreateWindow("Snek");
    
    // Register callback handler for window re-paint event
    glutDisplayFunc(display);
    
    // Our own OpenGL initialization
    initGL();
    
    // register keyboard press event processing function
    // works for numbers, letters, spacebar, etc.
    glutKeyboardFunc(kbd);
    
    // register special event: function keys, arrows, etc.
    glutSpecialFunc(kbdS);
    
    // handles mouse movement
    glutPassiveMotionFunc(cursor);
    
    // handles mouse click
    glutMouseFunc(mouse);
    
    // handles timer
    glutTimerFunc(0, timer, 0);
    
    // Enter the event-processing loop
    glutMainLoop();
    return 0;
}
