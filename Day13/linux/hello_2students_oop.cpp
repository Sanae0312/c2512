#include <iostream>
#include <cstdlib>

using std::cout;
using std::cin;
using std::endl;

struct Student
{
	int id;
	char name[255];
};

void read_student(Student& student);
void print_student(Student& student);

int main()
{
	Student student1;
	Student student2;

	cout << "Enter details of 1st student: " << endl;
	read_student(student1);

	cout << "Enter details of 2nd student: " << endl;
	read_student(student2);

	print_student(student1);
	print_student(student2);

	return EXIT_SUCCESS;
}

void read_student(Student& student)
{
	cout << "Enter id: ";
	cin >> student.id;
	cout << "Enter name: ";
	cin >> student.name;
}

void print_student(Student& student)
{
	cout << "Hello " << student.name << " of id " << student.id << " !!! " << endl;
}
