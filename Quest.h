#ifndef QUEST_H
#define QUEST_H
#include <string>
class Quest
{
	private:
		int questNum;
		//ProtoTypes
		int rand(int min, int max); //Random Number Generator
		std::string getScene(int,int); //gets the quest scene info
		bool monsterCheck(int); //Simulates checking for monsters
		

	public:
		Quest();
		//gets the quest scene info
		int startQuest(int);
		bool Battle(std::string monsterName,int monsterLevel, int monsterAttack, int monsterHealth, int playerAttack, int playerHealth);
		
};

#endif
