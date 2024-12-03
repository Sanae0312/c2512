#include <iostream>
#include <cstdlib>

using std::cout;
using std::cin;
using std::endl;

int main() 
{
	int id1, id2;
	char name1[255], name2[255];

	cout << "Enter id of 1st student: ";
	cin >> id1;
	cout << "Enter id of 2nd student: ";
	cin >> id2;

	cout << "Enter name of 1st student: ";
	cin >> name1;
	cout << "Enter name of 2nd student: ";
	cin >> name2;

	cout << "Hello " << name1 << " of id " << id1 << " !!!" << endl;
	cout << "Hello " << name2 << " of id " << id2 << " !!!" << endl;

	return EXIT_SUCCESS;
}
