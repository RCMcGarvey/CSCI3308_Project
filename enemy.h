#ifndef ENEMY_H
#define ENEMY_H

#include <QString>


enum EnemyType{Snowman, Ghost, Zombie, Skeleton, Vampire, Ghoul, Diary, ZippyFlap}; // Base enemy subtypes

/* Enemy attribute list:

*** DEFAULT ENEMIES ***

struct Snowman { // Tutorial enemy, super trash

    int health = 10;
    int max_health = 10;
    int base_attack = 0;
    double crit_chance = 0.0;

}

*** BASIC ENEMIES ***

struct Ghost { // Basic enemy

    int health = 100;
    int max_health = 100;
    int base_attack = 5;
    double crit_chance = 0.1;

};

struct Zombie { // Basic enemy, tanky

    int health = 150;
    int max_health = 150;
    int base_attack = 7;
    double crit_chance = 0.05;

};

struct Skeleton { // Basic enemy, glass cannon

    int health = 60;
    int max_health = 60;
    int base_attack = 10;
    double crit_chance = 0.3;

};

*** SPECIAL ENEMIES ***

struct Vampire { // Health stealer

    int health = 80;
    int max_health = 80;
    int base_attack = 7;
    double crit_chance = 0.3;

};

struct Ghoul { // More annoying, regenerative variant of Ghost type

    int health = 100;
    int max_health = 100;
    int base_attack = 5;
    double crit_chance = 0.4;

};

*** BOSS ENEMIES ***

struct Diary { // Main boss, the source of everything

    int health = 420;
    int max_health = 420;
    int base_attack = 20;
    double crit_chance = 0.5;

}

struct ZippyFlap { // Miniboss, crit_chance increases gradually

    int health = 200;
    int max_health = 200;
    int base_attack = 15;
    double crit_chance = 0.1;

}

*/

class enemy {

    public:

        enemy(); // Default constructor
        enemy(EnemyType, int, int, int, double); // Enemy type, health, max_health, base_attack, crit_chance
        enemy(EnemyType); // Set attributes based on enemy type (easier?)
        ~enemy();

        void adjustHealth(int); // For taking damage/healing
        void adjustCrit(double); // For ZippyFlap enemy
        int attack(); // For dealing damage
        bool getAlive();
        QString getEnemyName();
        int getHealth();

    private:

        EnemyType type;
        QString name;
        int health;
        int max_health;
        int base_attack;
        bool alive;
        double crit_chance;

};

#endif // ENEMY_H
