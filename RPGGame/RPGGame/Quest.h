#pragma once
#ifndef QUEST_H
#define QUEST_H
#include "Creature.h"
#include "Character.h"
#include <string>
class Quest
{

public:
	Quest();
	Quest(std::string user);
	//gets the quest scene info
	int startQuest(int);


private:
	bool Battle(std::string monsterName, int monsterLevel, int monsterAttack, int monsterHealth, int playerAttack, int playerHealth);
	int questNum;
	std::string userName;
	void setUserName(std::string);
	Creature monster = Creature(1, "monster");
	Character user = Character(1, userName);
	//Quest Prototypes
	int getQuest1();
	int getQuest2();
	int getQuest3();
	//ProtoTypes
	int rand(int min, int max); //Random Number Generator
	bool monsterCheck(int); //Simulates checking for monsters


};

#endif

