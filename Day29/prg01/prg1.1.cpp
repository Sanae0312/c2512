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
        
        friend ostream& operator<<(std::ostream &out, const Employee &e) 
        {
            out << e.id << " " << e.age << " " << e.name;
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


