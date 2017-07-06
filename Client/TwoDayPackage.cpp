#include <iostream>
using namespace std;
#include "TwoDayPackage.h"

TwoDayPackage::TwoDayPackage(const string name_, const string name2, const string Address_, const string Address2, const string City_,
	const string City2, const string State_, const string State2, const string Zip_, const string Zip2,
	int Weight_, int cost_, int fee_): Package(name_, name2, Address_, Address2, City_, City2, State_,
		State2, Zip_, Zip2, Weight_, cost_)
	//calls the prevouise class first then calls all the objacts
{
	setFee(fee_);
}
void TwoDayPackage::setFee(int fee_)
{
	fee = fee_;
}
int TwoDayPackage::getFee() const
{
	return fee;
}
int  TwoDayPackage::returnPackage() const//calls the cost package from packega so it can add it to the fee
{
	return fee + (Package::costPackage());//needs to be modified
}
