#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtSql>
#include <iostream>

void database()
{
    std::string password;
    std::cout << std::endl;
    std::cout << "Type password: ";
    std::cin >> password;

    QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL"); // Will use the driver referred to by "QPSQL" (PostgreSQL Driver) 
    db.setHostName("localhost");
    db.setDatabaseName("app_database");
    db.setUserName("postgres");
    db.setPassword(QString::fromStdString(password));
    
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

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;
    database();
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    return app.exec();
}

