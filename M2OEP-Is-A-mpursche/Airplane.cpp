//
// Created by mrgat on 3/2/2022.
//

#include "Airplane.h"
#include <iostream>
Airplane::Airplane() : Vehicle(), fuelCap(0), pilotWage(0), pilot("no pilot") {
}

int Airplane::getFuelCap() {
    return fuelCap;
}

int Airplane::getPricePerGal() {
    return pricePerGallon;
}

string Airplane::getPilot() {
    return pilot;
}

int Airplane::getPilotWage() {
    return pilotWage;
}

void Airplane::setFuelCap(int val) {
    if (val > 0) {
        fuelCap = val;
    }
}

void Airplane::setPicePerGal(int val) {
    if (val > 0){
        pricePerGallon = val;
    }
}

void Airplane::setPilot(string val) {
    pilot = val;
}

void Airplane::setPilotWage(int val) {
    if (val > 0){
        pilotWage = val;
    }
}

void Airplane::charter() {
    string inputStr;
    int inputInt;
    bool error = false;
    cout << "Charter a plane!" << endl;
    do{
        cout << "enter manufacturer of the plane:";
        cin >> inputStr;
        if (cin.fail()){
            cin.clear();
            cin.ignore(999, '\n');
            cout << "Please enter a valid string" << endl;
            error = true;
        }
    }while(error);
    setManuFac(inputStr);

    do{
        cout << "enter model of the plane:";
        cin >> inputStr;
        if (cin.fail()){
            cin.clear();
            cin.ignore(999, '\n');
            cout << "Please enter a valid string" << endl;
            error = true;
        }
    }while(error);
    setModel(inputStr);

    do {
        cout << "enter Number of seats:";
        cin >> inputInt;
        if (cin.fail()){
            cin.clear();
            cin.ignore(999, '\n');
            cout << "Please enter a valid integer" << endl;
            error = true;
        }
    }while(error);
    setNumSeats(inputInt);

    do {
        cout << "enter max speed of the plane:";
        cin >> inputInt;
        if (cin.fail()){
            cin.clear();
            cin.ignore(999, '\n');
            cout << "Please enter a valid integer" << endl;
            error = true;
        }
    }while(error);
    setMaxSpeed(inputInt);

    do{
        cout << "enter the fuel capacity of the plane:";
        cin >> inputInt;
        if (cin.fail()){
            cin.clear();
            cin.ignore(999, '\n');
            cout << "Please enter a valid integer" << endl;
            error = true;
        }
    }while(error);
    setFuelCap(inputInt);

    do{
        cout << "enter the fuel price for the plane:";
        cin >> inputInt;
        if (cin.fail()){
            cin.clear();
            cin.ignore(999, '\n');
            cout << "Please enter a valid integer" << endl;
            error = true;
        }
    }while(error);
    setPicePerGal(inputInt);

    do{
        cout << "enter price of the plane:";
        cin >> inputInt;
        if (cin.fail()){
            cin.clear();
            cin.ignore(999, '\n');
            cout << "Please enter a valid integer" << endl;
            error = true;
        }
    }while(error);
    setPrice(inputInt);

    do{
        cout << "enter pilot of the plane:";
        cin >> inputStr;
        if (cin.fail()){
            cin.clear();
            cin.ignore(999, '\n');
            cout << "Please enter a valid integer" << endl;
            error = true;
        }
    }while(error);
    setPilot(inputStr);

    do{
        cout << "enter the pilot's wage:";
        cin >> inputInt;
        if (cin.fail()){
            cin.clear();
            cin.ignore(999, '\n');
            cout << "Please enter a valid integer" << endl;
            error = true;
        }
    }while(error);
    setPilotWage(inputInt);
    int finalPrice = (getPricePerGal() * getFuelCap()) + getPrice();
    cout << "-------------------Charter Statement-------------------" << endl;
    cout << "Plane: " << getManuFac() << " " << getModel() << endl;
    cout << "\tPilot:" << getPilot() << endl;
    cout << "\tMax Speed:" << getMaxSpeed() << endl;
    cout << "\tNumber of Seats:" << getNumSeats() << endl;
    cout << "\t\tFinal Price:" << finalPrice << endl;
}