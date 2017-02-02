#ifndef QUEST_H
#define QUEST_H
#include <string>
class Quest
{
	private:
		int questNum;	
	public:
		Quest();
		//gets the quest goal information
		std::string getGoal(int);
		//gets the quest scene info
		static int startQuest(int);
	
};

#endif
