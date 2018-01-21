#include "TaskDao.h"
#include <QSqlQuery>

#include <QVariant>
#include <QSqlDatabase>
#include <QVector>
#include <entity/Task.h>

TaskDao::TaskDao(QSqlDatabase &database):
    database(database)
{
}

void TaskDao::init() const
{
    if(!database.contains("task")) {
        QSqlQuery query("CREATE TABLE task (id INTEGER PRIMARY KEY AUTOINCREMENT, name TEXT, description TEXT)", database);
        query.exec();
    }
}

const Task TaskDao::getTask(const int taskId) const
{
    QSqlQuery query("SELECT * FROM task WHERE id = :id", database);
    query.bindValue(":id", taskId);
    query.exec();

    Task task;
    if (query.size() == 1) {
        task.setId(query.value("id").toInt());
        task.setName(query.value("name").toString());
        task.setDescription(query.value("description").toString());
    }
    return task;
}

void TaskDao::addTask(Task &task) const
{
    QSqlQuery query("INSERT INTO task (name, description) VALUES(:name, :description)", database);
    query.bindValue(":name", task.getName());
    query.bindValue(":description", task.getDescription());
    query.exec();
    task.setId(query.lastInsertId().toInt());
}

void TaskDao::removeTask(const int taskId) const
{
    QSqlQuery query("DELETE * FROM task WHERE id = :id", database);
    query.bindValue(":id", taskId);
    query.exec();
}

void TaskDao::updateTask(const Task &task) const
{
    QSqlQuery query("UPDATE task SET name = :name, description = :description WHERE id = :id", database);
    query.bindValue(":name", task.getName());
    query.bindValue(":description", task.getDescription());
    query.bindValue(":id", task.getId());
    query.exec();
}

QVector<Task *> TaskDao::tasks() const
{
    QSqlQuery query("SELECT * FROM task", database);
    query.exec();
    QVector<Task *> taskList;
    while(query.next()) {
        Task* task = new Task();
        task->setId(query.value("id").toInt());
        task->setName(query.value("name").toString());
        task->setDescription(query.value("description").toString());
        taskList.append(task);
    }
    return taskList;
}
