#include <iostream>
#include <iomanip>
#include <cstdlib>

#include "surgery.h"

using std::cout;
using std::endl;
using std::string;

int main() {
	Surgery s1("S001" , 90);
	Surgery s2("S002" , 120);

	cout << std::boolalpha;
	cout << "Equals: " << s1.Equals(s2) << endl;
	cout << "NotEquals: " << s1.NotEquals(s2) << endl;
	cout << "GreaterThan: " << s1.GreaterThan(s2) << endl;
	cout << "GreaterThanEquals: " << s1.GreaterThanEquals(s2) << endl;
	cout << "LessThan: " << s1.LessThan(s2) << endl;
	cout << "LessThanEquals: " << s1.LessThanEquals(s2) << endl;

	return EXIT_SUCCESS;
}
