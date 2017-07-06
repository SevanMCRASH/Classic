#ifndef BOSS_H
#define BOSS_H
using namespace std;


class Boss
{
private:
	int *health;
	int *attack;
	int *defence;
	int *speed;
	int *userattack;
	int *userhealth;
	int *userdefence;
	int *userspeed;

public:
	Boss(int&,int&,int&,int&,int&,int&,int&,int&);
	void setHealth(int&);
	void setAttack(int&);
	void setDefence(int&);
	void setSpeed(int&);

	void setUserHealth(int&);
	void setUserAttack(int&);
	void setUserDefence(int&);
	void setUserSpeed(int&);

	int getHealth()const;
	int getAttack()const;
	int getDefence()const;
	int getSpeed()const;

	int getUserAttack()const;
	int getUserHealth()const;
	int getUserDefence()const;
	int getUserSpeed()const;

};
#endif

