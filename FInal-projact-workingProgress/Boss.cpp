#include <iostream>
using namespace std;
#include "Boss.h"

Boss::Boss(int &health_,int& attack_,int& defence_,int& speed_,int& Uhealth_, int& Uattack_,int& Udefence_,int& Uspeed_)
{// take in address
	setAttack(attack_);
	setHealth(health_);
	setDefence(defence_);
	setSpeed(speed_);
	setUserAttack(Uattack_);
	setUserHealth(health_);
	setUserDefence(Udefence_);
	setUserSpeed(Uspeed_);
}
void Boss::setHealth(int &health_)
{
	health = &health_;
}
void Boss::setAttack(int &attack_)
{
	attack = &attack_;
}
void Boss::setDefence(int &defence_)
{
	defence = &defence_;
}
void Boss::setSpeed(int &speed_)
{
	speed = &speed_;
}
void Boss::setUserHealth(int &Uhealth_)
{
	userhealth = &Uhealth_;
}
void Boss::setUserAttack(int &Uattack_)
{
	userattack = &Uattack_;
}
void Boss::setUserDefence(int &Udefence_)
{
	userdefence = &Udefence_;
}
void Boss::setUserSpeed(int &Uspeed_)
{
	userspeed = &Uspeed_;
}
int Boss::getHealth()const
{
	return *health;
}
int Boss::getAttack()const
{
	return *attack;
}
int Boss::getDefence()const
{
	return *defence;
}
int Boss::getSpeed()const
{
	return *speed;
}
int Boss::getUserHealth()const
{
	return *userhealth;
}
int Boss::getUserAttack()const
{
	return *userattack;
}
int Boss::getUserDefence()const
{
	return *userdefence;
}
int Boss::getUserSpeed()const
{
	return *userspeed;
}
