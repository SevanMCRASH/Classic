//Sevan Mardirossian
//Deon Safiy
//Jean Claud (JC)
#ifndef BOARDE_H
#define BOARDE_H

class Boarde
{
private:
	int ROW;
	int COL;
	int **arr;

public:
	Boarde(int, int);
	~Boarde();
	void setRow(int);
	void setCol(int);

	int getRow();
	int getCol();

	void displayboard();
	bool placeQueen(int, int);
	bool checker(int, int);
	virtual void setQueen(int, int);
	//void fullboard(Queen &print);
};
#endif // !