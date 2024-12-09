#include <iostream>

using namespace std;

class Complex
{
	private:
		int real; 
		int imag;
	public:
		Complex(int r, int i): real(r), imag(i) {}
		Complex(): real(0), imag(0) {}

		Complex operator +(const Complex& other)
		{
			return Complex(real + other.real, imag + other.imag);
		}

		friend ostream& operator <<(ostream& out, const Complex& other)
		{
			out << other.real << " + " << other.imag << " i" << endl;
			return out;
		}
};

int main()
{
	Complex c1(5,4);
	Complex c2(2,5);
	Complex c3;

	c3 = c1 + c2;

	cout << "c1: " << c1 << endl;
	cout << "c2: " << c2 << endl;
	cout << "c3: " << c3 << endl;


	return 0;
}

