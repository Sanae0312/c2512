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
