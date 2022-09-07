#ifndef DATABASE_CREATOR_H
#define DATABASE_CREATOR_H

#include "DatabaseConnection.h"

#include <QObject>

class DatabaseCreator : public QObject
{
    Q_OBJECT
public:
    DatabaseCreator(QObject* parent = nullptr) : QObject(parent) {}

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
