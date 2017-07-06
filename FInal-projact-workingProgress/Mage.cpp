#include <iostream>
#include <time.h>

using namespace std;
#include "Mage.h"
Mage::Mage(int& bosshp, int& bossattack, int& bossdefence, int& bossspeed, int& bosspower1_, int& bosspower2_,
	int& magehp, int& mageattack_, int& magedefence_, int& magespeed, int& shield_,int& addedshield_, int&power_,
	int& potion_) : Boss(bosshp, bossattack, bossdefence, bossspeed, magehp, mageattack_, magedefence_, magespeed)
{
	setAddedShield(addedshield_);
	setBossPower1(bosspower1_);
	setBossPower2(bosspower2_);
	setPower(power_);
	setUserPotion(potion_);
	setShield(shield_);
	setTotalUserHP(magehp);
	setTotalBossHP(bosshp);
}
void Mage::setTotalBossHP(int& bosshp)
{
	totalbosshp = &bosshp;
}
void Mage::setTotalUserHP(int& magehp)
{
	totaluserhp = &magehp;
}
void Mage::setShield(int& shield_)
{
	shield = &shield_;
}
void Mage::setAddedShield(int& addedshield_)
{
	addedshield = &addedshield_;
}
void Mage::setUserPotion(int &potion_)
{
	userpotion = &potion_;
}
void Mage::setPower(int& power_)
{
	power = &power_;
}
void Mage::setBossPower1(int& bosspower1_)
{
	bosspower1 = &bosspower1_;
}
void Mage::setBossPower2(int& bosspower2_)
{
	bosspower2 = &bosspower2_;
}
int Mage::getTotalBossHP()const
{
	return *totalbosshp;
}
int Mage::getTotalUserHP()const
{
	return *totaluserhp;
}
int Mage::getShield()const
{
	return *shield;
}
int Mage::getAddedShield()const
{
	return *addedshield;
}
int Mage::getPower()const
{
	return *power;
}
int Mage::getUserPotion()const
{
	return *userpotion;
}
int Mage::getBossPower1()const
{
	return *bosspower1;
}
int Mage::getBossPower2()const
{
	return *bosspower2;
}
int Mage::HPdecress()
{
	*totalbosshp = Boss::getDefence() - Boss::getUserAttack() + *totalbosshp;// result should be 15
	return *totalbosshp;
}
bool Mage::HPchecker()
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
int Mage::speedChecker()
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
int Mage::skill1()
{
	if (*shield < 0)
	{
		*shield = 0;
	}
	*shield = *shield + *addedshield;
	return *shield;
}
int Mage::skill2()
{
	*power = *power + Boss::getUserAttack();
	*totalbosshp = Boss::getDefence() - *power + *totalbosshp;
	return *totalbosshp;
}
int Mage::skill3()
{
	*totaluserhp = *totaluserhp + *userpotion;
	if (*totaluserhp > 800)
	{
		*totaluserhp = 800;
		return *totaluserhp;
	}
	else
	{
		return *totaluserhp;
	}
}
int Mage::maxUserOverDrive()
{
	*totalbosshp = Boss::getDefence() - (Boss::getUserAttack() * 10) + *totalbosshp;
	return *totalbosshp;
}
int Mage::bossAttack()
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
int Mage::bossSkill1()
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
int Mage::bossSkill2()
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
int Mage::maxBossOverDrive()
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