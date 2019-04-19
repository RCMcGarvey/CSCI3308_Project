/*
Anton's Changelog:
-Removed main(), to prevent undefined behavior
*/
#include "enemy.h"
#include "player.h"

#include <stdio.h>
#include <time.h>
#include <QVariant>

#include <QDebug>

enemy::enemy() { // Create default enemy (Snowman)
    srand(static_cast <unsigned int> (time(NULL)));
    type = Snowman;
    health = 10;
    max_health = 10;
    base_attack = 0;
    crit_chance = 0.0;
    alive = true; // Barely true
    name = "snowman";

}

enemy::enemy(EnemyType t, int h, int h_max, int b_atk, double c) { // Set custom attributes
    srand(static_cast <unsigned int> (time(NULL)));
    type = t;
    health = h;
    max_health = h_max;
    base_attack = b_atk;
    crit_chance = c;
    alive = true;
    name = "mimic";

}

enemy::enemy(EnemyType t) { // Set attributes based on enemy type
    srand(static_cast <unsigned int> (time(NULL)));
    type = t;
    switch(t) {
        case Snowman:
            health = 10;
            max_health = 10;
            base_attack = 0;
            crit_chance = 0.0;
            name = "snowman";
            break;
        case Ghost:
            health = 100;
            max_health = 100;
            base_attack = 5;
            crit_chance = 0.1;
            name = "ghost";
            break;
        case Zombie:
            health = 150;
            max_health = 150;
            base_attack = 7;
            crit_chance = 0.05;
            name = "zombie";
            break;
        case Skeleton:
            health = 60;
            max_health = 60;
            base_attack = 10;
            crit_chance = 0.3;
            name = "skeleton";
            break;
        case Vampire:
            health = 80;
            max_health = 80;
            base_attack = 7;
            crit_chance = 0.3;
            name = "vampire";
            break;
        case Ghoul:
            health = 100;
            max_health = 100;
            base_attack = 5;
            crit_chance = 0.4;
            name = "ghoul";
            break;
        case Diary:
            health = 420;
            max_health = 420;
            base_attack = 20;
            crit_chance = 0.5;
            name = "diary";
            break;
        case ZippyFlap:
            health = 200;
            max_health = 200;
            base_attack = 15;
            crit_chance = 0.1;
            name = "zippy flap";
            break;
    }
    alive = true;
}

enemy::~enemy() {}

void enemy::adjustHealth(int amt) {
    //qDebug()<<"Entered enemy adjust health";
    health += amt;
    //qDebug()<<health;
    if (health < 0) {
        health = 0;
        alive = false;
    }
    else if (health > max_health) { // Allows for healing abilites
        health = max_health;
    }

}

void enemy::adjustCrit(double amt) {

    crit_chance += amt;
    if (crit_chance < 0.0) {
        crit_chance = 0.0;
    }
    else if (crit_chance > 1.0) {
        crit_chance = 1.0;
    }

}

int enemy::attack() {

    int atk = base_attack;
    int bonus = rand() % 101;
    bool critFlag = false;
    (crit_chance * 100 > bonus) ? critFlag = true : critFlag = false;
    if (critFlag) { // Critical hit
        atk *= 3;
    }
    // Special attribute modifiers:
    if (type == Vampire) { // Vampire steals health
        adjustHealth(atk / 2);
    }
    if (type == Ghoul) { // Ghoul regens health each turn
        adjustHealth(5);
    }
    if (type == ZippyFlap) { // ZippyFlap has dynamic crit_chance
        adjustCrit(0.1);
    }
    if (critFlag && type == Skeleton) { // Skeleton yeets on crit
        atk = 70;
    }

    return atk;

}

bool enemy::getAlive() {

    return alive;

}

QString enemy::getEnemyName() {

    return name;

}

int enemy::getHealth() {

    return health;

}
/*
int main() {

    srand(time(0)); // Seeded 4/5

}
*/
