#include "BoardDao.h"

#include <QVector>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <entity/Board.h>
#include <QVariant>


BoardDao::BoardDao(QSqlDatabase &database):
    database(database)
{
}

void BoardDao::init() const
{
    if (!database.contains("board")) {
        QSqlQuery query("CREATE TABLE board (id INTEGER PRIMARY KEY AUTOINCREMENT, name TEXT)", database);
        query.exec();
    }
}

const Board BoardDao::getBoard(const int boardId) const
{
    QSqlQuery query("SELECT * FROM board WHERE id = :id", database);
    query.bindValue(":id", boardId);
    query.exec();

    Board board;
    board.setId(query.value("id").toInt());
    board.setName(query.value("name").toString());
    return board;
}

void BoardDao::addBoard(Board &board) const
{
    QSqlQuery query("INSERT INTO board (name) VALUES (:name)", database);
    query.bindValue(":name", board.getName());
    query.exec();
    board.setId(query.lastInsertId().toInt());
}

void BoardDao::removeBoard(const int boardId) const
{
    QSqlQuery query("DELETE * FROM board WHERE id = :id", database);
    query.bindValue(":id", boardId);
    query.exec();
}

void BoardDao::updateBoard(Board &board) const
{
    QSqlQuery query("DELETE * FROM board WHERE id = :id", database);
    query.bindValue(":id", board.getId());
    query.exec();
}

QVector<Board *> BoardDao::boards()
{
    QSqlQuery query("SELECT * FROM board", database);
    query.exec();
    QVector<Board *> boardList;
    while(query.next()) {
        Board* board = new Board();
        board->setId(query.value("id").toInt());
        board->setName(query.value("name").toString());
        boardList.append(board);
    }
    return boardList;
}
