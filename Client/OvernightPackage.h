#ifndef OVERNIGHTPACKAGE_H
#define OVERNIGHTPACKAGE_H
#include <string>
#include "Package.h"
using namespace std;

class OvernightPackage : public Package
{
private:
	int flatFee;
public:
	OvernightPackage (const string, const string, const string, const string,
		const string, const string, const string, const string,
		const string, const string, int = 0, int = 0, int = 0);//initializer with 2 default arguments
	
	void setNightFee(int);
	int getNightFee() const;
	int nightPackage() const;
};
#endif
