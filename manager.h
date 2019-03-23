#ifndef MANAGER_H
#define MANAGER_H

#include <QString>

class manager
{

public:
    manager();
    ~manager();

    //void userInput(QString input);
    void userInput(int input);
    void userInput(int input, int input2);
    int getPlayerHealth();
    QString getNarrative();

private:
    void combatEvent();
    void moveEvent();
    void playerEvent();


};

#endif // MANAGER_H
