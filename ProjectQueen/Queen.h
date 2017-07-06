//Sevan Mardirossian
//Deon Safiy
//Jean Claud (JC)
#ifndef QUEEN_H
#define QUEEN_H
#include "Boarde.h"
#include <vector>
using namespace std;
class Queen: public Boarde
{
private:
	vector<int> Qrow;
	vector<int> Qcol;

public:
	Queen(int, int);

	void setQueen(int, int);
	void positionOfQueen();
};
#endif