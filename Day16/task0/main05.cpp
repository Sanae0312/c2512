#include <iostream>
#include <cstdlib>
#include <string>

using std::string;
using std::cout;
using std::endl;

class HospitalStay
{
	private:
		string StayID;
		int NumberOfDays;
	public:
		bool LessThan(const HospitalStay& other);

		HospitalStay(string p_StayID, int p_NumberOfDays);
};

int main()
{
	HospitalStay stays[] = {HospitalStay("HS001", 5), HospitalStay("HS002", 7)};

	cout << std::boolalpha;
	cout << "LessThan: " << stays[0].LessThan(stays[1]) << endl;

	return EXIT_SUCCESS;
}

bool HospitalStay::LessThan(const HospitalStay& other)
{
	return (NumberOfDays < other.NumberOfDays);
}

HospitalStay::HospitalStay(string p_StayID, int p_NumberOfDays)
{
	StayID = p_StayID;
	NumberOfDays = p_NumberOfDays;
}


