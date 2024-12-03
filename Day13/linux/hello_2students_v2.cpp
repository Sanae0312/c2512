#include <iostream>
#include <cstdlib>

using std::cout;
using std::cin;
using std::endl;

void read_student(int& id, char* name)
{
	cout << "Enter id: ";
	cin >> id;
	cout << "Enter name: ";
	cin >> name;
}

void print_student(int& id, char* name)
{
	cout << "Hello " << name << " of id " << id << " !!!" << endl;
}

int main() 
{
	int id1, id2;
	char name1[255], name2[255];

	cout << "Enter details of 1st student: " << endl;
	read_student(id1,name1);
	cout << "Enter details of 1st student: " <<endl;
	read_student(id2,name2);

	print_student(id1,name1);
	print_student(id2,name2);
	
	return EXIT_SUCCESS;
}
