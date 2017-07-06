#ifndef PACKAGE_H
#define PACKAGE_H
#include <string>
using namespace std;

class Package
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
	Package(const string , const string, const string, const string,
		const string, const string, const string, const string,
		const string, const string, int = 0, int = 0);//initializer with 2 default arguments

	void setName(const string);
	void setRName(const string);
	void setAddress(const string);
	void setRAddress(const string);
	void setCity(const string);
	void setRCity(const string);
	void setState(const string);
	void setRState(const string);
	void setZipCode(const string);
	void setRZipCode(const string);
	void setWeight(int);
	void setCost(int);

	string getName() const;
	string getRName() const;
	string getAddress() const;
	string getRAddress() const;
	string getCity() const;
	string getRCity() const;
	string getState() const;
	string getRState() const;
	string getZipCode() const;
	string getRZipCode() const;
	int getWeight() const;
	int getCost() const;
	int costPackage() const;
};
#endif
