#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class ParkingSystem {
private:
    string carNumber;
    string startTime;
    string endTime;
    double Amount;
    string bookingNumber;
    int duration;

public:
    void reserveParkingSpot() {
        cout << "\n1.Reserve Parking spot:\n";
        cout << "Car Number:";
        // cin >> carNumber;
        cin.ignore();
        getline(cin, carNumber);
        // cout << carNumber << endl; 
        cout << "Enter Start Time (YYYY-MM-DD (24)HH:MM): ";
        // cin >> startTime;
        getline(cin,startTime);
        cout << "Enter End Time (YYYY-MM-DD (24)HH:MM): ";
        // cin >> endTime;
        getline(cin,endTime);
        cout << "Enter the Duration : ";

        cin >> duration;
        Amount = 10*duration; 
        cout << "Total Price: $ " << fixed << setprecision(2) << Amount << endl;
        char confirm;
        cout << "Confirm Booking (Y/N): ";
        cin >> confirm;
        if (confirm == 'Y' || confirm == 'y') {
            bookingNumber = "B240117-0001"; 
            cout << "Reservation successful, spot Id GR001 reserved under the name Minhaj" << endl ; 
            cout << "Generated Booking Number is " << bookingNumber << endl;
        }
    }

    void viewBookings() {
        cout << "\n2.view Bookings:\n";
        cout << "Car Number : " << carNumber << endl;
        cout << "Spot id : GR001" << endl;
        cout << "Start Time (YYYY-MM-DD HH:MM): " << startTime << endl;
        cout << "End Time (YYYY-MM-DD HH:MM): " << endTime << endl;
        cout << "Amount : Rs" << fixed << setprecision(2) << Amount << endl;
    }

    void unparkVehicle() {
        cout << "\n3.Unpark vehicle(payments):\n";
        string bookingNumberInput;
        string paymentMode;

        cout << "Booking Number / Car Number: ";
        cin >> bookingNumberInput;
        getline(cin,bookingNumberInput);
        cout << "Amount: $" << Amount << endl;
        cout << "Payment Mode (cash/card/upi): " << endl;   
        cout << "1. Cash" << endl;
        cout << "2. Card" << endl;
        cout << "3. Upi"  << endl;
        cout << "Enter your choice :" ;
        cin >> paymentMode;
                
        cout << "Payment Received Successfully.\n";
        cout << "Generated Payment Reference Number: P240117-0001\n";
    }
};

int main() {
    ParkingSystem ps;
    int choice;

    do {
        cout << "\n=== Driver Dashboard ===\n";
        cout << "1. Reserve Parking Spot\n";
        cout << "2. View Bookings\n";
        cout << "3. Unpark Vehicle\n";
        cout << "4. Profile\n";
        cout << "5. Logout\n";
        cout << "Enter your choice : ";
        cin >> choice;

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
                cout << "\nProfile\n";
                break;
            case 5:
                cout << "\nLogging out... Goodbye!\n";
                break;
            default:
                cout << "Invalid choice, please try again.\n";
        }
    } while (choice != 5);

    return 0;
}
