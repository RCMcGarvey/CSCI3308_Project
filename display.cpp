#include "display.h"
#include "ui_display.h"


Display::Display(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Display)
{
    ui->setupUi(this);

    //ui->lineEdit->setText(prompt);

    //connect(ui->lineEdit, SIGNAL(returnPressed()), this, SLOT(readInput()));

    tb.setColor(QPalette::Base, Qt::black);
    tb.setColor(QPalette::Text, Qt::white);
    ui->textEdit->setPalette(tb);
    box1 = false;

    ui->northButton->setVisible(false);
    ui->eastButton->setVisible(false);
    ui->southButton->setVisible(false);
    ui->westButton->setVisible(false);
    ui->weaponButton->setVisible(false);
    ui->spellButton->setVisible(false);
    ui->useButton->setVisible(false);
    ui->inspectButton->setVisible(false);
    ui->swapButton->setVisible(false);
    ui->interactButton->setVisible(false);
    ui->pickupButton->setVisible(false);
    ui->comboBox->setVisible(false);
    ui->comboBox_2->setVisible(false);
    //ui->lineEdit->setVisible(false);


}

Display::~Display()
{
    delete ui;
}

void Display::setHealth()
{
    ui->progressBar->setValue(bossMan.getPlayerHealth());
}

void Display::on_moveButton_clicked()
{
    if(ui->moveButton->text() == "Move")
    {
        ui->textEdit->append("Move Pushed");
        ui->northButton->setVisible(true);
        ui->eastButton->setVisible(true);
        ui->southButton->setVisible(true);
        ui->westButton->setVisible(true);
        ui->moveButton->setText("Cancel");
    }
    else
    {
        ui->textEdit->append("You canceled");
        ui->northButton->setVisible(false);
        ui->eastButton->setVisible(false);
        ui->southButton->setVisible(false);
        ui->westButton->setVisible(false);
        ui->moveButton->setText("Move");
    }


}

void Display::on_northButton_clicked()
{
    ui->textEdit->append("You went north");
    ui->northButton->setVisible(false);
    ui->eastButton->setVisible(false);
    ui->southButton->setVisible(false);
    ui->westButton->setVisible(false);
    ui->moveButton->setText("Move");
}

void Display::on_eastButton_clicked()
{
    ui->textEdit->append("You went east");
    ui->northButton->setVisible(false);
    ui->eastButton->setVisible(false);
    ui->southButton->setVisible(false);
    ui->westButton->setVisible(false);
    ui->moveButton->setText("Move");
}

void Display::on_westButton_clicked()
{
    ui->textEdit->append("You went west");
    ui->northButton->setVisible(false);
    ui->eastButton->setVisible(false);
    ui->southButton->setVisible(false);
    ui->westButton->setVisible(false);
    ui->moveButton->setText("Move");
}

void Display::on_southButton_clicked()
{
    ui->textEdit->append("You went south");
    ui->northButton->setVisible(false);
    ui->eastButton->setVisible(false);
    ui->southButton->setVisible(false);
    ui->westButton->setVisible(false);
    ui->moveButton->setText("Move");
}

void Display::on_fightButton_clicked()
{
    if(ui->fightButton->text() == "Fight")
    {
        ui->spellButton->setVisible(true);
        ui->weaponButton->setVisible(true);
        ui->lookButton->setEnabled(false);
        ui->fightButton->setText("Back");
    }
    else
    {
        ui->spellButton->setVisible(false);
        ui->weaponButton->setVisible(false);
        ui->lookButton->setEnabled(true);
        ui->fightButton->setText("Fight");
    }
}

void Display::on_InventoryButton_clicked()
{
    if(ui->InventoryButton->text() == "Inventory")
    {
        ui->useButton->setVisible(true);
        ui->inspectButton->setVisible(true);
        ui->swapButton->setVisible(true);
        ui->fightButton->setEnabled(false);
        ui->weaponButton->setEnabled(false);
        ui->spellButton->setEnabled(false);
        ui->lookButton->setEnabled(false);
        ui->moveButton->setEnabled(false);
        ui->InventoryButton->setText("Back");
    }
    else
    {
        ui->useButton->setVisible(false);
        ui->inspectButton->setVisible(false);
        ui->swapButton->setVisible(false);
        ui->comboBox->setVisible(false);
        ui->comboBox_2->setVisible(false);
        ui->fightButton->setEnabled(true);
        ui->weaponButton->setEnabled(true);
        ui->spellButton->setEnabled(true);
        ui->lookButton->setEnabled(true);
        ui->moveButton->setEnabled(true);
        ui->InventoryButton->setText("Inventory");
    }
}

void Display::on_lookButton_clicked()
{
    if(ui->lookButton->text() == "Look Around")
    {
        ui->interactButton->setVisible(true);
        ui->pickupButton->setVisible(true);
        ui->lookButton->setText("Back");
    }
    else
    {
        ui->interactButton->setVisible(false);
        ui->pickupButton->setVisible(false);
        ui->comboBox->setVisible(false);
        ui->comboBox_2->setVisible(false);
        ui->lookButton->setText("Look Around");
    }
}

void Display::on_weaponButton_clicked()
{
   ui->textEdit->append("You swing violently with your fists");
   ui->weaponButton->setVisible(false);
   ui->spellButton->setVisible(false);
   ui->fightButton->setText("Fight");
}

void Display::on_spellButton_clicked()
{
    ui->textEdit->append("You flail your hands in an attempt to cast a spell.");
    ui->weaponButton->setVisible(false);
    ui->spellButton->setVisible(false);
    ui->fightButton->setText("Fight");

}

