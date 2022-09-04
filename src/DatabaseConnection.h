#ifndef DATABASE_CONNECTION_H
#define DATABASE_CONNECTION_H

#include <QtSql>

class DatabaseConnection
{
public:
    enum class ExecutionMode
    {
        Silent,
        Print
    };
    DatabaseConnection(const QString& dbname);
    ~DatabaseConnection();
    void executeQuery(const QString& queryStr, ExecutionMode mode = ExecutionMode::Silent);
    void printQueryResult(QSqlQuery& query);
    void executeSqlFile(const QString& fileName);
private:
    QString postgresPassword;
    QString name;
};

#endif
