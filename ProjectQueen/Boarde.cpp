//Sevan Mardirossian
//Deon Safiy
//Jean Claud (JC)
#include "Boarde.h"
#include <iomanip>
#include <iostream>
using namespace std;


Boarde::Boarde(int row, int col)
{
	setCol(col);
	setRow(row);
	arr = new int*[row];
	for (int i = 0; i < row; i++)
	{
		arr[i] = new int[col];
	}
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			arr[i][j] = 0;
		}
	}
}

void Boarde::setCol(int col)
{
	COL = col;
}

void Boarde::setRow(int row)
{
	ROW = row;
}

int Boarde::getRow()
{
	return ROW;
}

int Boarde::getCol()
{
	return COL;
}

void Boarde::displayboard()
{
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			cout << setw(2) <<arr[i][j] << " ";
		}
		cout << endl;
	}
}

bool Boarde::placeQueen(int userrow, int usercol)
{
	if (checker(userrow, usercol) == false)
	{
		cout << "Please make a diffrent input." << endl;
		return false;
	}
	else
	{
		arr[userrow][usercol] = 1;
		setQueen(userrow, usercol);
		cout << "Queen has been placed";
		return true;
	}
}
//checks every single condition possible 
bool Boarde::checker(int row, int col)
{
		for (int i = 0; i < col; i++)
		{
			if (arr[row][i] == true)//check incremnt colume
			{
				return false;
			}
		}
		for (int i = col; i >= 0; i--)//check decrment colume
		{
			if (arr[row][i] == true)
			{
				return false;
			}
		}
		for (int i = 0; i < row; i++)
		{
			if (arr[i][col] == true)//check incremnt row
			{
				return false;
			}
		}
		for (int i = row; i >= 0; i--)
		{
			if (arr[i][col] == true)//check decremnt row
			{
				return false;
			}
		}
		for (int i = row, j = col; i < getRow() && j < getCol(); i++, j++)//check digonal 
		{
			if (arr[i][j] == true)//
			{
				return false;
			}
		}
		for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)//check digonal 
		{
			if (arr[i][j] == true)//
			{
				return false;
			}
		}
		for (int i = row, j = col; i < getRow() && j >= 0; i++, j--)//check digonal  
		{
			if (arr[i][j] == true)//
			{
				return false;
			}
		}
		for (int i = row, j = col; i >= 0 && j < getCol(); i--, j++)//check digonal 
		{
			if (arr[i][j] == true)//
			{
				return false;
			}
		}
		return true;
}

Boarde::~Boarde()
{
	for (int i = 0; i<getRow(); i++)
	{
		delete[] this->arr[i]; //this part was allocated with new[], so use delete[]
	}
	delete[]arr;
}

void Boarde::setQueen(int userrow, int usercol)
{
}




/*
check horizontally for 1 if fail return flag
check vertically for 1 if fail return a flag
check diagonaly for 1 if fail return a flag
 diagonal[i + 1][ j + 1]

*/






