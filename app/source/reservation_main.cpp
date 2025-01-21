#include "ParkingSystem.h"
#include <iostream>
#include <iomanip>

void ParkingSystem::reserveParkingSpot() {
    std::cout << "\n1.Reserve Parking spot:\n";
    std::cout << "Car Number:";
    std::cin.ignore();
    std::getline(std::cin, carNumber);
    std::cout << "Enter Start Time (YYYY-MM-DD (24)HH:MM): ";
    std::getline(std::cin, startTime);
    std::cout << "Enter End Time (YYYY-MM-DD (24)HH:MM): ";
    std::getline(std::cin, endTime);
    std::cout << "Enter the Duration : ";

    std::cin >> duration;
    Amount = 10 * duration; 
    std::cout << "Total Price: $ " << std::fixed << std::setprecision(2) << Amount << std::endl;
    
    char confirm;
    std::cout << "Confirm Booking (Y/N): ";
    std::cin >> confirm;
    if (confirm == 'Y' || confirm == 'y') {
        bookingNumber = "B240117-0001"; 
        std::cout << "Reservation successful, spot Id GR001 reserved under the name Minhaj" << std::endl; 
        std::cout << "Generated Booking Number is " << bookingNumber << std::endl;
    }
}

void ParkingSystem::viewBookings() {
    std::cout << "\n2.view Bookings:\n";
    std::cout << "Car Number : " << carNumber << std::endl;
    std::cout << "Spot id : GR001" << std::endl;
    std::cout << "Start Time (YYYY-MM-DD HH:MM): " << startTime << std::endl;
    std::cout << "End Time (YYYY-MM-DD HH:MM): " << endTime << std::endl;
    std::cout << "Amount : Rs" << std::fixed << std::setprecision(2) << Amount << std::endl;
}

void ParkingSystem::unparkVehicle() {
    std::cout << "\n3.Unpark vehicle(payments):\n";
    std::string bookingNumberInput;
    std::string paymentMode;

    std::cout << "Booking Number / Car Number: ";
    std::cin >> bookingNumberInput;
    std::cin.ignore();  // To ignore newline character after taking input for bookingNumberInput
    std::cout << "Amount: $" << Amount << std::endl;
    std::cout << "Payment Mode (cash/card/upi): " << std::endl;   
    std::cout << "1. Cash" << std::endl;
    std::cout << "2. Card" << std::endl;
    std::cout << "3. Upi"  << std::endl;
    std::cout << "Enter your choice: ";
    std::cin >> paymentMode;
                
    std::cout << "Payment Received Successfully.\n";
    std::cout << "Generated Payment Reference Number: P240117-0001\n";
}
