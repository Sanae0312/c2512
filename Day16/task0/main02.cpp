#include <iostream>
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
		HospitalStay(string p_StayID, int p_NumberOfDays);
		friend bool LessThan(const HospitalStay& first, HospitalStay& second);
};

bool LessThan(const HospitalStay& first, HospitalStay& second);

int main() 
{
	HospitalStay hs1("HS001", 5);
	HospitalStay hs2("HS002", 7);

	cout << std::boolalpha;
	cout << "LessThan: " << LessThan(hs1,hs2) << endl;

	return EXIT_SUCCESS;
}

bool LessThan(const HospitalStay& first, HospitalStay& second)
{
	return (first.NumberOfDays < second.NumberOfDays);
}

HospitalStay::HospitalStay(string p_StayID, int p_NumberOfDays)
{
	StayID = p_StayID;
	NumberOfDays = p_NumberOfDays;
}
