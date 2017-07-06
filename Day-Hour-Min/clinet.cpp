#include <iostream>
#include <iomanip>
#include "Date.h"
using namespace std;

int main()
{
	int day, month, year; 
	cout << "please enter the day, the month , and the year." << endl;
	cin >> day;
	cin >> month;
	cin >> year;
	if (day > 31 || month > 12)
	{
		cout << "please re-enter the day, month, and the year the days dont match with the months" << endl;
		cin >> day;
		cin >> month;
		cin >> year;
	}
	Date obj(day, month, year);
	obj.dateIncrease();
	cout << "The day is " << obj.getDay() << " month " << obj.getMonth() << " and year " << obj.getYear() << endl;

	system("pause");
	return 0;
}