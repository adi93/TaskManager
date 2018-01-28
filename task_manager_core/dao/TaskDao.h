#ifndef TASK_DAO_H
#define TASK_DAO_H

#include <QString>
#include <memory>
#include <vector>
class QSqlDatabase;
class Task;
class QSqlQuery;
class Picture;

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
    std::unique_ptr<std::vector<std::unique_ptr<Task>>> tasks() const;
    std::unique_ptr<std::vector<std::unique_ptr<Task>>> tasksForBoard(int boardId) const;

private:
    QSqlDatabase& database;
    std::unique_ptr<std::vector<std::unique_ptr<Task>>> prepareTaskList(QSqlQuery& query) const;
};

#endif // TASK_DAO_H
