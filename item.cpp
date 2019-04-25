#include "item.h"

Item *ItemPool[30];

void populateItems() {
    ItemPool[0] = new Item(0,weapon, "A Dry Stick", true, 5, 0, 0.01, 0);
    ItemPool[1] = new Item(1,weapon, "A Dry Twig", true, 2, 0, 0.01, 0);
    ItemPool[2] = new Item(2,consumable, "A Healing Potion", true, 0, 0, 0, 30);
    ItemPool[3] = new Item(3,weapon, "A Brick", true, 15, 0, 1, 0);
    ItemPool[4] = new Item(4,weapon, "A Wooden Board", false,  12, 0, 1, 0);
    ItemPool[5] = new Item(5,weapon, "A Kitchen Knife", false, 12, 0, 10.0, 0);
    ItemPool[6] = new Item(6,weapon, "A Kitchen Plate", true, 15, 0, 0.1, 0);
    ItemPool[7] = new Item(7,weapon, "A Dining Room Chair", true, 25, 0, 0.1, 0);
    ItemPool[8] = new Item(8,spell, "Fireball", false, 10, 0, 0.0, 0, "Standard spell dealing 10 damage.");
    ItemPool[9] = new Item(9,spell, "Deadly Dichotomy", false, 75, 0, 0.0, -50, "High damage spell that comes at a price.");
    ItemPool[10] = new Item(10,spell, "Inferno", false, 30, 0, 0.0, 0, "High damage fireball");
    ItemPool[11] = new Item(11,spell, "Heal", false, 0, 0, 0.0, 10, "Standard healing spell restores 10 health");
    ItemPool[12] = new Item(12,weapon, "Iron Sword", false, 15, 0, 0.0, 0);
    ItemPool[13] = new Item(13,weapon, "War Axe", false, 20, 0, 0.0, 0);
    ItemPool[14] = new Item(14,weapon, "Kingkiller", false, 50, 0, 0.2, 0);
    ItemPool[15] = new Item(15,weapon, "The Viper", false, 10, 0, 0.75, 0);
    ItemPool[16] = new Item(16,spell, "Scroll of Lighting", true, 40, 0, 0.0, 0, "High damage single use spell");
    ItemPool[17] = new Item(17,spell, "Scroll of Instadeath", true, 20, 0, 0.0, -100, "Be carefull with this one");
    ItemPool[18] = new Item(18,spell, "Magic Missle", false, 40, 0, 0.2, 0, "Very high damage spell");
    ItemPool[19] = new Item(19,armor, "Wooden Shield", false, 0, 10, 0.0, 0);
    ItemPool[20] = new Item(20,armor, "Bucket Helmet", false, 0, 15, 0.0, 0);
    ItemPool[21] = new Item(21,armor, "Chain Mail", false, 0, 30, 0.0, 0);
    ItemPool[22] = new Item(22,armor, "Steel Plate Mail", false, 50, 0, 0.0, 0);
    ItemPool[23] = new Item(23,consumable, "Potion of Mega Healing", true, 0, 0, 0.0, 50, "Provides massive healing");
    ItemPool[24] = new Item(24,consumable, "Potion of Iron Skin", true, 0, 5, 0.0, 0, "Slight defense buff");
    ItemPool[25] = new Item(25,consumable, "Potion of the Beserker", true, 5, 0, 0.0, 0, "Slight attack buff");
    ItemPool[26] = new Item(26,consumable, "Witches Brew", true, 10, 10, 0.0, -10, "attack and defense at what cost?");
    ItemPool[27] = new Item(27,armor, "Armor of Warding", true, 0, 70, 0.0, 0);
    ItemPool[28] = new Item(28,spell, "Healing Aura", false, -20, 0, 0.0, 40);
    ItemPool[29] = new Item(29,spell, "Scroll of Bladestorm", false, 20, 0, 1.0, 0, "This spell is single use but always crits.");
}

