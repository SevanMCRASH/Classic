#ifndef TWODAYPACKAGE_H
#define TWODAYPACKAGE_H
#include <string>
#include "Package.h"
using namespace std;
class  TwoDayPackage : public Package 
{
private:
	int fee;
public:
	//(neccessay to bring the second class in inorder to be able to add everthing to the fee)
	//(also inorder to call packege cost need to call all the previous class and all its veriables)
	TwoDayPackage(const string, const string, const string, const string,
		const string, const string, const string, const string,
		const string, const string, int = 0, int = 0, int = 0);//initializer with 2 default arguments;//initliazing 2 defulats again/bring the addess of stirngs in

	void setFee(int);
	int getFee() const;
	int returnPackage() const;
};
#endif
