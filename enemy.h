#ifndef ENEMY_H
#define ENEMY_H

enum EnemyType{Ghost, Zombie, Skeleton, Vampire, Ghoul}; // Base enemy subtypes

/* Enemy attribute list:

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
    int max_health = 75;
    int base_attack = 10;
    double crit_chance = 0.3;

};

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
    double crit_chance = 0.4

};


*/

class enemy {

    public:

        enemy(); // Default constructor
        enemy(EnemyType, int, int, int, double); // Enemy type, health, max_health, base_attack, crit_chance
        enemy(EnemyType); // Set attributes based only on enemy type (easier?)
        ~enemy();

        void adjustHealth(int); // For taking damage/healing
        int attack(); // For dealing damage
        bool getAlive();

    private:

        EnemyType type;
        int health;
        int max_health;
        int base_attack;
        bool alive;
        double crit_chance;

};

#endif // ENEMY_H
