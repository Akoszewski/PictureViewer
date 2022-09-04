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
    QList<QList<QString>> executeQuery(const QString& queryStr, ExecutionMode mode = ExecutionMode::Silent);
    void executeSqlFile(const QString& fileName);
private:
    QString postgresPassword;
    QString name;
};

#endif
