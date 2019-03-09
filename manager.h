#ifndef MANAGER_H
#define MANAGER_H

#include <QString>

class manager
{

public:
    manager();
    ~manager();

    QString userInput(QString input);
    int getPlayerHealth();
    QString getNarrative();
private:
    void combatEvent();
    void moveEvent();
    void playerEvent();


};

#endif // MANAGER_H
