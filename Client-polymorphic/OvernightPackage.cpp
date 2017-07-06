#include <iostream>
#include <string>
using namespace std;
#include "OvernightPackage.h"


OvernightPackage::OvernightPackage(const string name_, const string name2, const string Address_, const string Address2,
	const string City_, const string City2, const string State_, const string State2,
	const string Zip_, const string Zip2, int Weight_, int cost_, int night_) :package(name_, name2,
		Address_, Address2, City_, City2, State_, State2, Zip_, Zip2, Weight_, cost_)
{
	//calling all the sets and inintlizing them by sending in the address of the string in the main
	//and saying "setname = name_ " basically accessing the setfuntion
	setNightFee(night_);
}
void OvernightPackage::setNightFee(int nightFee_)
{
	flatFee = nightFee_;
}
int OvernightPackage::getNightFee() const
{
	return flatFee;
}
int OvernightPackage::nightPackage() const
{
	return (flatFee + package::getCost()) * package::getWeight();
}
void OvernightPackage::print() const
{
	cout << "Second name is: " << getCName() << endl
		<< "Address is: " << getCAddress() << endl
		<< "City is: " << getCCity() << endl
		<< "State is: " << getCState() << endl
		<< "Zip code is: " << getCZip() << endl
		<< "The overnight price is :" << getNightFee() << endl
		<< "cost of the overnight package: " << nightPackage() << endl;
}

