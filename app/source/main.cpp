#include <iostream>
#include "ui_common.h"
#include "driver_registration.h"
#include "login.h"

int main() {
    int choice = 0;
    while (choice != 99) {
        uiCommon.TitleBar("Main Menu");
        std::cout << "1) Driver Registration\n2) Login\n99) Exit\n";
        choice = uiCommon.in.Int("Enter your choice: ");

        switch (choice) {
        case 1:
            driverRegistration();
            break;
        case 2:
            login();
            break;
        case 99:
            std::cout << "Exiting...\n";
            break;
        default:
            std::cout << "Invalid choice. Try again.\n";
            uiCommon.PressAnyKey();
        }
    }
    return 0;
}
