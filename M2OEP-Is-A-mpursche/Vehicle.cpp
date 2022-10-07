//
// Created by mrgat on 3/2/2022.
//

#include "Vehicle.h"
Vehicle::Vehicle() {
    manufacturer = "default";
    model = "default";
    maxSpeed = 0;
    numSeats = 0;
    price = 0;
}

string Vehicle::getManuFac() {
    return manufacturer;
}

int Vehicle::getMaxSpeed() {
    return maxSpeed;
}

string Vehicle::getModel() {
    return model;
}

int Vehicle::getNumSeats() {
    return numSeats;
}

int Vehicle::getPrice() {
    return price;
}

void Vehicle::setManuFac(string val) {
    manufacturer = val;
}

void Vehicle::setMaxSpeed(int val) {
    maxSpeed = val;
}

void Vehicle::setModel(string val) {
    model = val;
}

void Vehicle::setPrice(int val) {
    price = val;
}

void Vehicle::setNumSeats(int val) {
    numSeats = val;
}
