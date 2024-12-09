/*Examples for diamond problem in inheritance:
=============================================================
These class structures represent the diamond problem,
where the `final derived class` 
inherits ambiguously 
from two intermediate classes 
that share a common base class.
=============================================================
Create one static object for final-derived class
and call all behaviours
and 
one dynamic object for final-derived class 
and call all behaviours

Define constructors and destructors for all the classes 

Example 3: `Vehicle System`
- `Base Class:` Vehicle `{field: brand, behavior: drive()}`
- `Derived Class 1:` LandVehicle `{field: numWheels, behavior: steer()}`
- `Derived Class 2:` WaterVehicle `{field: displacement, behavior: sail()}`
- `Final Derived Class:` AmphibiousVehicle `{field: mode, behavior: switchMode()}`
*/

#include <iostream>
#include <string>

using namespace std;

//Base class
class Vehicle
{
    public:
         string brand;

        //constructor
        Vehicle (string brand) : brand(brand)
        {
            cout << "Vehicle constructor called.." << endl;
        }

        //Destructor
        virtual ~Vehicle()
        {
            cout << "Vehicle desstructor called.." << endl;
        }

        void drive()
        {
            cout << brand << " can be driven " << endl;
        }
};

//Derived class1
class LandVehicle : virtual public Vehicle
{
    public:
        int numWheels;

        //constructor
        LandVehicle(string brand, int numWheels) : Vehicle(brand), numWheels(numWheels)
        {
            cout << "LandVehicle constructor called.." << endl;
        }

        //Destructor
        virtual ~LandVehicle()
        {
            cout << "LandVehicle destructor called.." << endl;
        }

        void steer()
        {
            cout << brand << " LandVehicle start steering.." << endl;
        }
};

//Derived class2
class WaterVehicle : virtual public Vehicle
{
    public:
        int displacement;

        //constructor
        WaterVehicle(string brand, int displacement) : Vehicle(brand), displacement(displacement)
        {
            cout << "WaterVehicle constructor called.." << endl;
        }

        //Destructor
        virtual ~WaterVehicle()
        {
            cout << "WaterVehicle destructor called.." << endl;
        }

        void sail()
        {
            cout << brand << " WaterVehicle start sailing" << endl;
        }
};

//Final derived class
class AmphibiousVehicle : public LandVehicle, public WaterVehicle
{
    public:
        string mode;

        //Constructor
        AmphibiousVehicle(string brand, int numWheels, int displacement, string mode) 
        : Vehicle(brand), LandVehicle(brand,numWheels), WaterVehicle(brand,displacement), mode(mode)
        {
            cout << "AmphibiousVehicle constructor called.." << endl;
        }

        //Destructor
        ~AmphibiousVehicle()
        {
            cout << "AmphibiousVehicle destructor called.." << endl;
        }

        void switchMode()
        {
            cout << "switching mode to " << mode << endl;
        }
};

int main()
{
    //Static object for Final Derived Class
    AmphibiousVehicle pav1("Terra", 4, 1500, "LandMode");
    pav1.drive();
    pav1.sail();
    pav1.switchMode();
    pav1.steer();
    
    cout << endl;

    //Dynamic object for Final Derived Class
    Vehicle* pav2 = new AmphibiousVehicle("Aqua", 6, 500, "WaterMode");
    pav2->drive();
    //pav2->steer();
    //pav2->sail();
    //pav2->switchMode();

    delete pav2;

    return 0;
}