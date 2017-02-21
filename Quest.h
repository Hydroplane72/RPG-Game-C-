#ifndef QUEST_H
#define QUEST_H
#include <string>
class Quest
{
	private:
		int questNum;	
	public:
		Quest();
		//gets the quest scene info
		int startQuest(int);
		bool Battle(string monsterName,int monsterLevel, int monsterAttack, int monsterHealth, int playerAttack, int playerHealth);
	
};

#endif
