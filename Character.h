#ifndef CHARACTER_H
#define CHARACTER_H
#include <string>
// ###########################
// Character Class Declaration
// ###########################

class Character
{
 private:
  int lvl, atk, def, hp;
  std::string nm;		
  bool dead;
 public:
  Character(int, std::string);
  void getStats();
  int Attack();
  bool Hit(int);
  bool Run();
  int GetHP();
  std::string GetName();
};

#endif
