#include "item.h"

Item *ItemPool[50];

void populateItems() {
    //Trash
    ItemPool[0] = new Item(0,weapon, "A Dry Twig", true, 5, 0, 0.01, 0);
    ItemPool[1] = new Item(1,weapon, "A Rusty Sword", true, 2, 0, 0.01, 0);
    ItemPool[2] = new Item(2,weapon, "A Brick", true, 15, 0, 0.01, 0);
    ItemPool[3] = new Item(3,weapon, "A Wooden Board", false,  12, 0, 0.01, 0);
    ItemPool[4] = new Item(4,weapon, "Candlestick", false, 1, 0, 0.0, 0, "Not for attacking.");
    ItemPool[5] = new Item(5,weapon, "The Lead Pipe", false, 5, 0, 0.0, 0, "Maybe its a clue. Mustard did it?");
    ItemPool[6] = new Item(6,weapon, "Wooden Stake", false, 11, 0, 0.0, 0, "Watch out for vampires.");


    //Consumables
    ItemPool[7] = new Item(7,consumable, "A Healing Potion", true, 0, 0, 0, 30, "Drink to heal.");
    ItemPool[8] = new Item(8,consumable, "Potion of Mega Healing", true, 0, 0, 0.0, 50, "Drink to BIG heal.");
    ItemPool[9] = new Item(9,consumable, "Potion of Iron Skin", true, 0, 5, 0.0, 0, "Increase defence.");
    ItemPool[10] = new Item(10,consumable, "Potion of the Beserker", true, 5, 0, 0.0, 0,"\"Become strong.\"");
    ItemPool[11] = new Item(11,consumable, "Witches Brew", true, 10, 10, 0.0, -10, "attack and defense at what cost?");
    ItemPool[12] = new Item(12,consumable,"Healing Potion of Death", true, 0, 0, 0, -100, "Drink this to heal for -100 healing death, guaranteed");
    ItemPool[13] = new Item(13,consumable, "Water", true, 0, 0, 0 , 2, "Crisp and refreshing!");
    ItemPool[14] = new Item(14,consumable, "Bubbly Water", true, 0, 0, 0 , 6, "Ooh bubbly!");
    ItemPool[15] = new Item(15,consumable, "Pocket Lint", true, 0, 0, 0.0, 0, "Crunchy.");
    ItemPool[16] = new Item(16,consumable, "Biscuit", true, 0, 0, 0 , 4, "Tastes like it has been there for a little while...");
    ItemPool[17] = new Item(17,consumable, "Swönky roll", true, 0, 0, 0 , -1, "Patent pending");


    //Ok Weapons
    ItemPool[18] = new Item(18,weapon, "A Kitchen Knife", false, 6, 0, .5, 0);
    ItemPool[19] = new Item(19,weapon, "A Kitchen Plate", true, 15, 0, 0.1, 0);
    ItemPool[20] = new Item(20,weapon, "A Dining Room Chair", true, 25, 0, 0.1, 0);
    ItemPool[21] = new Item(21,weapon, "Iron Sword", false, 15, 0, 0.0, 0);
    ItemPool[22] = new Item(22,weapon, "War Axe", false, 20, 0, 0.0, 0);
    ItemPool[23] = new Item(23,weapon, "Giant Hammer", false, 13, 0, 0.13, 0, "A giant could use this!");


    //Good weapons
    ItemPool[24] = new Item(24,weapon, "Kingkiller", false, 50, 0, 0.2, 0);
    ItemPool[25] = new Item(25,weapon, "The Viper", false, 10, 0, 0.75, 0);
    ItemPool[26] = new Item(26,weapon, "Leech Blade", false, 10, 0, 0.0, 10, "Crafted from the tooth of vampire.");
    ItemPool[27] = new Item(27,weapon, "Crossbow", false, 15, 0, 0.5, 0, "This could come in handy.");


    //Armor
    ItemPool[28] = new Item(28,armor, "Wooden Shield", false, 0, 10, 0.0, 0);
    ItemPool[29] = new Item(29,armor, "Bucket Helmet", false, 0, 15, 0.0, 0);
    ItemPool[30] = new Item(30,armor, "Chain Mail", false, 0, 30, 0.0, 0);
    ItemPool[31] = new Item(31,armor, "Steel Plate Mail", false, 0, 50, 0.0, 0);
    ItemPool[32] = new Item(32,armor, "Armor of Warding", true, 0, 70, 0.0, 0);
    ItemPool[33] = new Item(33,armor, "Imbued Body Plate", false, 0, 18, 0.0, 0, "Glows with a faint blue light");
    ItemPool[34] = new Item(34,armor, "Paper Tuxedo", false, 0, 1, 0.0, 0, "Lookin’ sharp ;)");
    ItemPool[35] = new Item(35,armor, "Leather chestpiece", false, 0, 10, 0.0, 0, "Not the best material");


    //Spells
    ItemPool[36] = new Item(36,spell, "Fireball", false, 10, 0, 0.0, 0, "Standard spell dealing 10 damage.");
    ItemPool[37] = new Item(37,spell, "Deadly Dichotomy", false, 75, 0, 0.0, -50, "High damage spell that comes at a price.");
    ItemPool[38] = new Item(38,spell, "Inferno", false, 30, 0, 0.0, 0, "Hgh damage fireball");
    ItemPool[39] = new Item(39,spell, "Heal", false, 0, 0, 0.0, 10, "Standard healing spell restores 10 health");
    ItemPool[40] = new Item(40,spell, "Magic Missle", false, 40, 0, 0.2, 0, "Very high damage spell");
    ItemPool[41] = new Item(41,spell, "Healing Aura", false, -20, 0, 0.0, 40);
    ItemPool[42] = new Item(42,spell, "Vaporizing Laser", false, 20, 0, 0.33, 0, "ERADICATE");
    ItemPool[43] = new Item(43,spell, "Scroll of Pebble Rain", true, 4, 0, .5, 0, "Rain pebbles on your foes!");
    ItemPool[44] = new Item(44,spell, "Very Spontaneous Meteorite", true, 15, 0, .3 , -5, "A giant flaming rock falls out of the sky!");


    //Scrolls
    ItemPool[45] = new Item(45,spell, "Scroll of Lighting", true, 40, 0, 0.0, 0, "High damage single use spell");
    ItemPool[46] = new Item(46,spell, "Scroll of Instadeath", true, 20, 0, 0.0, -1000, "Be carefull with this one");
    ItemPool[47] = new Item(47,spell, "Scroll of Bladestorm", false, 20, 0, 1.0, 0, "This spell is single use but always crits.");
    ItemPool[48] = new Item(48,spell, "Scroll of Bladestorm", false, 20, 0, 1.0, 0, "This spell is single use but always crits.");
}
