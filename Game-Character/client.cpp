//Sevan Mardirossian
//JEANCLAUDE HASROUTY
//DEON SEYFI	

#include <iostream>
#include <string>
#include <iomanip>
#include "character.h"
#include "combatcharacter.h"
using namespace std;

int main()
{
	string choice;
	string name, weaponname = "Washeda", shieldname = "Gladio";
	double height;
	int weight;
	cout << "please choose your name" << endl;
	getline(cin, name);
	cout << "please choose your height" << endl;
	cin >> height;
	while (cin.fail()) 
	{
		cout << "Error" << std::endl;
		cin.clear();//clears your cin
		cin.ignore(256, '\n');//ignores 256 inputs
		cout << "please choose your height again" << endl;
		cin >> height;
	}
	cout << "please choose your weight" << endl;
	cin >> weight;
	while (cin.fail())
	{
		cout << "Error" << std::endl;
		cin.clear();//clears you cin
		cin.ignore(256, '\n');//ignore 256 inputs
		cout << "please choose your weight again" << endl;
		cin >> weight;
	}

	character state(name, height, weight);
	combatcharacter state2(weaponname, shieldname, name, height, weight);
	character *ptrstate = &state;
	combatcharacter *ptrstate2 = &state2;

	do
	{
		cout << "Now lets begin the fight" << endl
			<< "This is your states " << endl
			<< "choose a) to use the weapon" << endl
			<< "choose b) to save your comrade" << endl
			<< "choose c) to reload your weapon" << endl;
		ptrstate->displayAttributes();
		cout << "--------------------------------" << endl;
		ptrstate2->displayAttributes();

		cout << "Please make a choice. " << endl;
		cin >> choice;
		while (choice != "a" && choice != "b" && choice != "c")
		{
			cout << "Please make a choice. again" << endl;
			cin >> choice;
		}

		if (choice == "a")
		{
			cout << "You have chosen to use your weapon." << endl;
			ptrstate2->useWeapon();
		}
		else if (choice == "b")
		{
			cout << "You have chosen to save another guy." << endl;
			ptrstate2->saveAnotherCharacter();
		}
		else if (choice == "c")
		{
			cout << "You have chosen to reload your weapon." << endl;
			ptrstate2->reloadWeapon();
		}

		if (ptrstate2->noHealth() == true)
		{
			cout << "OH NOOO, you have been attacked." << endl;
			ptrstate2->getAttacked();
		}
	} while (ptrstate2->noHealth()== true);
	system("pause");
	return 0;
}