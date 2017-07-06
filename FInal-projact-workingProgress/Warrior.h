#ifndef WARRIOR_H
#define WARRIOR_H
using namespace std;
#include "Boss.h"

class Warrior:public Boss
{
private:
	int *totalbosshp;
	int *totaluserhp;
	int *shield;
	int *addedshield;
	int *useroverdrive;
	int *userpotion;
	int *power;
	int *bosspower1;
	int *bosspower2;
public:
	Warrior(int&, int&, int&, int&, int&, int&, int&, int&, int&, int&, int&, int&, int&, int&);
	void setTotalBossHP(int&);
	void setTotalUserHP(int&);
	void setShield(int&);
	void setAddedShield(int&);
	void setUserPotion(int&);
	void setPower(int&);
	void setBossPower1(int&);
	void setBossPower2(int&);
	int getTotalBossHP()const;
	int getTotalUserHP()const;
	int getShield()const;
	int getAddedShield()const;
	int getUserPotion()const;
	int getPower()const;
	int getBossPower1()const;
	int getBossPower2()const;
	int speedChecker();
	bool HPchecker();
	int skill1();
	int skill2();
	int skill3();
	int bossSkill1();
	int bossSkill2();
	int maxUserOverDrive();
	int maxBossOverDrive();
	int HPdecress();//changing value cant make const
	int bossAttack();
};
#endif

