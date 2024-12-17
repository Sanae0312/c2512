// // Coding Question: 1.1
//     Employee {id, age, name} //id, age, name are value objects 
//     Employee e1(101,22,"Athira"),e2(102,23,"Bhagya");
//     cout << e1 << endl; //101 22 Athira
//     cout << e2 << endl; //102 23 Bhagya
//     e1.swap(e2);
//     cout << e1 << endl; //102 23 Bhagya
//     cout << e2 << endl; //101 22 Athira

#include <iostream>
#include <string>
#include <utility>
#include <cstdlib>

using namespace std;

class Employee
{
    private:
        int id;
        int age;
        string name;
    public:
        Employee(int id, int age, const string& name) : id(id), name(name), age(age) {}

        Employee(Employee&& other) noexcept
        : id(other.id), age(other.age), name(std::move(other.name)) 
        {
            other.id = 0;
            other.age = 0;
        }

        Employee& operator=(Employee&& other) 
        {
            if (this != &other) 
            {
                id = other.id;
                age = other.age;
                name = std::move(other.name);
                other.id = 0;
                other.age = 0;
            }
        return *this;
    }
        
        friend ostream& operator<<(std::ostream &out, const Employee &e);
            
        void swap(Employee& other)
        {
            Employee temp = std::move(*this);  
            *this = std::move(other);          
            other = std::move(temp);  
        }
};

ostream& operator<<(std::ostream &out, const Employee &e) 
{
    out << e.id << " " << e.age << " " << e.name;
    return out;
}

int main()
{
     Employee e1(101,22,"Athira");
     Employee e2(102,23,"Bhagya");

     cout << "Before swapping.." << endl;
     cout << e1 << endl;
     cout << e2 << endl;
     
     e1.swap(e2);
     
     cout << "After swapping.." << endl;
     cout << e1 << endl;
     cout << e2 << endl;
     
     return EXIT_SUCCESS;
}