void Display::on_useButton_clicked()
{
    currentButton = "Use Item";
    if(ui->useButton->text() == "Use Item")
    {
        ui->comboBox->setVisible(true);
        populateDropdown(1, "Use Item");
        box1 = true;
        ui->InventoryButton->setEnabled(false);
        ui->inspectButton->setEnabled(false);
        ui->swapButton->setEnabled(false);
        ui->useButton->setText("Cancel");
    }
    else
    {
        ui->comboBox->setVisible(false);
        box1 = false;
        ui->InventoryButton->setEnabled(true);
        ui->inspectButton->setEnabled(true);
        ui->swapButton->setEnabled(true);
        ui->useButton->setText("Use Item");
    }
}

void Display::on_pickupButton_clicked()
{
    currentButton = "Pick Up";
    if(ui->pickupButton->text() == "Pick Up")
    {
        ui->comboBox->setVisible(true);
        populateDropdown(1, "Pick Up");
        box1 = true;
        ui->lookButton->setEnabled(false);
        ui->interactButton->setEnabled(false);
        ui->pickupButton->setText("Cancel");
    }
    else
    {
        ui->comboBox->setVisible(false);
        box1 = false;
        ui->lookButton->setEnabled(true);
        ui->interactButton->setEnabled(true);
        ui->pickupButton->setText("Pick Up");
    }
}

void Display::on_inspectButton_clicked()
{
    currentButton = "Inspect";
    if(ui->inspectButton->text() == "Inspect")
    {
        ui->comboBox->setVisible(true);
        populateDropdown(1, "Inspect");
        box1 = true;
        ui->InventoryButton->setEnabled(false);
        ui->useButton->setEnabled(false);
        ui->swapButton->setEnabled(false);
        ui->inspectButton->setText("Cancel");
    }
    else
    {
        ui->comboBox->setVisible(false);
        box1 = false;
        ui->InventoryButton->setEnabled(true);
        ui->useButton->setEnabled(true);
        ui->swapButton->setEnabled(true);
        ui->inspectButton->setText("Inspect");
    }
}

void Display::on_swapButton_clicked()
{
    currentButton = "Swap";
    if(ui->swapButton->text() == "Swap")
    {
        ui->comboBox->setVisible(true);
        populateDropdown(1, "Swap");
        ui->comboBox_2->setVisible(true);
        populateDropdown(2, "Swap");
        ui->comboBox_2->setEnabled(false);
        ui->InventoryButton->setEnabled(false);
        ui->useButton->setEnabled(false);
        ui->inspectButton->setEnabled(false);
        ui->swapButton->setText("Cancel");
    }
    else
    {
        ui->comboBox->setVisible(false);
        ui->comboBox_2->setVisible(false);
        ui->comboBox_2->setEnabled(true);
        ui->InventoryButton->setEnabled(true);
        ui->useButton->setEnabled(true);
        ui->inspectButton->setEnabled(true);
        ui->swapButton->setText("Swap");
    }
}

void Display::on_interactButton_clicked()
{
    currentButton = "Interact";
    if(ui->interactButton->text() == "Interact")
    {
        ui->comboBox->setVisible(true);
        populateDropdown(1, "Interact");
        box1 = true;
        ui->interactButton->setText("Cancel");
        ui->pickupButton->setEnabled(false);
        ui->lookButton->setEnabled(false);
    }
    else
    {
        ui->comboBox->setVisible(false);
        box1 = false;
        ui->interactButton->setText("Interact");
        ui->pickupButton->setEnabled(true);
        ui->lookButton->setEnabled(true);
    }
}

void Display::populateDropdown(int box, QString button)
{
    if(box == 1)
    {
        if(button == "Swap" || button == "Use Item" || button == "Inspect")
        {
            ui->comboBox->addItem("Slot 1");
            ui->comboBox->addItem("Slot 2");
            ui->comboBox->addItem("Slot 3");
            ui->comboBox->addItem("Slot 4");
            ui->comboBox->addItem("Slot 5");
            ui->comboBox->addItem("Slot 6");
            ui->comboBox->addItem("Slot 7");
            ui->comboBox->addItem("Slot 8");
        }
    }
    else if (box == 2)
    {
        if(button == "Swap")
        {
            ui->comboBox_2->addItem("Slot 1");
            ui->comboBox_2->addItem("Slot 2");
            ui->comboBox_2->addItem("Slot 3");
            ui->comboBox_2->addItem("Slot 4");
            ui->comboBox_2->addItem("Slot 5");
            ui->comboBox_2->addItem("Slot 6");
            ui->comboBox_2->addItem("Slot 7");
            ui->comboBox_2->addItem("Slot 8");
        }
    }
}

void Display::on_comboBox_activated(int index)
{
    if(box1)
    {
        bossMan.userInput(index);
        if(currentButton == "Use Item")
        {
            ui->comboBox->clear();
            on_useButton_clicked();
        }
        else if(currentButton == "Inspect")
        {
            ui->comboBox->clear();
            on_inspectButton_clicked();
        }
        else if (currentButton == "Interact")
        {
            ui->comboBox->clear();
            on_interactButton_clicked();
        }
        else if (currentButton == "Pick Up")
        {
            ui->comboBox->clear();
            on_pickupButton_clicked();
        }
    }
    else
    {
        item = index;
        ui->comboBox_2->setEnabled(true);
    }
}

void Display::on_comboBox_2_activated(int index)
{
    bossMan.userInput(item, index);
    ui->comboBox->clear();
    ui->comboBox_2->clear();
    on_swapButton_clicked();
}
