/*
This class is the quests class.
It is supposed to Hold info and play the required quests.
Programmed by Matthew Rozendaal: Total time: 9
getQuest()
getScene()
monsterCheck()
getQuest2()

Intigrated All the classes and quests. Got them to work together.
Intigrated Items:
Creature
Main
Character
Quest 1
Quest 3
Battle function
*/

#include "Quest.h"
#include "Creature.h"
#include "Character.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
using namespace std;


Quest::Quest()
{
}

Quest::Quest(std::string user)
{
	setUserName(user);
}

/**
Finds the Quest Number then finds the scene within that quest Number
*/
int Quest::startQuest(int questNum)
{
	//return variable
	int quest =0;
	//If statements to find the correct quest
	if (questNum == 1)
	{
		quest = getQuest1();
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
void Quest::setUserName(std::string user)
{
	userName = user;
}

/**
The same random number generator that Gabriel did
*/
int Quest::rand(int min, int max)
{

	static bool first = true;
	int randNum;

	if (first)
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
bool Quest::monsterCheck(int chance)
{
	//get Random number
	int randomNumber = rand(0, 10);
	if (randomNumber < chance) //Check chance for monster
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

Output Timing:
System pauses are to allow the user to just press any
key to go to next line of info or task.
Optional: We could use a sleep timer that makes the computer stop
for a certain amount of time. This would allow for the user to read without having to click to get the next line

*/
/**
Quest 1 Created by Katherine A
*/
int Quest::getQuest1()
{

	int response1; //for user input
	bool fightResult;
	bool responseCorrect = false; //if user response is wrong
	do //input check
	{
		cout << "I got word that he was seen traveling through the forest with a bunch of other children,but that could have just been a pesant looking to collect their reward. " << endl;
		cout << "With that you heard out to the forest in hopes of finding the boy." << endl;
		cout << "Shortly after beiginning your journey into the forest, you come upon a young woman all alone in the woods." << endl;
		cout << "Select a response:" << endl;
		cout << "1. Greet her (ask her name) and ask her if she has heard anything about a group of children being escorted through the forest" << endl;
		cout << "2. Continue on your way without acknowledging her." << endl;
		cin >> response1;
		if (response1 == 1 || response1 == 2)
		{
			responseCorrect = true;
		}
	} while (!responseCorrect);
	system("cls");

	if (response1 == 1)
	{
		do //input check
		{
			cout << "I am Anias.  I did hear that the organized crime group in the next shire over was doing something with children.  I'm not entirely sure what, but I do know someone who could give us more information." << endl;
			cout << "Please select one of the following options:" << endl;
			cout << "1. You decide you don't like Anias's idea and stay in the forest." << endl;
			cout << "2. You decide to follow Anias's lead." << endl;
			cin >> response1;
			if (response1 == 1 || response1 == 2)
			{
				responseCorrect = true;
			}
		} while (!responseCorrect);
		system("cls");
		if (response1 == 2)
		{
			do //input check
			{
				cout << "You and Anias travel to the next shire and enter the pub in hopes of making contact with Anias's lead.  You order a drink at the bar and take a seat after noticing that Anias is nowhere to be found." << endl;
				cout << "A bar maid walks over and says, you have been summoned.  Please follow me." << endl;
				cout << "you do one of the following: " << endl;
				cout << "1. Follow the bar maid" << endl;
				cout << "2. You tell the bar maid that you are just fine where you are and stay put." << endl;
				cin >> response1;
				if (response1 == 1 || response1 == 2)
				{
					responseCorrect = true;
				}
			} while (!responseCorrect);
			system("cls");

			if (response1 == 1)
			{
				do//input check
				{
					cout << "You are taken into a smoke filled back room.  A Goblin by the name of Ted invites you to sit down" << endl;
					cout << "Wher is Anias? you ask.  She has been stored for the moment, just in case you don't check out, Ted responds folding his hands." << endl;
					cout << "I'm not here to expose your operation.  I am only here to find a boy.  He has dark hair and green eyes." << endl;
					cout << "I may have knowledge of such a boy.  What would you want with such a boy asks Ted." << endl;
					cout << "Select one of the following responses: " << endl;
					cout << "1. I am looking to do with a boy what I wish.  That should not concern you." << endl;
					cout << "2. I am looking for the prince.  It is imparative that I return him to his royal highness at once." << endl;
					cin >> response1;
					if (response1 == 1 || response1 == 2)
					{
						responseCorrect = true;
					}
				} while (!responseCorrect);
				system("cls");

				if (response1 = 1)
				{
					cout << "Very well, Ted responds. Bring six silver shillings to the cavern of the unknown tommorow at twilight." << endl;
					cout << "Anias is then released from a near by room.  The two of you leave the bar and find an inn to stay in for the night." << endl;
					cout << "  Hey Anias, do you have any money on you?, you ask.  Not a cent, she responds.  You shake your purse with the remaining 4 shillings you have and pay 1 shilling for room and board for the two of you." << endl;
					cout << "At dusk the next day you head to the cavern of the unknown.  It is especially dark as it is twilight." << endl;
					cout << "Shows up with a chain gang of young boys.  Select the one that suits your tastes, prompts the ogre:" << endl;
					cout << "You look at all of the boys thouroughly and find the prince by the birthmark on his hand.  I will have this one, you tell the ogre." << endl;
					cout << "That will be 10 Silver Shillings, says the Ogre.  I thought it would be six, you argue.  Either way, I suppose it was bound to end this way, you say as you draw your sword." << endl;

					// fight scene
					fightResult = Battle("Ogre");

					if (!fightResult) //the User died
					{
						return 1; //the user failed the quest return 1
					}
					monster.levelUp(); //Level up the monsters
					user.levelUp();//Level up the user
				}
				else if (response1 == 2)
				{
					cout << "I suppose that's the way it is, the goblin said as Anias is taken out of the closet and both of you have your throats cut." << endl;
					return 2; //you failed
				}
			}
		}
		else if (response1 == 1) //end quest
		{
			cout << "You continue to wander in the forest fail the quest." << endl;

			return 1;
		}
	}
	else if (response1 == 2)	//fight endless
	{
		cout << "You continue to wander in the forest and fail the quest." << endl;

		return 1;
	}

	cout << "Congrats you completed quest 1!" << endl;
	system("pause");
	return 2;
}
int Quest::getQuest2()
{
	//variables
	int returnNum;
	bool fightResult;

	//Scene 1 - Mountains

	//Scene 1 - going over the mountain
	cout << "You are trecking over the mountains to get the jewel back." << endl;
	system("pause");
	if (Quest::monsterCheck(2))
	{
		cout << "A monster has found you!" << endl;
		cout << "You must fight him to continue on" << endl;

		fightResult = Battle("Wolf");

		if (!fightResult) //the User died
		{
			return 1; //the user failed the quest return 1
		}
		monster.levelUp(); //Level up the monsters
		user.levelUp();//Level up the user

		cout << "You nurse your injuries as you continue on." << endl;
	}
	cout << "As you continue to walk you see the faint outline of a building." << endl;
	system("pause");
	if (monsterCheck(4))
	{
		cout << "A monster has found you!" << endl;
		cout << "You must fight him to continue on" << endl;

		fightResult = Battle("Orc");

		if (!fightResult) //the User died
		{
			return 1; //the user failed the quest return 1
		}
		monster.levelUp(); //Level up the monsters
		user.levelUp();//Level up the user
		cout << "You nurse your injuries as you continue on." << endl;
	}
	cout << "You a closer now and you can now see the building is a castle." << endl;
	if (monsterCheck(6))
	{
		cout << "A scout has found you!" << endl;
		cout << "You must fight him to continue on." << endl;

		fightResult = Battle("Scout");

		if (!fightResult) //the User died
		{
			return 1; //the user failed the quest return 1
		}
		monster.levelUp(); //Level up the monsters
		user.levelUp();//Level up the user
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
	cout << "As you creep up on the castle you notice that it is guarded by a monster." << endl;
	cout << "The only two ways are to either dress up like a prostitute for the king " << endl;
	cout << "or fight the monster and try to scale the wall." << endl;
	//do until user enters 1 or 2
	do {
		cout << "Enter 1 to dress up as a prositute or Enter 2 to fight the monster." << endl;
		cin >> userIn;
		if (userIn == 1 || userIn == 2)
		{
			stop = true;
		}
	} while (!stop);//While not true

	if (userIn == 1) //user is a prostitute
	{
		if (monsterCheck(2)) //check on if they will be caught 
		{
			//if rand number is 1 or 2 then the user will fight the monster
			cout << "The monster didn't believe you (or believed you too well)." << endl;

			fightResult = Battle("Monster");

			if (!fightResult) //the User died
			{
				return 1; //the user failed the quest return 1
			}
			monster.levelUp(); //Level up the monsters
			user.levelUp();//Level up the user
			cout << "After defeating the monster you swim the moat and scale the wall." << endl;
		}
	}
	else //the user decides to fight
	{
		cout << "You charge the monster with sword drawn" << endl;

		fightResult = Battle("Monster");

		if (!fightResult) //the User died
		{
			return 1; //the user failed the quest return 1
		}
		monster.levelUp(); //Level up the monsters
		user.levelUp();//Level up the user

	}

	cout << "Success!" << endl;
	cout << "You have made it inside the castle" << endl;

	system("pause");
	//Clear the Screen
	system("cls");
	//Scene 3 - Inside Castle
	//Throne room, Queen?s Quarters, King?s quarters, Sanctuary, Guard Room or Great hall

	//Let user choose rooms to go into
	//Array of rooms
	string rooms[6] = { "Throne room", "Queens Quarters", "Kings Quarters", "Sanctuary", "Guard Room", "Great Hall" };
	int roomNum = rand(0, 5); //The room with the Jewel in it
	do
	{
		//give choices
		cout << "You have 6 rooms to look in." << endl;
		for (int i = 5; i >= 0; i--)
		{
			cout << "[" << i << "]: " << rooms[i] << endl;
		}
		cout << "Choose one: ";
		cin >> userIn; //get input

		fightResult = Battle("monster");

		if (!fightResult) //the User died
		{
			return 1; //the user failed the quest return 1
		}
		monster.levelUp(); //Level up the monsters
		user.levelUp();//Level up the user
	} while (userIn != roomNum); //if user input does not = room number
								 //out put result
	cout << "As you walk into the " << rooms[roomNum] << ".";
	cout << "You see the jewel and its guardian. The guardian is sleeping." << endl;
	system("pause");
	if (monsterCheck(5)) //Should be 50/50 chance
	{
		cout << "The Guardian has Awoken!" << endl;

		fightResult = Battle("Guardian");

		if (!fightResult) //the User died
		{
			return 1; //the user failed the quest return 1
		}
		monster.levelUp(); //Level up the monsters
		user.levelUp();//Level up the user
		cout << " Congrats you have defeated the guardian" << endl;
	}
	else
	{
		cout << "Quietly you steal the jewel back." << endl;
	}

	system("pause");
	//Clear the Screen
	system("cls");
	//Scene 4 - Exit the Castle

	/*
	Scene 4: Once the stone is found, exit the castle (and fight the monster again) without being detected.
	*/
	cout << "Stealthily you start to make your way out of the castle." << endl;
	if (monsterCheck(6)) //check on if they will be caught 
	{

		cout << "You have been found!" << endl;

		fightResult = Battle("Monster Guard");

		if (!fightResult) //the User died
		{
			return 1; //the user failed the quest return 1
		}
		monster.levelUp(); //Level up the monsters
		user.levelUp();//Level up the user
		cout << "Slowly you continue onwards through the dungeons" << endl;
		system("pause");
	}

	cout << "You have made it to the front gates but there is a new guard there!" << endl;
	cout << "Fight him quickly and escape!" << endl;
	//fight the guard

	fightResult = Battle("Guard");
	if (!fightResult) //the User died
	{
		return 1; //the user failed the quest return 1
	}
	monster.levelUp(); //Level up the monsters
	user.levelUp();//Level up the user
	cout << "You have defeated the monster and escape to the mountains." << endl;
	system("pause");

	//Clear the Screen
	//system("cls");
	//Scene 5 - Through the Mountains again

	cout << "The trees blur by as you race to get away from the castle of monsters." << endl;
	if (monsterCheck(8))
	{
		cout << "One of the monsters from the castle has caught up to you!" << endl;

		fightResult = Battle("Monster pursuer");

		if (!fightResult) //the User died
		{
			return 1; //the user failed the quest return 1
		}
		monster.levelUp(); //Level up the monsters
		user.levelUp();//Level up the user
		cout << "The path ahead is getting harder with your wounds." << endl;
		system("pause");
	}
	cout << "The castle is getting smaller as you run. The mountains are looming over you." << endl;
	if (monsterCheck(4))
	{
		cout << "A monster thinks of you as easy pickings!" << endl;
		cout << "Show him the error of his ways" << endl;

		fightResult = Battle("Hungry monster");

		if (!fightResult) //the User died
		{
			return 1; //the user failed the quest return 1
		}
		monster.levelUp(); //Level up the monsters
		user.levelUp();//Level up the user
		cout << "The monsters death may have alerted others to your position.\nYou continue on quickly." << endl;
		system("pause");
	}
	cout << "The winds are howling and you can hear the monsters still chasing you in the mountains." << endl;
	if (monsterCheck(6))
	{
		cout << "A monster has caught your scent and found you." << endl;

		fightResult = Battle("Hungry Monster");

		if (!fightResult) //the User died
		{
			return 1; //the user failed the quest return 1
		}
		monster.levelUp(); //Level up the monsters
		user.levelUp();//Level up the user
		cout << "The monsters death may have alerted others to your position. You continue on quickly." << endl;
		//system("pause");
	}
	cout << "You can see the kings castle in the distance. You laugh in delight as" << endl <<
		"you start on your way to the castle." << endl;
	if (monsterCheck(2))
	{
		cout << "A monster went ahead of you and planned an ambush." << endl;

		fightResult = Battle("Monster");

		if (!fightResult) //the User died
		{
			return 1; //the user failed the quest return 1
		}
		monster.levelUp(); //Level up the monsters
		user.levelUp();//Level up the user
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
//2/16/2017 - 5:00 pm - 7:00 pm
//2/19/2017 - 7:00 pm - 7:30 pm, 9:30 pm - 12:45 am
int Quest::getQuest3()
{
	int userNum = 0; //variable for user selection during dialogue
	bool flag = false; //generic flag variable
	bool fightResult = false;
	bool sceneComplete = false; //flag for whether or not to move on to scene 2 in the 3rd quest
	bool repeat = false; //used to show if the player has gone back to a certain dialogue area

						 ////////////////////////////////////////////////
						 //////Scene 1 - to the Queen's chambers/////////
						 ////////////////i////////////////////////////////
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
			fightResult = Battle("monster");

			if (!fightResult) //the User died
			{
				return 1; //the user failed the quest return 1
			}
			monster.levelUp(); //Level up the monsters
			user.levelUp();//Level up the user
			cout << "You check yourself over and patch up your wounds." << endl;
		}
		else
		{
			cout << "A deer, startled by your movement, bolts out from the brush, and disappears deeper into the forest.";
		}
		cout << "You continue hiking through the forest, which seems to be getting darker the deeper you go." << endl << endl;

		//system("pause");

		///////////////////////////
		//Second Encounter Chance//
		///////////////////////////
		cout << "A clearing opens in front of you.  It is dark, but you notice some ruins." << endl;
		cout << "As you approach the ruins, a shape stands out.  It looks humanoid...but maybe not?  You can't tell..." << endl;
		if (monsterCheck(8))
		{
			fightResult = Battle("Half Orc-Human");

			if (!fightResult) //the User died
			{
				return 1; //the user failed the quest return 1
			}
			monster.levelUp(); //Level up the monsters
			user.levelUp();//Level up the user
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
		cout << "You can hear something in the distance. It sounds like...a village?" << endl;
		cout << "As you get closer, you can make out voices, although you can't understand them." << endl;

		if (monsterCheck(9))
		{
			cout << "You are almost to the voices when something bursts out in front of you!" << endl;

			fightResult = Battle("Unknown Attacker");

			if (!fightResult) //the User died
			{
				return 1; //the user failed the quest return 1
			}
			monster.levelUp(); //Level up the monsters
			user.levelUp();//Level up the user
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
		////////////////////////////
		//First Encounter chance////
		////////////////////////////

		cout << "You decide to venture down the path that seems to be traveled fairly regularly." << endl;
		cout << "As you get a little ways along the path, you hear a branch snap..." << endl;
		if (monsterCheck(3)) //checks to see if a random monster appears
		{
			fightResult = Battle("monster");

			if (!fightResult) //the User died
			{
				return 1; //the user failed the quest return 1
			}
			monster.levelUp(); //Level up the monsters
			user.levelUp();//Level up the user
			cout << "You check yourself over and patch up your wounds." << endl;
		}
		else
		{
			cout << "A deer, startled by your movement, bolts across the path, and disappears into the forest." << endl;
		}
		cout << "You continue on the path, which winds around a bend." << endl << endl;

		system("pause");

		///////////////////////////
		//Second Encounter Chance//
		///////////////////////////
		cout << "The path exits into a clearing.  It is dark, but you notice some ruins." << endl;
		cout << "As you approach the ruins, a shape stands out.  It looks humanoid...but maybe not?  You can't tell..." << endl;
		if (monsterCheck(4))
		{
			fightResult = Battle("Hooded Attacker");

			if (!fightResult) //the User died
			{
				return 1; //the user failed the quest return 1
			}
			monster.levelUp(); //Level up the monsters
			user.levelUp();//Level up the user
			cout << "You bandage yourself up, and take a quick breather." << endl;
		}
		else
		{
			cout << "The shape appears to be a statue of some sort of humanoid beast, left in tact from whatever these ruins used to be." << endl;
			cout << "It poses no threat, but makes you wonder what used to live here..." << endl;
		}
		cout << "You take out your map, and make note of the approximate location of these ruins, for further exploration at a later date." << endl;
		cout << "You find the path again and proceed out of the clearing, deeper into the forest." << endl;

		system("pause");

		///////////////////////////
		//Third Encounter Chance//
		///////////////////////////
		cout << "As you venture deeper, you notice a strange silence." << endl;
		if (monsterCheck(6))
		{
			fightResult = Battle("monster");

			if (!fightResult) //the User died
			{
				return 1; //the user failed the quest return 1
			}
			monster.levelUp(); //Level up the monsters
			user.levelUp();//Level up the user
			cout << "You rub some dirt on your wounds and hope for the best." << endl;
		}
		else
		{
			cout << "The silence is unnerving, but only a psychological threat." << endl;
		}
		cout << "You notice a small hut up ahead." << endl;

		system("pause");

		///////////////////////////
		//Fourth Encounter Chance//
		///////////////////////////
		cout << "You cautiously approach the hut.  There are no obvious signs of life." << endl;
		cout << "You slowly crack the door open." << endl;
		if (monsterCheck(8))
		{
			fightResult = Battle("Killer");

			if (!fightResult) //the User died
			{
				return 1; //the user failed the quest return 1
			}monster.levelUp(); //Level up the monsters
			user.levelUp();//Level up the user
			cout << "Is that your blood....or its...you dont know, but you wipe if off none the less." << endl;
		}
		else
		{
			cout << "The hut looks as if it has been ransacked by bandits." << endl;
			cout << "The only thing left of note is a mangled skeleton." << endl;
		}

		system("pause");

		/////////////////////////
		//Last Encounter Chance//
		/////////////////////////
		cout << "You can hear something in the distance. It sounds like...a village?" << endl;
		cout << "As you get closer, you can make out voices, although you can't understand them." << endl;

		if (monsterCheck(9))
		{
			cout << "You are almost to the voices when something bursts out in front of you!" << endl;
			fightResult = Battle("Look out");

			if (!fightResult) //the User died
			{
				return 1; //the user failed the quest return 1
			}
			monster.levelUp(); //Level up the monsters
			user.levelUp();//Level up the user
			cout << "You take a few moments to recuperate and stop the bleeding." << endl;
		}
		else
		{
			cout << "You step out of the trees, and into what looks like a small village. " << endl;
		}
	}
	////////////////////////////////////////////
	////Scene 3 - Speaking to the shaman////////
	///////////////////////////////////////////
	cout << "As you enter the village, you notice that it is very quiet." << endl;
	cout << "You look around and notice that things have been left lying around on the ground, like the people left in a hurry." << endl;
	cout << "There seems to be a larger hut in the middle.  As you approach it, you hear footsteps behind you..." << endl;
	cout << endl;
	cout << "A number of Goblins have come out of hiding and have surrounded you.  They are all armed, but looked scared." << endl;
	cout << "One of the Goblins steps forward, 'Who are you and why have you entered our village?'" << endl;
	cout << endl;
	cout << "'I am just a servant of the King to the North, come looking for the Great Goblin Shaman of this village. I mean you no harm.'" << endl;
	system("pause");

	cout << "The door of the large hut opens slowly. An old Goblin steps out, clad in ceremonial garb." << endl;
	cout << "'I am who you seek,' the Goblin says, 'how can I help you, Sur Vant?" << endl;

	flag = false; //resets flag for next response
	do  //asks user for a response to the question, does not actually change anything the goblin will say, just trying to keep the player from reading too much without interaction
	{
		if (flag == true)
		{
			cout << "Invalid input, please try again..." << endl;
		}
		cout << "1. The Queen is sick, and doesn't seem like herself..." << endl;
		cout << "2. I've heard you know a bit about possessions..." << endl;
		cout << "3. A friend of mine is possessed and I'd like your help." << endl;
		cin >> userNum;
		flag = true;
	} while (userNum != 1 && userNum != 2 && userNum != 3); //checks user's input to make sure it is a valid response

	cout << "'Possession...that's a tricky one,' he scratches his chin and contemplates." << endl;
	cout << "He abruptly shuffles back into his hut.  After a few moments he returns with an old book." << endl;
	cout << "The book looks as if it has been around for ages..." << endl;
	cout << "'I may know of a cure, but only one who has shown their might can receive knowledge from our sacred tomes.'" << endl;
	cout << "He shouts, 'Bring out Fliggurt!'" << endl;
	cout << endl;
	system("pause");

	cout << "You hear something rolling your way.  Around one of the huts comes a wheeled cage, being pushed by a number of Goblins." << endl;
	cout << "'Behold, this is FLiggurt!' the Shaman exclaims. 'If you can best him, I will share our secret...'" << endl;
	cout << "One of the Goblins steps around and unlocks the door to the cage. With a squeak, the door opens and a blur shoots towards you..." << endl;

	fightResult = Battle("Goblin Champion");

	if (!fightResult) //the User died
	{
		return 1; //the user failed the quest return 1
	}
	monster.levelUp(); //Level up the monsters
	user.levelUp();//Level up the user

	cout << "Before the final blow is struck, the Shaman yells, 'Stop! I've seen enough...'" << endl;
	cout << "The Shaman hurriedly walks over to the body of Fliggurt." << endl;
	cout << "He whispers something and you see the body of Fliggurt begin to glow." << endl;
	cout << "His wounds begin to heal, and he begins to breath again." << endl;
	cout << endl;
	system("pause");

	cout << "The Shaman turns back to you, 'so now that we have settled that...'" << endl;
	cout << "'The remedy is actually pretty easy.  You just need to find the Bloodroot.'" << endl;
	cout << "'It looks like this,' he shows you a drawing from the book." << endl;
	cout << "'Once you have that, you just make it into a tea and make the possessed drink it,' the Shaman recites." << endl;
	cout << "'I've seen the roots around this forest.  Go find some and help your friend!'" << endl;
	cout << "You thank the Goblins and head back out into the forest to find the Bloodroot." << endl;

	cout << endl;
	system("pause");

	////////////////////////////////////////
	////Scene 4 - Finding the Herb//////////
	////////////////////////////////////////
	sceneComplete = false;  //reset bool to false and use for when root is found

	int herbChance = 2; //using as a percentage to find the Bloodroot herb

	cout << "You stumble around looking for the Bloodroot in the forest." << endl;

	do // loop for finding the Bloodroot
	{

		if (monsterCheck(10 - herbChance)) // using the monster check to either find the herb, or fight a monster
		{
			cout << "You didn't find the herb...but you did find something else." << endl;
			/////
			/////
			///// add monster fight
			/////
			/////
			cout << "You take a few moments to recuperate and stop the bleeding." << endl;
			cout << endl;
			herbChance = herbChance + 2; //increases each subsequent chance of finding the root

			cout << "You continue forward, looking for the Bloodroot" << endl;
		}
		else
		{
			cout << "You found it! You dig up the Bloodroot, and head off back towards the castle." << endl;
			sceneComplete = true;
		}
	} while (sceneComplete == false);

	cout << endl;
	system("pause");
	////////////////////////////////////////
	////Scene 5 - Healing the Queen/////////
	////////////////////////////////////////
	cout << "As you enter the castle, you notice something is different." << endl;
	cout << "Everything is darker...all of the candles are out, and there is a cold breeze coming down the hall." << endl;
	cout << "You head towards the kitchen to make the Bloodroot into a tea." << endl;
	cout << "As you approach the kitchen, something emerges from the shadows..." << endl;

	fightResult = Battle("Cook");

	if (!fightResult) //the User died
	{
		return 1; //the user failed the quest return 1
	}
	monster.levelUp(); //Level up the monsters
	user.levelUp();//Level up the user
	cout << endl;
	system("pause");

	cout << "'Is it safe now?' a feminine voice calls from the kitchen." << endl;
	cout << "'Yes,' you reply.  The Queen's handmaiden emerges from the kitchens." << endl;
	cout << "'Oh, hey, it's you! Things kind of went downhill after you left.'" << endl;
	cout << "'Creatures started coming out of the Queen's chambers. I ran to find help, but everyone seems to be missing.'" << endl;
	cout << "'Then something attacked me, but I was able to get in here and hide.'" << endl;
	cout << "'Were you able to find the Shamans and a cure?' she asks." << endl;

	flag = false; //resets flag for next response
	do  //another conversation answer that doesn't really change much, just trying to keep the player from reading too much without any interaction
	{
		if (flag == true)
		{
			cout << "Invalid input, please try again..." << endl;
		}
		cout << "1. Do you know how to make Bloodroot tea?" << endl;
		cout << "2. That depends...what's in it for me?" << endl;
		cout << "3. Here is a Bloodroot. We need to make it into tea and have the Queen drink it." << endl;
		cin >> userNum;
		flag = true;
	} while (userNum != 1 && userNum != 2 && userNum != 3); //checks user's input to make sure it is a valid response

	if (userNum == 1 || userNum == 3)
	{
		cout << "'I've never made Bloodroot tea, but I've made regular tea...so hopefully its the same concept,' she replies." << endl;
	}
	else if (userNum == 2)
	{
		cout << "'I really don't think this is the time for that...if we get out of here alive I'm sure you can ask the King and Queen for something.'" << endl;
		cout << "'Fine,' you acknowledge that this probably wasn't the best time for that." << endl;
		cout << "'We need to make this into a tea,' you fully explain the remedy to her. " << endl;
		cout << "'Easy peasy,' she says." << endl;
	}

	cout << "'Guard the door while I take care of this,' she says." << endl;
	cout << "'No matter what happens, keep making the tea,' you tell her." << endl;
	cout << "Just then, the door bursts open..." << endl;

	fightResult = Battle("monster");

	if (!fightResult) //the User died
	{
		return 1; //the user failed the quest return 1
	}
	monster.levelUp(); //Level up the monsters
	user.levelUp();//Level up the user
	cout << endl;
	system("pause");

	cout << "'That was a close one,' the handmaiden looks relieved." << endl;
	cout << "'The tea is done though!' she exclaims." << endl;
	cout << "'How about I stay here, and you can give the tea to the Queen,' she smiles." << endl;
	cout << "You nod, grab the tea from the handmaiden and set off towards the Queen's chambers again." << endl;

	cout << endl;
	cout << "As you approach the Queen's room, you notice a figure at the door. " << endl;
	cout << "You set the tea down in anticipation of what will happen next..." << endl;

	fightResult = Battle("Assassin");

	if (!fightResult) //the User died
	{
		return 1; //the user failed the quest return 1
	}
	monster.levelUp(); //Level up the monsters
	user.levelUp();//Level up the user
	cout << endl;
	system("pause");

	cout << "Its body slumps to the floor. You take a second to collect yourself and the tea." << endl;
	cout << "You kick open the door to the Queen's chamber." << endl;
	cout << "The Queen is laying in the middle of the room, surrounded by the bones of what appear to be a number of castle guards." << endl;
	cout << "'Back again?' she shouts,'You won't leave this time...'" << endl;
	cout << "The queen transforms into some sort of creature, and charges at you." << endl;

	fightResult = Battle("Monstrous Queen");

	if (!fightResult) //the User died
	{
		return 1; //the user failed the quest return 1
	}
	monster.levelUp(); //Level up the monsters
	user.levelUp();//Level up the user
	cout << endl;
	system("pause");

	cout << "Upon defeat, the Queen's body collapses to the ground; returned to normal shape at least." << endl;
	cout << "You notice that, luckily, the cup of tea remained upright and is sitting close by." << endl;
	cout << "The cup is still warm.  You pick it up and pour it into the Queen's agape mouth." << endl;
	cout << "Immediately, the room brightens, and the Queen's skin regains its color." << endl;
	cout << "Her eyes open slowly...'Thank you...' she stammers." << endl;
	cout << "'For the last number of weeks I have been a slave in my own body; aware of everything, but unable to do anything." << endl;
	cout << "You help her sit up against her bed." << endl;
	cout << "'If there is ever anything I can do to repay you...please, please....let me know'" << endl;
	cout << "You leave the Queen to rest, and head back to the throne room to visit with the king" << endl;

	cout << endl;
	system("pause");

	return 2; //should return that quest 3 has been completed
}

// Battle System by Gabriel Lockner
// Implemented February 19, 2017
bool Quest::Battle(string monsterName)
{
	monster.setName(monsterName);
	int choice;
	cout << "A level " << monster.getLevel() << monster.GetName() << " is attacking!"
		<< "\n What do you do?\n\n";

	cout << user.GetName() <<" HP:" << user.GetHP() << endl;
	cout << monster.GetName() << " HP:" << monster.GetHP() << endl;

	cout << "1.) Fight\n2.) Run!\n\n";
	cin >> choice;

	while (choice != 1 && choice != 2)
	{
		cout << "Invalid! Try again: \n\n"
			<< "1.) Fight\n2.) Run\n\n";
		cin >> choice; //Zach says - I think we need another cin here otherwise it is an infinite loop -Matt says true
	}

	if(choice == 1)
	{
		while (true) //fighting
		{
			
			cout << "WHACK!\n\n You hit the " << monster.GetName() << " for "
				<< user.Attack() << " damage!\n\n";

			//subtract from monsters health
			monster.Hit(user.Attack());

		
			if (monster.GetHP() < 1)
			{
				cout << "You successfully killed the " << monster.GetName() << "!\n\n";
				//Reset for next fight
				user.reset();
				monster.reset();
				return true; //RETURN TRUE TO INDICATE VICTORY
			}

			cout << "The " << monster.GetName() << " retaliated for "
				<< monster.Attack() << " damage!\n\n";

			user.Hit(monster.Attack());

			if (user.GetHP() < 1)
			{
				cout << "The " << monster.GetName() << " has dealt lethal damage...\n"
					<< "You died!";				
				return false; // RETURN FALSE TO INDICATE DEFEAT
			}

			do
			{
				cout << "1.) Fight\n2.) Run\n\n";
				cin >> choice;
			} while (choice != 1 && choice != 2);
		}	
	}
	else if (choice ==2)
	{
		cout << "You deftly escape the " << monster.GetName() << "'s attacks.\n"
			<< "Got away safely!";
		return true;
	}
	else
	{
			cout << "ERROR: INVALID INPUT\n";
	}
	//Reset for next fight
	user.reset();
	monster.reset();
	//Technically it should never get here
	return false;
}
