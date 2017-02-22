// Implementation file for the Monster class
// last updated Monday January 23, 2017

//time spent here: like an hour

#include <iostream>
#include <string>

#include "Creature.h"

Creature::Creature(int level, std::string name)
{
 nm = name;
 lvl = level;
 hp = level * 5 + 10;
 atk = level * 2.1;
 def = level * 1.5;
}

void Creature::getStats()
{
 std::cout << "\nRetrieving Stats...\n";
 std::cout << "NAME:    " << nm << std::endl;
 std::cout << "LEVEL:   " << lvl << std::endl;
 std::cout << "HP:      " << hp << std::endl;
 std::cout << "ATTACK:  " << atk << std::endl;
 std::cout << "DEFENSE: " << def << std::endl;
}

int Creature::Attack()
{
 return atk;
}

int Creature::GetHP()
{
 return hp;
}

std::string Creature::GetName()
{
 return nm;
}

void Creature::Hit(int dmg)
{
 hp = hp - dmg;
}

bool Creature::Run()
{
 return true;
}

