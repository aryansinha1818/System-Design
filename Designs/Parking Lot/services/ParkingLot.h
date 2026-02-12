#pragma once
#include <vector>
#include "../models/ParkingFloor.h"
#include "../models/Ticket.h"

using namespace std;

class ParkingLot
{
private:
    static ParkingLot *instance;
    vector<ParkingFloor *> floors;
    int ticketCounter;

    ParkingLot();

public:
    static ParkingLot *getInstance();
    void addFloor(ParkingFloor *floor);
    Ticket *parkVehicle(Vehicle *vehicle);
    void unparkVehicle(Ticket *ticket);
};