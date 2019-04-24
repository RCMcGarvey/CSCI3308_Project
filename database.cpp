#include "database.h"
#include <QtDebug>

database::database()
{
        QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL");
        db.setHostName("127.0.0.1");
        db.setDatabaseName("csci3308_proj");
        db.setUserName("postgres");
        QString dbPass = qgetenv("DBPASS");

        qDebug() << dbPass;
        db.setPassword("OpenSesame");
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

