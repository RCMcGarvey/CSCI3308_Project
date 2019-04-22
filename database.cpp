#include "database.h"

database::database()
{
        QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL");
        db.setHostName("127.0.0.1");
        db.setDatabaseName("proj_db");
        db.setUserName("csci3308_proj");
        QString dbPass = qgetenv("DBPASS");
        db.setPassword(dbPass);
        bool ok = db.open();
        if (ok){
            cout << "Database Connection Open!" << endl;
        }
        else {
            cout << "Database Connection Failed!!!" << endl;
            throw;
        }
}


void database::addUser(QString username, QString usr_password)
{
    QSqlQuery query;

    QString execStr = "INSERT INTO proj_schema.\"User\"(username,usr_password)"
                      "VALUES('" + username + "', '" + usr_password + "');";

    query.exec(execStr);

}


database::~database()
{
    //Close database!!
    db.close();
}

