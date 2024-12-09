#include <iostream>
using namespace std;

int main()
{
	int ids[4] = {100,200,300,400};

	cout << "using element iterator" << endl;
	for ( auto e : ids)
	{
		cout << "Elements: " << e << endl;
	}

	cout << "ids= " << ids << endl;
	cout << "ids[0]= " << &ids[0] << endl;
	cout << "address= " << ((int*)(&ids+1))-1 << endl;
	cout << "address= " << ((int*)(ids+1))-1 << endl;

	return 0;
}
