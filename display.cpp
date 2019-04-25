#include "display.h"
#include "ui_display.h"



Display::Display(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Display)
{
    ui->setupUi(this);
    signin = false;
    ui->lineEdit_2->setEchoMode(QLineEdit::Password);
    ui->warrior->setVisible(false);
    ui->mage->setVisible(false);
    ui->bard->setVisible(false);
    ui->rogue->setVisible(false);
    ui->pushButton->setVisible(false);
    ui->pushButton_2->setVisible(false);
    ui->lineEdit->setVisible(false);
    ui->lineEdit_2->setVisible(false);


    gamestart = false;
    signin = false;


    tb.setColor(QPalette::Base, Qt::black);
    tb.setColor(QPalette::Text, Qt::white);
    ui->textEdit->setPalette(tb);

    ui->progressBar->setStyleSheet("QProgressBar::chunk {background: rgb(150, 0, 20, 100%);}");
    ui->progressBar_2->setStyleSheet("QProgressBar::chunk {background: rgb(150, 0, 20, 100%);}");

    ui->textEdit->setStyleSheet(QStringLiteral("font: 10pt \"times\";"));
    ui->label->setVisible(false);
    ui->InventoryButton->setVisible(false);
    ui->moveButton->setVisible(false);
    ui->fightButton->setVisible(false);
    ui->lookButton->setVisible(false);
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
    ui->label_2->setVisible(false);
    ui->progressBar->setVisible(false);
    ui->progressBar_2->setVisible(false);


}

Display::~Display()
{
    delete ui;
}

void Display::mainMenu()
{
    ui->lineEdit->setVisible(true);
    ui->lineEdit_2->setVisible(true);
    ui->textEdit->clear();
    ui->lineEdit_2->setEnabled(false);
    ui->textEdit->setHtml("<center><big>Developed by Swonky Creatures</big></center>"
                          "<br></br>"
                          "<center><big>The Spooky Mansion</big></center>");
    if (signin == false)
    {
        ui->textEdit->append("<br></br>Please sign in.");
        ui->textEdit->append("Username");
        ui->textEdit->append("Password");
    }
    else
    {
        ui->pushButton->setVisible(true);
        ui->pushButton_2->setVisible(true);
        ui->lineEdit_2->setVisible(false);
        ui->lineEdit->setEnabled(false);
    }

}

void Display::instructions()
{
    QString howYouDo = "-Basic interaction is through the push buttons.\n"
                       "-You are unable to move while there is an enemy in the same area you are.\n"
                       "-When you attack an enemy you can use a weapon or a spell.\n"
                       "    -Weapons can be used/picked up by Bards, Warriors, and Rogues.\n"
                       "    -Spells can be used/picked up Mages, Bards, and Rogues.\n"
                       "    -All other items can be picked up by the other classes.\n"
                       "    [Weapon, Spell, Armor, Item, Item, ...]\n"
                       "-Once a room has been cleared its state wont change.\n"
                       "Get to the end and dont die.";
    ui->textEdit->append(howYouDo);
}

void Display::startGame()
{
    ui->textEdit->clear();
    ui->warrior->setVisible(true);
    ui->mage->setVisible(true);
    ui->bard->setVisible(true);
    ui->rogue->setVisible(true);
    ui->textEdit->append("Please select your class\n"
                         "Warrior: Has more health and replaces its spell slot for a second weapon slot.\n"
                         "Mage: Second spell slot and no weapon slot.\n"
                         "Bard: Slightly less health but two extra item slots\n"
                         "Rogue: Normal inventory, has a crit chance");

}

void Display::andThusItBegins()
{
    ui->moveButton->setVisible(true);
    ui->fightButton->setVisible(true);
    ui->InventoryButton->setVisible(true);
    ui->lookButton->setVisible(true);
    ui->label->setVisible(true);
    ui->progressBar->setVisible(true);
    ui->textEdit->append(bossMan.startNarrative());
    ui->progressBar->setMaximum(bossMan.getPlayerHealth());
    ui->progressBar->setValue(bossMan.getPlayerHealth());
    ui->progressBar_2->setVisible(false);
    ui->progressBar_2->setMaximum(bossMan.enemyHealth());
    ui->label_2->setVisible(false);
    box1 = false;
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
        ui->progressBar_2->setValue(0);
        ui->progressBar_2->setVisible(false);
        ui->label_2->setVisible(false);
        ui->moveButton->setText("Cancel");
    }
    else
    {
        //ui->textEdit->append("You canceled");
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
    ui->progressBar_2->setMaximum(bossMan.enemyHealth());
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
    ui->progressBar_2->setMaximum(bossMan.enemyHealth());
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
    ui->progressBar_2->setMaximum(bossMan.enemyHealth());
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
    ui->progressBar_2->setMaximum(bossMan.enemyHealth());
    ui->northButton->setVisible(false);
    ui->eastButton->setVisible(false);
    ui->southButton->setVisible(false);
    ui->westButton->setVisible(false);
    ui->moveButton->setText("Move");
}

