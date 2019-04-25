/*
Random is seeded in player.cpp as of 3/29
Most cout statements can be replaced with alternative behaviors
*/

#include <iostream>

//to seed random number generator
#include <stdio.h>
#include <time.h>
#include "player.h"
#include "item.h"
#include <QDebug>

//Simple constructor

/*
Consider replacing the following method with a signal/slot pair
*/
// bool Item::action(){
//   if(has_message) display_message();
//   //complete implementation
// }



 /////////////////////////END ITEM CLASS DEFINITIONS////////////////////////////
////////////////////////BEGIN PLAYER CLASS DEFINITIONS/////////////////////////


Player::Player(){
  health = 100;
  max_health = 100;
  base_attack = 5;//can be changed in subclasses
  attack_boost = 0;
  defense_boost = 0;
  for(int i = 0; i<8; i++) inventory.push_back(nullptr);
}

Player::Player(PlayerClass role)
{
    if(role == Warrior)
        //weapon, weapon, normal
    {
        health = 125;
        max_health = 125;
        base_attack = 5;
        attack_boost = 0;
        defense_boost = 0;
        critChance = 0;
        inventory.push_back(ItemPool[5]);
        for(int i = 1; i < 8; ++i)
        {
            inventory.push_back(nullptr);
        }

    }
    else if(role == Mage)
        //spell, spell, normal
    {
        health = 100;
        max_health = 100;
        base_attack = 0;
        attack_boost = 0;
        defense_boost = 0;
        critChance = 0;
        inventory.push_back(ItemPool[8]);
        for (int i = 1; i < 8; ++i)
        {
            inventory.push_back(nullptr);
        }
    }
    else if(role == Bard)
    {
        health = 90;
        max_health = 90;
        base_attack = 5;
        attack_boost = 0;
        defense_boost = 0;
        critChance = 0;
        inventory.resize(10);
        inventory.push_back(ItemPool[3]);
        for(int i = 1; i < 10; ++i)
        {
            inventory[i] = nullptr;
        }
    }
    else if(role == Rogue)
    {
        health = 100;
        max_health = 100;
        base_attack = 5;
        attack_boost = 0;
        defense_boost = 0;
        critChance = .33;
        inventory.push_back(ItemPool[5]);
        for (int i = 1; i < 8; ++i)
        {
            inventory.push_back(nullptr);
        }
    }
    this->role = role;
}

//Attempts to add item to current inventory
//returns true if item was added to inventory

//May need to re-implement print/output
bool Player::collectItem(Item* new_item){
  bool flag = false;
  switch(new_item->type)
  {
    case weapon:
      if(role == Warrior)
      {
        if(inventory[0] == nullptr)
        {
            inventory[0] = new_item;
            flag = true;
        }
        else if(inventory[1] == nullptr)
        {
            inventory[1] = new_item;
            flag = true;
        }
        else
        {
            for (int i = 3; i < inventory.size(); ++i)
            {
                if(inventory[i] == nullptr)
                {
                    inventory[i] = new_item;
                    flag = true;
                    break;
                }
            }
        }
      }
      else if(role == Mage)
      {
        return flag;
      }
      else if(role == Bard || role == Rogue)
      {
          if(inventory[0] == nullptr)
          {
              inventory[0] = new_item;
              return true;
          }
          else
          {
            for(int i = 3; i < inventory.size(); ++i)
            {
                if(inventory[i] == nullptr)
                {
                    inventory[i] = new_item;
                    return true;
                }
            }
          }
      }
      break;
    case spell:
    if(role == Mage)
    {
      if(inventory[0] == nullptr)
      {
          inventory[0] = new_item;
          flag = true;
      }
      else if(inventory[1] == nullptr)
      {
          inventory[1] = new_item;
          flag = true;
      }
      else
      {
          for (int i = 3; i < inventory.size(); ++i)
          {
              if(inventory[i] == nullptr)
              {
                  inventory[i] = new_item;
                  flag = true;
                  break;
              }
          }
      }
    }
    else if(role == Warrior)
    {
      return flag;
    }
    else if(role == Bard || role == Rogue)
    {
        if(inventory[1] == nullptr)
        {
            inventory[1] = new_item;
            flag = true;
        }
        else
        {
          for(int i = 3; i < inventory.size(); ++i)
          {
              if(inventory[i] == nullptr)
              {
                  inventory[i] = new_item;
                  flag = true;
                  break;
              }
          }
        }
    }
      break;
    case armor:
      if(inventory[2] == nullptr)
      {
          inventory[2] = new_item;
          flag = true;
      }
      else
      {
        for(int i = 3; i < inventory.size(); ++i)
        {
            if(inventory[i] == nullptr)
            {
                inventory[i] = new_item;
                flag = true;
                break;
            }
        }
      }
      break;
    case consumable:
      for(int i = 3; i < inventory.size(); ++i)
      {
          if(inventory[i] == nullptr)
          {
              inventory[i] = new_item;
              flag = true;
              break;
          }
      }
      break;
    case other:
      for(int i = 3; i < inventory.size(); ++i)
      {
          if(inventory[i] == nullptr)
          {
              inventory[i] = new_item;
              flag = true;
              break;
          }
      }
      break;
  }
  return flag;
  //std::cout<<"You couldn't pick up the "<<new_item->name<<". (You may need to drop an item)"<<std::endl;
}

