#ifndef FINAL_PROJECT_MPURSCHE_SNAKE_H
#define FINAL_PROJECT_MPURSCHE_SNAKE_H
#include "Quad.h"
#include <vector>
using namespace std;

class Snake : public Quad {
private :
    color abtEatColor;
    color fillOg;
    int amtEaten = 1;
    vector<Quad> tail;
public :
    //constructor
    Snake(color fill, point center, unsigned int width, unsigned int height, int eaten);
    //draw method

    //virtual void draw() const override;
    //getter for amount eaten
    int getAmtEaten();
    //setter for amount eaten
    void setAmtEaten(int);
    //overlap method
    bool isOverlapping(Quad) const;
    //eating method
    void eat();
    //about to be eaten color shift
    void openMouth();
    //eaten color shift
    void closeMouth();
};

#endif //FINAL_PROJECT_MPURSCHE_SNAKE_H
