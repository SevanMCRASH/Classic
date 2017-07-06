//Sevan Mardirossian
//Deon Safiy
//Jean Claud (JC)
#include"Queen.h"
#include <iostream>
#include <vector>
using namespace std;

Queen::Queen(int row, int col):Boarde(row,col)//defualt constructor just to make it work
{	
}

void Queen::setQueen(int userrow, int usercol)
{
	Qrow.push_back(userrow +1);
	Qcol.push_back(usercol +1);
}

void Queen::positionOfQueen()
{
	cout << endl;
	cout << "Queen rows are: ";
	for (int num : Qrow)
	{
		 cout << num << " ";
	}
	cout << endl;
	cout << "Queen rows are: ";
	for (int num : Qcol)
	{
		cout<< num << " ";
	}
	cout << endl;
}





