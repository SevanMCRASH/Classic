#ifndef CHARACTER_H
#define CHARACTER_H
using namespace std;
#include<string>


class character
{
private:
	string name;
	double height;
	int weight;
	double tendency;// from -1.0 to 1.0
	double health;//rememeber must diplay percentage 0.0-1.0

public:
	character(const string, const double, const int);
	void setHeight(double);
	void setWeight(int);

	string getName()const;
	int getWeight()const;
	double getHeight()const;
	double getTendency()const;
	double getHealth()const;

	void heal(double);
	void injure(double);
	void takeAction(double);
	virtual void displayAttributes();

};
#endif
