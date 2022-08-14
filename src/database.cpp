#include "database.h"

Database::Database(const QString& dbname)
    : name(dbname)
{
    postgresPassword = "haslo123";

    QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL");
    db.setHostName("localhost");
    db.setDatabaseName(name);
    db.setUserName("postgres");
    db.setPassword(postgresPassword);

    bool res = db.open();
    if (!res) {
        qCritical() << "Error opening database: " << db.lastError();
    }
}

Database::~Database()
{
    {
        QSqlDatabase db = QSqlDatabase::database();
        db.close();
    }
    QSqlDatabase::removeDatabase(QSqlDatabase::defaultConnection);
}

void Database::exampleQuery()
{
    QSqlQuery query("SELECT * FROM patients");
    while (query.next()) {
        QString name = query.value(1).toString();
        QString surname = query.value(2).toString();
        QString age = query.value(3).toString();
        qDebug() << name << " " << surname << " " << age;
    }
}

void Database::executeQuery(const QString& queryStr)
{
    QSqlQuery query(queryStr);
}