void Display::on_fightButton_clicked()
{
    if(bossMan.enemyHealth() != 0)
    {
        ui->progressBar_2->setValue(bossMan.enemyHealth());
        ui->progressBar_2->setVisible(true);
        ui->label_2->setVisible(true);
    }
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
        ui->progressBar_2->setVisible(false);
        ui->label_2->setVisible(false);
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
        ui->textEdit->append(bossMan.lookAround());
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
   ui->progressBar_2->setValue(bossMan.enemyHealth());
   ui->weaponButton->setVisible(false);
   ui->spellButton->setVisible(false);
   ui->lookButton->setEnabled(true);
   ui->fightButton->setText("Fight");
   if(bossMan.gameOver == true)
   {
       QTimer::singleShot(5000, this, SLOT(on_actionMain_Menu_triggered()));
   }
}

void Display::on_spellButton_clicked()
{
    currentButton ="Spell";

//    ui->textEdit->append("You flail your hands in an attempt to cast a spell.");
    ui->textEdit->append(bossMan.combatEvent(currentButton));
    ui->progressBar->setValue(bossMan.getPlayerHealth());
    ui->progressBar_2->setValue(bossMan.enemyHealth());
    ui->weaponButton->setVisible(false);
    ui->spellButton->setVisible(false);
    ui->lookButton->setEnabled(true);
    ui->fightButton->setText("Fight");
    if(bossMan.gameOver == true)
    {
        QTimer::singleShot(5000, this, SLOT(on_actionMain_Menu_triggered()));
    }
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
        if(currentButton == "Drop")
        {
            ui->comboBox->setVisible(false);
            ui->comboBox_2->setVisible(false);
            ui->comboBox->clear();
            ui->comboBox_2->clear();
        }
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
               ui->comboBox->addItem(bossMan.getItem(i,1));
            }
        }
    }
    else if (box == 2)
    {
        if(button == "Swap" || button == "Drop")
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
            ui->textEdit->append(bossMan.use(index));
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
                if(bossMan.role == 1)
                {
                    ui->textEdit->append("Warriors cant pick up spells");
                    ui->comboBox->clear();
                    on_pickupButton_clicked();
                }
                else if(bossMan.role == 2)
                {
                    ui->textEdit->append("Mages cant pick up weapons");
                    ui->comboBox->clear();
                    on_pickupButton_clicked();
                }
                else
                {
                    ui->textEdit->append("You need to drop an item");
                    populateDropdown(2, "Drop");
                    currentButton = "Drop";
                    ui->comboBox_2->setVisible(true);
                }
            }
            else
            {
                if(ui->comboBox->currentText() == "Nothing there")
                {
                    ui->textEdit->append("You cant pick up something that doesnt exist.");
                    ui->comboBox->clear();
                    on_pickupButton_clicked();
                }
                else
                {
                    ui->textEdit->append("You picked up a " + ui->comboBox->currentText() + ".");
                    ui->comboBox->clear();
                    on_pickupButton_clicked();
                }
            }
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
        ui->comboBox_2->clear();
        ui->comboBox->clear();
        on_pickupButton_clicked();
    }
    else if(currentButton == "Swap")
    {
        bossMan.swap(item, index);
        ui->comboBox->clear();
        ui->comboBox_2->clear();
        on_swapButton_clicked();
    }
}

void Display::on_actionMain_Menu_triggered()
{
    ui->InventoryButton->setVisible(false);
    ui->InventoryButton->setEnabled(true);
    ui->moveButton->setVisible(false);
    ui->moveButton->setEnabled(true);
    ui->fightButton->setVisible(false);
    ui->fightButton->setEnabled(true);
    ui->lookButton->setVisible(false);
    ui->lookButton->setEnabled(true);
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
    ui->label->setVisible(false);
    ui->label_2->setVisible(false);
    ui->progressBar->setVisible(false);
    ui->progressBar_2->setVisible(false);

    ui->lineEdit->setVisible(true);
    ui->lineEdit_2->setVisible(true);

    //bossMan.startGame();

    mainMenu();

}

