#include <iostream>
#include <iomanip>
#include "combatcharacter.h"
using namespace std;

combatcharacter::combatcharacter(string weaponname, string shieldname, string name_, double height_, int weight_) : character(name_, height_, weight_)
{
	wstrenght = 10;
	sstrenght = 10;
	setSheildName(shieldname);
	setWeapondName(weaponname);
}

void combatcharacter::setWeapondName(string name_)
{
	wname = name_;
}

void combatcharacter::setSheildName(string name_)
{
	sname = name_;
}

string combatcharacter::getShieldName()
{
	return sname;
}

string combatcharacter::getWeaponName()
{
	return wname;
}

double combatcharacter::getWeaponStrenght()
{
	return wstrenght;
}

double combatcharacter::getShieldStrenght()
{
	return sstrenght;
}

void combatcharacter::useWeapon()
{
	cout << "you used your weapon" << endl;
	if (wstrenght == 0 || character::getHealth() == 0)
	{
		cout << "sorry your either dead or your weapon has no more strenght" << endl;
	}
	else
	{
		character::injure(0.05);//decresse health by 5%
		wstrenght = getWeaponStrenght() - 1.0;
		cout << "your weapon strenght now is " << wstrenght << endl;
		character::takeAction(-0.2);
	}
}

void combatcharacter::getAttacked()
{
	cout << "you got attacked " << endl;
	if (sstrenght > 0)
	{
		sstrenght -= 1;
		cout << "your have now " << sstrenght << " shield" << endl;
	}
	else
	{
		character::injure(0.15);//decresse health by 15%
	}
}

void combatcharacter::saveAnotherCharacter()
{
	cout << "you saved your friend " << endl;
	if (character::getHealth() == 0)
	{
		cout << "sorry your dead " << endl;
	}
	else
	{
		character::takeAction(0.2);
		character::heal(0.05);//heal for %5
		sstrenght += 1;
		cout << "your have now " << sstrenght << " shield" << endl;
	}
}

void combatcharacter::reloadWeapon()
{
	cout << "you reloaded your weapon " << endl;
	if (character::getHealth() == 0)
	{
		cout << "sorry your dead " << endl;
	}
	else
	{
		sstrenght += 1;
		character::takeAction(-0.1);
	}
}

bool combatcharacter::noHealth()
{
	if (character::getHealth() <= 0)
	{
		return false;
	}
	else
	{
		return true;
	}
}

void combatcharacter::displayAttributes()
{
	cout << "Charcters name is " << character::getName() << endl
		<< "Charcters weight is " << character::getWeight() << endl
		<< "Charcters weapon name is " << getWeaponName() << endl
		<< "Charcters shield name is " << getShieldName() << endl;

	cout << setprecision(2) << fixed << "Charcters height is " << character::getHeight() << endl
		<< "Charcters tendency is " << character::getTendency() << endl
		<< "Charcters weapon strenght is " << getWeaponStrenght() << endl
		<< "Charcters shield strenght is " << getShieldStrenght() << endl
		<< "Charcters health is " << character::getHealth() * 100 << "%" << endl;
	if (character::getHealth() == 0)
	{
		cout << " the character is dead(unfortunately)." << endl;
	}
}

