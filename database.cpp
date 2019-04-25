#include "database.h"
#include <QtDebug>

database::database()
{
        QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL");
        db.setHostName("ec2-54-225-76-136.compute-1.amazonaws.com");
        db.setDatabaseName("d4vqhahb2ccari");
        db.setUserName("kiqporjdqtmvlq");
        //QString dbPass = qgetenv();

        //qDebug() << dbPass;
        //db.setPassword("");
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

