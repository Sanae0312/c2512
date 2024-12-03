#include <iostream>
#include <cstdlib>
#include <string>

using std::cout;
using std::endl;
using std::string;

class HospitalStay
{
	private:
		string StayID;
		int NumberOfDays;
	public:
		HospitalStay(string p_StayID, int p_NumberOfDays);
		friend class Comparisons;
};

class Comparisons
{
	public:
		static bool LessThan(const HospitalStay& first, const HospitalStay& second);
};

int main()
{
	HospitalStay hs1("HS001", 5);
	HospitalStay hs2("HS002", 7);

	cout << std::boolalpha;
	cout << "LessThan: " << Comparisons::LessThan(hs1,hs2) << endl;

	return EXIT_SUCCESS;
}


bool Comparisons::LessThan(const HospitalStay& first, const HospitalStay& second)
{
	return (first.NumberOfDays < second.NumberOfDays);
}

HospitalStay::HospitalStay(string p_StayID, int p_NumberOfDays)
{
	StayID = p_StayID;
	NumberOfDays = p_NumberOfDays;
}

