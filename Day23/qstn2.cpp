// single inheritance using static binding:
// =============================================================
// Create two static objects for Both Base and Derived class
// and call all behaviours
// and 
// one two dynamic objects for Base and Derived class 
// and call all behaviours

// Define constructors and destructors for all the classes 

// Example 3: `E-commerce System`
// - `Base Class:` Product `{field: price, behavior: displayInfo()}`
// - `Derived Class:` Electronics `{field: warranty, behavior: powerOn()}`

//================================================================================
#include <iostream>
#include <string>

using namespace std;

//Base class:
class Product
{
    public:
        int price;

        //Constructor
        Product(int price) : price(price)
        {
            cout << "Product constructor called.." << endl;
        }

        //Destructor
        ~Product()
        {
            cout << "Product destructor called.." << endl;
        }

        //Behaviour
        void displayInfo()
        {
            cout << "Product price is " << price << endl;
        }
};

//Derived class
class Electronics : public Product
{
    public:
        int warranty;

    //Constructor
    Electronics(int price, int warranty) : Product(price), warranty(warranty)
    {
        cout << "Electronics constructor called.." << endl;
    }    

    //Destructor
    ~Electronics()
    {
        cout << "Electronics destructor called.." << endl;
    } 

    void powerOn()
    {
        cout << "The electronic device with a " << warranty 
        << " year warranty is now powered on" << endl;
    }
};

int main()
{
    //static object 
    Product prod1(500);
    Electronics elc1(1000, 4);

    prod1.displayInfo();
    elc1.displayInfo();
    elc1.powerOn();

    //Dynamic object
    Product* prod2 = new Product(1000);
    Electronics* elc2 = new Electronics(200, 1);
    
    prod2->displayInfo();
    elc2->displayInfo();
    elc2->powerOn();

    delete prod2;
    delete elc2;

    return 0;
}