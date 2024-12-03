#include <iostream>
#include <cstdlib>

using std::cout;
using std::cin;
using std::endl;

int main() 
{
	char name[255];
	cout << "Enter a name: ";
	cin >> name;
	cout << "Hello " << name << " !!!" << endl;

	return EXIT_SUCCESS;
}
