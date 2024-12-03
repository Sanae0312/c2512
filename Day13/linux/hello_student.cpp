#include <iostream>
#include <cstdlib>

using std::cout;
using std::cin;
using std::endl;

int main() 
{
	int id;
	char name[255];
	cout << "Enter id: ";
	cin >> id;
	cout << "Enter a name: ";
	cin >> name;
	cout << "Hello " << name << " of id " << id << " !!!" << endl;

	return EXIT_SUCCESS;
}
