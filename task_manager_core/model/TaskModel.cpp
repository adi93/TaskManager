#include "TaskModel.h"

TaskModel::TaskModel(const BoardModel &boardModel, QObject *parent):
    QAbstractListModel(parent),
    db(DatabaseManager::instance()),
    boardId(0),
    taskList(new std::vector<std::unique_ptr<Task>>)
{
    connect(&boardModel, &BoardModel::rowsRemoved, this, &TaskModel::deleteTaskForBoard);
}

QModelIndex TaskModel::addTask(const Task &task)
{
    int rowIndex = rowCount();
    beginInsertRows(QModelIndex(), rowIndex, rowIndex);
    std::unique_ptr<Task> newTask(new Task(task));
    db.taskDao.addTask(*newTask);
    taskList->push_back(std::move(newTask));
    endInsertRows();
    return index(rowIndex, 0);
}

int TaskModel::rowCount(const QModelIndex &parent) const
{
    return taskList->size();
}

QVariant TaskModel::data(const QModelIndex &index, int role) const
{
    if (!isIndexValid(index)) {
        return QVariant();
    }
    const Task& task= *taskList->at(index.row());
    switch (role) {
    case Roles::DescriptionRole:
        return task.getDescription();
    case Qt::DisplayRole:
        return task.getName();
    default:
        return QVariant();
    }
}

bool TaskModel::setData(const QModelIndex &index, const QVariant &map, int role)
{
    if (!map.canConvert<QMap<QString, QVariant>>() || !isIndexValid(index) || role != Qt::EditRole) {
        return false;
    }
    QMap<QString, QVariant> qvariantMap = map.toMap();
    Task &task = *taskList->at(index.row());
    task.setName(qvariantMap.value("name").toString());
    task.setDescription(qvariantMap.value("description").toString());
    db.taskDao.updateTask(task);
    emit dataChanged(index, index);
    return true;


}

void TaskModel::setBoardId(int boardId)
{
    beginResetModel();
    TaskModel::boardId = boardId;
    loadTasks(boardId);
    endResetModel();
}

void TaskModel::clearBoard()
{
    setBoardId(0);
}

void TaskModel::deleteTaskForBoard()
{
    db.taskDao.removeTasksForBoard(boardId);
    clearBoard();
}

void TaskModel::loadTasks(int boardId)
{
    if (boardId <= 0) {
        taskList.reset(new std::vector<std::unique_ptr<Task>>);
        return;
    }
    taskList = db.taskDao.tasksForBoard(boardId);
}

bool TaskModel::isIndexValid(const QModelIndex &index) const
{
    return index.row() >=0 && index.row() < rowCount() && index.isValid();
}
