#include <iostream>
#include <cstdlib>

using namespace std;

int gcd(int a, int b)
{
	while(b != 0)
	{
		int temp = b;
		b = a % b;
		a = temp;
	}
	return a;
}

class Fraction
{
	private:
		int numerator;
		int denominator;
	public:
		Fraction(int numerator, int denominator) : numerator(numerator), denominator(denominator) { }

        friend ostream& operator<<(ostream output, const Fraction& fraction);
        Fraction operator+(const Fraction& other)
        {
            Fraction result(0,1);
            result.numerator = (this->numerator * other.denominator) + (this->denominator * other.numerator);
            result.denominator = this->denominator * other.denominator;
            return result;
        }

		bool operator<(const Fraction& other) 
        {
            return ((float)this->numerator / (float)this->denominator) < ((float)other.numerator / (float)other.denominator);
        }
};

ostream& operator<<(ostream& output, const Fraction& fraction) 
{ 
    output << fraction.numerator << "/" << fraction.denominator;
    return output;
}

Fraction add(const Fraction& other)
{
	int new_num, new_den;
	new_num = ((numerator * other.denominator) + (other.numerator * denominator));
	new_den = (denominator * other.denominator);
	simplify(int new_num, int new_den);
}

void simplify()
{
	divisor = int gcd();
	new_num = new_num / divisor;
	new_den = new_den / divisor;

	return fraction(new_num,new_den);
}

void display()
{
	cout << new_num << "/" << new_den;
}

int main()
{
	Fraction f1(1,2);
	Fraction f2(2,3);

	Fraction result = f1.add(f2);
	cout << "Sum of 2 fractions: "; 
       	result.display();

	return EXIT_SUCCESS;
}


