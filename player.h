#ifndef PLAYER_H
#define PLAYER_H
/*


*/

#include <string>
#include "item.h"

//Feel free to add other item types here
enum class ItemType{Weapon, Armor, Spell, Other};

//Base item class (may be subclassed for different behaviors or effects)

//basic player class
class Player{
public:
  Player();
  Player(int);

  //tries to add an item to the inventory
  //returns false if item cannot be collected
  bool collectItem(Item*);
  //Clears the <param>th inventory slot
  Item* dropItem(int);
  //for taking damage or recovering health
  void adjustHealth(int);

  void useItem(int slot);

  //Activates or deactivates a certain item in the inventory
  void toggleItem(int slot);

  //returns attack damage
  int attack();
  //Updates player's stats fields
  void calculateStats();
  //gets health for health bars;
  int getHealth();

  Item* getInventory(int slot);

private:

  Item* inventory[8];
  //[Weapon, Armor, Spell, item, item, item, item, item]
  int health;//current health
  int max_health;//can change as character levels up
  int base_attack;
  // double defense;
  int attack_boost;
  int defense_boost;
};
#endif // PLAYER_H
