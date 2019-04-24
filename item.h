#ifndef ITEM_H
#define ITEM_H

#include <string>
#include <QString>
#include <vector>

using namespace std;

enum ItemType{weapon, spell, armor, consumable, other};

struct Item{

  //what the item is
  ItemType type;
  QString name;
  //item behavior when
  bool is_single_use;
  bool is_active;
  // int uses; //how many times item can be used
  int healing;
  int attack_boost;
  int defense_boost;
  double crit_chance;
  int ID;

// in case the item is a sheet of paper which says something
  bool has_message;
  QString message;

  //Constructor: (basic weapons, armor, and potions)
  //  type        name     singleuse atk dfs  crit
  Item(int id ,ItemType t, QString n, bool single_use, int atk, int def, double crit, int heal)
  {
    type = t;
    ID = id;
    name = n;
    is_single_use = single_use;
    is_active = false;
    attack_boost = atk;
    defense_boost = def;
    crit_chance = crit;
    has_message = false;
    healing = heal;
    message = "";
  } //set

  //Constructor: (scrolls, items with messages, misc)
  //  type        name     singleuse atk dfs  crit    use/message
  Item(int id ,ItemType t, QString n, bool single_use, int atk, int def, double crit, int heal, QString msg)
  {
    ID = id;
    type = t;
    name = n;
    is_single_use = single_use;
    is_active = false;
    attack_boost = atk;
    defense_boost = def;
    crit_chance = crit;
    healing = heal;
    has_message = true;
    message = msg;
  }

  Item(){}

  //open to implementation
  QString display_message()
  {
      if(message != "")
      {
          return message;
      }
      else if(type == weapon)
      {
           return name + ", Attack Value: " + QString::number(attack_boost);
      }
      else if(type == spell)
      {
           return name + ", Description: " + message;
      }
      else if(type == armor)
      {
           return name + ", Armor Value: " + QString::number(defense_boost);
      }
      else
      {
           return name + ". " + message;
      }
  }
  // bool action();//may be used to destroy single-use items after use
};

extern Item *ItemPool[30];

void populateItems();




#endif // ITEM_H