void Display::on_actionHelp_triggered()
{
    instructions();
}

void Display::on_warrior_clicked()
{
   bossMan.setPlayerClass(1);
   ui->warrior->setVisible(false);
   ui->mage->setVisible(false);
   ui->bard->setVisible(false);
   ui->rogue->setVisible(false);
   ui->textEdit->clear();
   andThusItBegins();
}

void Display::on_mage_clicked()
{
    bossMan.setPlayerClass(2);
    ui->warrior->setVisible(false);
    ui->mage->setVisible(false);
    ui->bard->setVisible(false);
    ui->rogue->setVisible(false);
    ui->textEdit->clear();
    andThusItBegins();
}

void Display::on_bard_clicked()
{
    bossMan.setPlayerClass(3);
    ui->warrior->setVisible(false);
    ui->mage->setVisible(false);
    ui->bard->setVisible(false);
    ui->rogue->setVisible(false);
    ui->textEdit->clear();
    andThusItBegins();
}

void Display::on_rogue_clicked()
{
    bossMan.setPlayerClass(4);
    ui->warrior->setVisible(false);
    ui->mage->setVisible(false);
    ui->bard->setVisible(false);
    ui->rogue->setVisible(false);
    ui->textEdit->clear();
    andThusItBegins();
}

void Display::on_lineEdit_returnPressed()
{
    if(signin != true)
    {
        bossMan.setUser(ui->lineEdit->text());
        ui->lineEdit_2->setEnabled(true);
        ui->lineEdit->setEnabled(false);
    }
    else
    {
        if(currentButton == "New")
        {
            bossMan.setPlayerName(ui->lineEdit->text());
            bossMan.addChar();
            ui->lineEdit->clear();
            ui->lineEdit->setVisible(false);
            startGame();
        }
        else if(currentButton == "Load")
        {
            ui->lineEdit->clear();
            ui->lineEdit->setVisible(false);
            bossMan.loadGame();
            ui->textEdit->append(bossMan.startNarrative());

             ui->moveButton->setVisible(true);
             ui->fightButton->setVisible(true);
             ui->InventoryButton->setVisible(true);
             ui->lookButton->setVisible(true);
             ui->label->setVisible(true);
             ui->progressBar->setVisible(true);


        }
    }

}

void Display::on_lineEdit_2_returnPressed()
{
    bossMan.setPass(ui->lineEdit_2->text());
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_2->setVisible(false);
    if(currentButton == "exists")
    {
        if(bossMan.signIn())
        {
            signin = true;
            ui->textEdit->append("Signin Success");
            ui->pushButton->setVisible(true);
            ui->pushButton_2->setVisible(true);
        }
        else
        {
            ui->textEdit->append("Signin failed");
            ui->lineEdit_2->setVisible(true);
        }
    }
    else if(currentButton == "newusr")
    {
        bossMan.createUser();
        ui->textEdit->append("Created user");
        bossMan.signIn();
        ui->pushButton->setVisible(true);
        ui->pushButton_2->setVisible(true);
        signin = true;
    }
}

void Display::on_pushButton_clicked()
{
    ui->lineEdit->setEnabled(true);
    ui->textEdit->append("Please enter a character name.");
    currentButton = "New";
    ui->pushButton->setVisible(false);
    ui->pushButton_2->setVisible(false);
}


void Display::on_pushButton_2_clicked()
{
    ui->lineEdit->setEnabled(true);
    ui->textEdit->append("Please enter a character name.");
    currentButton = "Load";
    ui->pushButton->setVisible(false);
    ui->pushButton_2->setVisible(false);
    ui->textEdit->clear();
}

void Display::on_actionSave_triggered()
{
    bossMan.saveGame();
    ui->textEdit->append("Game saved");
}

void Display::on_exists_clicked()
{
    currentButton = "exists";
    ui->exists->setVisible(false);
    ui->newusr->setVisible(false);
    mainMenu();
}


void Display::on_newusr_clicked()
{
    currentButton = "newusr";
    ui->newusr->setVisible(false);
    ui->exists->setVisible(false);
    mainMenu();
}