//Clears and returns a pointer to the item in the slot'th inventory slot
Item* Player::dropItem(int slot){
  Item* dropped = inventory[slot];
  inventory[slot] = nullptr;
  return dropped;
}

//Adjusts health by the increment (positive or negative)
//defaults to min(0) or max_health if result is out of bounds
void Player::adjustHealth(int increment){
  health += increment;
  if(health<0) health = 0;
  else if(health>max_health) health = max_health;
}

// (Equipping an item)
void Player::toggleItem(int slot){
  inventory[slot]->is_active = !inventory[slot]->is_active;
}

//Returns attack damage dealt by player
int Player::attack(QString type){
  calculateStats();
  int atk = base_attack+attack_boost;
  //to prevent SIGSEGVs
  int bonus = rand()%1000;
  if(role == Warrior){
      if(type =="Weapon"){
          if(inventory[0]){
              atk+=inventory[0]->attack_boost;
              if(inventory[0]->is_single_use) inventory[0] = nullptr;
          }
          if(inventory[1]){
              atk+=inventory[1]->attack_boost;
              if(inventory[1]->is_single_use) inventory[1] = nullptr;
          }
      }
      else if(type == "Spell"){
         return 0;
      }
  }
  else if(role == Mage){
      if(type =="Weapon"){
        return 0;
      }
      else if(type == "Spell"){
        if(inventory[0]){
          adjustHealth(inventory[0]->defense_boost);
          atk+=inventory[0]->attack_boost;
          if(inventory[0]->is_single_use) inventory[0] = nullptr;
        }
        if(inventory[1]){
          adjustHealth(inventory[1]->defense_boost);
          atk+=inventory[1]->attack_boost;
          if(inventory[1]->is_single_use) inventory[1] = nullptr;
        }
      }
  }
  else{
      if(type =="Weapon"){
          if(inventory[0]){
              atk+=inventory[0]->attack_boost;
              if(inventory[0]->is_single_use) inventory[0] = nullptr;
          }
      }
      else if(type == "Spell"&&inventory[1]){
        adjustHealth(inventory[1]->defense_boost);
        atk+=inventory[1]->attack_boost;
        if(inventory[1]->is_single_use) inventory[1] = nullptr;
      }
  }
  atk += (rand()%10* atk/20);//to vary attack damage (constants can be adjusted)

  if(role == Mage&&(inventory[1]&&inventory[1]->crit_chance+critChance)*1000>bonus) atk*=3;
  else if(inventory[0]&&(inventory[0]->crit_chance+critChance)*1000>bonus) atk*=3;//critical hit
  if(bonus>989) atk = 0;//attack missed... for some reason

  /*
  if(inventory[0]&&inventory[0]->is_active){
    atk+=inventory[0]->attack_boost;
    if(inventory[0]->crit_chance+critChance*1000>bonus) atk*=3;//critical hit
  }
  atk += (rand()%10* atk/20);//to vary attack damage (constants can be adjusted)
  if(bonus>989) atk = 0;//attack missed... for some reason
  */
  return atk;
}

//For combat, updates Player's attack/defense
void Player::calculateStats(){
  Item* item;
  attack_boost = 0;
  defense_boost = 0;
  for(int i = 1; i<8; i++){
    item = inventory[i];
    if(item&&item->is_active){
      defense_boost+=item->defense_boost;
      attack_boost+=item->attack_boost;
      if(item->is_single_use) delete item;
      inventory[i] = nullptr;
    }
  }
}

