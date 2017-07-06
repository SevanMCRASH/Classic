#include <iostream>
#include "Integerset.h"
using std::cout;
using std::endl;

void Integerset::setSize(int M_size)//sets the size to an int so its more resuable
{
	size = M_size;//This basically is creating an size of 0 = 0
}

Integerset::Integerset(int M_size)//creates the array, remmeber that "constructor" is getting the size of the array
{
	setSize(M_size);//makes size = M_size, which means the computer now knows what size equals too
	arr = new int[size];//created a array in the "heap"
	for (int i = 0; i < size; i++)
	{
		arr[i] = 0;// array of 0 has elemnts of 0 initlized to it stores value
	}
}

Integerset::Integerset(int *array, int M_size)//initialize the regulare array to a "pointer array"
{
	setSize(M_size);
	arr = new int[size];
	for (int i = 0; i < size; i++)
	{
		arr[i] = array[i];// pointer arrays easire to access remeber stroes address
	}
}

/*
1. Basically you are creating an arrays of 0 = 0 that can be recreated
2. Then you makes sure the to be able to access it again by returning it
*/

int Integerset::getSize()//makes the integer size resuable
{
	return size;
}

int * Integerset::getArr()//gets the address of the array that was input 
{
	return arr;
}

void Integerset::printBoard()
{
	for (int k = 0; k <= size; k++)//checks to see if it is less then the size of array
	{
		if (arr[k] == 0)// print 0 if elemnt is in array is "0"
		{
			cout << " array " << k +1 << " ----- " << endl;
		}
		else if (arr[k] == 1)//print 1 if emelent is in array is"1"
		{
			cout << " array " << k +1 << " is " << arr[k] << endl;
		}
	}
}

bool Integerset::isEqual(Integerset &set)//fucntion isEqual is calling class secondArr by address
{
	if (getSize() != set.getSize())//checks the size of array if they are same
	{
		return false;
	}
	for (int i = 0; i <= getSize(); i++)//checks to see if the elements are equal
	{
		if (arr[i] != set.getArr()[i])
		{
			return false;
		}
	}
	return true;//returns true if both are proven false
}

Integerset * Integerset::UnionOfSets(Integerset &set)// funtion that has taken the address of class-name and is trying to bring back a pointer
{
	int maxSize = getSize() > set.getSize() ? getSize() : set.getSize();//??
	Integerset *newset = new Integerset(maxSize);//??

	for (int i = 0; i < maxSize; i++)
	{
		for (int i = 0; i < maxSize; i++)
		{
			if (arr[i] == 1 || set.getArr()[i] == 1)//if either arrays are one it initilizes as one
			{
				newset->InsertElement(i);
			}
			else
			{
				newset->DeleteElement(i);
			}
		}
		return newset;
	}
}

Integerset * Integerset::IntersectionOfSets(Integerset &set)// funtion that has taken the address of class-name and is trying to bring back a pointer
{
	int maxSize = getSize() > set.getSize() ? getSize() : set.getSize();//??
	Integerset *secondset = new Integerset(maxSize);//??

	for (int i = 0; i < maxSize; i++)
		{
			if (arr[i] == 1 && set.getArr()[i] == 1)//if either arrays are one it initilizes as one
				{
					secondset->InsertElement(i);
				}
			else
				{
					secondset->DeleteElement(i);
				}
			}
		return secondset;
}

void Integerset::InsertElement(int num)
{
	if (num > size)
	{
		num = size;
	}
	else
	{
		arr[num] = 1;
	}
}



void Integerset::DeleteElement(int num)
{
	if (num > size)
	{
		num = size;
	}
	else
	{
		arr[num] = 0;
	}
}


Integerset::~Integerset()
{
	delete[] arr;
}
