//Zach Smith
//with group - Katherine Minks, Gabriel Lockner, Matthew Rozendaal, Matthew Kolker (didn't show up first meeting)
//zachswsmith@gmail.com or zssmith@dmacc.edu

// 1/25/17 - 5:00 pm to 6:00 pm
// 1/26/17 - 5:30 pm to 6:30 pm
// 1/31/17 - 8:15 pm to 9:30 pm
// 2/1/17 - 9:30 pm to 10:30 pm

/*
	Matthew Rozendaal
	Got Quest And Main to work together - 30 Minutes
	Learned how to do clear screen easily through this video:
	https://youtu.be/VZ3mqZMtLmY
*/
//This is a text-based Role-Playing game where a player makes a character then goes on a quest, 
//defeating bad guys/monsters on the way.
#include "Character.h"
#include "Creature.h"
#include <ctime>
#include <iostream>
#include <string>
//Class headers
#include "Quest.h"
#include "Creature.h"
#include "Character.h"
using namespace std;

void menu();
int menuSelect();
void startGame(string);
int questMenu();
int randNum();


int main()
{
	const int startGameNum = 1; //number that is Start game
	const int numberOfNames = 5; //number of names in the Names array
	const string gameName = "Game Name"; //string for game name, so that we can easily change the name of the game
	string userName; //user defined name
	int menuNum;
	
	//array that holds the names that can be randomly assigned to a creature vvv
	string Names[numberOfNames] = {"Goblin", "Rat", "Ogre", "Snake", "Dragon"};
	
	cout << "Welcome to " + gameName << endl;
	cout << "Choose what you would like to do:" << endl;
	
	do{
		menuNum = menuSelect(); //calls menu and gets the user's menu selection
		
		if (menuNum == startGameNum) //to start the game
		{
			cout << "Please type your name (followed by the enter key): ";
			cin >> userName;
			startGame(userName);
		}
	} while(menuNum != 2);
	cout << "Thanks for playing!" << endl; //to exit the program
	return 0;
}

////////////////////////////////////////////
//used to create the initial start menu/////
////////////////////////////////////////////
void menu()
{
	cout << "1. Start game" << endl;
	cout << "2. Exit game" << endl;
	cout << "Please enter the number of your choice: " << endl;	
}

//////////////////////////////////////////////////////////
//receives and checks users input for initial start menu//
//////////////////////////////////////////////////////////
int menuSelect()
{
	int menuNum;
	
	menu(); //prints menu
	cin >> menuNum; //user inputs number selection for menu
	
	while (menuNum != 1 && menuNum != 2) //making sure the user number is a valid menu selection
	{
		cout << endl;
		cout << "Invalid selection.  Please choose again: " << endl; //error message if invalid selection
		menu(); //prints menu again
		cin >> menuNum;
	}
	
	return menuNum; //returns their number to the main program
}

//////////////////////////////////////
//starts the storyline for the game///
//////////////////////////////////////
void startGame(string userName)
{
	//Variables
	int questMenuSelection;
	int questCompletion;
	//Class instances
	Quest questSelect;
	Character character(1, userName);
	Creature monster(1, "Monster");
	//Go through this till the user wishes to quit doing quests
	do {
		cout << endl;
		cout << "You've been summoned to the king's throne room. As you enter you hear sobbing.\n The King looks at you and exclaims, 'Oh "<< userName << ", you have to help me! ";
		cout << "Our son is\n missing, my wife hasn't left her room in days and someone has stolen the \n family jewels.'\n 'I just don't know what to do...'" << endl;
		cout << endl;
	
		questMenuSelection = questMenu(); //prints out the quest menu, then receives their checked input
		/*
		1 = fail
		2 = completed
		3 = endless loop
		*/
		if (questMenuSelection == 1)
		{
			system("cls");
			questCompletion = questSelect.startQuest(1);
		}
		else if (questMenuSelection == 2)
		{
			//Clear the Screen
			system("cls");
			//Start Quest
			questCompletion = questSelect.startQuest(2);
		}
		else if (questMenuSelection == 3)
		{
			//Clear Screen of anything before now
			system("cls");
			//Start quest
			questCompletion = questSelect.startQuest(3);
		}
		else if (questMenuSelection == 4)
		{
			//User decides to do nothing with the king
			//We should then have the user leave and 
			//Fight monsters till they die.
			cout << "Good-bye!" << endl;
			system("pause");
			system("cls");
			return;
		}
		else
		{
			cout << "There is an unknown error." << endl;
		}
		/*
		1 = fail
		2 = completed
		*/
		if(questCompletion == 1) //Stop quests
		{
			questMenuSelection =4;
		}
		
	} while(questMenuSelection !=4);
}

////////////////////////////////////////////////////
//creates the quest menu and checks user selection//
////////////////////////////////////////////////////
int questMenu()
{
	int menuNum;

	cout << "Select a response: " << endl;
	cout << "1. I could take a look for you son.  Where last was he seen?" << endl;
	cout << "2. I could find out who took your jewels.  Are there any clues?" << endl;
	cout << "3. I could check on your wife.  Where is her room?" << endl;
	cout << "4. Sorry, I can't help you at this time." << endl;
	cin >> menuNum;

	while (menuNum != 1 && menuNum != 2 && menuNum != 3 && menuNum != 4) //making sure the user number is a valid menu selection
	{
		cout << endl;
		cout << "Invalid selection.  Please choose again: " << endl; //error message if invalid selection
		cout << "1. I could take a look for you son.  Where last was he seen?" << endl;
		cout << "2. I could find out who took your jewels.  Are there any clues?" << endl;
		cout << "3. I could check on your wife.  Where is her room?" << endl;
		cout << "4. Sorry, I can't help you at this time." << endl;
		cin >> menuNum;
	}

	return menuNum;
}
