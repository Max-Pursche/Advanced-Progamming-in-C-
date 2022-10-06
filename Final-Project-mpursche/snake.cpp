//
// Created by mrgat on 4/29/2022.
//
#include "Quad.h"
#include "snake.h"
Snake::Snake(color fill, point center, unsigned int width, unsigned int height, int eaten) : Quad(fill, center, width, height) {
    fillOg = fill;
    amtEaten = eaten;
    abtEatColor = {fill.red + 0.5, fill.green + 0.5, fill.blue + 0.5};
}

bool Snake::isOverlapping(Quad piece) const {
    //snake head can be on diff sides i.e. bottom y == top y or left x == right x
    if (getRightX() >= piece.getLeftX() && getLeftX() <= piece.getRightX() && getBottomY() >= piece.getTopY() && getTopY() <= piece.getBottomY()) {
        return true;
    }
    else {
        return false;
    }
}

int Snake::getAmtEaten() {
    return amtEaten;
}

void Snake::setAmtEaten(int amt) {
    amtEaten = amt;
}

void Snake::eat() {
    amtEaten += 1;
}

void Snake::openMouth() {
    setColor(abtEatColor);
}

void Snake::closeMouth() {
    setColor(fillOg);
}

