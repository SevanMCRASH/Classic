#ifndef Integer_H
#define Integer_H

class Integerset
{
private:
	int size;
	int *arr;
	void setSize(int);//makes void set size
	
public: 
	Integerset(int);//make an array in the run time(basically in the "heap")
	Integerset(int *array, int size);//creates a pointer array
	~Integerset();//destructor

	int getSize();//makes size resuable
	int *getArr();//makes *arr resuable
	void printBoard();//prints arrays
	bool isEqual(Integerset &set);//b/c you are passing another class you have to pass the address of the class name

	Integerset* UnionOfSets(Integerset &set);//becuse we equaled it to a pointer we need to make so that unionset is calling a pointer
	Integerset* IntersectionOfSets(Integerset &set);// same as unionset
	void InsertElement(int num);//addes values
	void DeleteElement(int num);//subtraces values

};
#endif // !
