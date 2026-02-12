#include "ParkingLot.h"

ParkingLot *ParkingLot::instance = nullptr;

ParkingLot::ParkingLot()
{
    ticketCounter = 0;
}

ParkingLot *ParkingLot::getInstance()
{
    if (!instance)
    {
        instance = new ParkingLot();
    }
    return instance;
}

void ParkingLot::addFloor(ParkingFloor *floor)
{
    floors.push_back(floor);
}

Ticket *ParkingLot::parkVehicle(Vehicle *vehicle)
{
    for (auto floor : floors)
    {
        ParkingSpot *spot = floor->getAvailability(vehicle->type);
        if (spot)
        {
            spot->park();
            return new Ticket(++ticketCounter, vehicle, spot);
        }
    }
    return nullptr;
}

void ParkingLot::unparkVehicle(Ticket *ticket)
{
    ticket->parkingSpot->unpark();
}
