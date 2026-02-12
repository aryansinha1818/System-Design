#pragma once
#include "../enums/VehicleType.h"
#include "../enums/SpotType.h"

class ParkingSpot
{
public:
    int spotId;
    bool isOccupied;
    SpotType type;

    ParkingSpot(int id, SpotType type)
    {
        this->spotId = id;
        this->type = type;
        this->isOccupied = false;
    }

    bool canFitVehicle(VehicleType vehicleType)
    {
        // here we are having the same order as for vehicletype and spotype
        // first car then bike. to basically have a array like thing
        // spottype::bike -> 0
        // spottype::car -> 1

        return static_cast<int>(type) == static_cast<int>(vehicleType);
    }

    void park()
    {
        isOccupied = true;
    }

    void unpark()
    {
        isOccupied = false;
    }
};