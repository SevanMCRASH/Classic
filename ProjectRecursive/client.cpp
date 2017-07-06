//sevan Mardirossian
//Deon Seyfi
//Jean Claude
//lab 1 CSIS 211
#include <iostream>
#include <vector>
#include <string>
using namespace std;

template <class T, class U, class V, class W >
class Quduplcalulater
{
public:
	void binarySearch(T arr[], U lower, V upper, W target);//int,string,double
};

template <class T, class U, class V >
class Multipalcalulater
{
public:
	void maxarray(T arr[], U target, V size);//int,string,double
};

class caluclater
{
public:
	int recursivePower(int, int);
	int reverseDigits(int, int);
};

int main()
{
	caluclater obj;
	Multipalcalulater <int, int, int> obj1;
	Multipalcalulater <double, double, int> obj2;
	Multipalcalulater <char, char, int> obj3;
	Quduplcalulater <int, int, int, int> primary;
	Quduplcalulater <char, int, int, char> secondary;
	Quduplcalulater <double, int, int, double> third;
	int number,power;
	int num = 12345;
	int num2 = 0;
	int arr[] = { 1,2,8,4,7,6 };
	char arr2[] = { 'p','e', 'r','s','o','n'};
	double arr3[] = { 5.0, 4.0};
	cout << "Bring out the maxarray from an integer" << endl;
	obj1.maxarray(arr, 6, 6);
	cout << "Bring out the maxarray from an string" << endl;
	obj3.maxarray(arr2,'p', 3);
	cout << "Bring out the maxarray from an double" << endl;
	obj2.maxarray(arr3,5.0,1);
	cout << "searching from an integer" << endl;
	primary.binarySearch(arr, 0, 6, 8);
	cout << "searching from an string" << endl;
	secondary.binarySearch(arr2, 0, 6, 'e');
	cout << "searching from an double" << endl;
	third.binarySearch(arr3, 0, 2, 4.0);
	cout << "please enter the number and then the power" << endl;
	cin >> number >> power;
	while (number < 0 && power < 0)
	{
		cout << "please enter the number and then the power again"<<endl;
		cin >> number >> power;
	}

	int total = obj.recursivePower(number, power);
	cout << "the total is " << total << endl;

	cout << obj.reverseDigits(num,num2) << endl; 

	system("pause");
	return 0;
}


int caluclater::recursivePower(int n, int p)//int
{
	if (p == 0)
	{
		return 1;
	}
	else
	{
		return n*(recursivePower(n, p - 1));
	}

}

template <class T, class U, class V >
void Multipalcalulater<T,U,V>::maxarray(T arr[], U target, V size)//int,string,double
{
	if (size >= 0)
	{
		if (target < arr[size])
		{
			target = arr[size];
		}
	  maxarray(arr,target, size-1);
	}
	else
	{
		cout << "The max value is " << (int)target << endl;
	}
}

template <class T, class U, class V, class W >
void Quduplcalulater<T,U,V,W>::binarySearch(T arr[], U lower, V upper, W target)//int,string,double
{
	if (lower > upper)
	{
		cout << "not in the original array "<< endl;
	}
	else
	{
		if (target == arr[lower])
		{
			cout << "the position of the element is " << lower + 1 << endl;
		}
		else
		{
			binarySearch(arr, lower + 1, upper, target);
		}
	}
	/*else
	{
		int mid = lower + (upper - lower) / 2;
		if (target == arr[mid])
		{
			cout << "the position of the element is " << mid+1 << endl;
		}
		else if(target < arr[mid])
		{
			binarySearch(arr, lower, mid - 1, target);
		}
		else
		{
			binarySearch(arr, mid + 1, upper, target);
		}

	}*/
}

int caluclater::reverseDigits(int num, int num2)//int
{

	if (num == 0)
	{
		return num2;
	}
	else
	{
		num2 = num2 * 10 + (num % 10);
		num = num / 10;
		reverseDigits(num,num2);
	}
		
}