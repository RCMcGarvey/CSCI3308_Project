#ifndef ENEMY_H
#define ENEMY_H

enum EnemyType{Ghost, Zombie, Skeleton}; // Base enemy subtypes

/* Enemy attribute list:

struct Ghost {

    int health = 100;
    int max_health = 100;
    int base_attack = 5;
    double crit_chance = 0.1;

};

struct Zombie {

    int health = 150;
    int max_health = 150;
    int base_attack = 7;
    double crit_chance = 0.05;

};

struct Skeleton {

    int health = 60;
    int max_health = 75;
    int base_attack = 10;
    double crit_chance = 0.3;

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
