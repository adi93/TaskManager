#include "BoardModel.h"

BoardModel::BoardModel(QObject *parent) :
    QAbstractListModel(parent),
    db(DatabaseManager::instance()),
    boardList(db.boardDao.boards())
{
}

int BoardModel::rowCount(const QModelIndex &parent) const
{
    return boardList->size();
}

QVariant BoardModel::data(const QModelIndex &index, int role) const
{
    if (!isIndexValid(index)) {
        return QVariant();
    }
    const Board& board = *boardList->at(index.row());
    switch (role) {
    case Roles::IdRoles:
        return board.getId();
    case Roles::NameRole:
    case Qt::DisplayRole:
        return board.getName();
    default:
        return QVariant();
    }
}

QHash<int, QByteArray> BoardModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles.insert(Roles::IdRoles, "id");
    roles.insert(Roles::NameRole, "name");
    return roles;
}

QModelIndex BoardModel::addBoard(const Board &board)
{
    int rowIndex = rowCount();
    beginInsertRows(QModelIndex(), rowIndex, rowIndex);
    std::unique_ptr<Board> newBoard(new Board(board));
    db.boardDao.addBoard(*newBoard);
    boardList->push_back(std::move(newBoard));
    endInsertRows();
    return index(rowIndex, 0);
}

bool BoardModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (!isIndexValid(index) || role != Roles::NameRole) {
        return false;
    }
    Board& board = *boardList->at(index.row());
    board.setName(value.toString());
    db.boardDao.updateBoard(board);
    emit dataChanged(index, index);
    return true;
}

bool BoardModel::removeRows(int row, int count, const QModelIndex &parent)
{
    if (row < 0 || count < 0 || (row + count) >= rowCount())
        return false;
    beginRemoveRows(QModelIndex(), row, row + count);
    int countLeft = count;
    while(countLeft--) {
        const Board& board = *boardList->at(row + countLeft);
        db.boardDao.removeBoard(board.getId());
    }
    boardList->erase(boardList->begin() + row, boardList->begin() + row + count);
    endRemoveRows();
    return true;
}

bool BoardModel::isIndexValid(const QModelIndex &index) const
{
    return index.row() >= 0 && index.row() < rowCount() && index.isValid();
}
