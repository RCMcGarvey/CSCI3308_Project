#include "display.h"
#include "ui_display.h"



Display::Display(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Display)
{
    ui->setupUi(this);

    mainMenu();

    //ui->lineEdit->setText(prompt);

    //connect(ui->lineEdit, SIGNAL(returnPressed()), this, SLOT(readInput()));

    tb.setColor(QPalette::Base, Qt::black);
    tb.setColor(QPalette::Text, Qt::white);
    ui->textEdit->setPalette(tb);

    ui->progressBar->setStyleSheet("QProgressBar::chunk {background: rgb(150, 0, 20, 100%);}");
    ui->progressBar_2->setStyleSheet("QProgressBar::chunk {background: rgb(150, 0, 20, 100%);}");

    ui->progressBar_2->setVisible(false);

    box1 = false;

    ui->textEdit->setStyleSheet(QStringLiteral("font: 12pt \"times\";"));

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

    ui->textEdit->append(bossMan.getNarrative());
    ui->progressBar->setMaximum(bossMan.getPlayerHealth());
    ui->progressBar->setValue(bossMan.getPlayerHealth());
}

Display::~Display()
{
    delete ui;
}

void Display::mainMenu()
{
    ui->textEdit->setHtml("<center><big>Presented by some Swonky Creatures</big></center>");
    //QThread::sleep(10);
    //ui->textEdit->setText("Hi there");

}

void Display::on_moveButton_clicked()
{
    if(ui->moveButton->text() == "Move")
    {
        //ui->textEdit->append("Move Pushed");
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
    //ui->textEdit->append("You went north");
    ui->textEdit->append(bossMan.move(1));
    ui->northButton->setVisible(false);
    ui->eastButton->setVisible(false);
    ui->southButton->setVisible(false);
    ui->westButton->setVisible(false);
    ui->moveButton->setText("Move");
}

void Display::on_eastButton_clicked()
{
    //ui->textEdit->append("You went east");
    ui->textEdit->append(bossMan.move(2));
    ui->northButton->setVisible(false);
    ui->eastButton->setVisible(false);
    ui->southButton->setVisible(false);
    ui->westButton->setVisible(false);
    ui->moveButton->setText("Move");
}

void Display::on_westButton_clicked()
{
    //ui->textEdit->append("You went west");
    ui->textEdit->append(bossMan.move(4));
    ui->northButton->setVisible(false);
    ui->eastButton->setVisible(false);
    ui->southButton->setVisible(false);
    ui->westButton->setVisible(false);
    ui->moveButton->setText("Move");
}

void Display::on_southButton_clicked()
{
    //ui->textEdit->append("You go south");
    ui->textEdit->append(bossMan.move(3));
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
   currentButton = "Weapon";
   //ui->textEdit->append("You swing violently with your fists");
   ui->textEdit->append(bossMan.combatEvent(currentButton));
   //ui->textEdit->append(bossMan.getNarrative());
   ui->progressBar->setValue(bossMan.getPlayerHealth());
   ui->weaponButton->setVisible(false);
   ui->spellButton->setVisible(false);
   ui->fightButton->setText("Fight");
}

void Display::on_spellButton_clicked()
{
    currentButton ="Spell";

//    ui->textEdit->append("You flail your hands in an attempt to cast a spell.");
    ui->textEdit->append(bossMan.combatEvent(currentButton));
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
        ui->comboBox->clear();
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
        ui->comboBox->clear();
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
        ui->comboBox->clear();
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
        ui->comboBox->clear();
        ui->comboBox_2->clear();
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
        ui->comboBox->clear();
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

        if(button == "Swap" || button == "Use Item" || button == "Inspect" || button == "Drop")
        {
            for(int i = 0; i < bossMan.howManyItems(); ++i)
            {
                ui->comboBox->addItem(bossMan.getItem(i,2));
            }
        }
        else if(button == "Interact" || button == "Pick Up")
        {
            //ui->textEdit->append(QString::number(bossMan.howManyItems(),10));
            for(int i = 0; i < 4; ++i)
            {
                if(bossMan.getItem(i, 1) != "Nothing there")
                    ui->comboBox->addItem(bossMan.getItem(i,1));

            }
        }
    }
    else if (box == 2)
    {
        if(button == "Swap")
        {
            for(int i = 0; i < bossMan.howManyItems(); ++i)
            {
                ui->comboBox_2->addItem(bossMan.getItem(i,2));
            }
        }
    }
    else if(1)
    {

    }
}

void Display::on_comboBox_activated(int index)
{
    if(box1)
    {
        //bossMan.userInput(index);
        if(currentButton == "Use Item")
        {
            ui->comboBox->clear();
            on_useButton_clicked();
        }
        else if(currentButton == "Inspect")
        {
            ui->textEdit->append(bossMan.inspect(index));
            ui->comboBox->clear();
            on_inspectButton_clicked();
        }
        else if (currentButton == "Interact")
        {
            ui->comboBox->clear();
            ui->textEdit->append(bossMan.interact(index));
            on_interactButton_clicked();
        }
        else if (currentButton == "Pick Up")
        {
            if(bossMan.pickup(index) == false)
            {
                ui->textEdit->append("You need to drop an item");
                populateDropdown(2, "Drop");
                currentButton = "Drop";
                ui->comboBox_2->setVisible(true);
            }
            else
            {
                ui->textEdit->append("You picked up a " + ui->comboBox->currentText() + ".");
                ui->comboBox->clear();
            }
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
    if(currentButton == "Drop")
    {
        bossMan.drop(index);
    }
    else if(currentButton == "Swap")
    {
        bossMan.userInput(item, index);
        ui->comboBox->clear();
        ui->comboBox_2->clear();
        on_swapButton_clicked();
    }
}
