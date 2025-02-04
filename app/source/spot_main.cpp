#include <iostream>
#include <sstream>
#include <string>
#include <map>
#include <vector>

#include "./../headers/spot_main.h"
#include "./../headers/ui_common.h"

// Data structure for a parking spot
struct Spot {
    std::string spotId;
    double charge;
    bool availability;
};

// Global map to manage spots for each floor
std::map<std::string, std::vector<Spot>> spotDatabase;

class SpotController {
    public:
        static void Read(std::string& floorNumber, std::string& spotId, int flags = 3) {
            if ((flags & 1) != 0) {
                std::cout << "Floor Number: "; 
                std::cin >> floorNumber;
            }
            if ((flags & 2) != 0) {
                std::cout << "Spot ID: ";
                std::cin >> spotId;
            }
        }

        void Create() {
            uiCommon.TitleBar("Admin App > Spot Management > Create Spot");
            std::string floorNumber, spotId;
            double charge;
            bool availability;

            Read(floorNumber, spotId, 1);
            std::cout << "Enter Spot id: ";
            std::cin >> spotId;
            std::cout << "Enter Spot Charge: ";
            std::cin >> charge;
            std::cout << "Is the Spot Available? (1 for Yes, 0 for No): ";
            int input;
            std::cin >> input;
            availability = (input == 1);

            // Add spot to the database
            spotDatabase[floorNumber].push_back({spotId, charge, availability});
            std::cout << "Spot created successfully!" << std::endl;
            uiCommon.PressAnyKey(true);
        }

        void Edit() {
            uiCommon.TitleBar("Admin App > Spot Management > Edit Spot");
            // std::string floorNumber, spotId;
            // Read(floorNumber, spotId, 3);

            // // Search for the spot
            // auto& spots = spotDatabase[floorNumber];
            // auto it = std::find(spots.begin(), spots.end(), [&](const Spot& spot) {
            //     return spot.spotId == spotId;
            // });

            // if (it == spots.end()) {
            //     std::cout << "Spot not found!" << std::endl;
            //     uiCommon.PressAnyKey(true);
            //     return;
            // }

            // // Edit spot details
            // std::cout << "Editing Spot ID: " << it->spotId << std::endl;
            // std::cout << "Enter new Spot Charge: ";
            // std::cin >> it->charge;
            // std::cout << "Is the Spot Available? (1 for Yes, 0 for No): ";
            // int input;
            // std::cin >> input;
            // it->availability = (input == 1);

            // std::cout << "Spot details updated successfully!" << std::endl;
            uiCommon.PressAnyKey(true);
        }

        void Delete() {
            uiCommon.TitleBar("Admin App > Spot Management > Delete Spot");
            // std::string floorNumber, spotId;
            // Read(floorNumber, spotId, 3);

            // // Search and delete the spot
            // auto& spots = spotDatabase[floorNumber];
            // auto it = std::remove_cv(spots.begin(), spots.end(), [&](const Spot& spot) {
            //     return spot.spotId == spotId;
            // });

            // if (it != spots.end()) {
            //     spots.erase(it, spots.end());
            //     std::cout << "Spot deleted successfully!" << std::endl;
            // } else {
            //     std::cout << "Spot not found!" << std::endl;
            // }

            uiCommon.PressAnyKey(true);
        }

        void DisplayAll() {
            uiCommon.TitleBar("Admin App > Spot Management > List of Spots");

            // if (spotDatabase.empty()) {
            //     std::cout << "No spots available." << std::endl;
            //     uiCommon.PressAnyKey(true);
            //     return;
            // }

            // for (const auto& [floorNumber, spots] : spotDatabase) {
            //     std::cout << "Floor Number: " << floorNumber << std::endl;
            //     for (const auto& spot : spots) {
            //         std::cout << "  Spot ID: " << spot.spotId
            //                   << ", Charge: " << spot.charge
            //                   << ", Available: " << (spot.availability ? "Yes" : "No")
            //                   << std::endl;
            //     }
            // }

            uiCommon.PressAnyKey(true);
        }
};

static int ReadSpotMenu() {
    int choice;

    uiCommon.TitleBar("Admin App > Spot Management");

    std::stringstream soutput;
    soutput << "1 - Create Spot" << std::endl;
    soutput << "2 - Edit Spot" << std::endl;
    soutput << "3 - Delete Spot" << std::endl;
    soutput << "4 - Display All Spots" << std::endl;
    soutput << "99 - Exit" << std::endl;
    soutput << "Your choice: ";
    choice = uiCommon.in.Int(soutput.str());

    uiCommon.Line('~');
    uiCommon.PressAnyKey(true);
    return choice;
}

void ManageSpot() {
    SpotController controller;

    int choice;
    do {
        choice = ReadSpotMenu();
        switch (choice) {
            case 99: {
                std::cout << std::endl;
            } break;
            case 1: {
                controller.Create();
            } break;
            case 2: {
                controller.Edit();
            } break;
            case 3: {
                controller.Delete();
            } break;
            case 4: {
                controller.DisplayAll();
            } break;
        }
    } while (99 != choice);
}
