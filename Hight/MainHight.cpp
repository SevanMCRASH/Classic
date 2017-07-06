#include <iostream>
#include <iomanip>
#include "Hight.h"
using namespace std;

int main()
{
	double total;
	Myhight H1, H2(6,34);

	cout << "my height is " << H2 << "or " << setprecision(3)<<H2.getDecimal()<<" Decimal "<< endl;
	cout << "please enter your hight" << endl;
	cin >> H1; 
	cout << "your hight is " << H1 << endl;
	cout << "the total in decimal form is " << setprecision(3) <<H1.getDecimal() << endl;
	cout << "your hight plus my hight equals " << H1 + H2 << endl;
	cout << "Your hight minus my hight equals is " << H1 - H2 << endl;
	if (H1 == H2)
	{
		cout << "Our hights are equal" << endl;
	}
	else if (H1 != H2)
	{
		cout << "Our hights are not equal" << endl;
		if (H1 < H2)
		{
			cout << "Your hight is greater then my hight by " << H2 - H1 << endl;
		}
		else if (H1 > H2)
		{
			cout << "My hight is greater then your hight by " << H1 - H2 << endl;
		}
	}

	system("pause");
	return 0;
}