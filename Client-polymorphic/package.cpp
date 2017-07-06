#include <iostream>
using namespace std;
#include "package.h"


package::package(const string name_, const string name2, const string Address_, const string Address2, const string City_,
	const string City2, const string State_, const string State2, const string Zip_, const string Zip2,
	int Weight_, int cost_)//constructor initlizing the string/doubles in the sets
{
	//calling all the sets and inintlizing them by sending in the address of the string in the main
	//and saying "setname = name_ " basically accessing the setfuntion
	setName(name_);
	setCName(name2);
	setAddress(Address_);
	setCAddress(Address2);
	setCity(City_);
	setCCity(City2);
	setState(State_);
	setCState(State2);
	setZip(Zip_);
	setCZip(Zip2);
	setWeight(Weight_);
	setCost(cost_);
}
void package::setName(const string name_)
{
	senderName = name_;
}
void package::setCName(const string name2)
{
	reciverName = name2;
}
void package::setAddress(const string Address_)
{
	senderAddress = Address_;
}
void package::setCAddress(const string Address2)
{
	reciverAddress = Address2;
}
void package::setCity(const string City_)
{
	senderCity = City_;
}
void package::setCCity(const string City2)
{
	reciverCity = City2;
}
void package::setState(const string State_)
{
	senderState = State_;
}
void package::setCState(const string State2)
{
	reciverState = State2;
}
void package::setZip(const string Zip_)
{
	senderZip = Zip_;
}
void package::setCZip(const string Zip2)
{
	reciverZip = Zip2;
}
void package::setWeight(int weight_)
{
	senderWeight = weight_;
}
void package::setCost(int cost_)
{
	senderCost = cost_;
}
string package::getName() const
{
	return senderName;
}
string package::getCName() const
{
	return reciverName;
}
string package::getAddress() const
{
	return senderAddress;
}
string package::getCAddress() const
{
	return reciverAddress;
}
string package::getCity() const
{
	return senderCity;
}
string package::getCCity() const
{
	return reciverCity;
}
string package::getState() const
{
	return senderState;
}
string package::getCState() const
{
	return reciverState;
}
string package::getZip() const
{
	return senderZip;
}
string package::getCZip() const
{
	return reciverZip;
}
int package::getWeight() const
{
	return senderWeight;
}
int package::getCost() const
{
	return senderCost;
}
int package::costPackage() const
{
	return  senderWeight * senderCost;
}
void package::print()const
{
	cout << "Sender name is: " << getName() << endl
		<< "Address is: " << getAddress() << endl
		<< "City is: " << getCity() << endl
		<< "State is: " << getState() << endl
		<< "Zip code is: " << getZip() << endl
		<< "Weight: " << getWeight() << endl
		<< "Cost per ounces " << getCost() << endl
		<< "cost of the package: " << costPackage() << endl;
}
