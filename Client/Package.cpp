#include <iostream>
using namespace std;
#include "Package.h"

Package::Package(const string name_, const string name2,const string Address_, const string Address2, const string City_,
				 const string City2, const string State_, const string State2, const string Zip_, const string Zip2,
	             int Weight_, int cost_)//constructor initlizing the string/doubles in the sets
{
	//calling all the sets and inintlizing them by sending in the address of the string in the main
	//and saying "setname = name_ " basically accessing the setfuntion
	setName(name_);
	setRName(name2);
	setAddress(Address_);
	setRAddress(Address2);
	setCity(City_);
	setRCity(City2);
	setState(State_);
	setRState(State2);
	setZipCode(Zip_);
	setRZipCode(Zip2);
	setWeight(Weight_);
	setCost(cost_);
}
void Package::setName(const string name_)
{
	senderName = name_;
}
void Package::setRName(const string name2)
{
	reciverName = name2;
}
void Package::setAddress(const string Address_)
{
	senderAddress = Address_;
}
void Package::setRAddress(const string Address2)
{
	reciverAddress = Address2;
}
void Package::setCity(const string City_)
{
	senderCity = City_;
}
void Package::setRCity(const string City2)
{
	reciverCity = City2;
}
void Package::setState(const string State_)
{
	senderState = State_;
}
void Package::setRState(const string State2)
{
	reciverState = State2;
}
void Package::setZipCode(const string Zip_)
{
	senderZip = Zip_;
}
void Package::setRZipCode(const string Zip2)
{
	reciverZip = Zip2;
}
void Package::setWeight(int weight_)
{
	senderWeight = weight_;
}
void Package::setCost(int cost_)
{
	senderCost = cost_;
}
string Package::getName() const
{
	return senderName;
}
string Package::getRName() const
{
	return reciverName;
}
string Package::getAddress() const
{
	return senderAddress;
}
string Package::getRAddress() const
{
	return reciverAddress;
}
string Package::getCity() const
{
	return senderCity;
}
string Package::getRCity() const
{
	return reciverCity;
}
string Package::getState() const
{
	return senderState;
}
string Package::getRState() const
{
	return reciverState;
}
string Package::getZipCode() const
{
	return senderZip;
}
string Package::getRZipCode() const
{
	return reciverZip;
}
int Package::getWeight() const
{
	return senderWeight;
}
int Package::getCost() const
{
	return senderCost;
}
int Package::costPackage() const
{
	return  senderWeight * senderCost;
}