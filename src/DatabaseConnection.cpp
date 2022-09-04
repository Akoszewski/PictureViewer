#include "DatabaseConnection.h"

DatabaseConnection::DatabaseConnection(const QString& dbname)
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

DatabaseConnection::~DatabaseConnection()
{
    {
        QSqlDatabase db = QSqlDatabase::database();
        db.close();
    }
    QSqlDatabase::removeDatabase(QSqlDatabase::defaultConnection);
}

QList<QList<QString>> DatabaseConnection::executeQuery(const QString& queryStr, ExecutionMode mode)
{
    QSqlQuery query;
    if (!query.exec(queryStr)) {
        qDebug() << "Failed:" << queryStr << " Reason:" << query.lastError();
    }

    QList<QList<QString>> result;
    while (query.next()) {
        QSqlRecord record = query.record();
        QList<QString> resultRow;
        for (int i = 0; i < record.count(); ++i) {
            resultRow.append(record.value(i).toString());
        }
        if (mode == ExecutionMode::Print) {
            qDebug() << resultRow.join(" ");
        }
        result.append(resultRow);
    }
    return result;
}

void DatabaseConnection::executeSqlFile(const QString& fileName)
{
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qCritical() << "Failed to open sql file: " << fileName;
        return;
    }

    QTextStream in(&file);
    QString sqlCode = in.readAll();
    QStringList statements = sqlCode.split(';', Qt::SkipEmptyParts);
 
    for (const QString& statement : statements) {
        if (statement.trimmed() != "") {
            executeQuery(statement, ExecutionMode::Print);
        }
    }
}
