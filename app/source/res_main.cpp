#include <iostream>
#include "ParkingSystem.h"

int main() {
    ParkingSystem ps;
    int choice;

    do {
        std::cout << "\n=== Driver Dashboard ===\n";
        std::cout << "1. Reserve Parking Spot\n";
        std::cout << "2. View Bookings\n";
        std::cout << "3. Unpark Vehicle\n";
        std::cout << "4. Profile\n";
        std::cout << "5. Logout\n";
        std::cout << "Enter your choice : ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                ps.reserveParkingSpot();
                break;
            case 2:
                ps.viewBookings();
                break;
            case 3:
                ps.unparkVehicle();
                break;
            case 4:
                std::cout << "\nProfile\n";
                break;
            case 5:
                std::cout << "\nLogging out... Goodbye!\n";
                break;
            default:
                std::cout << "Invalid choice, please try again.\n";
        }
    } while (choice != 5);

    return 0;
}
