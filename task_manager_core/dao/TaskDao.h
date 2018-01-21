#ifndef TASK_DAO_H
#define TASK_DAO_H

#include<QString>

class QSqlDatabase;
class Task;
class QSqlQuery;

class TaskDao
{
public:
    TaskDao(QSqlDatabase& database);
    void init() const;

    const Task getTask(const int taskId) const;
    void addTask(Task& task) const;
    void removeTask(const int taskId) const;
    void updateTask(const Task& task) const;


    void removeTasksForBoard(const int boardId) const;
    QVector<Task *> tasks() const;
    QVector<Task *> tasksForBoard(int boardId) const;

private:
    QSqlDatabase& database;
    QVector<Task *> prepareTaskList(QSqlQuery& query) const;
};

#endif // TASK_DAO_H
