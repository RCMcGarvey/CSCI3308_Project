#ifndef Display_H
#define Display_H

#include <QMainWindow>
#include "manager.h"

namespace Ui {
class Display;
}

class Display : public QMainWindow
{
    Q_OBJECT

public:
    explicit Display(QWidget *parent = nullptr);
    ~Display();

    void setHealth();
    void printMessage(QString message);

public slots:
    void readInput();

private:
    Ui::Display *ui;

    manager king;

    QPalette tb = palette();
    QString prompt = ">>>";
};

#endif // Display_H
