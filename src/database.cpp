#include "database.h"

Database::Database()
{
    db = QSqlDatabase::addDatabase("QPSQL"); // Will use the driver referred to by "QPSQL" (PostgreSQL Driver) 
    db.setHostName("localhost");
    db.setDatabaseName("app_database");
    db.setUserName("postgres");
    db.setPassword("haslo123");
    
    bool res = db.open();
    if (res) {
        QSqlQuery query("SELECT * FROM patients");
        while (query.next()) {
          QString name = query.value(1).toString();
          QString surname = query.value(2).toString();
          QString age = query.value(3).toString();
          qDebug() << name << " " << surname << " " << age;
        }
    } else {
        qCritical() << "Error opening database: " << db.lastError();
    }
}

Database::~Database()
{
    db.close();
}
