#include <iostream>
#include <iomanip>
#include "Integerset.h"

using namespace std;

int main()
{
	int user1[] = { 1,1,0,1,0,0,1,1,0,0 };//array of 10
	int user2[] = { 1,1,1,0,0,0,0,0 };//array of 8
	
	Integerset firstArr(user1, 10);//class calls user1 = array, and calls all the elemnts
	Integerset secondArr(user2, 5);// class calls user2 = array, but only calls 5 elemnts
	Integerset thirdArr(10);
	Integerset forthArr(8);
	Integerset fifthArr(user1, 10);

	firstArr.printBoard();//prints
	cout << " " << endl;
	secondArr.printBoard();//prints
	
	if (firstArr.isEqual(secondArr))//check to see if equal
	{
		cout << "is equal " << endl;
	}
	else
	{
		cout << " not equal " << endl;
	}

	if (firstArr.isEqual(thirdArr))//check to see if equal
	{
		cout << "is equal " << endl;
	}
	else
	{
		cout << " not equal " << endl;
	}

	Integerset *newset;// new pointer by class
	newset = thirdArr.UnionOfSets(forthArr);//stor address of "firstArr"that is calling "unionset" to compare and see if they are equal
	newset->printBoard();//basically this means newset.printboard(its calling print board)

	Integerset *secondset;// new pointer by class
	secondset = firstArr.IntersectionOfSets(thirdArr);//stor address of "firstArr"that is calling "Intersection" to compare and see if they are equal
	secondset->printBoard();//basically this means secondset.printboard(its calling print board)

	system("pause");
	return 0;
}