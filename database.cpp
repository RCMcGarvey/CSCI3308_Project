#include "database.h"


database::database()
{
        QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL");
        db.setHostName("ec2-54-225-76-136.compute-1.amazonaws.com");
        db.setDatabaseName("d4vqhahb2ccari");
        db.setUserName("kiqporjdqtmvlq");
        QString dbPass = qgetenv("");
        db.setPassword("df75c634d836ec46359fd12e8abb1f9dc0ec8e550a7e0634f0f32d278495ef2c");
        bool ok = db.open();
        if (ok){
            cout << "Database Connection Open!" << endl;
        }
        else {
            cout << "Database Connection Failed!!!" << endl;
        }
}


int database::addUser(QString username, QString usr_password)
{
    QSqlQuery query, unique_name;

    // Checks that username is unique
    QString check_name = "SELECT COUNT(*) from proj_schema.\"User\" where username = '" + username + "';";
    unique_name.exec(check_name);

    if(unique_name.next()){
        if(unique_name.value(0).toInt() == 0){
            QString execStr = "INSERT INTO proj_schema.\"User\"(username,usr_password)"
                              "VALUES('" + username + "', '" + usr_password + "');";
            query.exec(execStr);
        }
    }
    else {
        return -1;
    }

    return getUid(username); //CHANGE TO RETURN USER_ID

}


bool database::signIn(QString username, QString usr_password)
{
    int uid = getUid(username);
    QSqlQuery get_pass;

    QString execStr = "SELECT usr_password FROM proj_schema.\"User\" WHERE username ='" + username + "';";
    get_pass.exec(execStr);

    if(get_pass.next()){
        if(get_pass.value(0).toString() == usr_password){
            return true;
        }
   }

    return false;
}


int database::getUid(QString username)
{
    QSqlQuery query;
    QString execStr;

    execStr = "SELECT user_id FROM proj_schema.\"User\" WHERE username = '" + username + "';";

    query.exec(execStr);

    return query.value(0).toInt();

}


int database::addChar(QString char_name, QString user)
{
    QSqlQuery query, unique_name, update_usr;
    QString execStr,inventory, usr_str;

    // Checks that character name is unique
//    QString check_name = "SELECT COUNT(*) from proj_schema.\"Characters\" where name = '" + char_name + "';";
//    unique_name.exec(check_name);

//    if(unique_name.next()){
//        if(unique_name.value(0).toInt() == 0){
//            execStr = "INSERT INTO proj_schema.\"Characters\"(char_id, char_name)"
//                              "VALUES('" + char_name + "', '" + user + "');";
//            query.exec(execStr);
//        }
//        //usr_str = "UPDATE proj_schema.\"User\" SET characters";
//    }
//    else {
//        return -1;
//    }

    execStr = "INSERT INTO proj_schema.\"Characters\"(char_id, char_name)"
                                  "VALUES('" + char_name + "', '" + user + "');";
    query.exec(execStr);

    return getCharId(char_name);
}


int database::getCharId(QString char_name)
{
    QSqlQuery query;
    QString execStr;

    execStr = "SELECT user_id FROM proj_schema.\"Characters\" WHERE name = '" + char_name + "';";

    query.exec(execStr);

    if(query.next()){
        return query.value(0).toInt();
    }

    return -1;
}


void database::saveGame(QString char_name, QString game_data)
{

    QSqlQuery save_query;
    QString execStr;

    execStr = "UPDATE proj_schema.\"Characters\" SET char_string =" + game_data + " where name =" + char_name + ";";

    save_query.exec(execStr);

}


QString database::loadGame(QString char_name)
{
    QSqlQuery load_query;
    QString game_data, execStr;

    execStr = "SELECT char_string from proj_schema.\"Characters\" where name =" + char_name + ";";

    load_query.exec(execStr);

    if(load_query.next()){
        return load_query.value(0).toString();
    }

    return QString::number(-1);

}


database::~database()
{
    //Close database!!
    db.close();
    cout << "Database Connection Closed!" << endl;
}

