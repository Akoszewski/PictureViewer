#ifndef DATABASE_H
#define DATABASE_H

#include <QtSql>

class Database
{
public:
    Database();
    ~Database();
private:
    QSqlDatabase db;
};

#endif
