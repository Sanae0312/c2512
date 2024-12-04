#include <iostream>
#include <cstdlib>

using namespace std:

class Fraction
{
	private:
		int numerator;
		int denominator;
	public:
		Fraction(int n_numerator, int d_denominator)
		{
			numerator = n_numerator;
			denominator = d_denominator;
		}
		
		void add(const Fraction& other);
		void display();
};

void add(const Fraction& other)
{
	int new_num, new_den;
	new_num = ((numerator * other.denominator) + (other.numerator * denominator));
	new_den = (denominator * other.denominator);
}


