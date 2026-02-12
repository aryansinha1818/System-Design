#pragma once
#include <ctime>
#include "Vehicle.h"
#include "ParkingSpot.h"

class Ticket
{
public:
    int ticketId;
    time_t entryTime; // 17000000
    Vehicle *vehicle;
    ParkingSpot *parkingSpot;

    Ticket(int id, Vehicle *vehicle, ParkingSpot *spot)
    {
        this->ticketId = id;
        this->vehicle = vehicle;
        this->parkingSpot = spot;
        this->entryTime = time(nullptr);
    }
};