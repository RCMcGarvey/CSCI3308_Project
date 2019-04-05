#ifndef ITEM_H
#define ITEM_H

#include <string>

using namespace std;

struct Item{

  //what the item is
  string type;
  std::string name;
  //item behavior when
  bool is_single_use;
  bool is_active;
  // int uses; //how many times item can be used
  int attack_boost;
  int defense_boost;
  double crit_chance;

// in case the item is a sheet of paper which says something
  bool has_message;
  std::string message;

  //Constructor: (basic weapons, armor, and potions)
  //  type        name     singleuse atk dfs  crit
  Item(string t, std::string n, bool single_use, int atk, int def, double crit)
  {
    type = t;
    name = n;
    is_single_use = single_use;
    is_active = false;
    attack_boost = atk;
    defense_boost = def;
    crit_chance = crit;
    has_message = false;
    message = "";
  } //set

  //Constructor: (scrolls, items with messages, misc)
  //  type        name     singleuse atk dfs  crit    use/message
  Item(string t, std::string n, bool single_use, int atk, int def, double crit, std::string msg)
  {
    type = t;
    name = n;
    is_single_use = single_use;
    is_active = false;
    attack_boost = atk;
    defense_boost = def;
    crit_chance = crit;
    has_message = true;
    message = msg;
  }

  Item(){}

  //open to implementation
  void display_message();
  // bool action();//may be used to destroy single-use items after use
};

#endif // ITEM_H
