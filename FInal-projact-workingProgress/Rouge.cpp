#include <iostream>
#include <time.h>

using namespace std;
#include "Rouge.h"
Rouge::Rouge(int& bosshp, int& bossattack, int& bossdefence, int& bossspeed, int& bosspower1_, int& bosspower2_,
	int& rougehp, int& rougeattack_, int& rougedefence_, int& rougespeed, int& shield_,int& addedshield_, int&power_,
	int& potion_) : Boss(bosshp, bossattack, bossdefence, bossspeed, rougehp, rougeattack_, rougedefence_, rougespeed)
{
	setAddedShield(addedshield_);
	setBossPower1(bosspower1_);
	setBossPower2(bosspower2_);
	setPower(power_);
	setUserPotion(potion_);
	setShield(shield_);
	setTotalUserHP(rougehp);
	setTotalBossHP(bosshp);
}
void Rouge::setTotalBossHP(int& bosshp)
{
	totalbosshp = &bosshp;
}
void Rouge::setTotalUserHP(int& magehp)
{
	totaluserhp = &magehp;
}
void Rouge::setShield(int& shield_)
{
	shield = &shield_;
}
void Rouge::setAddedShield(int& addedshield_)
{
	addedshield = &addedshield_;
}
void Rouge::setUserPotion(int &potion_)
{
	userpotion = &potion_;
}
void Rouge::setPower(int& power_)
{
	power = &power_;
}
void Rouge::setBossPower1(int& bosspower1_)
{
	bosspower1 = &bosspower1_;
}
void Rouge::setBossPower2(int& bosspower2_)
{
	bosspower2 = &bosspower2_;
}
int Rouge::getTotalBossHP()const
{
	return *totalbosshp;
}
int Rouge::getTotalUserHP()const
{
	return *totaluserhp;
}
int Rouge::getShield()const
{
	return *shield;
}
int Rouge::getAddedShield()const
{
	return *addedshield;
}
int Rouge::getPower()const
{
	return *power;
}
int Rouge::getUserPotion()const
{
	return *userpotion;
}
int Rouge::getBossPower1()const
{
	return *bosspower1;
}
int Rouge::getBossPower2()const
{
	return *bosspower2;
}
int Rouge::HPdecress()
{
	*totalbosshp = Boss::getDefence() - Boss::getUserAttack() + *totalbosshp;// result should be 15
	return *totalbosshp;
}
bool Rouge::HPchecker()
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
int Rouge::speedChecker()
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
int Rouge::skill1()
{
	if (*shield < 0)
	{
		*shield = 0;
	}
	*shield = *shield + *addedshield;
	return *shield;
}
int Rouge::skill2()
{
	*power = *power + Boss::getUserAttack();
	*totalbosshp = Boss::getDefence() - *power + *totalbosshp;
	return *totalbosshp;
}
int Rouge::skill3()
{
	*totaluserhp = *totaluserhp + *userpotion;
	if (*totaluserhp > 1000)
	{
		*totaluserhp = 1000;
		return *totaluserhp;
	}
	else
	{
		return *totaluserhp;
	}
}
int Rouge::maxUserOverDrive()
{
	*totalbosshp = Boss::getDefence() - (Boss::getUserAttack() * 10) + *totalbosshp;
	return *totalbosshp;
}
int Rouge::bossAttack()
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
int Rouge::bossSkill1()
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
int Rouge::bossSkill2()
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
int Rouge::maxBossOverDrive()
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