#include <iomanip>
#include <iostream>
#include "Hight.h"
using namespace std;

Myhight::Myhight()//defult
{
	feet = 1.0;
	inch = 1.0;
	total = 1.0;
}
Myhight::Myhight(double feet_, double inch_)//initilizer
{
	setFeet(feet_);//initlizing //bascially calling set = sending value and initlizing it in there
	setInch(inch_);//initlizing//calling setfuntion
	setDecimal(feet_, inch_);//calling decimal funtion from initlizer
}
void Myhight::setFeet(double feet_)//create feet
{
    if (feet_< 0)
	{
		cout << "invalid choice" << endl;
		feet = 0;
	}
	feet = feet_;
	this->feet = feet;
}
void Myhight::setInch(double inch_)//creat inch
{		
	while (inch_ >= 12)
	{
		inch_ -= 12;
		++feet;
	}
	if (inch_< 0)
	{
		cout << "invalid choice" << endl;
		inch = 0;
	}
	inch = inch_;
	this->inch = inch;
}
void Myhight::setDecimal(double feet_,double inch_)//creat decimal total
{
	total = feet_ + inch_ / 12;
	this->total = total;
}
double Myhight::getDecimal()const
{
	return total;
}
double Myhight::getFeet()const
{
	return feet;
}
double Myhight::getInch()const
{
	return inch;
}
ostream &operator<<(ostream& out, const Myhight& Newhight)//output
{
	out << Newhight.getFeet()<< " feet and " << Newhight.getInch()<< " inch"<< endl;
	return out;
}
istream &operator>>(istream& in, Myhight& Newhight)//input
{
	in >> Newhight.feet>> Newhight.inch;
	Newhight.total = Newhight.feet + Newhight.inch / 12;
	while (Newhight.inch >= 12)
	{
		Newhight.inch -= 12;
		++Newhight.feet;
	}
	if (Newhight.inch < 0)
	{
		cout << "invalid choice" << endl;
		Newhight.inch = 0;
	}
	else if (Newhight.feet < 0)
	{
		cout << "invalid choice" << endl;
		Newhight.feet = 0;
	}
	return in;
}
Myhight Myhight::operator+(const Myhight&H2)//opertaor only allows one address to passed for now
{
	Myhight H3;
	H3.feet = feet + H2.feet;//for now this makes sense becuase this->H1 and H2 is the second hight
	H3.inch =  inch + H2.inch;//same idea for now this->inch works b/c it is pointing at h1
	return H3;
}
Myhight Myhight::operator-(const Myhight&H2)//opertaor only allows one address to passed for now
{
	Myhight H1;
	H1.feet = this->feet - H2.feet;//for now this makes sense becuase this->H1 and H2 is the second hight
	H1.inch = this->inch - H2.inch;//same idea for now this->inch works b/c it is pointing at h1
	if (H1.feet < 0)
	{
		cout << "value for feet dosent exist b/c it is lower then negative" << endl;
		H1.feet = 0;
	}
	else if (H1.inch < 0)
	{
		cout << "value feo inch dosent exist b/c it is lower then negative" << endl;
		H1.inch = 0;
	}
	return H1;
}
bool Myhight::operator==(const Myhight&H2)
{
	Myhight H1;
	H1.feet = this->feet;
	H1.inch = this->inch;
	if (H1.feet == H2.feet && H1.inch == H2.inch)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool Myhight::operator!=(const Myhight&H2)
{
	Myhight H1;
	H1.feet = this->feet;
	H1.inch = this->inch;
	if (H1.feet != H2.feet || H1.inch != H2.inch)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool Myhight::operator<(const Myhight&H2)
{
	Myhight H1;
	H1.feet = this->feet;
	H1.inch = this->inch;
	if (H1.feet < H2.feet && H1.inch < H2.inch)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool Myhight::operator>(const Myhight&H2)
{
	Myhight H1;
	H1.feet = this->feet;
	H1.inch = this->inch;
	if (H1.feet > H2.feet && H1.inch > H2.inch)
	{
		return true;
	}
	else
	{
		return false;
	}
}