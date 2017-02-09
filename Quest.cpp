/*
This class is the quests class.
It is supposed to Hold info and play the required quests.
Programmed by Matthew Rozendaal: Total time: 6
Structure
getGoal()
getQuest()
getScene()
monsterCheck()
getQuest2()
*/

#include "Quest.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
//ProtoTypes
int rand(int min, int max); //Random Number Generator
std::string getScene(int,int); //gets the quest scene info
bool monsterCheck(int); //Simulates checking for monsters
//Quest Prototypes
//int getQuest1();
int getQuest2(); //quest 2 function
//int getQuest3();

Quest::Quest()
{
}
/**
	Finds the Quest Number then finds the scene within that quest Number
*/
int Quest::startQuest(int questNum)
{
	//return variable
	int quest;
	//If statements to find the correct quest
	if(questNum == 1)
	{
		// quest = getQuest1();
	}
	if (questNum == 2)
	{
		quest = getQuest2();
	}
	if (questNum == 3)
	{
		// quest = getQuest3();
	}
	
	return quest;
}

/**
The same random number generator that Gabriel did
*/
int rand(int min, int max)
{

static bool first = true;
int randNum;

if(first)
	{
		std::srand((unsigned)time(0));
		first = false;
	}

randNum = std::rand() % (max - min) + min;
return randNum;
}
//Makes a chance of a monster showing up
//if the random number is less than the chance 
//number then there is a monster to fight.
bool monsterCheck(int chance)
{
	//get Random number
	int randomNumber = rand(0, 10);
	if(randomNumber < chance) //Check chance for monster
	{
		return true;
	}
	return false;
}

/** Start of Quest Functions
	Each Quest is carried out in the functions
	At the end the quest will return an int that tells the 
	computer if the user failed, completed, or got stuck
	fighting monsters till they die.
	1 = fail
	2 = completed
	3 = endless loop
	
	Output Timing:
	System pauses are to allow the user to just press any 
	key to go to next line of info or task.
	Optional: We could use a sleep timer that makes the computer stop
	for a certain amount of time. This would allow for the user to read without having to click to get the next line
	
*/

