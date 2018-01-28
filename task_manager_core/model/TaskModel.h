#ifndef TASKMODEL_H
#define TASKMODEL_H

#include <model/BoardModel.h>
#include <QAbstractListModel>
#include <task_manager_core_global.h>
#include <memory>
#include <vector>
#include <entity/Task.h>

class TASK_MANAGER_CORESHARED_EXPORT TaskModel : public QAbstractListModel
{
    Q_OBJECT
public:
    TaskModel(const BoardModel &boardModel, QObject* parent = 0);

    QModelIndex addTask(const Task& task);

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role) const override;
    bool setData(const QModelIndex &index, const QVariant &map, int role) override;

    void setBoardId(int boardId);
    void clearBoard();
private:
    void loadTasks(int boardId);
    bool isIndexValid(const QModelIndex& index) const;

public slots:
    void deleteTaskForBoard();

public:
    enum Roles {
        DescriptionRole = Qt::UserRole + 1
    };
private:
    DatabaseManager &db;
    unsigned int boardId;
    std::unique_ptr<std::vector<std::unique_ptr<Task>>> taskList;
};

#endif // TASKMODEL_H
