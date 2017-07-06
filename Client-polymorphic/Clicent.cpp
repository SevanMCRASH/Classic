//Sevan Mardirossian
//CSIS 137
#include <iostream>
#include <iomanip>
using namespace std;


#include "TwoDayPackage.h"
#include "package.h"
#include "OvernightPackage.h"


int main()
{
	package package1(" Vane Vol ", " Guest ", " Palamica ", "UNKNOWEN ", " Talinam ", " UNKNOWN ", " Kot ", " UNKNOWN ", " N/A ", " N/A ", 5, 7);
	TwoDayPackage package2(" Vane Vol ", " Valina Vol ", " Palamica ", "brim ", " Talinam ", " Vox ", " Kot ", "Lors", " N/A ", "N/A", 5, 7, 9);
	OvernightPackage package3(" Vane Vol ", "Vanitus Vol", " Palamica ", "Foice", " Talinam ", "Talinam", " Kot ", "Lon", " ", "N/A", 5, 7, 20);


	package *package1ptr = nullptr;
	TwoDayPackage *package2ptr = nullptr;
	OvernightPackage *package3ptr = nullptr;
	package1.print();//basically inherating everything some how that you able to print them out instead of the old style
	cout << "--------------------------------------------" << endl;
	package2.print();
	cout << "--------------------------------------------" << endl;
	package3.print();


	package1ptr = &package1;//stroing address
	package1ptr->print();//print address
	cout << "--------------------------------------------" << endl;


	package2ptr = &package2;
	package2ptr->print();
	cout << "--------------------------------------------" << endl;

	package3ptr = &package3;
	package3ptr->print();

	system("PAUSE");
	return 0;
}