//int getQuest1();
int getQuest2()
{
	//variables
	int returnNum;
	
	{ //Scene 1 - Mountains
		
		//Scene 1 - going over the mountain
		cout << "You are trecking over the mountains to get the jewel back." << endl;
		system("pause");
		if(monsterCheck(2)) 
		{
			cout << "A monster has found you!" << endl;
			cout << "You must fight him to continue on" << endl;
			//Start fight function here
			/* TODO (#1#): Add fight function here. */
			
			//Fights return a bool
			//true if dead
			//false if alive
			/*
			if(fightResult) //the User died
			{
				return 1; //the user failed the quest return 1
			}
			
			*/
			cout << "You nurse your injuries as you continue on." << endl;
		}
		cout << "As you continue to walk you see the faint outline of a building." << endl;
		system("pause");
		if(monsterCheck(4)) 
		{
			cout << "A monster has found you!" << endl;
			cout << "You must fight him to continue on" << endl;
			//Start fight function here
			/* TODO (#1#): Add fight function here. */
			
			//Fights return a bool
			//true if dead
			//false if alive
			/*
			if(fightResult) //the User died
			{
				return 1; //the user failed the quest return 1
			}
			
			*/
			cout << "You nurse your injuries as you continue on." << endl;
		}
		cout << "You a closer now and you can now see the building is a castle." << endl;
		if(monsterCheck(6)) 
		{
			cout << "A scout has found you!" << endl;
			cout << "You must fight him to continue on." << endl;
			//Start fight function here
			/* TODO (#1#): Add fight function here. */
			
			//Fights return a bool
			//true if dead
			//false if alive
			/*
			if(fightResult) //the User died
			{
				return 1; //the user failed the quest return 1
			}
			
			*/
			cout << "You nurse your injuries as you continue on." << endl;
		}
		cout << "With a nod you realise that the castle is Gregors Castle." << endl;
		system("pause");
		//Clear the Screen
		system("cls");
	}	
	{ //Scene 2 - Outside Castle
		//variables
		int userIn;
		bool stop = false;
		cout<< "As you creep up on the castle you notice that it is guarded by a monster." << endl;
		cout << "The only two ways are to either dress up like a prostitute for the king " << endl;
		cout << "or fight the monster and try to scale the wall." << endl;
		//do until user enters 1 or 2
		do{
			cout << "Enter 1 to dress up as a prositute or Enter 2 to fight the monster." << endl;
			cin >> userIn;
			if(userIn==1 || userIn==2)
			{
				stop = true;
			}
		}while(!stop);//While not true
		
		if(userIn == 1) //user is a prostitute
		{
			if(monsterCheck(2)) //check on if they will be caught 
			{
				//if rand number is 1 or 2 then the user will fight the monster
				cout<< "The monster didn't believe you (or believed you too well)." << endl;
				//Start fight function here
				/* TODO (#1#): Add fight function here. */
				
				//Fights return a bool
				//true if dead
				//false if alive
				/*
				if(fightResult) //the User died
				{
					return 1; //the user failed the quest return 1
				}
				
				*/
				cout << "After defeating the monster you swim the moat and scale the wall." << endl;
			}
		}
		else //the user decides to fight
		{
			cout << "You charge the monster with sword drawn" << endl;
			//Start fight function here
			/* TODO (#1#): Add fight function here. */
			
			//Fights return a bool
			//true if dead
			//false if alive
			/*
			if(fightResult) //the User died
			{
				return 1; //the user failed the quest return 1
			}
			
			*/
			
		}
		
		cout << "Success!" << endl;
		cout << "You have made it inside the castle" << endl;
		system("pause");
		//Clear the Screen
		system("cls");
	}
	{ //Scene 3 - Inside Castle
	//Throne room, Queen’s Quarters, King’s quarters, Sanctuary, Guard Room or Great hall
	//Let user choose rooms to go into
	//Array of rooms
		string rooms[6] = {"Throne room", "Queens Quarters", "Kings Quarters", "Sanctuary", "Guard Room", "Great Hall"};
		int roomNum = rand(0, 5); //The room with the Jewel in it
		int userIn;	
		do 
		{
			//give choices
			cout << "You have 6 rooms to look in." << endl;
			for(int i = 5; i>=0;i--)
			{
				cout << "[" << i << "]: "<< rooms[i] << endl;
			}
			cout<< "Choose one: ";
			cin >> userIn; //get input
			/* TODO (#1#): Add fight function here. */
			
			//Fights return a bool
			//true if dead
			//false if alive
			/*
			if(fightResult) //the User died
			{
				return 1; //the user failed the quest return 1
			}
			
			*/
		} while(userIn != roomNum); //if user input does not = room number
		//out put result
		cout << "As you walk into the " << rooms[roomNum] << ".";
		cout << "You see the jewel and its guardian. The guardian is sleeping." << endl;
		system("pause");
		if(monsterCheck(5)) //Should be 50/50 chance
		{
			cout<< "The Guardian has Awoken!" << endl;
			/* TODO (#1#): Add fight function here. */
			
			//Fights return a bool
			//true if dead
			//false if alive
			/*
			if(fightResult) //the User died
			{
				return 1; //the user failed the quest return 1
			}
			
			*/
			cout << " Congrats you have defeated the guardian" << endl;
		}else
		{
			cout <<"Quietly you steal the jewel back." << endl;
		}
		system("pause");
		//Clear the Screen
		system("cls");
	}
	{ //Scene 4 - Exit the Castle
		/*
		Scene 4: Once the stone is found, exit the castle (and fight the monster again) without being detected.
		*/
		cout<< "Stealthily you start to make your way out of the castle." << endl;
		if(monsterCheck(6)) //check on if they will be caught 
		{
			
			cout << "You have been found!" << endl;
			//Start fight function here
			/* TODO (#1#): Add fight function here. */
			
			//Fights return a bool
			//true if dead
			//false if alive
			/*
			if(fightResult) //the User died
			{
				return 1; //the user failed the quest return 1
			}
			
			*/
			cout << "Slowly you continue onwards through the dungeons" << endl;
			system("pause");
		}
		
		cout << "You have made it to the front gates but there is a new guard there!" << endl;
		cout << "Fight him quickly and escape!" << endl;
		//fight the guard
		/* TODO (#1#): Add fight function here. */
		
		//Fights return a bool
		//true if dead
		//false if alive
		/*
		if(fightResult) //the User died
		{
			return 1; //the user failed the quest return 1
		}
		
		*/
		cout << "You have defeated the monster and escape to the mountains." << endl;
		system("pause");
		//Clear the Screen
		system("cls");
	}
	{ //Scene 5 - Through the Mountains again
		cout << "The trees blur by as you race to get away from the castle of monsters." << endl;
		if(monsterCheck(8)) 
		{
			cout << "One of the monsters from the castle has caught up to you!" << endl;
			//Start fight function here
			/* TODO (#1#): Add fight function here. */
			
			//Fights return a bool
			//true if dead
			//false if alive
			/*
			if(fightResult) //the User died
			{
				return 1; //the user failed the quest return 1
			}
			
			*/
			cout << "The path ahead is getting harder with your wounds." << endl;
			system("pause");
		}
		cout << "The castle is getting smaller as you run. The mountains are looming over you." << endl;
		if(monsterCheck(4)) 
		{
			cout << "A monster thinks of you as easy pickings!" << endl;
			cout << "Show him the error of his ways" << endl;
			//Start fight function here
			/* TODO (#1#): Add fight function here. */
			
			//Fights return a bool
			//true if dead
			//false if alive
			/*
			if(fightResult) //the User died
			{
				return 1; //the user failed the quest return 1
			}
			
			*/
			cout << "The monsters death may have alerted others to your position.\nYou continue on quickly." << endl;
			system("pause");
		}
		cout << "The winds are howling and you can hear the monsters still chasing you in the mountains." << endl;
		if(monsterCheck(6)) 
		{
			cout << "A monster has caught your scent and found you." << endl;
			//Start fight function here
			/* TODO (#1#): Add fight function here. */
			
			//Fights return a bool
			//true if dead
			//false if alive
			/*
			if(fightResult) //the User died
			{
				return 1; //the user failed the quest return 1
			}
			
			*/
			cout << "The monsters death may have alerted others to your position. You continue on quickly." << endl;
			system("pause");
		}
		cout << "You can see the kings castle in the distance. You laugh in delight as" << endl << 
		"you start on your way to the castle." << endl;
		if(monsterCheck(2)) 
		{
		cout << "A monster went ahead of you and planned an ambush." << endl;
		//Start fight function here
		/* TODO (#1#): Add fight function here. */
		
		//Fights return a bool
		//true if dead
		//false if alive
		/*
		if(fightResult) //the User died
		{
			return 1; //the user failed the quest return 1
		}
		
		*/
		cout << "The kings guard is on its way." << endl;
		system("pause");
		//Clear the Screen
		system("cls");
		}
	}
	//Give the jewel to the king
	cout << "The kingdom rejoices as the jewel is returned." << endl;
	cout << "You have completed the Crown Jewel quest." << endl;
	return 2;
}
//int getQuest3();

