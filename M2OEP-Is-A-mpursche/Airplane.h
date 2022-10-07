//
// Created by mrgat on 3/2/2022.
//

#ifndef M2OEP_IS_A_MPURSCHE_AIRPLANE_H
#define M2OEP_IS_A_MPURSCHE_AIRPLANE_H
#include "vector"
#include "istream"
#include "ostream"
#include "Vehicle.h"

class Airplane : public Vehicle {
private:
    int fuelCap;
    int pricePerGallon;
    string pilot;
    int pilotWage;
public:
    //construcor
    Airplane();

    //getters
    int getFuelCap();
    int getPricePerGal();
    string getPilot();
    int getPilotWage();

    //setters
    void setFuelCap(int);
    void setPicePerGal(int);
    void setPilot(string);
    void setPilotWage(int);

    //overriding the charter method
    void charter() override;
};


#endif //M2OEP_IS_A_MPURSCHE_AIRPLANE_H
