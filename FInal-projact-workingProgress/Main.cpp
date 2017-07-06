//Sevan Mardirossian
//137 CSIS 
//Wensday night
//completion(100%)
#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;
#include "Boss.h"
#include "Warrior.h"
#include "Mage.h"
#include "Rouge.h"
int main()
{
	srand((unsigned)time(0));
	int potionnumber = 3, bosschoice, preventextraturn = 0;
	int defaulthp = 0, defaultattack = 0, defaultdefence = 0, defaultspeed = 0;//defult state
	int bHp = 2000, battack = 75, bdefence = 20, bspeed = 30, boverdrive = 0, bosspower1 = 100, bosspower2 = 300;//boss states
	int WHp = 1200, Wattack = 50, Wdefence = 50, Wspeed = 25, Wshield = 0, Wshieldadd = 500, Woverdrive = 0, Wpotion = 250, Wpower = 25 + 50;//Warrior state
	int MHp = 800, Mattack = 35, Mdefence = 30, Mspeed = 35, Mshield = 0, Mshieldadd = 1000, Moverdrive = 0, Mpotion = 250, Mpower = 100;//mage state
	int RHp = 1000, Rattack = 40, Rdefence = 35, Rspeed = 50, Rshield = 0, Rshieldadd = 750, Roverdrive = 0, Rpotion = 250, Rpower = 5*2;//mage state
	char choice, choice2, choice3, choosecharacter;
	Boss state1(bHp, battack, bdefence, bspeed, defaulthp, defaultattack, defaultdefence, defaultspeed);//hp,attack,defence,speed
	Warrior state2(bHp, battack, bdefence, bspeed, bosspower1, bosspower2, WHp, Wattack, Wdefence, Wspeed, Wshield, Wshieldadd, Wpower, Wpotion);//ability/overdrive
	Mage state3(bHp, battack, bdefence, bspeed, bosspower1, bosspower2, MHp, Mattack, Mdefence, Mspeed, Mshield, Mshieldadd, Mpower, Mpotion);//ability/overdrive
	Rouge state4(bHp, battack, bdefence, bspeed, bosspower1, bosspower2, RHp, Rattack, Rdefence, Rspeed, Rshield, Rshieldadd, Rpower, Rpotion);//ability/overdrive

	cout << "You are facing Armas the self proclaimed genius " << endl// Armen + Thomas = Armas XD
		<< "he has " << state1.getHealth() << " health " << endl
		<< "attack of " << state1.getAttack() << endl
		<< "with " << state1.getDefence() << " defence " << endl
		<< "and " << state1.getSpeed() << " speed " << endl
		<< "with two skills such as" << endl
		<< "a)TimeWarp - dose 100 damage no matter" << endl
		<< "b)OverClockked - dose 300 damage no matter"<<endl
		<< "OverDrive-The Judgment dose very heavy damage(750), but every 5 rounds" << endl;
	cout << "You have the choice of pick warrior, mage, or rouge to fight" << endl
		<< "now choose 1 for warrior, choose 2 for mage, choose 3 rouge\n" << endl
		<< "Warrior state:      Mage state:          Rogue state:" << endl
		<< "HP: "<<WHp<<"            HP: "<<MHp<<"              HP: "<<RHp<<endl
		<< "Attack: " << Wattack << "          Attack: " << Mattack << "           Attack: " << Rattack<< endl
		<< "Defence: " << Wdefence << "         Defence: " << Mdefence << "          Defence: " << Rdefence<< endl
		<< "Speed: " << Wspeed << "           Speed: " << Mspeed << "            Speed: " << Rspeed <<"\n"<< endl
		<< "Warrior skills:                      Mage skills:                           Rouge skills:" << endl
		<< "a)Guard-gives you 500 shield         a)Barrier- adds 1000 magic force       a)MirrorImage-adds 750 hit point of dodge" << endl
		<< "b)Smakdownupcut-very strong skill    b)Force-strong magnatic push           b)Vanshing drive-really fast strike" << endl
		<< "(+25 each hit)                         (fix (100+atack) each hit)           (slow start but, doubles after each use)" <<endl   
		<< "c)potion(x3)-heal 100 hp             c)potion(x3)-heals 100 hp              c)potion(x3)-heal 100 hp" << endl
		<< "(additional use will skip your turn) (additional use will skip your turn)   (additional use will skip your turn)"<<endl      
		<< "Overdrive-DemsiRoll                  Overdrive-Implosion                    Overdrice-Infinite Assulte\n" << endl;
	cout << "now please choose to 'p' attack or q to quite " << endl;
	cin >> choice;
	while (choice != 'p' && choice != 'P' && choice != 'q' && choice != 'Q')
	{
		cout << "please make a proper choice " << endl;
		cin >> choice;
	}
	if (choice == 'p' || choice == 'P')
	{
		cout << "now please choose which character you want " << endl
			<< "1)Warrior" << endl
			<< "2)Mage" << endl
			<< "3)Rogue" << endl;
		cin >> choosecharacter;
		while (choosecharacter != '1' && choosecharacter != '2' && choosecharacter != '3')
		{
			cout << "please make a proper choice " << endl;
			cin >> choosecharacter;
		}
		///////////////////
		//  WARRIOR CODE //
		///////////////////
		if(choosecharacter == '1')
		{ 
			while (state2.HPchecker() == true)
			{
				if (state2.speedChecker() == 1)//fast characters use this
				{

					if (Woverdrive == 3)
					{
						cout << "Hey your Overdrive is ready want to us it?" << endl
							<< "just say 'Y' for yes, 'N' for no" << endl;
						cin >> choice3;
						while (choice3 != 'Y' && choice3 != 'y' && (choice3 != 'n' && choice3 != 'N'))
						{
							cout << "please make a proper choice" << endl;
							cin >> choice3;
						}
						if (choice3 == 'Y' || choice3 == 'y')
						{
							cout << "You yelled: ITS OVER! and his HP droped to " << state2.maxUserOverDrive() << endl;
							Woverdrive = Woverdrive - 3;
							preventextraturn++;
						}
						else
						{
							cout << "ok" << endl;
							Woverdrive--;
						}
					}
					if (state2.HPchecker() == true)
					{
						if (preventextraturn == 0)
						{
							cout << "now please choose to 'A'to attack, 1 to guard, 2 to do takedownupcut, 3 to use potion" << endl;
							cin >> choice2;
							while (choice2 != 'A' && choice2 != '1' && choice2 != '2' && choice2 != '3')
							{
								cout << "please make a proper choice " << endl;
								cin >> choice2;
							}
							if (choice2 == 'A')
							{
								cout << "after attacking his health is now " << state2.HPdecress() << endl;
								if (Woverdrive < 4)
								{
									Woverdrive++;
								}
							}
							else  if (choice2 == '1')
							{
								cout << "You yelled: GUARD and gained " << state2.skill1() << " shield" << endl;
								if (Woverdrive < 4)
								{
									Woverdrive++;
								}
							}
							else  if (choice2 == '2')
							{
								cout << "You yelled: YOU BETTER LOOKOUT, BECUASE IM GOING TO KNOCKOUT YOU OUT." << endl
									<< " the boss has " << state2.skill2() << " health after damage" << endl;
								if (Woverdrive < 4)
								{
									Woverdrive++;
								}
							}
							else  if (choice2 == '3')
							{
								if (potionnumber == 0)
								{
									cout << "No more potions be more wize with your matriel" << endl
										<< "sorry but it looks like you wasted a turn. keep count" << endl;
								}
								else
								{
									cout << "You clamied with relive: Nice, some recovery" << endl;
									cout << "You have " << state2.skill3() << " health" << endl;
									potionnumber--;
									if (Woverdrive < 4)
									{
										Woverdrive++;
									}
								}
							}
						}
						else if (preventextraturn == 1)
						{
							cout << "Now its the bosses turn" << endl;
							preventextraturn--;
						}
					}

					if (state2.HPchecker() == true)
					{
						if (boverdrive == 5)
						{
							if (state2.getShield() == 0)
							{
								cout << "BOSS CLAIMED: IM A FREAKING GENIUS and your health is reduced to " << state2.maxBossOverDrive() << endl;
								boverdrive = boverdrive - 5;
								preventextraturn += 2;
							}
							else if (state2.getShield() > 0)
							{
								state2.maxBossOverDrive();
								if (state2.getShield() == 0 || state2.getShield() < 0)
								{
									cout << "BOSS CLAIMED: IM A FREAKING GENIUS and your health is reduced to " << state2.getTotalUserHP() << endl;
									boverdrive = boverdrive - 5;
									preventextraturn += 2;
								}
								else if(state2.getShield() > 0)
								{
									cout << "BOSS CLAIMED: IM A FREAKING GENIUS and your shield is reduced to " << state2.getShield() << endl;
									cout << "you have " << state2.getTotalUserHP() << " health" << endl;
									boverdrive = boverdrive - 5;
									preventextraturn += 2;
								}
							}
						}

						if (state2.HPchecker() == true)
						{
							if (preventextraturn == 0)
							{
								bosschoice = rand() % 3 + 1;//BOSS DECISION AI
								cout << "boss chose number " << bosschoice << endl;
								if (bosschoice == 1)
								{
									if (state2.getShield() == 0)
									{
										cout << "the boss attacked you and you have " << state2.bossAttack() << " health" << endl;
										boverdrive++;
									}
									else if (state2.getShield() > 0)
									{
										state2.bossAttack();
										if (state2.getShield() == 0 || state2.getShield() < 0)
										{
											cout << " you have " << state2.getTotalUserHP() << " health" << endl;
											boverdrive++;
										}
										else
										{
											cout << " the boss attacked you and now you have " << state2.getShield() << " shield" << endl;
											cout << " you have " << state2.getTotalUserHP() << " health" << endl;
											boverdrive++;
										}
									}
								}
								else if (bosschoice == 2)
								{
									if (state2.getShield() == 0)
									{
										cout << "the boss used Timewarp and you have " << state2.bossSkill1() << " health" << endl;
										boverdrive++;
									}
									else if (state2.getShield() > 0)
									{
										state2.bossSkill1();
										if (state2.getShield() == 0 || state2.getShield() < 0)
										{
											cout << " you have " << state2.getTotalUserHP() << " health" << endl;
											boverdrive++;
										}
										else
										{
											cout << "the boss used TimeWarp and you have now " << state2.getShield() << " shield" << endl;
											cout << " you have " << state2.getTotalUserHP() << " health" << endl;
											boverdrive++;
										}
									}
								}
								else if (bosschoice == 3)
								{
									if (state2.getShield() == 0)
									{
										cout << "the boss used his strongest skill Overclocked and you have now " << state2.bossSkill2() << " health" << endl;
										boverdrive++;
									}
									else if (state2.getShield() > 0)
									{
										state2.bossSkill2();
										if (state2.getShield() == 0 || state2.getShield() < 0)
										{
											cout << " you have " << state2.getTotalUserHP() << " health" << endl;
											boverdrive++;
										}
										else
										{
											cout << "the boss used his strongest skill Overclocked and you have now " << state2.getShield() << " shield" << endl;
											cout << " you have " << state2.getTotalUserHP() << " health" << endl;
											boverdrive++;
										}
									}
								}
							}
							else if (preventextraturn == 2)
							{
								cout << "Now its your turn" << endl;
								preventextraturn -= 2;
							}
						}
					}
				}
				////////////////////////////////////////////////////////////////////////////////////////////
				///                                                                                     ///
				///                   SECONDE SPEED CHECKER FOR SLOW CHARACTERS                         ///                                                  ///
				///                                                                                     ///
				///////////////////////////////////////////////////////////////////////////////////////////

				else if (state2.speedChecker() == 2)//slow characters use this
				{
					while (state2.HPchecker() == true)
					{
						if (boverdrive == 5)
						{
							if (state2.getShield() == 0)
							{
								cout << "BOSS CLAIMED: IM A FREAKING GENIUS and your health is reduced to " << state2.maxBossOverDrive() << endl;
								boverdrive = boverdrive - 5;
								preventextraturn += 2;
							}
							else if (state2.getShield() > 0)
							{
								state2.maxBossOverDrive();
								if (state2.getShield() == 0 || state2.getShield() < 0)
								{
									cout << "BOSS CLAIMED: IM A FREAKING GENIUS and your health is reduced to " << state2.getTotalUserHP() << endl;
									boverdrive = boverdrive - 5;
									preventextraturn += 2;
								}
								else if (state2.getShield() > 0)
								{
									cout << "BOSS CLAIMED: IM A FREAKING GENIUS and your shield is reduced to " << state2.getShield() << endl;
									cout << "you have " << state2.getTotalUserHP() << " health" << endl;
									boverdrive = boverdrive - 5;
									preventextraturn += 2;
								}
							}
						}
						if (state2.HPchecker() == true)
						{
							if (preventextraturn == 0)
							{
								bosschoice = rand() % 3 + 1;//BOSS DECISION AI
								cout << "boss chose number " << bosschoice << endl;
								if (bosschoice == 1)
								{
									if (state2.getShield() == 0)
									{
										cout << "the boss attacked you and you have " << state2.bossAttack() << " health" << endl;
										boverdrive++;
									}
									else if (state2.getShield() > 0)
									{
										state2.bossAttack();
										if (state2.getShield() == 0 || state2.getShield() < 0)
										{
											cout << "you have " << state2.getTotalUserHP() << " health" << endl;
											boverdrive++;
										}
										else
										{
											cout << "the boss attacked you and now you have " << state2.getShield() << " shield" << endl;
											cout << "you have " << state2.getTotalUserHP() << " health" << endl;
											boverdrive++;
										}
									}
								}
								else if (bosschoice == 2)
								{
									if (state2.getShield() == 0)
									{
										cout << "the boss used his Timewarp and you have " << state2.bossSkill1() << " health" << endl;
										boverdrive++;
									}
									else if (state2.getShield() > 0)
									{
										state2.bossSkill1();
										if (state2.getShield() == 0 || state2.getShield() < 0)
										{
											cout << "you have " << state2.getTotalUserHP() << " health" << endl;
											boverdrive++;
										}
										else
										{
											cout << "the boss used TimeWarp and you have " << state2.getShield() << " shield" << endl;
											cout << "you have " << state2.getTotalUserHP() << " health" << endl;
											boverdrive++;
										}
									}
								}
								else if (bosschoice == 3)
								{
									if (state2.getShield() == 0)
									{
										cout << "the boss used his strongest skill Overclocked and you have now " << state2.bossSkill2() << " health" << endl;
										boverdrive++;
									}
									else if (state2.getShield() > 0)
									{
										state2.bossSkill2();
										if (state2.getShield() == 0 || state2.getShield() < 0)
										{
											cout << " you have " << state2.getTotalUserHP() << " health" << endl;
											boverdrive++;
										}
										else
										{
											cout << "the boss used his strongest skill Overclocked and you have now " << state2.getShield() << " shield" << endl;
											cout << " you have " << state2.getTotalUserHP() << " health" << endl;
											boverdrive++;
										}
									}
								}
							}
							else if (preventextraturn == 2)
							{
								cout << "Now its your turn" << endl;
								preventextraturn -= 2;
							}
						}

						if (state2.HPchecker() == true)//must check all the time b/c hp might run out
						{
							if (Woverdrive == 3)
							{
								cout << "Hey your Overdrive is ready want to us it?" << endl
									<< "just say 'Y' for yes, 'N' for no" << endl;
								cin >> choice3;
								while (choice3 != 'Y' && choice3 != 'y' && (choice3 != 'n' && choice3 != 'N'))
								{
									cout << "please make a proper choice" << endl;
									cin >> choice3;
								}
								if (choice3 == 'Y' || choice3 == 'y')
								{
									cout << "You yelled: ITS OVER! and his HP droped to " << state2.maxUserOverDrive() << endl;
									Woverdrive = Woverdrive - 3;
									preventextraturn++;
								}
								else
								{
									cout << "ok" << endl;
									Woverdrive--;
								}

							}
							if (state2.HPchecker() == true)
							{
								if (preventextraturn == 0)
								{
									cout << "now please choose to 'A' attack, 1 to guard, 2 to do takedownupcut, 3 to use potion" << endl;
									cin >> choice2;
									while (choice2 != 'A' && choice2 != '1' && choice2 != '2' && choice2 != '3')
									{
										cout << "please make a proper choice " << endl;
										cin >> choice2;
									}
									if (choice2 == 'A' || choice2 == 'a')
									{
										cout << "after attacking his health is now " << state2.HPdecress() << endl;
										if (Woverdrive < 4)
										{
											Woverdrive++;
										}
									}
									else  if (choice2 == '1')
									{
										cout << "You yelled: GUARD and gained " << state2.skill1() << " shield" << endl;
										if (Woverdrive < 4)
										{
											Woverdrive++;
										}
									}
									else  if (choice2 == '2')
									{
										cout << "You yelled: YOU BETTER LOOKOUT, BECUASE IM GOING TO KNOCKOUT YOU OUT." << endl
											<< " the boss has " << state2.skill2() << " health" << endl;
										if (Woverdrive < 4)
										{
											Woverdrive++;
										}
									}
									else  if (choice2 == '3')
									{
										if (potionnumber == 0)
										{
											cout << "No more potions be more wize with your matriel" << endl
												<< "sorry but it looks like you wasted a turn. keep count" << endl;
										}
										else
										{
											cout << "You clamied with relive: Nice, some recovery" << endl;
											cout << "You have " << state2.skill3() << " health" << endl;
											potionnumber--;
											if (Woverdrive < 4)
											{
												Woverdrive++;
											}
										}
									}
								}
								else if (preventextraturn == 1)
								{
									cout << "Now its Bosses turn" << endl;
									preventextraturn--;
								}
							}
						}
					}
				}
			}
		}//choose character
		////////////////
		//  MAGE CODE //
		////////////////
		else if (choosecharacter == '2')
		{
			while (state3.HPchecker() == true)
			{
				if (state3.speedChecker() == 1)//fast characters use this
				{
					if (Moverdrive == 3)
					{
						cout << "Hey your Overdrive is ready want to us it?" << endl
							<< "just say 'Y' for yes, 'N' for no" << endl;
						cin >> choice3;
						while (choice3 != 'Y' && choice3 != 'y' && (choice3 != 'n' && choice3 != 'N'))
						{
							cout << "please make a proper choice" << endl;
							cin >> choice3;
						}
						if (choice3 == 'Y' || choice3 == 'y')
						{
							cout << "You closed you eyes and said: GOODBYE! and the boss was left with " << state3.maxUserOverDrive() << " health" << endl;
							Moverdrive = Moverdrive - 3;
							preventextraturn++;
						}
						else
						{
							cout << "ok" << endl;
							Moverdrive--;
						}
					}
					if (state3.HPchecker() == true)
					{
						if (preventextraturn == 0)
						{
							cout << "now please choose to 'A' attack, 1 to use barrier, 2 to use force, 3 to use potion" << endl;
							cin >> choice2;
							while (choice2 != 'A' && choice2 != '1' && choice2 != '2' && choice2 != '3')
							{
								cout << "please make a proper choice " << endl;
								cin >> choice2;
							}
							if (choice2 == 'A')
							{
								cout << "after attacking his health is now " << state3.HPdecress() << endl;
								if (Moverdrive < 4)
								{
									Moverdrive++;
								}
							}
							else  if (choice2 == '1')
							{
								cout << "You yelled: Now its a fair game, and you gained " << state3.skill1() << " barrier" << endl;
								if (Moverdrive < 4)
								{
									Moverdrive++;
								}
							}
							else  if (choice2 == '2')
							{
								cout << "You yelled: FORCE." << endl
									<< " the boss now has " << state3.skill2() << " health" << endl;
								if (Moverdrive < 4)
								{
									Moverdrive++;
								}
							}
							else  if (choice2 == '3')
							{
								if (potionnumber == 0)
								{
									cout << "No more potions be more wize with your matriel" << endl
										<< "sorry but it looks like you wasted a turn. keep count" << endl;
								}
								else
								{
									cout << "You clamied with relive: Nice, some recovery" << endl;
									cout << "You have " << state3.skill3() << " health" << endl;
									potionnumber--;
									if (Moverdrive < 4)
									{
										Moverdrive++;
									}
								}
							}
						}
						else if (preventextraturn == 1)
						{
							cout << "Now its the bosses turn" << endl;
							preventextraturn--;
						}
					}

					if (state3.HPchecker() == true)
					{
						if (boverdrive == 5)
						{
							if (state3.getShield() == 0)
							{
								cout << "BOSS CLAIMED: IM A FREAKING GENIUS and your health is reduced to " << state3.maxBossOverDrive() << endl;
								boverdrive = boverdrive - 5;
								preventextraturn += 2;
							}
							else if (state3.getShield() > 0)
							{
								state3.maxBossOverDrive();
								if (state3.getShield() == 0 || state3.getShield() < 0)
								{
									cout << "BOSS CLAIMED: IM A FREAKING GENIUS and your health is reduced to " << state3.getTotalUserHP() << endl;
									boverdrive = boverdrive - 5;
									preventextraturn += 2;
								}
								else if (state3.getShield() > 0)
								{
									cout << "BOSS CLAIMED: IM A FREAKING GENIUS and your shield is reduced to " << state3.getShield() << endl;
									cout << "you have " << state3.getTotalUserHP() << " health" << endl;
									boverdrive = boverdrive - 5;
									preventextraturn += 2;
								}
							}
						}

						if (state3.HPchecker() == true)
						{
							if (preventextraturn == 0)
							{
								bosschoice = rand() % 3 + 1;//BOSS DECISION AI
								cout << "boss chose number " << bosschoice << endl;
								if (bosschoice == 1)
								{
									if (state3.getShield() == 0)
									{
										cout << "the boss attacked you and you have " << state3.bossAttack() << " health" << endl;
										boverdrive++;
									}
									else if (state3.getShield() > 0)
									{
										state3.bossAttack();
										if (state3.getShield() == 0 || state3.getShield() < 0)
										{
											cout << " you have " << state3.getTotalUserHP() << " health" << endl;
											boverdrive++;
										}
										else
										{
											cout << " the boss attacked you and now you have " << state3.getShield() << " barrier" << endl;
											cout << " you have " << state3.getTotalUserHP() << " health" << endl;
											boverdrive++;
										}
									}
								}
								else if (bosschoice == 2)
								{
									if (state3.getShield() == 0)
									{
										cout << "the boss used Timewarp and you have " << state3.bossSkill1() << " health" << endl;
										boverdrive++;
									}
									else if (state3.getShield() > 0)
									{
										state3.bossSkill1();
										if (state3.getShield() == 0 || state3.getShield() < 0)
										{
											cout << " you have " << state3.getTotalUserHP() << " health" << endl;
											boverdrive++;
										}
										else
										{
											cout << "the boss used TimeWarp and you have now " << state3.getShield() << " barrier" << endl;
											cout << " you have " << state3.getTotalUserHP() << " health" << endl;
											boverdrive++;
										}
									}
								}
								else if (bosschoice == 3)
								{
									if (state3.getShield() == 0)
									{
										cout << "the boss used his strongest skill Overclocked and you have now " << state3.bossSkill2() << " health" << endl;
										boverdrive++;
									}
									else if (state3.getShield() > 0)
									{
										state3.bossSkill2();
										if (state3.getShield() == 0 || state3.getShield() < 0)
										{
											cout << " you have " << state3.getTotalUserHP() << " health" << endl;
											boverdrive++;
										}
										else
										{
											cout << "the boss used his strongest skill Overclocked and you have now " << state3.getShield() << " barrier" << endl;
											cout << " you have " << state3.getTotalUserHP() << " health" << endl;
											boverdrive++;
										}
									}
								}
							}
							else if (preventextraturn == 2)
							{
								cout << "Now its your turn" << endl;
								preventextraturn -= 2;
							}
						}
					}
				}
				////////////////////////////////////////////////////////////////////////////////////////////
				///                                                                                     ///
				///                   SECONDE SPEED CHECKER FOR SLOW CHARACTERS                         ///                                                  ///
				///                                                                                     ///
				///////////////////////////////////////////////////////////////////////////////////////////

				else if (state3.speedChecker() == 2)//slow characters use this
				{
					while (state3.HPchecker() == true)
					{
						if (boverdrive == 5)
						{
							if (state3.getShield() == 0)
							{
								cout << "BOSS CLAIMED: IM A FREAKING GENIUS and your health is reduced to " << state3.maxBossOverDrive() << endl;
								boverdrive = boverdrive - 5;
								preventextraturn += 2;
							}
							else if (state3.getShield() > 0)
							{
								state3.maxBossOverDrive();
								if (state3.getShield() == 0 || state3.getShield() < 0)
								{
									cout << "BOSS CLAIMED: IM A FREAKING GENIUS and your health is reduced to " << state3.getTotalUserHP() << endl;
									boverdrive = boverdrive - 5;
									preventextraturn += 2;
								}
								else if (state3.getShield() > 0)
								{
									cout << "BOSS CLAIMED: IM A FREAKING GENIUS and your shield is reduced to " << state3.getShield() << endl;
									cout << "you have " << state3.getTotalUserHP() << " health" << endl;
									boverdrive = boverdrive - 5;
									preventextraturn += 2;
								}
							}
						}
						if (state3.HPchecker() == true)
						{
							if (preventextraturn == 0)
							{
								bosschoice = rand() % 3 + 1;//BOSS DECISION AI
								cout << "boss chose number " << bosschoice << endl;
								if (bosschoice == 1)
								{
									if (state3.getShield() == 0)
									{
										cout << "the boss attacked you and you have " << state3.bossAttack() << " health" << endl;
										boverdrive++;
									}
									else if (state3.getShield() > 0)
									{
										state3.bossAttack();
										if (state3.getShield() == 0 || state3.getShield() < 0)
										{
											cout << "you have " << state3.getTotalUserHP() << " health" << endl;
											boverdrive++;
										}
										else
										{
											cout << "the boss attacked you and now you have " << state3.getShield() << " barrier" << endl;
											cout << "you have " << state3.getTotalUserHP() << " health" << endl;
											boverdrive++;
										}
									}
								}
								else if (bosschoice == 2)
								{
									if (state3.getShield() == 0)
									{
										cout << "the boss used Timewarp and you have " << state3.bossSkill1() << " health" << endl;
										boverdrive++;
									}
									else if (state3.getShield() > 0)
									{
										state3.bossSkill1();
										if (state3.getShield() == 0 || state3.getShield() < 0)
										{
											cout << "you have " << state3.getTotalUserHP() << " health" << endl;
											boverdrive++;
										}
										else
										{
											cout << "the boss used TimeWarp and you have " << state3.getShield() << " barrier" << endl;
											cout << "you have " << state3.getTotalUserHP() << " health" << endl;
											boverdrive++;
										}
									}
								}
								else if (bosschoice == 3)
								{
									if (state3.getShield() == 0)
									{
										cout << "the boss used his strongest skill Overclocked and you have now " << state3.bossSkill2() << " health" << endl;
										boverdrive++;
									}
									else if (state3.getShield() > 0)
									{
										state3.bossSkill2();
										if (state3.getShield() == 0 || state3.getShield() < 0)
										{
											cout << " you have " << state3.getTotalUserHP() << " health" << endl;
											boverdrive++;
										}
										else
										{
											cout << "the boss used his strongest skill Overclocked and you have now " << state3.getShield() << " barrier" << endl;
											cout << " you have " << state3.getTotalUserHP() << " health" << endl;
											boverdrive++;
										}
									}
								}
							}
							else if (preventextraturn == 2)
							{
								cout << "Now its your turn" << endl;
								preventextraturn -= 2;
							}
						}

						if (state3.HPchecker() == true)//must check all the time b/c hp might run out
						{
							if (Moverdrive == 3)
							{
								cout << "Hey your Overdrive is ready want to us it?" << endl
									<< "just say 'Y' for yes, 'N' for no" << endl;
								cin >> choice3;
								while (choice3 != 'Y' && choice3 != 'y' && (choice3 != 'n' && choice3 != 'N'))
								{
									cout << "please make a proper choice" << endl;
									cin >> choice3;
								}
								if (choice3 == 'Y' || choice3 == 'y')
								{
									cout << "You closed you eyes and said: GOODBYE! and the boss was left with" << state3.maxUserOverDrive() << " health"<< endl;
									Moverdrive = Moverdrive - 3;
									preventextraturn++;
								}
								else
								{
									cout << "ok" << endl;
									Moverdrive--;
								}

							}
							if (state3.HPchecker() == true)
							{
								if (preventextraturn == 0)
								{
									cout << "now please choose to 'A' attack, 1 to use barrier, 2 to use force, 3 to use potion" << endl;
									cin >> choice2;
									while (choice2 != 'A' && choice2 != '1' && choice2 != '2' && choice2 != '3')
									{
										cout << "please make a proper choice " << endl;
										cin >> choice2;
									}
									if (choice2 == 'A' || choice2 == 'a')
									{
										cout << "after attacking his health is now " << state3.HPdecress() << endl;
										if (Moverdrive < 4)
										{
											Moverdrive++;
										}
									}
									else  if (choice2 == '1')
									{
										cout << "You yelled: Now its a fair game and gained " << state3.skill1() << " barrier" << endl;
										if (Moverdrive < 4)
										{
											Moverdrive++;
										}
									}
									else  if (choice2 == '2')
									{
										cout << "You yelled: FORCE" << endl
											<< " the has now " << state3.skill2() << " health" << endl;
										if (Moverdrive < 4)
										{
											Moverdrive++;
										}
									}
									else  if (choice2 == '3')
									{
										if (potionnumber == 0)
										{
											cout << "No more potions be more wize with your matriel" << endl
												<< "sorry but it looks like you wasted a turn. keep count" << endl;
										}
										else
										{
											cout << "You clamied with relive: Nice, some recovery" << endl;
											cout << "You have " << state3.skill3() << " health" << endl;
											potionnumber--;
											if (Moverdrive < 4)
											{
												Moverdrive++;
											}
										}
									}
								}
								else if (preventextraturn == 1)
								{
									cout << "Now its Bosses turn" << endl;
									preventextraturn--;
								}
							}
						}
					}
				}
			}
		}//choosecharacter
		/////////////////
		//  ROUGE CODE //
		/////////////////
		else if (choosecharacter == '3')
		{
			while (state4.HPchecker() == true)
			{
				if (state4.speedChecker() == 1)//fast characters use this
				{

					if (Roverdrive == 3)
					{
						cout << "Hey your Overdrive is ready want to us it?" << endl
							<< "just say 'Y' for yes, 'N' for no" << endl;
						cin >> choice3;
						while (choice3 != 'Y' && choice3 != 'y' && (choice3 != 'n' && choice3 != 'N'))
						{
							cout << "please make a proper choice" << endl;
							cin >> choice3;
						}
						if (choice3 == 'Y' || choice3 == 'y')
						{
							cout << "You Smirked and said: To bad, You can't keep up and he was left with " << state4.maxUserOverDrive()<<" health" << endl;
							Roverdrive = Roverdrive - 3;
							preventextraturn++;
						}
						else
						{
							cout << "ok" << endl;
							Roverdrive--;
						}
					}
					if (state4.HPchecker() == true)
					{
						if (preventextraturn == 0)
						{
							cout << "now please choose to 'A'to attack, 1 to Marrage, 2 to do Vanshing drive, 3 to use potion" << endl;
							cin >> choice2;
							while (choice2 != 'A' && choice2 != '1' && choice2 != '2' && choice2 != '3')
							{
								cout << "please make a proper choice " << endl;
								cin >> choice2;
							}
							if (choice2 == 'A')
							{
								cout << "after attacking his health is now " << state4.HPdecress() << endl;
								if (Roverdrive < 4)
								{
									Roverdrive++;
								}
							}
							else  if (choice2 == '1')
							{
								cout << "You yelled: MIRROR MARAGE, which one is me, can you tell? and you gained " << state4.skill1() << " illusion" << endl;
								if (Roverdrive < 4)
								{
									Roverdrive++;
								}
							}
							else  if (choice2 == '2')
							{
								cout << "You yelled: TOO SLOW" << endl
									<< " the boss has " << state4.skill2() << " health after damage" << endl;
								if (Roverdrive < 4)
								{
									Roverdrive++;
								}
							}
							else  if (choice2 == '3')
							{
								if (potionnumber == 0)
								{
									cout << "No more potions be more wize with your matriel" << endl
										<< "sorry but it looks like you wasted a turn. keep count" << endl;
								}
								else
								{
									cout << "You clamied with relive: Nice, some recovery" << endl;
									cout << "You have " << state4.skill3() << " health" << endl;
									potionnumber--;
									if (Roverdrive < 4)
									{
										Roverdrive++;
									}
								}
							}
						}
						else if (preventextraturn == 1)
						{
							cout << "Now its the bosses turn" << endl;
							preventextraturn--;
						}
					}

					if (state4.HPchecker() == true)
					{
						if (boverdrive == 5)
						{
							if (state4.getShield() == 0)
							{
								cout << "BOSS CLAIMED: IM A FREAKING GENIUS and your health is reduced to " << state4.maxBossOverDrive() << endl;
								boverdrive = boverdrive - 5;
								preventextraturn += 2;
							}
							else if (state4.getShield() > 0)
							{
								state4.maxBossOverDrive();
								if (state4.getShield() == 0 || state4.getShield() < 0)
								{
									cout << "BOSS CLAIMED: IM A FREAKING GENIUS and your health is reduced to " << state4.getTotalUserHP() << endl;
									boverdrive = boverdrive - 5;
									preventextraturn += 2;
								}
								else if (state4.getShield() > 0)
								{
									cout << "BOSS CLAIMED: IM A FREAKING GENIUS and your illusion is reduced to " << state4.getShield() << endl;
									cout << "you have " << state4.getTotalUserHP() << " health" << endl;
									boverdrive = boverdrive - 5;
									preventextraturn += 2;
								}
							}
						}

						if (state4.HPchecker() == true)
						{
							if (preventextraturn == 0)
							{
								bosschoice = rand() % 3 + 1;//BOSS DECISION AI
								cout << "boss chose number " << bosschoice << endl;
								if (bosschoice == 1)
								{
									if (state4.getShield() == 0)
									{
										cout << "the boss attacked you and you have " << state4.bossAttack() << " health" << endl;
										boverdrive++;
									}
									else if (state4.getShield() > 0)
									{
										state4.bossAttack();
										if (state4.getShield() == 0 || state4.getShield() < 0)
										{
											cout << " you have " << state4.getTotalUserHP() << " health" << endl;
											boverdrive++;
										}
										else
										{
											cout << " the boss attacked you and now you have " << state4.getShield() << " illusion" << endl;
											cout << " you have " << state4.getTotalUserHP() << " health" << endl;
											boverdrive++;
										}
									}
								}
								else if (bosschoice == 2)
								{
									if (state4.getShield() == 0)
									{
										cout << "the boss used Timewarp and you have " << state4.bossSkill1() << " health" << endl;
										boverdrive++;
									}
									else if (state4.getShield() > 0)
									{
										state4.bossSkill1();
										if (state4.getShield() == 0 || state4.getShield() < 0)
										{
											cout << " you have " << state4.getTotalUserHP() << " health" << endl;
											boverdrive++;
										}
										else
										{
											cout << "the boss used TimeWarp and you have now " << state4.getShield() << " illusion" << endl;
											cout << " you have " << state4.getTotalUserHP() << " health" << endl;
											boverdrive++;
										}
									}
								}
								else if (bosschoice == 3)
								{
									if (state4.getShield() == 0)
									{
										cout << "the boss used his strongest skill Overclocked and you have now " << state4.bossSkill2() << " health" << endl;
										boverdrive++;
									}
									else if (state4.getShield() > 0)
									{
										state4.bossSkill2();
										if (state4.getShield() == 0 || state4.getShield() < 0)
										{
											cout << " you have " << state4.getTotalUserHP() << " health" << endl;
											boverdrive++;
										}
										else
										{
											cout << "the boss used his strongest skill Overclocked and you have now " << state4.getShield() << " illusion" << endl;
											cout << " you have " << state4.getTotalUserHP() << " health" << endl;
											boverdrive++;
										}
									}
								}
							}
							else if (preventextraturn == 2)
							{
								cout << "Now its your turn" << endl;
								preventextraturn -= 2;
							}
						}
					}
				}
				////////////////////////////////////////////////////////////////////////////////////////////
				///                                                                                     ///
				///                   SECONDE SPEED CHECKER FOR SLOW CHARACTERS                         ///                                                  ///
				///                                                                                     ///
				///////////////////////////////////////////////////////////////////////////////////////////

				else if (state4.speedChecker() == 2)//slow characters use this
				{
					while (state4.HPchecker() == true)
					{
						if (boverdrive == 5)
						{
							if (state4.getShield() == 0)
							{
								cout << "BOSS CLAIMED: IM A FREAKING GENIUS and your health is reduced to " << state4.maxBossOverDrive() << endl;
								boverdrive = boverdrive - 5;
								preventextraturn += 2;
							}
							else if (state4.getShield() > 0)
							{
								state4.maxBossOverDrive();
								if (state4.getShield() == 0 || state4.getShield() < 0)
								{
									cout << "BOSS CLAIMED: IM A FREAKING GENIUS and your health is reduced to " << state4.getTotalUserHP() << endl;
									boverdrive = boverdrive - 5;
									preventextraturn += 2;
								}
								else
								{
									cout << "BOSS CLAIMED: IM A FREAKING GENIUS and your illusion is reduced to " << state4.getShield() << endl;
									cout << "you have " << state4.getTotalUserHP() << " health" << endl;
									boverdrive = boverdrive - 5;
									preventextraturn += 2;
								}
							}
						}
						if (state4.HPchecker() == true)
						{
							if (preventextraturn == 0)
							{
								bosschoice = rand() % 3 + 1;//BOSS DECISION AI
								cout << "boss chose number " << bosschoice << endl;
								if (bosschoice == 1)
								{
									if (state4.getShield() == 0)
									{
										cout << "the boss attacked you and you have " << state4.bossAttack() << " health" << endl;
										boverdrive++;
									}
									else if (state4.getShield() > 0)
									{
										state4.bossAttack();
										if (state4.getShield() == 0 || state4.getShield() < 0)
										{
											cout << "you have " << state4.getTotalUserHP() << " health" << endl;
											boverdrive++;
										}
										else if (state2.getShield() > 0)
										{
											cout << "the boss attacked you and now you have " << state4.getShield() << " illusion" << endl;
											cout << "you have " << state4.getTotalUserHP() << " health" << endl;
											boverdrive++;
										}
									}
								}
								else if (bosschoice == 2)
								{
									if (state4.getShield() == 0)
									{
										cout << "the boss used his Timewarp and you have " << state4.bossSkill1() << " health" << endl;
										boverdrive++;
									}
									else if (state4.getShield() > 0)
									{
										state4.bossSkill1();
										if (state4.getShield() == 0 || state4.getShield() < 0)
										{
											cout << "you have " << state4.getTotalUserHP() << " health" << endl;
											boverdrive++;
										}
										else
										{
											cout << "the boss used TimeWarp and you have " << state4.getShield() << " illusion" << endl;
											cout << "you have " << state4.getTotalUserHP() << " health" << endl;
											boverdrive++;
										}
									}
								}
								else if (bosschoice == 3)
								{
									if (state4.getShield() == 0)
									{
										cout << "the boss used his strongest skill Overclocked and you have now " << state4.bossSkill2() << " health" << endl;
										boverdrive++;
									}
									else if (state4.getShield() > 0)
									{
										state4.bossSkill2();
										if (state4.getShield() == 0 || state4.getShield() < 0)
										{
											cout << " you have " << state4.getTotalUserHP() << " health" << endl;
											boverdrive++;
										}
										else
										{
											cout << "the boss used his strongest skill Overclocked and you have now " << state4.getShield() << " illusion" << endl;
											cout << " you have " << state4.getTotalUserHP() << " health" << endl;
											boverdrive++;
										}
									}
								}
							}
							else if (preventextraturn == 2)
							{
								cout << "Now its your turn" << endl;
								preventextraturn -= 2;
							}
						}

						if (state4.HPchecker() == true)//must check all the time b/c hp might run out
						{
							if (Roverdrive == 3)
							{
								cout << "Hey your Overdrive is ready want to us it?" << endl
									<< "just say 'Y' for yes, 'N' for no" << endl;
								cin >> choice3;
								while (choice3 != 'Y' && choice3 != 'y' && (choice3 != 'n' && choice3 != 'N'))
								{
									cout << "please make a proper choice" << endl;
									cin >> choice3;
								}
								if (choice3 == 'Y' || choice3 == 'y')
								{
									cout << "You Smirked and said: To bad, You can't keep up and he was left with " << state4.maxUserOverDrive() << endl;
									Roverdrive = Roverdrive - 3;
									preventextraturn++;
								}
								else
								{
									cout << "ok" << endl;
									Roverdrive--;
								}

							}
							if (state4.HPchecker() == true)
							{
								if (preventextraturn == 0)
								{
									cout << "now please choose to 'A' attack, 1 to Marrage, 2 to do Vanshing drive, 3 to use potion" << endl;
									cin >> choice2;
									while (choice2 != 'A' && choice2 != '1' && choice2 != '2' && choice2 != '3')
									{
										cout << "please make a proper choice " << endl;
										cin >> choice2;
									}
									if (choice2 == 'A' || choice2 == 'a')
									{
										cout << "after attacking his health is now " << state4.HPdecress() << endl;
										if (Roverdrive < 4)
										{
											Roverdrive++;
										}
									}
									else  if (choice2 == '1')
									{
										cout << "You yelled: MIRROR MARAGE,which one is me, can you tell? and you gained " << state4.skill1() << " illusion" << endl;
										if (Roverdrive < 4)
										{
											Roverdrive++;
										}
									}
									else  if (choice2 == '2')
									{
										cout << "You yelled: TOO SLOW" << endl
											<< " the boss has " << state4.skill2() << " health" << endl;
										if (Roverdrive < 4)
										{
											Roverdrive++;
										}
									}
									else  if (choice2 == '3')
									{
										if (potionnumber == 0)
										{
											cout << "No more potions be more wize with your matriel" << endl
												<< "sorry but it looks like you wasted a turn. keep count" << endl;
										}
										else
										{
											cout << "You clamied with relive: Nice, some recovery" << endl;
											cout << "You have " << state4.skill3() << " health" << endl;
											potionnumber--;
											if (Roverdrive < 4)
											{
												Roverdrive++;
											}
										}
									}
								}
								else if (preventextraturn == 1)
								{
									cout << "Now its Bosses turn" << endl;
									preventextraturn--;
								}
							}
						}
					}
				}
			}
		}
	}
	else if (choice == 'q' || choice == 'Q')
	{
		cout << "thank you for playing";
	}
	system("pause");
	return 0;
}
