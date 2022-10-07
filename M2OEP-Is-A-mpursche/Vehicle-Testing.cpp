#include <iostream>
#include "Airplane.h"

bool testAirplane();

int Main(){
    if (testAirplane()){
        cout << "Passed all test cases" << endl;
    }
    return 0;
}

bool testAirplane() {
    bool passed = true;
    Airplane airplane;
    if (airplane.getPilot() != "no pilot"){
        cout << "Failed default constructor case" << endl;
        passed = false;
    }
    airplane.setFuelCap(14);
    if (airplane.getFuelCap() != 14) {
        cout << "Failed 14 test case" << endl;
        passed = false;
    }
    airplane.setPilot("Bobby da Mormon");
    if (airplane.getPilot() != "Bobby da Mormon"){
        cout << "Failed Bobby test case" << endl;
        passed = false;
    }
    return passed;
}