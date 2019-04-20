#ifndef Display_H
#define Display_H

#include <QMainWindow>
#include "manager.h"
#include <QThread>
#include <QTimer>

namespace Ui {
class Display;
}

class Display : public QMainWindow
{
    Q_OBJECT

public:
    explicit Display(QWidget *parent = nullptr);
    ~Display();

    void mainMenu();
    void printMessage(QString message);
    void instructions();
    void startGame();
    void andThusItBegins();


private slots:
    void on_moveButton_clicked();

    void on_northButton_clicked();

    void on_eastButton_clicked();

    void on_westButton_clicked();

    void on_southButton_clicked();

    void on_fightButton_clicked();

    void on_InventoryButton_clicked();

    void on_lookButton_clicked();

    void on_weaponButton_clicked();

    void on_spellButton_clicked();

    void on_useButton_clicked();

    void on_pickupButton_clicked();

    void on_inspectButton_clicked();

    void on_swapButton_clicked();

    void on_interactButton_clicked();

    void on_comboBox_activated(int index);

    void on_comboBox_2_activated(int index);

    void on_actionMain_Menu_triggered();

    void on_actionHelp_triggered();

    void on_warrior_clicked();

    void on_mage_clicked();

    void on_bard_clicked();

    void on_rogue_clicked();

private:
    Ui::Display *ui;
    void populateDropdown(int box, QString button);

    Manager bossMan;

    QPalette tb = palette();
    bool box1;
    int item;
    QString currentButton;
};

#endif // Display_H
