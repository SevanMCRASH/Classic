#ifndef TWODAYPACKAGE_H
#define TWODAYPACKAGE_H
#include <string>
#include "Package.h"
using namespace std;
class  TwoDayPackage : public package
{
private:
	int fee;
public:
	TwoDayPackage(const string, const string, const string, const string,
		const string, const string, const string, const string,
		const string, const string, int = 0, int = 0, int = 0);


	void setFee(int);
	int getFee() const;
	virtual int returnPackage() const;
	virtual void print()const;
};
#endif
