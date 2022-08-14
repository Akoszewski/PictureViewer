#ifndef DATABASE_H
#define DATABASE_H

#include <QtSql>

class Database
{
public:
    enum class ExecutionMode
    {
        Silent,
        Print
    };
    Database(const QString& dbname);
    ~Database();
    void executeQuery(const QString& queryStr, ExecutionMode mode = ExecutionMode::Silent);
    void printQueryResult(QSqlQuery& query);
    void executeSqlFile(const QString& fileName);
private:
    QString postgresPassword;
    QString name;
};

#endif
