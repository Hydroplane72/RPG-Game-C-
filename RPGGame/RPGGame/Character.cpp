// Implementation file for the Monster class
// last updated Wednesday February 15, 2017

#include <iostream>
#include <string>

#include "Character.h"

Character::Character()
{
}

Character::Character(int level, std::string name)
{
	nm = name;
	lvl = level;
	hp = level * 5 + 10;
	atk = level * 2.1;
	def = level * 1.5;
}

void Character::getStats()
{
	std::cout << "\nRetrieving Stats...\n";
	std::cout << "NAME:    " << nm << std::endl;
	std::cout << "LEVEL:   " << lvl << std::endl;
	std::cout << "HP:      " << hp << std::endl;
	std::cout << "ATTACK:  " << atk << std::endl;
	std::cout << "DEFENSE: " << def << std::endl;
}

int Character::Attack()
{
	return atk;
}

int Character::GetHP()
{
	return hp;
}

std::string Character::GetName()
{
	return nm;
}

void Character::SetName(std::string name)
{
	nm = name;
}



void Character::reset()
{
	//resets character stuff for next fight
	hp = lvl * 5 + 10;
	atk = lvl * 2.1;
	def = lvl * 1.5;
}

void Character::levelUp()
{
	lvl++;
	reset();
}

bool Character::Hit(int dmg)
{
	hp = hp - dmg;
	if (hp <= 0)
	{
		return false;
	}
	return true;
}

bool Character::Run()
{
	return true;
}
