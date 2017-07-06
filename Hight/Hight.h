#ifndef HIGHT_H
#define HIGHT_H
#include <iostream>
using std::ostream;
using std::istream;

class Myhight
{
	friend ostream &operator<<(ostream&, const Myhight&);
	friend istream &operator>>(istream&, Myhight&);
private:
	double feet;
	double inch;
	double total;

public:
	Myhight();//defaul.neccassary if nothing is going in
	Myhight(double, double);//overloaded.if something is going in
	void setFeet(double);
	void setInch(double);
	void setDecimal(double,double);
	double getFeet()const;
	double getInch()const;
	double getDecimal()const;
    Myhight operator+(const Myhight&);
	Myhight operator-(const Myhight&);
	bool operator==(const Myhight&);
	bool operator!=(const Myhight&);
	bool operator<(const Myhight&);
	bool operator>(const Myhight&);
};
#endif