#ifndef DATABASE_H
#define DATABASE_H

#include <QtSql>

class Database
{
public:
    Database(const QString& dbname);
    ~Database();
    void exampleQuery();
    void executeQuery(const QString& queryStr);
private:
    QString postgresPassword;
    QString name;
};

#endif
