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
        Employee(int v_id = 0, int v_age = 0, string v_name = "")
            : id(make_unique<int>(v_id)), age(make_unique<int>(v_age)), name(make_unique<string>(v_name)) {}

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

    friend ostream& operator<<(ostream& os, const Employee& e);
    friend istream& operator>>(istream& is, Employee& e);
};

class Programmer : public Employee
{
    public:
        unique_ptr<string[]> tasks;
        unique_ptr<int> taskCount;

    public:
        Programmer(int v_id = 0, int v_age = 0, string v_name = "", string* v_tasks = nullptr, int v_taskCount = 0)
            : Employee(v_id, v_age, v_name), taskCount(make_unique<int>(v_taskCount)) 
            {
                tasks = make_unique<string[]>(*taskCount);
                if (v_tasks) {
                    for (int i = 0; i < *taskCount; ++i) 
                    {
                        tasks[i] = v_tasks[i];
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

    friend ostream& operator<<(ostream& os, const Programmer& p);
    friend istream& operator>>(istream& is, Programmer& p);
};

// Overloaded operator<< for Employee
ostream& operator<<(ostream& os, const Employee& e) 
{
    e.printDetails();
    return os;
}

// Overloaded operator>> for Employee
istream& operator>>(istream& is, Employee& e) 
{
    cout << "Enter ID: ";
    is >> *e.id;
    cout << "Enter Age: ";
    is >> *e.age;
    cout << "Enter Name: ";
    is.ignore();
    getline(is, *e.name);
    return is;
}

// Overloaded operator<< for Programmer
ostream& operator<<(ostream& os, const Programmer& p) 
{
    p.printDetails();
    return os;
}

// Overloaded operator>> for Programmer
istream& operator>>(istream& is, Programmer& p) 
{
    is >> static_cast<Employee&>(p);  // Input base class details
    cout << "Enter number of tasks: ";
    int count;
    is >> count;
    p.taskCount = make_unique<int>(count);
    p.tasks = make_unique<string[]>(count);
    cout << "Enter tasks:\n";
    is.ignore();  // Clear buffer
    for (int i = 0; i < count; ++i) {
        cout << "Task " << i + 1 << ": ";
        getline(is, p.tasks[i]);
    }
    return is;
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
