#include <iostream>
using namespace std;

int main()
{
	int* ptrId = new int {100};
	cout << "Address of dynamic memory= " << ptrId << endl;
	cout << "Value of dynamic memory= " << *ptrId << endl;

	delete ptrId;
	ptrId = nullptr;

	return 0;
}
