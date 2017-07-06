#include <iostream>
#include <iomanip>
#include "character.h"
using namespace std;

character::character(const string name_, const double height_, const int weight_)
{
	name = name_;
	setHeight(height_);
	setWeight(weight_);
	health = 1.0;
	tendency = 0.0;
}

void character::setHeight(double height_)
{
	height = height_;
}

void character::setWeight(int weight_)
{
	weight = weight_;
}

string character::getName()const
{
	return name;
}

int character::getWeight()const
{
	return weight;
}

double character::getHeight()const
{
	return height;
}

double character::getTendency()const
{
	return tendency;
}

double character::getHealth()const
{
	return health;
}

void character::heal(double H_increase)
{
	health = getHealth() + H_increase;
	cout << "your health is now " << health * 100 << "%" << endl;
}

void character::injure(double H_decresse)
{
	health = getHealth() - H_decresse;
	cout << "your health is now " << health * 100 << "%" << endl;
}

void character::takeAction(double tendency_)
{
	tendency = getTendency() + tendency_;
	if (tendency > 1.0)
	{
		tendency = tendency - tendency_;
		cout << "your tendency can't go up more then " << tendency<< endl;
	}
	else if (tendency < -1.0)
	{
		tendency = tendency - tendency_;
		cout << "your tendency can't go lower then " << tendency<<endl;
	}
	else
	{
		cout << "your tendency is now " << tendency<< endl;
	}
}

void character::displayAttributes()
{
	cout << "Charcters name is " << getName() << endl
		<< "Charcters weight is " << getWeight() << endl;

	cout << setprecision(2) << fixed << "Charcters height is " << getHeight() << endl
		<< "Charcters tendency is " << getTendency() << endl
		<< "Charcters health is " << getHealth() * 100 << "%" << endl;
}