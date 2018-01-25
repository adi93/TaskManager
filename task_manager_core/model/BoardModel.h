#ifndef BOARDMODEL_H
#define BOARDMODEL_H

#include <QAbstractListModel>
#include <QHash>
#include <memory>
#include <vector>

#include <entity/Board.h>
#include <task_manager_core.h>
#include <dao/DatabaseManager.h>


class TASK_MANAGER_CORESHARED_EXPORT BoardModel : public QAbstractListModel
{
    Q_OBJECT
//functions
public:
    BoardModel(QObject* parent = 0);


    //accessors
    int rowCount(const QModelIndex& parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QHash<int, QByteArray> roleNames() const override;

    //setters
    QModelIndex addBoard(const Board& board);
    bool setData(const QModelIndex &index, const QVariant &value, int role) override;
    bool removeRows(int row, int count, const QModelIndex &parent) override;
private:
    bool isIndexValid(const QModelIndex& index) const;

// data memebers
public:
    enum Roles {
        IdRoles = Qt::UserRole + 1,
        NameRole
    };
private:
    DatabaseManager& db;
    std::unique_ptr<std::vector<std::unique_ptr<Board>>> boardList;
};

#endif // BOARDMODEL_H
