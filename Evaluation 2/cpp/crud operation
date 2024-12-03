#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;

const int MAX_SURGERIES = 100;

class Surgeries
{
	friend class SurgeryManager;
	private:
		string SurgeryID;
		int Duration;
};

class SurgeryManager
{
	private:
		Surgeries totalSurgeries[MAX_SURGERIES];
		int numSurgeries;
	public:
		int findIndexById(string SurgeryID);
		void create();
		void displayAll();
		void editById();
		void deleteById();

		SurgeryManager();
};

void printMenu();

int main()
{
	SurgeryManager manager;

	int choice;

	do
	{
		printMenu();
		
		cout << "Enter the choice: ";
		cin >> choice;

		switch(choice)
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
				cout << "Terminating the program.\n";
				break;
			default:
				cout << "Invalid choice.Please enter a number between 1 and 5.\n";
		}
	}while (choice != 5);

	return EXIT_SUCCESS;
}

void SurgeryManager::create()
{
	if (numSurgeries >= MAX_SURGERIES)
	{
		cout << "Error: Maximum surgery limit reached.\n";
		return;
	}
	
	string SurgeryID;
	int Duration;

	cout << "Enter Surgery SurgeryID: ";
	cin >> SurgeryID;

	if (findIndexById(SurgeryID) != -1)
	{
		cout << "Error: " << SurgeryID << "already exists.";
		return;
	}

	cout << "Enter duration: ";
	cin >> Duration;
	
	totalSurgeries[numSurgeries].SurgeryID = SurgeryID;
	totalSurgeries[numSurgeries].Duration = Duration;
	numSurgeries++;

	cout << "Surgery created successfully/";
}

void SurgeryManager::displayAll()
{
	if (numSurgeries == 0)
	{
		cout << "No surgeries available for display/";
		return;
	}

	cout << "................................................\n";
	cout << "|   SurgeryID | Duration                       |\n";
	cout << "................................................\n";
	for (int i = 0 ; i < numSurgeries ; i++)
	{
		cout << "| " << setw(10) << totalSurgeries[i].SurgeryID << " |" 
			 << setw(13) << totalSurgeries[i].Duration << setw(22) << " |\n";
	}
	cout << "................................................\n";
}

int SurgeryManager::findIndexById(string SurgeryID)
{
	for (int i = 0 ; i < numSurgeries ; i++)
	{
		if (totalSurgeries[i].SurgeryID == SurgeryID)
		{
			return i;
		}
	}
	
	return -1;
}

void SurgeryManager::editById()
{
	string SurgeryID;
	cout << "Enter surgery id to edit: ";
	cin >> SurgeryID;

	int index = findIndexById(SurgeryID);

	if (index == -1)
	{
		cout << "Error: surgery id not found.";
		return;
	}

	cout << "Enter new duration: ";
	cin >> totalSurgeries[index].Duration;

	cout << "Surgery updated successfully.";
}

void SurgeryManager::deleteById()
{
	string SurgeryID;

	cout << "Enter surgery id to delete: ";
	cin >> SurgeryID;

	int index = findIndexById(SurgeryID);

	if (index == -1)
	{
		cout << "Error: surgery id not found.";
		return;
	}

	for (int i = index ; i < numSurgeries - 1 ; i++)
	{
		totalSurgeries[i] = totalSurgeries[i+1];
	}
	numSurgeries--;

	cout << "Surgery id deleted successfully.\n";
}

SurgeryManager::SurgeryManager()
{
	numSurgeries = 0;
}

void printMenu()
{
	cout << "\n==== Surgery Management Module ====\n";
	cout << "1. Create Surgery Data\n";
	cout << "2. Display Surgery Data\n";
	cout << "3. Edit Surgery Data\n";
	cout << "4. Delete Surgery Data\n";
	cout << "5. Exit\n";
}
