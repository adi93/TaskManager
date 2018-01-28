#include "TaskDao.h"
#include <QSqlQuery>

#include <QVariant>
#include <QSqlDatabase>
#include <QVector>
#include <entity/Task.h>

#include <memory>
#include <vector>

TaskDao::TaskDao(QSqlDatabase &database):
	database(database)
{
}

void TaskDao::init() const
{
    if(!database.contains("task")) {
        QSqlQuery query("CREATE TABLE task (id INTEGER PRIMARY KEY AUTOINCREMENT, name TEXT, "
                        "description TEXT, boardId UNSIGNED INT)", database);
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
		task.setBoardId(query.value("boardId").toInt());
	}
	return task;
}

void TaskDao::addTask(Task &task) const
{
	QSqlQuery query("INSERT INTO task (name, description, boardId) VALUES(:name, :description, boardId)", database);
	query.bindValue(":name", task.getName());
	query.bindValue(":description", task.getDescription());
	query.bindValue(":boardId", task.getBoardId());
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
	QSqlQuery query("UPDATE task SET name = :name, description = :description, boardId = :boardId WHERE id = :id", database);
	query.bindValue(":name", task.getName());
	query.bindValue(":description", task.getDescription());
	query.bindValue(":boardId", task.getBoardId());
	query.bindValue(":id", task.getId());
	query.exec();
}

void TaskDao::removeTasksForBoard(const int boardId) const
{
	QSqlQuery query("DELETE * FROM task where boardId = :boardId", database);
	query.bindValue(":boardId", boardId);
	query.exec();
}

std::unique_ptr<std::vector<std::unique_ptr<Task>>> TaskDao::tasks() const
{
	QSqlQuery query("SELECT * FROM task", database);
	return prepareTaskList(query);

}

std::unique_ptr<std::vector<std::unique_ptr<Task>>> TaskDao::tasksForBoard(int boardId) const
{
	QSqlQuery query("SELECT * FROM task WHERE boardId = :boardId", database);
	query.bindValue(":boardId", boardId);
	return prepareTaskList(query);

}

std::unique_ptr<std::vector<std::unique_ptr<Task>>> TaskDao::prepareTaskList(QSqlQuery &query) const
{

    std::unique_ptr<std::vector<std::unique_ptr<Task>>> taskList(new std::vector<std::unique_ptr<Task>>);
    while(query.next()) {
std::unique_ptr<Task> task(new Task());
		task->setId(query.value("id").toInt());
		task->setName(query.value("name").toString());
		task->setDescription(query.value("description").toString());
		task->setBoardId(query.value("boardId").toInt());
        taskList->push_back(std::move(task));
	}
	return taskList;
}

