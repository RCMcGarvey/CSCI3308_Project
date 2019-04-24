#include "item.h"

Item *ItemPool[30];

void populateItems() {
    ItemPool[0] = new Item(weapon, "A Dry Stick", true, 5, 0, 0.01, 0);
    ItemPool[1] = new Item(weapon, "A Dry Twig", true, 2, 0, 0.01, 0);
    ItemPool[2] = new Item(consumable, "A Healing Potion", true, 0, 0, 0, 30);
    ItemPool[3] = new Item(weapon, "A Brick", true, 15, 0, 1, 0);
    ItemPool[4] = new Item(weapon, "A Wooden Board", false,  12, 0, 1, 0);
    ItemPool[5] = new Item(weapon, "A Kitchen Knife", false, 12, 0, 10.0, 0);
    ItemPool[6] = new Item(weapon, "A Kitchen Plate", true, 15, 0, 0.1, 0);
    ItemPool[7] = new Item(weapon, "A Dining Room Chair", true, 25, 0, 0.1, 0);
}

