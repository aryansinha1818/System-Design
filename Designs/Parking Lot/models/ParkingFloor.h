#pragma once
#include <vector>
#include "ParkingSpot.h"

using namespace std;

class ParkingFloor
{
public:
    int floorNumber;
    vector<ParkingSpot *> spots;

    ParkingFloor(int floorNumber)
    {
        this->floorNumber = floorNumber;
    }

    void addParkingSpot(ParkingSpot *spot)
    {
        spots.push_back(spot);
    }

    ParkingSpot *getAvailability(VehicleType vehicleType)
    {
        for (auto spot : spots)
        {
            if (!spot->isOccupied && spot->canFitVehicle(vehicleType))
            {
                return spot;
            }
        }

        return nullptr;
    }
};