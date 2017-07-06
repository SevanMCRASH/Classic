//Sevan Mardirossian
//Deon Safiy
//Jean Claud (JC)
#include <iostream>
#include <iomanip>
#include "Boarde.h"
#include "Queen.h"
using namespace std;

int main()
{
	bool flag = true;
	int rowinput, colinput;
	const int maxrow = 8;
	const int maxcol = 8;
	Boarde obj(maxrow, maxcol);
	Queen obj2(maxrow, maxcol);
	Queen *ptr = &obj2;
	while (true)
	{
		do {
			obj.displayboard();
			cout << "Please choose row:" << endl;
			cin >> rowinput;
			cout << "Please choose colume:" << endl;
			cin >> colinput;
			flag = obj.placeQueen(rowinput - 1, colinput - 1);
			if (flag == true)
			{
				ptr->setQueen(rowinput - 1, colinput - 1);
			}
			ptr->positionOfQueen();
		} while (flag == false);
	}
	system("pause");
	return 0;
}