int Player::getHealth()
{
    return health;
}

vector<Item*>& Player::getInventory()
{
    return inventory;
}

QString Player::useItem(int slot)
{
    Item *current = new Item();
    current = inventory[slot];
    if(current == nullptr) return "You can't use something that doesn't exist";
    switch(current->type)
    {
    case weapon:
        return "You can only use that in combat.";
    case spell:
        if(current->attack_boost > 0)
        {
            return "You can only use a damage spell during combat.";
        }
        health += current->healing;
        defense_boost += defense_boost;
        break;
    case armor:
        return "Armor is not a usable item.";
    case consumable:
        health += current->healing;
        defense_boost += current->defense_boost;
        inventory[slot] = nullptr;
        delete current;
        return "You used the item";
    case other:
        break;
    }
}

int Player::getDefense()
{
    return defense_boost;
}

//make string of length n out of a value
QString Player::makeNS(int len, int val){
  QString str = "";
  //case: item
  if(len == 2){
    if(val<10){
      str+="0";
      str+=QString::number(val, 10);
    }
    else{
      str+=QString::number(val, 10);
    }
    return str;
  }
  QString num = QString::number(val, 10);
  for(int i = 0; i<(len-num.length()); i++){
    str+="0";
  }
  str+=num;
  return str;
}

QString Player::saveGame(){
  QString save = "";
  //adding player role
  if(role == Mage) save+="M";
  else if(role == Warrior) save+="W";
  else if(role == Bard) save+="B";
  else save+="R";
  //adding health
  save+=makeNS(5,health);
  save+=makeNS(5,max_health);
  save+=makeNS(4,base_attack);
  save+=makeNS(4,attack_boost);
  save+=makeNS(4,defense_boost);
  //inventory
  for(int i = 0; i<inventory.size(); i++){
    // save+=;
  }
  return save;
}

void Player::loadGame(QString l){
  QString load = l;
  if(load[0] == "R"){
    critChance = .33;
    role = Rogue;
  }
  else if(load[0] == "M") role = Mage;
  else if(load[0] == "B") role = Bard;
  else role = Warrior;
  //loading health
  QString val = load.left(6);
  health = val.toInt();
  load = load.mid(6);
  //loading max health
  val = load.left(6);
  max_health = val.toInt();
  load = load.mid(6);
  //loading attack
  val = load.left(5);
  base_attack = val.toInt();
  load = load.mid(5);
  //loading attack boost
  val = load.left(5);
  attack_boost = val.toInt();
  load = load.mid(5);
  //loading defense boost
  val = load.left(5);
  defense_boost = val.toInt();
  load = load.mid(5);

  int slot = 0;
  while(load.length()>0){
    // val = load.substr(0,1);
    // inventory[slot] = itemFunction(slot);
    // slot++;
    // load = load.substr(1);
  }
}
//save string format:
/*
H: Health
R/HHHHH/MMMMM/AAAA/BBBB/DDDD/(inventory slots)

*/
//Used to test functionalities of various methods
//This isn't necessary
/*int main(){
  //seeding random number generator
  srand(time(0));
  //testing weapon slot
  Item* generic_sword = new Item(ItemType::Weapon, "Player's Sword", false, 15,0,.4);
  Item* generic_sword2 = new Item(ItemType::Weapon, "Player's Sword 2", false, 15,0,.4);
  //testing armor slot
  Item* generic_armor = new Item(ItemType::Armor, "Generic Armor", false, 0,15,0.0);
  Item* generic_armor2 = new Item(ItemType::Armor, "Rusty Armor", false, 0,-15,0.0);
  Item* sui = new Item(ItemType::Spell, "Sparkler", true, 1000,0,0.);
  sui->is_active = true;
  Player* dude = new Player();
  dude->collectItem(generic_sword);
  dude->collectItem(generic_sword2);
  dude->collectItem(generic_armor);
  dude->collectItem(generic_armor2);
  dude->collectItem(sui);
  std::cout<<"Player attacks for "<<dude->attack()<<std::endl;
  std::cout<<"Player attacks for "<<dude->attack()<<std::endl;
  std::cout<<"Program terminated successfully"<<std::endl;
  return 0;
}
*/
