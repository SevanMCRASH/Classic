#include <string>
#include "Date.h"
using namespace std;


//IMPLEMENTATION OF DATE CLASS
Date::Date() {
	setDate(1, 1, 2007);
}

Date::Date(int day, int month, int year) {
	setDate(day, month, year);
}

void Date::setDate(int dy, int mth, int yr) {
	month = mth;
	day = dy;
	year = yr;
}
void Date::dateIncrease()
{
	if (getMonth() == 2 )
	{
		if (getDay() == 28)
		{
			day = 1;
			month = getMonth() + 1;
		}
	}
	else if (getMonth() == 1 || getMonth() == 3 || getMonth() == 5 || getMonth() == 7 || getMonth() == 8 || getMonth() == 10 || getMonth() == 12)
	{
		if (getDay() == 31)
		{
			if (getMonth() == 12)
			{
				day = 1;
				month = 1;
				year = getYear() + 1;
			}
			else
			{
				day = 1;
				month = getMonth() + 1;
			}
		}

	}
	else if (getMonth() == 4 || getMonth() == 6 || getMonth() == 9 || getMonth() == 11)
	{
		if (getDay() == 30)
		{
			day = 1;
			month = getMonth() + 1;
		}

	}
	else
	{
		day = getDay() + 1;
	}
	//january - 31
	//febuvary - 28
	//march - 31
	//april - 30
	//may - 31
	//june 30
	//july 31
	//august 31
	//september 30
	//october 31
	//novemebr 30
	//decamber 31
}
int Date::getMonth() {
	return month;
}

int Date::getDay() {
	return day;
}

int Date::getYear() {
	return year;
}
