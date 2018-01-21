#ifndef TASK_DAO_H
#define TASK_DAO_H

#include<QString>

class QSqlDatabase;
class Task;

class TaskDao
{
public:
    TaskDao(QSqlDatabase& database);
    void init() const;

    const Task getTask(const int taskId) const;
    void addTask(Task& task) const;
    void removeTask(const int taskId) const;
    void updateTask(const Task& task) const;

    QVector<Task *> tasks() const;
private:
    QSqlDatabase& database;
};

#endif // TASK_DAO_H
