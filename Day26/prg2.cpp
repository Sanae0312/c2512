#include <iostream>
#include <stdexcept>

using namespace std;

class StackOverflowException : public exception
{
    public:
        const char* what() const noexcept override 
        {
            return "Stack Overflow: Cannot push onto a full stack.";
        }
};

class StackUnderflowException : public exception
{
    public:
        const char* what() const noexcept override 
        {
            return "Stack Underflow: Cannot pop or access  from an empty stack.";
        }
};

template<class T>
class C2512Stack 
{
private:
    static const int _size = 3; 
    T arr[_size];           
    int _top;                    

public:
    // Constructor 
    C2512Stack() : _top(0) {}

    void push(T data)
    {
        if (_top >= _size)
        {
            throw StackOverflowException();
        }
        arr[_top] = data;
        _top++;
    }
    
    void pop()
    {
        if (_top <= 0)
        {
            throw StackUnderflowException();
        }
        _top--;
    }

    double top()
    {
        if (_top <= 0)
        {
            throw StackUnderflowException();
        }
        return arr[_top - 1];
    }
};

int main()
{
    try
    {
        C2512Stack<double> stack;
    
        stack.push(10.0);
        stack.push(12.0);
        stack.push(11.0);
        //stack.push(13.0);
    
        cout << stack.top() << endl; // Output: 11.0
        stack.pop();
    
        cout << stack.top() << endl; // Output: 12.0
        stack.pop();
    
        cout << stack.top() << endl; // Output: 10.0
        stack.pop();
    
        // Error: Underflow
        cout << stack.top() << endl; 
        stack.pop();
    }
    catch (const exception& ex) 
    {
        cout << "Error: " << ex.what() << endl;
    
    }
    
        return 0;
}
