#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include<QString>
class QSqlDatabase;

const QString DATABASE_FILENAME = "task.db";
class DatabaseManager
{
public:
    static DatabaseManager instance();
    ~DatabaseManager();

protected:
    DatabaseManager(const QString& path = DATABASE_FILENAME);
private:
    DatabaseManager& operator =(const DatabaseManager& rhs);
    DatabaseManager(const DatabaseManager& rhs);

    QSqlDatabase *database;
};

#endif // DATABASEMANAGER_H
