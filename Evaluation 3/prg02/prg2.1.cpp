 // 2.1
 //    change the crud ops with HospitalStay from array of HospitalStay called `stays`
 //    to vector<HospitalStay> stays.

#include <iostream>
#include <iomanip>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

class SurgeryManager{
    private:
        vector<string>SurgeryIDs;
        vector<int>Durations;
    
    public:
        int findIndexById(string& SurgeryID);
        void create();
        void displayAll();
        void editById();
        void deleteById();

};

int main()
{
    SurgeryManager manager;
    int choice; 

     do {
        printMenu(); 
        cout << "Enter your choice: ";
        cin >> choice;

        // Menu-driven functionality
        switch (choice) 
        {
            case 1:
                manager.create();   
                break;
            case 2: 
                manager.displayAll(); 
                break;
            case 3: 
                manager.editById();      
                break;
            case 4:
                manager.deleteById();    
                break;
            case 5:
                cout << "Exiting the system. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please enter a number between 1 and 5.\n";
        }
    } while (choice != 5);

    return 0;
}

void SurgeryManager::create()
{
    string SurgeryID;
    int Duration;

    cout << "Enter Surgery SurgeryID : ";
    cin >> SurgeryID;

    if (findIndexById(SurgeryID) != -1) 
    {
        cout << "Error: Surgery SurgeryID already exists. Please use a unique SurgeryID.\n";
        return;
    }

    cout << "Enter Durations : ";
    cin >> Duration;

    SurgeryIDs.push_back(SurgeryID);
    Durations.push_back(Duration);

    cout << "Surgery created successfully.\n";
}

void SurgeryManager::displayAll()
{
    if (SurgeryIDs.empty())
    {
        cout << "No Surgery available to display.\n";
        return;
    }

    cout << "------------------------- \n";
    cout << "|   SURGERYID | DURATION |\n";
    cout << "--------------------------\n";
    for (auto ITER = SurgeryIDs.begin() ; ITER != SurgeryIDs.end() ; ITER++) 
    {
        cout << "| " << setw(10) << SurgeryIDs[ITER] << " | "
             << setw(9) << Durations[ITER] << " |\n";
    }
    cout << "--------------------------\n";
}

int SurgeryManager::findIndexById(string& SurgeryID) 
{
    auto iter = find(SurgeryIDs.begin(),SurgeryIDs.end(),SurgeryID);
    if(iter != SurgeryIDs.end())
    {
        return distance(SurgeryIDs.begin(),iter);
    }
    return -1;
}

void SurgeryManager::editById() 
{
    string SurgeryID;
    cout << "Enter Surgery SurgeryID to edit: ";
    cin >> SurgeryID;

    int index = findIndexById(SurgeryID);
    if (index == -1) {
        cout << "Error: Surgery SurgeryID not found.\n";
        return;
    }

    cout << "Current Details - Duration: " << Durations[index] << "\n";

    cout << "Enter New Duration: ";
    cin >> Durations[index];

    cout << "Surgey updated successfully.\n";
}

void SurgeryManager::deleteById() 
{
    string SurgeryID;
    cout << "Enter Surgery SurgeryID to delete: ";
    cin >> SurgeryID;

    int index = findIndexById(SurgeryID);
    if (index == -1) 
    {
        cout << "Error: Surgery SurgeryID not found.\n";
        return;
    }
}

    SurgeryIDs.erase(SurgeryIDs.begin()+index);
    Durations.erase(Durations.begin()+index);

    cout << "Surgery deleted successfully.\n";
}

void printMenu()
{
    cout << "\n=== Surgery Management Module ===\n";
    cout << "1. Create Surgery\n";
    cout << "2. Display All Surgery\n";
    cout << "3. Edit Surgery\n";
    cout << "4. Delete Surgery\n";
    cout << "5. Exit\n";
}
