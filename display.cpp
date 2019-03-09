#include "display.h"
#include "ui_display.h"

Display::Display(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Display)
{
    ui->setupUi(this);

    ui->lineEdit->setText(prompt);

    connect(ui->lineEdit, SIGNAL(returnPressed()), this, SLOT(readInput()));

    tb.setColor(QPalette::Base, Qt::black);
    tb.setColor(QPalette::Text, Qt::white);
    ui->textEdit->setPalette(tb);
    ui->lineEdit->setPalette(tb);
}

Display::~Display()
{
    delete ui;
}

void Display::readInput()
{
    //king.parseLine(ui->lineEdit->text());
    ui->lineEdit->clear();
    ui->lineEdit->setText(prompt);
}

void Display::setHealth()
{
    ui->progressBar->setValue(king.getPlayerHealth());
}
