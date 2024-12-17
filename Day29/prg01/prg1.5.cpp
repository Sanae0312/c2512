#include <iostream>
#include <algorithm>
#include <string>
#include <memory>
#include <vector>
using namespace std;

class Employee
{
    public:
        unique_ptr<int> id;
        unique_ptr<int> age;
        unique_ptr<string> name;

    public:
        Employee(int e_id = 0, int e_age = 0, string e_name = "")
            : id(make_unique<int>(e_id)), age(make_unique<int>(e_age)), name(make_unique<string>(e_name)) {}

    virtual void printDetails() const 
    {
        cout << *id << " " << *age << " " << *name;
    }

    virtual void swap(Employee& other) 
    {
        std::swap(id, other.id);
        std::swap(age, other.age);
        std::swap(name, other.name);
    }

    friend ostream& operator<<(ostream& out, const Employee& employee);
    friend istream& operator>>(istream& input, Employee& employee);
};

class Programmer : public Employee
{
    public:
        unique_ptr<string[]> tasks;
        unique_ptr<int> taskCount;

    public:
        Programmer(int p_id = 0, int p_age = 0, string p_name = "", string* p_tasks = nullptr, int p_taskCount = 0)
            : Employee(p_id, p_age, p_name), taskCount(make_unique<int>(p_taskCount)) 
            {
                tasks = make_unique<string[]>(*taskCount);
                if (p_tasks) {
                    for (int i = 0; i < *taskCount; ++i) 
                    {
                        tasks[i] = p_tasks[i];
                    }
            }
    }

    void swap(Programmer& other)
    {
        std::swap(tasks, other.tasks);
        std::swap(taskCount, other.taskCount);
        Employee::swap(other);
    }

    void printDetails() const override 
    {
        Employee::printDetails();
        cout << " Tasks: ";
        for (int i = 0; i < *taskCount; ++i) 
        {
            cout << tasks[i] << " ";
        }
    }

    friend ostream& operator<<(ostream& out, const Programmer& programmer);
    friend istream& operator>>(istream& input, Programmer& programmer);
};

// Overloaded operator<< for Employee
ostream& operator<<(ostream& out, const Employee& employee) 
{
    employee.printDetails();
    return out;
}

// Overloaded operator>> for Employee
istream& operator>>(istream& input, Employee& employee) 
{
    cout << "Enter ID: ";
    input >> *employee.id;
    cout << "Enter Age: ";
    input >> *employee.age;
    cout << "Enter Name: ";
    input.ignore();
    getline(input, *employee.name);
    return input;
}

// Overloaded operator<< for Programmer
ostream& operator<<(ostream& out, const Programmer& programmer) 
{
    programmer.printDetails();
    return out;
}

// Overloaded operator>> for Programmer
istream& operator>>(istream& input, Programmer& programmer) 
{
    input >> static_cast<Employee&>(programmer);  // Input base class details
    cout << "Enter number of tasks: ";
    int count;
    input >> count;
    programmer.taskCount = make_unique<int>(count);
    programmer.tasks = make_unique<string[]>(count);
    cout << "Enter tasks:\n";
    input.ignore();  // Clear buffer
    for (int i = 0; i < count; ++i) {
        cout << "Task " << i + 1 << ": ";
        getline(input, programmer.tasks[i]);
    }
    return input;
}

int main() 
{
    int N;
    cout << "Enter the number of programmers: ";
    cin >> N;

    vector<unique_ptr<Programmer>> programmers;

    // Input programmers
    for (int i = 0; i < N; ++i) 
    {
        cout << "\nEnter details for Programmer " << i + 1 << ":\n";
        auto p = make_unique<Programmer>();
        cin >> *p;
        programmers.push_back(move(p));
    }

    // Display all programmers
    cout << "\nDetails of Programmers:\n";
    for (int i = 0; i < programmers.size(); ++i) 
    {
        cout << "Programmer " << i + 1 << ": " << *programmers[i] << endl;
    }

    // Demonstrate swap between two programmers
    if (programmers.size() >= 2) {
        cout << "\nSwapping Programmer 1 and Programmer 2...\n";
        programmers[0]->swap(*programmers[1]);

        cout << "\nAfter Swap:\n";
        cout << "Programmer 1: " << *programmers[0] << endl;
        cout << "Programmer 2: " << *programmers[1] << endl;
    } 
    else 
    {
        cout << "\nNot enough programmers to demonstrate swap.\n";
    }

    return 0;
}
