//
// Created by mrgat on 3/2/2022.
//

#ifndef M2OEP_IS_A_MPURSCHE_VEHICLE_H
#define M2OEP_IS_A_MPURSCHE_VEHICLE_H
#include "vector"
#include "istream"
#include "ostream"
using namespace std;
class Vehicle {
private:
    int numSeats;
    int maxSpeed;
    int price;
    string manufacturer;
    string model;
public:
    //constructor
    Vehicle();

    //getters
    virtual int getNumSeats();
    virtual int getMaxSpeed();
    virtual int getPrice();
    virtual string getManuFac();
    virtual string getModel();

    //setters
    void setNumSeats(int);
    void setMaxSpeed(int);
    void setPrice(int);
    void setManuFac(string);
    void setModel(string);

    //explicit method to generate a charter and est price
    virtual void charter() = 0;
};


#endif //M2OEP_IS_A_MPURSCHE_VEHICLE_H
