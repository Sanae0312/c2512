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
		friend bool LessThan(const HospitalStay& first, const HospitalStay& second);
};

bool LessThan(const HospitalStay& first, const HospitalStay& second);

class Surgery
{
	private:
		string SurgeryID;
		int Duration;
	public:
		Surgery(string p_SurgeryID, int p_Duration);
		friend bool LessThan(const Surgery& first, const Surgery& second);
};

bool LessThan(const Surgery& first, const Surgery& second);

int main()
{
	HospitalStay hs1("HS001", 5);
	HospitalStay hs2("HS002", 7);

	Surgery s1("S001", 90);
	Surgery s2("S002", 120);

	cout << std::boolalpha;
	cout << "LessThan: " << LessThan(hs1,hs2) << endl;
	cout << "LessThan: " << LessThan(s1,s2) << endl;

	return EXIT_SUCCESS;
}


bool LessThan(const HospitalStay& first, const HospitalStay& second)
{
	return (first.NumberOfDays < second.NumberOfDays);
}

bool LessThan(const Surgery& first, const Surgery& second)
{
	return (first.Duration < second.Duration);
}

HospitalStay::HospitalStay(string p_StayID, int p_NumberOfDays)
{
	StayID = p_StayID;
	NumberOfDays = p_NumberOfDays;
}

Surgery::Surgery(string p_SurgeryID, int p_Duration)
{
	SurgeryID = p_SurgeryID;
	Duration = p_Duration;
}
