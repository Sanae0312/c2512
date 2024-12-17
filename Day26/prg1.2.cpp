#include <iostream>

using namespace std;

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
            cout << "Stack Overflow: Cannot push onto a full stack." << endl;
            return;
        }
        arr[_top] = data;
        _top++;
    }

    void pop()
    {
        if (_top <= 0)
        {
            cout << "Stack Underflow: Cannot pop from an empty stack." << endl;
            return;
        }
        _top--;
    }

    double top()
    {
        if (_top <= 0)
        {
            cout << "Stack Underflow: No elements in the stack." << endl;
            return -1; 
        }
        return arr[_top - 1];
    }
};

int main()
{
    C2512Stack<double> stack;

    stack.push(10.0);
    stack.push(12.0);
    stack.push(11.0);
    stack.push(13.0);

    cout << stack.top() << endl; // Output: 11.0
    stack.pop();

    cout << stack.top() << endl; // Output: 12.0
    stack.pop();

    cout << stack.top() << endl; // Output: 10.0
    stack.pop();

    // Error: Underflow
    cout << stack.top() << endl; 
    stack.pop();

    return 0;
}