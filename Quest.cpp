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

int getQuest3();

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
		quest = getQuest3();
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

	 //Scene 1 - Mountains

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

	 //Scene 2 - Outside Castle

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
  //Scene 3 - Inside Castle
	//Throne room, Queen�s Quarters, King�s quarters, Sanctuary, Guard Room or Great hall

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
	 //Scene 4 - Exit the Castle

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
	//Scene 5 - Through the Mountains again

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
	
	//Give the jewel to the king
	cout << "The kingdom rejoices as the jewel is returned." << endl;
	cout << "You have completed the Crown Jewel quest." << endl;
	return 2;
}


//Zach Smith
//2/8/2017 - 6pm - 6:30 pm, 9:30 pm - 12:00 am
//2/9/2017 - 4:30 pm - 6:30 pm
//2/15/2017 - 10:30 pm - 11:30 pm
int getQuest3()
{
	int userNum = 0; //variable for user selection during dialogue
	bool flag = false, //generic flag variable
		sceneComplete = false, //flag for whether or not to move on to scene 2 in the 3rd quest
		repeat = false; //used to show if the player has gone back to a certain dialogue area

	////////////////////////////////////////////////
	//////Scene 1 - to the Queen's chambers/////////
	////////////////////////////////////////////////
	do 
	{
		if (repeat == true) //used if this is the not the first time you have talked to the hand maiden
		{
			cout << "'Hello again,' the hand maiden exclaims, 'Did you find your answer?'" << endl;
			flag = false;
		}
		else if (repeat == false && flag == true)
		{
			cout << "What would you like to ask now?" << endl;
			flag = false;
		}
		else //used if this is the first time you have been to the Queen's chambers and talked to the hand maiden
		{
		cout << "The King gives you directions and you head towards the Queen's chambers." << endl;
		cout << "The Queen's hand maiden is sitting on a bench next to the door." << endl;
		cout << "The hand maiden asks, 'Can I help you with something?'" << endl;
		}


		do //gets user's selection for hand maiden dialogue question
		{
			if (flag == true) //used to add an extra cout if the menu is being repeated due to bad selection
			{
				cout << "Invalid selection. Please try again:" << endl;
			}

			if (repeat == false) //ask the hand maiden initial questions
			{
				cout << "1. The King has asked me to check on the Queen." << endl;
				cout << "2. Can you tell me what's wrong with the Queen?" << endl;
				cout << "3. No, Nevermind. (walk back to the King)" << endl;
				cout << "Type the number of your response: " << endl;
			}
			else if (repeat == true)
			{
				cout << "1. I'd like to talk to the queen again." << endl;
				cout << "2. Are you sure you can't tell me what's wrong with the queen?" << endl;
				cout << "3. No, Nevermind. (walk back to the King)" << endl;
				cout << "Type the number of your response: " << endl;
			}

			cin >> userNum;
			flag = true; //flips flag to true so that if the menu repeats, it adds the invalid selection response before printing the menu again
		} while (userNum != 1 && userNum != 2 && userNum != 3);

		////////////////////////////////
		/////Speaking with the Queen////
		////////////////////////////////
		if (userNum == 1) 
		{
			if (repeat == false)
			{
				cout << "Hand maiden says,'She hasn't been up for much talking lately, but you are more than welcome to try.'" << endl;
				cout << "The hand maiden stands up and opens one of the large doors." << endl;
				cout << "You step forward and enter the Queen's chambers. You hear the door shut behind you." << endl;
				cout << "As you enter the dimly lit room, you look around and notice the high, painted ceilings. They depict what you think are Gods feasting and having fun." << endl;
				cout << "While looking around at the extravagent room, you hear soft crying." << endl;
				cout << "The Queen has collapsed in the corner of the room with her head in her hands." << endl;
				cout << "As you approach, the Queen briefly looks up. 'Please, just go away' she whispers." << endl;
			}
			else if (repeat == true)
			{
				cout << "'Be careful,' she says, 'the Queen doesn't like to repeat herself, or people that meddle in her affairs...'" << endl;
				cout << "You open the door and enter the Queen's room again." << endl;
				cout << "The room seems darker now, but you can still make out the silhouette of the Queen in the corner of the room. " << endl;
				cout << "'Come to interogate me again?' she shouts." << endl;
				cout << "In the darkness, you notice a strange glow seemingly coming from her eyes." << endl;
			}
			flag = false; //resets flag to false

			do //gets users input for "go away" response and subsequent "first" responses
			{
				if (flag == true)
				{
					cout << "Invalid selection. Please try again:" << endl;
				}

				if (repeat == false)
				{
					cout << "1. I'm here to help. What's wrong?" << endl;
					cout << "2. The King wants to know if you are okay?" << endl;
					cout << "3. As you wish. I'll let you be. (go back outside the room)" << endl;
					cout << "Type the number of your response: " << endl;
				}
				else if (repeat == true)
				{
					cout << "1. I just want to help, but I can't help if I don't know what's wrong..." << endl;
					cout << "2. I'm just doing what the King asked of me.  He is worried about you." << endl;
					cout << "3. I've made a mistake coming back to disturb you.  I'm sorry. (go back outside the room)" << endl;
					cout << "Type the number of your response : " << endl;
				}
				cin >> userNum;
				flag = true;
			} while (userNum != 1 && userNum != 2 && userNum != 3);

			if (userNum == 1) //I'm here to help. What's wrong?
			{
				if (repeat == false)
				{
					cout << "'Are you a doctor?' she asks. " << "You shake your head 'no'." << endl;
					cout << "'Then are you a shaman?' she asks. " << "Again, you shake your head 'no'." << endl;
					cout << "'Then I don't see how you can fix my problem.' she waves you off" << endl;
					cout << "You take that as your cue to leave, and walk out of the Queen's room." << endl;
					cout << endl;
					sceneComplete = false;
					repeat = true;

					system("pause");
				}
				else if (repeat == true)
				{
					cout << "'I warned you to leave...' as she says this, you notice the glowing eyes seem to be floating." << endl;
					cout << "Suddenly the eyes are right in front of you, and with a terribly loud screech, your life is cut short..." << endl;

					/////////////////
					//need to figure out how to kill the player and exit the main program from here
					////////////////

					return 1;
				}
			}
			else if (userNum == 2) //The King wants to know if you are okay?
			{
				if (repeat == false)//first time through
				{
					cout << "'Tell the King I'm fine. He needn't worry about me,' she waves you off." << endl;
					cout << "You take that as your cue to leave, and walk out of the Queen's room." << endl;
					cout << endl;
					sceneComplete = false;
					repeat = true;

					system("pause");
				}
				else if (repeat == true)//second time through
				{
					cout << "'I warned you to leave...' as she says this, you notice the glowing eyes seem to be floating." << endl;
					cout << "Suddenly the eyes are right in front of you, and with a terribly loud screech, your life is cut short..." << endl;

					///////////////
					//need to figure out how to kill the player and exit the main program from here
					//////////////

					return 1;
				}
			}
			else //leave the queen's room without asking any questions
			{
				cout << "You leave the Queen's room." << endl;
				cout << endl;
				sceneComplete = false;
				repeat = true;

				system("pause");
			}
			flag = false; //resets flag
		}

		////////////////////////////////////////
		/////Speaking with the hand maiden//////
		///////////////////////////////////////
		else if (userNum == 2)
		{
			if (repeat == false) //if you ask the maiden before talking to the queen
			{
				cout << "'It's not really my place to tell. You should talk to the Queen.'" << endl;

				repeat = false;
				flag = true;
			}
			else if (repeat == true) //after you have talked to the queen
			{
				cout << "The hand maiden looks around.  She ushers you in close." << endl;
				cout << "'Look,' she whispers, 'somethings not right with the Queen.  It's like she's possessed or something.'" << endl;
				cout << "'I've heard stories of the Goblin Shamans dealing with things like this.  Maybe you could find one?'" << endl;
				cout << "'The guards might know,' she states matter of factly." << endl << endl;

				cout << "You make your way to the gates of the castle.  There are 2 guards standing idly by." << endl;
				cout << "You ask the guards at the gate for directions.  They mention they have heard of Goblins raiding from deep in the South forest." << endl;
				cout << "As you	exit the castle, you bid them thanks, and head into the forest towards the last known location of the goblin village." << endl;

				sceneComplete = true;
			}
		}
		//////////////////////////////////////////////////////////////
		//////////////////Turning down Queen's quest//////////////////
		//goes back to the King without beginning the queen's quest//
		/////////////////////////////////////////////////////////////
		else 
		{
			cout << "You return to the King." << endl;
			cout << endl;
			return 1; //***Note: not sure how we want to show NOT completing the quest, but not dying
		}
	} while (sceneComplete == false);

	system("pause");
	
	/////////////////////////////////////
	////Scene 2 - Into the Forest////////
	/////////////////////////////////////
	
	sceneComplete = false;
	do
	{
		cout << endl;
		cout << "Your journey takes you deep into the forest.  As you are walking, you notice a sort of trail." << endl;
		cout << "The trail veers a little off to the South East, but looks much easier to travel." << endl;
		
		do
		{
			cout << "What would you like to do? " << endl;
			cout << "1. Keep traveling straight South" << endl;
			cout << "2. Take the path heading South East" << endl;
			cout << "Type the number of your choice: " << endl;
			cin >> userNum;
		} while (userNum != 1 && userNum != 2); //checks user's input to make sure it is a valid response

		/////////////////////////////////////////////////////////////////////////////
		//Keep traveling south, higher chance of fighting, but less fights possible//
		/////////////////////////////////////////////////////////////////////////////
		if (userNum == 1) 
		{
			cout << "You decide to keep traveling south, through the undisturbed forest." << endl;
			cout << "As you get farther from the path, you hear a branch snap..." << endl;
			
			////////////////////////////
			//First Encounter chance////
			////////////////////////////
			if (monsterCheck(6)) //checks to see if a random monster appears
			{
				/////
				/////
				///// add monster fight
				/////
				/////
				cout << "You check yourself over and patch up your wounds." << endl;
			}
			else
			{
				cout << "A deer, startled by your movement, bolts out from the brush, and disappears deeper into the forest.";
			}
			cout << "You continue hiking through the forest, which seems to be getting darker the deeper you go." << endl << endl;

			system("pause");

			///////////////////////////
			//Second Encounter Chance//
			///////////////////////////
			cout << "A clearing opens in front of you.  It is dark, but you notice some ruins." << endl;
			cout << "As you approach the ruins, a shape stands out.  It looks humanoid...but maybe not?  You can't tell..." << endl;
			if (monsterCheck(8))
			{
				/////
				/////
				///// add monster fight
				/////
				/////
				cout << "You bandage yourself up, and take a quick breather." << endl;
			}
			else
			{
				cout << "The shape appears to be a statue of some sort of humanoid beast, left in tact from whatever these ruins used to be." << endl;
				cout << "It poses no threat, but makes you wonder what used to live here..." << endl;
			}
			cout << "You take out your map, and make note of the approximate location of these ruins, for further exploration at a later date." << endl;
			cout << "You proceed out of the clearing, and deeper into the forest." << endl;

			system("pause");

			/////////////////////////
			//Last Encounter Chance//
			/////////////////////////
			cout << "You can hear something in the distance. It sounds like...a village?"<< endl;
			cout << "As you get closer, you can make out voices, although you can't understand them." << endl;

			if (monsterCheck(9))
			{
				cout << "You are almost to the voices when something bursts out in front of you!" << endl;
				/////
				/////
				///// add monster fight
				/////
				/////
				cout << "You take a few moments to recuperate and stop the bleeding." << endl;
			}
			else
			{
				cout << "You step out of the trees, and into what looks like a small village. " << endl;
			}
		}

		////////////////////////////////////////////////////////////////////////////////
		//take the south east path, lower chance of fighting, but more fights possible//
		////////////////////////////////////////////////////////////////////////////////
		else if (userNum == 2)
		{

		}

		else //if userNum is anything other than 1 or 2 after being validated
		{
			cout << "An error has occurred." << endl;
		}

		sceneComplete = true;
	} while (sceneComplete == false);

	system("pause");
	////////////////////////////////////////////
	////Scene 3 - Speaking to the shaman////////
	///////////////////////////////////////////
	sceneComplete = false;
	do
	{

		cout << "Here is scene 3" << endl; //just a test to see if get to scene 3
		sceneComplete = true;
	} while (sceneComplete == false);

	system("pause");

	////////////////////////////////////////
	////Scene 4 - Finding the Herb//////////
	////////////////////////////////////////
	sceneComplete = false;
	do
	{

		cout << "Here is scene 4" << endl; //just a test to see if get to scene 4
		sceneComplete = true;
	} while (sceneComplete == false);

	system("pause");

	////////////////////////////////////////
	////Scene 5 - Healing the Queen/////////
	////////////////////////////////////////
	sceneComplete = false;
	do
	{

		cout << "Here is scene 5" << endl; //just a test to see if get to scene 5
		sceneComplete = true;
	} while (sceneComplete == false);

	system("pause");

	return 2; //should return that quest 3 has been completed
}

