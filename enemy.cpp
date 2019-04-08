#include "enemy.h"
#include "player.h"

#include <stdio.h>
#include <time.h>

enemy::enemy() { // Create default enemy

    health = 100;
    max_health = 100;
    base_attack = 5;
    alive = true;

}

enemy::enemy(EnemyType t, int h, int h_max, int b_atk, double c) { // Enemy type, health, max_health, base_attack

    type = t;
    health = h;
    max_health = h_max;
    base_attack = b_atk;
    crit_chance = c;

}

enemy::enemy(EnemyType t) { // Set attributes based on enemy type

    type = t;
    switch(t) {
        case Ghost:
            health = 100;
            max_health = 100;
            base_attack = 5;
            crit_chance = 0.1;
            break;
        case Zombie:
            health = 150;
            max_health = 150;
            base_attack = 7;
            crit_chance = 0.05;
            break;
        case Skeleton:
            health = 60;
            max_health = 60;
            base_attack = 10;
            crit_chance = 0.3;
            break;
    }

}

enemy::~enemy() {}

void enemy::adjustHealth(int amt) {

    health += amt;
    if (health < 0) {
        health = 0;
        alive = false;
    }
    else if (health > max_health) { // Allows for healing abilites
        health = max_health;
    }

}

int enemy::attack() {

    int atk = base_attack;
    int bonus = rand() % 1000;
    (crit_chance * 1000 > bonus) ? atk *= 3 : atk *= 1;
    return atk;

}

int main() {

    srand(time(0)); // Seeded 4/5

}
