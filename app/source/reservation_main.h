#ifndef PARKINGSYSTEM_H
#define PARKINGSYSTEM_H

#include <string>

class ParkingSystem {
private:
    std::string carNumber;
    std::string startTime;
    std::string endTime;
    double Amount;
    std::string bookingNumber;
    int duration;

public:
    void reserveParkingSpot();
    void viewBookings();
    void unparkVehicle();
};

#endif // PARKINGSYSTEM_H
