#include <iostream>
#include "services/ParkingLot.h"

using namespace std;

int main()
{
    ParkingLot *parkingLot = ParkingLot::getInstance();

    ParkingFloor *floor1 = new ParkingFloor(1);
    floor1->addParkingSpot(new ParkingSpot(1, SpotType::CAR));
    floor1->addParkingSpot(new ParkingSpot(2, SpotType::BIKE));

    parkingLot->addFloor(floor1);

    Vehicle *car = new Vehicle("KA-01-1234", VehicleType::CAR);

    Ticket *ticket = parkingLot->parkVehicle(car);

    if (ticket)
    {
        cout << "Vehicle parked successfully. Ticket ID: "
             << ticket->ticketId << endl;

        parkingLot->unparkVehicle(ticket);
        cout << "Vehicle exited successfully." << endl;
    }
    else
    {
        cout << "Parking lot is full." << endl;
    }

    return 0;
}
