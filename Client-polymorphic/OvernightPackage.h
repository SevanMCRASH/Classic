#ifndef OVERNIGHTPACKAGE_H
#define OVERNIGHTPACKAGE_H
#include <string>
#include "Package.h"
using namespace std;


class OvernightPackage : public package
{
private:
	int flatFee;
public:
	OvernightPackage(const string, const string, const string, const string,
		const string, const string, const string, const string,
		const string, const string, int = 0, int = 0, int = 0);


	void setNightFee(int);
	int getNightFee() const;
	virtual int nightPackage() const;
	virtual void print()const;
};
#endif
