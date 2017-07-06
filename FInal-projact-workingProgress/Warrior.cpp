#include <iostream>
#include <time.h>

using namespace std;
#include "Warrior.h"
Warrior::Warrior(int& bosshp, int& bossattack, int& bossdefence, int& bossspeed, int& bosspower1_, int& bosspower2_,
	             int& warriorhp, int& warriorattack_, int& warriordefence_, int& warriorspeed, int& shield_,int& addedshield_,int&power_, 
	             int& potion_): Boss(bosshp, bossattack, bossdefence, bossspeed,warriorhp, warriorattack_, warriordefence_, warriorspeed)
{
	setAddedShield(addedshield_);
	setBossPower1(bosspower1_);
	setBossPower2(bosspower2_);
	setPower(power_);
	setUserPotion(potion_);
	setShield(shield_);
	setTotalUserHP(warriorhp);
	setTotalBossHP(bosshp);
}
void Warrior::setTotalBossHP(int& bosshp)
{
	totalbosshp = &bosshp;
}
void Warrior::setTotalUserHP(int& warriorhp)
{
	totaluserhp = &warriorhp;
}
void Warrior::setShield(int& shield_)
{
	shield = &shield_;
}
void Warrior::setAddedShield(int& addedshield_)
{
	addedshield = &addedshield_;
}
void Warrior::setUserPotion(int &potion_)
{
	userpotion = &potion_;
}
void Warrior::setPower(int& power_)
{
	power = &power_;
}
void Warrior::setBossPower1(int& bosspower1_)
{
	bosspower1 = &bosspower1_;
}
void Warrior::setBossPower2(int& bosspower2_)
{
	bosspower2 = &bosspower2_;
}
int Warrior::getTotalBossHP()const
{
	return *totalbosshp;
}
int Warrior::getTotalUserHP()const
{
	return *totaluserhp;
}
int Warrior::getShield()const
{
	return *shield;
}
int Warrior::getAddedShield()const
{
	return *addedshield;
}
int Warrior::getPower()const
{
	return *power;
}
int Warrior::getUserPotion()const
{
	return *userpotion;
}
int Warrior::getBossPower1()const
{
	return *bosspower1;
}
int Warrior::getBossPower2()const
{
	return *bosspower2;
}
int Warrior::HPdecress()
{
	*totalbosshp = Boss::getDefence() - Boss::getUserAttack() + *totalbosshp;// result should be 15
	return *totalbosshp;
}
bool Warrior::HPchecker()
{
	if (*totalbosshp == 0 || *totalbosshp < 0 || (*totaluserhp == 0 || *totaluserhp < 0))
	{
		return false;
	}
	else
	{
		return true;
	}
}
int Warrior::speedChecker()
{
	if (Boss::getUserSpeed() > Boss::getSpeed())
	{
		return 1;
	}
	else
	{
		return 2;
	}
}
int Warrior::skill1()
{
	if (*shield < 0)
	{
		*shield = 0;
	}
	*shield = *shield + *addedshield;
	return *shield;
}
int Warrior::skill2()
{
	*power = *power + Boss::getUserAttack();
	*totalbosshp = Boss::getDefence() - *power + *totalbosshp;
	return *totalbosshp;
}
int Warrior::skill3()
{
	*totaluserhp = *totaluserhp + *userpotion;
	if (*totaluserhp > 1200)
	{
		*totaluserhp = 1200;
		return *totaluserhp;
	}
	else
	{
		return *totaluserhp;
	}
}
int Warrior::maxUserOverDrive()
{
	*totalbosshp = Boss::getDefence() - (Boss::getUserAttack()*10) + *totalbosshp;
	return *totalbosshp;
}
int Warrior::bossAttack()
{
	if (getShield() > 0)
	{
		*shield = Boss::getUserDefence() - Boss::getAttack() + *shield;
		if (*shield == 0 || *shield < 0)
		{
			*totaluserhp = *shield + *totaluserhp;
			return *totaluserhp;
		}
		else
		{
			return *shield;
		}
	}
	else if (getShield() <= 0)
	{
		*totaluserhp = Boss::getUserDefence() - Boss::getAttack() + *totaluserhp;
		return *totaluserhp;
	}
}
int Warrior::bossSkill1()
{
	if (getShield() > 0)
	{
		*shield = *shield - *bosspower1;
		if (*shield == 0 || *shield < 0)
		{
			*totaluserhp = *shield + *totaluserhp;
			return *totaluserhp;
		}
		else
		{
			return *shield;
		}
	}
	else if (getShield() <= 0)
	{
		*totaluserhp = *totaluserhp - *bosspower1;
		return *totaluserhp;
	}
}
int Warrior::bossSkill2()
{
	if (getShield() > 0)
	{
		*shield = *shield - *bosspower2;
		if (*shield == 0 || *shield < 0)
		{
			*totaluserhp = *shield + *totaluserhp;
			return *totaluserhp;
		}
		else
		{
			return *shield;
		}
	}
	else if (getShield() <= 0)
	{
		*totaluserhp = *totaluserhp - *bosspower2;
		return *totaluserhp;
	}
}
int Warrior::maxBossOverDrive()
{
	if (getShield() > 0)
	{
		*shield = *shield - 750;
		if (*shield == 0 || *shield < 0)
		{
			*totaluserhp = *shield + *totaluserhp;
			return *totaluserhp;
		}
		else
		{
			return *shield;
		}
	}
	else if (getShield() <= 0)
	{
		*totaluserhp = *totaluserhp - 750;
		return *totaluserhp;
	}
}
	