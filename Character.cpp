// Implementation file for the Monster class
// last updated Wednesday February 15, 2017

#include <iostream>
#include <string>

#include "Character.h"

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

bool Character::Hit(int dmg)
{
 hp = hp - dmg;
}

bool Character::Run()
{
 return true;
}

