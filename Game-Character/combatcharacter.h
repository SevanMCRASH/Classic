#ifndef COMBATCHARACTER_H
#define COMBATCHARACTER_H
using namespace std;
#include"character.h"

class combatcharacter : public character
{
private:
	string wname;
	string sname;
	double wstrenght;
	double sstrenght;

public:
	combatcharacter(string, string, string, double, int);//if any time you don't have hard code for values use get fucntions
	void setWeapondName(string);
	void setSheildName(string);

	string getShieldName();
	string getWeaponName();
	double getWeaponStrenght();
	double getShieldStrenght();

	void useWeapon();//a
	void getAttacked();//default
	void saveAnotherCharacter();//b
	void reloadWeapon();//c
	bool noHealth();//checker 
	void displayAttributes();
};
#endif


