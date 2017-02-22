#ifndef CREATURE_H
#define CREATURE_H
#include <string>
// ##########################
// Creature class declaration
// ##########################

class Creature
{
 private:
  int lvl, atk, def, hp;
  std::string nm;
 public:
  Creature(int, std::string);
  void getStats();
  int Attack();
  void Hit(int);
  bool Run();
  int GetHP();
  std::string GetName();
};

#endif

