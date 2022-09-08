#ifndef DATABASE_SETUPER_H
#define DATABASE_SETUPER_H

#include "DatabaseConnection.h"

#include <QObject>

class DatabaseSetuper : public QObject
{   
    Q_OBJECT
public:
    DatabaseSetuper(QObject *parent = nullptr) : QObject(parent) {}
    void createDatabase(const QString& databaseName)
    {
        DatabaseConnection postgresDb("postgres");
        postgresDb.executeQuery("create database " + databaseName + ";");
    }

    Q_INVOKABLE void setupDatabase()
    {
        createDatabase("app_database");
        DatabaseConnection db("app_database");
        db.executeSqlFile(":/setupdb.sql");
    }
};

#endif
