//1.2 "id, age, name" as dynamic memory using new and delete 

#include <iostream>
#include <string>
#include <utility>
#include <cstring>
#include <cstdlib>

using namespace std;

class Employee
{
    private:
        int* id;
        int* age;
        char* name;
    public:
        Employee(int id, int age, const string& name) 
        {
            this->id = new int (id);
            this->age = new int (age);
            this->name = new char[name.length()+1];
            strcpy(this->name, name.c_str());
        }
        
        ~Employee()
        {
            delete id;
            delete age;
            delete[] name;
        }
        friend ostream& operator<<(std::ostream &out, const Employee &e) 
        {
            out << *e.id << " " << *e.age << " " << e.name;
            return out;
        }
        
        void swap(Employee& other)
        {
            std::swap(id,other.id);
            std::swap(age,other.age);
            std::swap(name,other.name);
        }
};

int main()
{
     Employee e1(101,22,"Athira");
     Employee e2(102,23,"Bhagya");
     
     cout << e1 << endl;
     cout << e2 << endl;
     
     e1.swap(e2);
     
     cout << "After swapping.." << endl;
     cout << e1 << endl;
     cout << e2 << endl;
     
     return EXIT_SUCCESS;
}


