#include <iostream>
#include "ui_common.h"
#include "driver_page.h"

void driverPage(const std::string &username) {
    int choice = 0;
    while (choice != 99) {
        uiCommon.TitleBar("Driver Page");
        std::cout << "Welcome, " << username << "!\n";
        std::cout << "1) View/Edit Profile\n2) Do Reservation\n3) Pay and Unpark\n4) Change Password\n99) Logout\n";
        choice = uiCommon.in.Int("Enter your choice: ");

        switch (choice) {
        case 1:
            std::cout << "View/Edit Profile not implemented yet.\n";
            break;
        case 2:
            std::cout << "Do Reservation not implemented yet.\n";
            break;
        case 3:
            std::cout << "Pay and Unpark not implemented yet.\n";
            break;
        case 4:
            std::cout << "Change Password not implemented yet.\n";
            break;
        case 99:
            std::cout << "Logging out...\n";
            break;
        default:
            std::cout << "Invalid choice. Try again.\n";
        }
        uiCommon.PressAnyKey();
    }
}
