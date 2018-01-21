#include "DatabaseManager.h"

#include <QSqlDatabase>

DatabaseManager DatabaseManager::instance()
{
    static DatabaseManager singleton;
    return singleton;
}

DatabaseManager::~DatabaseManager()
{
    database->close();
    delete database;
}

DatabaseManager::DatabaseManager(const QString &path):
    database(new QSqlDatabase(QSqlDatabase::addDatabase("QSQLITE")))
{
    database->setDatabaseName(path);
    database->open();
}
