#include <iostream>
#include <iomanip>

using namespace std;

const int MAX_SURGERIES = 100;

class Surgeries
{
	friend class SurgeryManager;
	private:
		string SurgeryID;
		int Duration;
	public:
		bool LessThan(const Surgeries& other);
		bool GreaterThan(const Surgeries& other);

		string GetSurgeryID();
		int GetDuration();
};

class SurgeryManager
{
	friend class SurgeriesAggregator;
	friend int main();
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

class SurgeriesAggregator
{
	public:
		int findMin(SurgeryManager& manager);
		int findMax(SurgeryManager& manager);
		int find2ndMin(SurgeryManager& manager);
		int find2ndMax(SurgeryManager& manager);
};

void printMenu();

int main()
{
	SurgeryManager manager;
	SurgeriesAggregator aggregator;

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
				cout << "Surgery id with minimum duration, " 
				<< manager.totalSurgeries[aggregator.findMin(manager)].GetSurgeryID()
				<< " with duration "
				<< manager.totalSurgeries[aggregator.findMin(manager)].GetDuration();
				break;
			case 6:
				cout << "Surgery id with maximum duration, " 
				<< manager.totalSurgeries[aggregator.findMax(manager)].GetSurgeryID()
				<< " with duration "
				<< manager.totalSurgeries[aggregator.findMax(manager)].GetDuration();
				break;
			case 7:
				cout << "Surgery id with second minimum duration, " 
				<< manager.totalSurgeries[aggregator.find2ndMin(manager)].GetSurgeryID()
				<< " with duration "
				<< manager.totalSurgeries[aggregator.find2ndMin(manager)].GetDuration();
				break;
			case 8:
				cout << "Surgery id with second maximum duration, " 
				<< manager.totalSurgeries[aggregator.find2ndMax(manager)].GetSurgeryID()
				<< " with duration "
				<< manager.totalSurgeries[aggregator.find2ndMax(manager)].GetDuration();
				break;
			case 9:
				cout << "Terminating the program.\n";
				break;
			default:
				cout << "Invalid choice.Please enter a number between 1 and 9.\n";
		}
	}while (choice != 9);

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
		cout << "Error: surgery id already exists.";
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
		cout << "No surgeries available for display.";
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
	cout << "5. Find Surgery With Minimum Duration\n";
	cout << "6. Find Surgery With Maximum Duration\n";
	cout << "7. Find Surgery With Second Minimum Duration\n";
	cout << "8. Find Surgery With Second Maximum Duration\n";
	cout << "9. Exit\n";

}

bool Surgeries::LessThan(const Surgeries& other)
{
	return (Duration < other.Duration);
}

bool Surgeries::GreaterThan(const Surgeries& other)
{
	return (Duration > other.Duration);
}

string Surgeries::GetSurgeryID()
{
	return SurgeryID;
}

int Surgeries::GetDuration()
{
	return Duration;
}

int SurgeriesAggregator::findMin(SurgeryManager& manager)
{
	Surgeries* arr = manager.totalSurgeries;
	int& n = manager.numSurgeries;

	int minIndex = 0;
	for (int i = 0 ; i < n ; i++)
	{
		if (arr[i].LessThan(arr[minIndex]))
		{
			minIndex = i;
		}
	}
	return minIndex;
}

int SurgeriesAggregator::findMax(SurgeryManager& manager)
{
	Surgeries* arr = manager.totalSurgeries;
	int& n = manager.numSurgeries;

	int maxIndex = 0;
	for (int i = 0 ; i < n ; i++)
	{
		if (arr[i].GreaterThan(arr[maxIndex]))
		{
			maxIndex = i;
		}
	}
	return maxIndex;
}

int SurgeriesAggregator::find2ndMin(SurgeryManager& manager)
{
	Surgeries* arr = manager.totalSurgeries;
	int& n = manager.numSurgeries;

	int minIndex = findMin(manager);
	int secondMinIndex = (minIndex == 0) ? 1 : 0;

	for (int i = 0 ; i < n ; i++)
	{
		if (i != minIndex)
		{
			if (arr[i].LessThan(arr[secondMinIndex]))
			{
				secondMinIndex = i;
			}
	}	}
	return secondMinIndex;
}

int SurgeriesAggregator::find2ndMax(SurgeryManager& manager)
{
	Surgeries* arr = manager.totalSurgeries;
	int& n = manager.numSurgeries;

	int maxIndex = findMax(manager);
	int secondMaxIndex = (maxIndex == 0) ? 1 : 0;

	for (int i = 0 ; i < n ; i++)
	{
		if (i != maxIndex)
		{
			if (arr[i].GreaterThan(arr[secondMaxIndex]))
			{
				secondMaxIndex = i;
			}
	}	}
	return secondMaxIndex;
}


