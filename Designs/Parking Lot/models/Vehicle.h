#pragma once
#include <string>
#include "../enums/VehicleType.h"

using namespace std;

class Vehicle
{
public:
    string vehicleNumber;
    VehicleType type;

    Vehicle(string number, VehicleType type)
    {
        this->vehicleNumber = number;
        this->type = type;
    }
};