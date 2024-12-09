/*
single inheritance with dynamic binding
=============================================================
one two dynamic/static objects of the Derived class 
pointed by base class pointer
and call all behaviours using Base class pointer 

Override Base Class behaviors to derived class.
Define constructors and destructors for all the classes 
Define all the fields as dynamic fields in each class 

If you use string, use c-string (don't use string class)
        ie. dynamic c-string [dynamic char array]

Example 3: `Account and SavingsAccount`
- `Base Class:` `Account`  
  - Fields: `accountNumber`, `balance`  
  - Pure Virtual Behaviors: `deposit()`, `withdraw()`  
- `Derived Class:` `SavingsAccount`  
  - Fields: `interestRate`  
*/

#include <iostream>
#include <cstring>

using namespace std;

//Base class:
class Account
{
    protected:
        char* accountNumber;
        double balance;

    public:
        //Constructor
        Account(const char* accnmbr, double blnc) 
        {
            accountNumber = new char[strlen(accnmbr) + 1];
            strcpy(accountNumber, accnmbr);
            balance = blnc;
            cout << "Account constructor called.." << endl;
        }

        //Destructor
        virtual ~Account()
        {
            cout << "Account destructor called.." << endl;
            delete[] accountNumber;
        }

        //Behaviour
        virtual void deposit(double amount) = 0;
        
        virtual void withdraw(double amount) = 0;
};

//Derived class
class SavingsAccount : public Account
{
    protected:
        double interestRate;

    public:
        //Constructor
         SavingsAccount(const char* accnmbr, double blnc, double rate)
        : Account(accnmbr, blnc), interestRate(rate) 
        {
            cout << "SavingsAccount constructor called.." << endl;
        }    

        //Destructor
        ~SavingsAccount()
        {
            cout << "SavingsAccount destructor called.." << endl;
        } 

        void deposit(double amount) override
        {
            balance = balance + amount;
            cout << "Deposited " << amount << 
            " to account " << accountNumber << ", balance is " << balance << endl;
        }

        void withdraw(double amount) override
        {
            if (balance >= amount)
            {
                balance = balance - amount;
                cout << "Withdrew " << amount << " from account "
                << accountNumber << ", balance is " << balance << endl;
            }
            else 
            {
                cout << "Insufficiant balance in account" << endl;
            }
        }
};

int main()
{
    Account* acc1 = new SavingsAccount("223432", 55000.55, 10);
    Account* acc2 = new SavingsAccount("143434", 22000, 5);

    cout << "=== Account 1 ===" << endl;
    acc1->deposit(500);
    acc1->withdraw(300);

    cout << "=== Account 2 ===" << endl;
    acc2->deposit(1000);
    acc2->withdraw(1500);

    delete acc1;
    delete acc2;

    return 0;
}