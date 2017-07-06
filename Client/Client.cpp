//sevan mardiossian
//CSIS 137
#include <iostream>
#include <iomanip>
using namespace std;
#include "TwoDayPackage.h"
#include "Package.h"
#include "OvernightPackage.h"

int main()
{
	Package Pack1("Vane Vol", " ", "Palamica", " ", "Talinam"," ", "Kot", " ", "N/A"," ", 5, 7);
	TwoDayPackage Pack2(" ", "Valina Vol", " ", "brim", " ", "Vox", " ", "Lors", " ", "N/A", 5, 7, 9);//weight,cost,rushed fee
	OvernightPackage Pack3(" ", "Vanitus Vol", " ", "Foice", " ", "Talinam", " ", "Lon", " ", "N/A", 5, 7, 20);//weight,cost,overnight
	Package *Pack1ptr = &Pack1;
	

	cout << "Sender name is: " << Pack1ptr->getName() << endl
		<< "Address is: " << Pack1.getAddress() << endl
		<< "City is: " << Pack1.getCity() << endl
		<< "State is: " << Pack1.getState() << endl
		<< "Zip code is: " << Pack1.getZipCode() << endl
		<< "Weight: " << Pack1.getWeight() << endl
		<< "Cost per ounces " << Pack1.getCost() << endl
		<< "cost of the package: " << Pack1.costPackage() << endl
		<< "--------------------------------------------" << endl;
	//the second package is comenssing
	cout << "First name is: " << Pack2.getRName() << endl
		<< "Address is: " << Pack2.getRAddress() << endl
		<< "City is: " << Pack2.getRCity() << endl
		<< "State is: " << Pack2.getRState() << endl
	    << "Zip code is: " << Pack2.getRZipCode() << endl
	    << "The 2 day shipment is :"<< Pack2.getFee() <<endl
		<< "cost of the 2 day package: " << Pack2.returnPackage() << endl
		<< "--------------------------------------------" << endl;
	//the third package is comenssing
	cout << "First name is: " << Pack3.getRName() << endl
		<< "Address is: " << Pack3.getRAddress() << endl
		<< "City is: " << Pack3.getRCity() << endl
		<< "State is: " << Pack3.getRState() << endl
		<< "Zip code is: " << Pack3.getRZipCode() << endl
        << "The overnight price is :"<< Pack3.getNightFee() <<endl
		<< "cost of the overnight package: " << Pack3.nightPackage() << endl
		<< "--------------------------------------------" << endl;
	system("PAUSE");
	return 0;
}

