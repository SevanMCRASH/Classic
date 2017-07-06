#ifndef PACKAGE_H
#define PACKAGE_H
#include <string>
using namespace std;


class package
{
private:
	string senderName;//1
	string senderAddress;//2
	string senderCity;//3
	string senderState;//4
	string senderZip;//5
	int senderWeight;//6
	int senderCost;//7
	string reciverName;//8
	string reciverAddress;//9
	string reciverCity;//10
	string reciverState;//11
	string reciverZip;//12
public:
	package(const string, const string, const string, const string,
		const string, const string, const string, const string,
		const string, const string, int = 0, int = 0);//initializer with 2 default arguments


	void setName(const string);
	void setCName(const string);
	void setAddress(const string);
	void setCAddress(const string);
	void setCity(const string);
	void setCCity(const string);
	void setState(const string);
	void setCState(const string);
	void setZip(const string);
	void setCZip(const string);
	void setWeight(int);
	void setCost(int);


	string getName() const;
	string getCName() const;
	string getAddress() const;
	string getCAddress() const;
	string getCity() const;
	string getCCity() const;
	string getState() const;
	string getCState() const;
	string getZip() const;
	string getCZip() const;
	int getWeight() const;
	int getCost() const;
	virtual int costPackage() const;
	virtual void print()const;
};
#endif
