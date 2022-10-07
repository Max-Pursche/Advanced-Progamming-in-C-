#include "graphics.h"
#include "Quad.h"
#include "Quad.cpp"
#include "shape.h"
#include "shape.cpp"
#include "circle.h"
#include "circle.cpp"
#include <iostream>
#include <time.h>
#include <vector>
using namespace std;
GLdouble width, height;
int wd;
//Button spawn({1, 0, 0}, {100, 100}, 100, 50, "Press");
vector<Quad> squares;
vector<Circle> circles;
void spawnSquare(int x,int y) {
    squares.push_back(Quad({rand() % 10 / 10.0, rand() % 10 / 10.0, rand() % 10 / 10.0}, {x, y}, rand()%10 + 20, rand()%10 + 20));
}
void spawnCircle(int x,int y) {
    circles.push_back(Circle({rand() % 10 / 10.0, rand() % 10 / 10.0, rand() % 10 / 10.0}, x, y, rand()%5+15));
}

void init() {
    width = 720;
    height = 500;
    srand(time(0));
    gameState = STATE1;
}

/* Initialize OpenGL Graphics */
void initGL() {
    // Set "clearing" or background color
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Black and opaque
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
        char str[] = "Press 'S' to start";
        glRasterPos2d(width/2.5, height/2);
        for (const char &letter : str) {
            glutBitmapCharacter(GLUT_BITMAP_8_BY_13, letter);
        }
    }
    if(gameState == STATE2) {
        char str2[] = "Press 'C' to clear";
        glRasterPos2i((20), 20);
        for (const char &letter : str2) {
            glutBitmapCharacter(GLUT_BITMAP_8_BY_13, letter);
        }
    }
    if(gameState == STATE3) {
        char str3[] = "No More Confetti!!";
        glRasterPos2i(width/2, height/2);
        for (const char &letter : str3) {
            glutBitmapCharacter(GLUT_BITMAP_8_BY_13, letter);
        }
    }

    for (const Quad &square : squares) {
        square.draw();
    }
    for (const Circle &circle : circles) {
        circle.draw();
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
            gameState = STATE2;
            break;
        }
        case 'c': {
            circles.clear();
            squares.clear();
            break;
        }
    }
    glutPostRedisplay();
}


void cursor(int x, int y) {

    glutPostRedisplay();
}

// button will be GLUT_LEFT_BUTTON or GLUT_RIGHT_BUTTON
// state will be GLUT_UP or GLUT_DOWN
void mouse(int button, int state, int x, int y) {
    if(button == GLUT_LEFT_BUTTON && state == GLUT_UP){
        int randInt = rand();
        //Square
        if(randInt%2 == 0){
            spawnSquare(x,y);
        }
        //Circle
        else{
            spawnCircle(x,y);
        }
    }
    glutPostRedisplay();
}

/* Main function: GLUT runs as a console application starting at main()  */
int main(int argc, char** argv) {
    init();
    
    glutInit(&argc, argv);          // Initialize GLUT
    
    glutInitDisplayMode(GLUT_RGBA);
    
    glutInitWindowSize((int)width, (int)height);
    glutInitWindowPosition(100, 200); // Position the window's initial top-left corner
    /* create the window and store the handle to it */
    wd = glutCreateWindow("*|*Pretty Shapes*|*");
    
    // Register callback handler for window re-paint event
    glutDisplayFunc(display);
    
    // Our own OpenGL initialization
    initGL();
    
    // register keyboard press event processing function
    // works for numbers, letters, spacebar, etc.
    glutKeyboardFunc(kbd);
    
    // handles mouse movement
    glutPassiveMotionFunc(cursor);
    
    // handles mouse click
    glutMouseFunc(mouse);
    
    // Enter the event-processing loop
    glutMainLoop();
    return 0;
}
