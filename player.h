#ifndef PLAYER_H
#define PLAYER_H
/*


*/

#include <string>

//Feel free to add other item types here
enum class ItemType{Weapon, Armor, Spell, Other};

//Base item class (may be subclassed for different behaviors or effects)
struct Item{

  //what the item is
  ItemType type;
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
  Item(ItemType, std::string, bool, int, int, double); //set

  //Constructor: (scrolls, items with messages, misc)
  //  type        name     singleuse atk dfs  crit    use/message
  Item(ItemType, std::string, bool, int, int, double, std::string);

  //open to implementation
  void display_message();
  // bool action();//may be used to destroy single-use items after use
};

//basic player class
class Player{
public:
  Item* inventory[8];
  //[Weapon, Armor, Spell, item, item, item, item, item]
  int health;//current health
  int max_health;//can change as character levels up
  int base_attack;
  // double defense;
  int attack_boost;
  int defense_boost;

  Player();
  Player(int);

  //tries to add an item to the inventory
  //returns false if item cannot be collected
  bool collectItem(Item*);
  //Clears the <param>th inventory slot
  Item* dropItem(int);
  //for taking damage or recovering health
  void adjustHealth(int);

  //Activates or deactivates a certain item in the inventory
  void toggleItem(int slot);

  //returns attack damage
  int attack();
  //Updates player's stats fields
  void calculateStats();
};
#endif // PLAYER_H
