#include "BoardDao.h"

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QVariant>

#include <entity/Board.h>
#include "DatabaseManager.h"


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

std::unique_ptr<std::vector<std::unique_ptr<Board>>> BoardDao::boards() const
{
    QSqlQuery query("SELECT * FROM board", database);
    query.exec();
    std::unique_ptr<std::vector<std::unique_ptr<Board>>> boardList(new std::vector<std::unique_ptr<Board>>());
    while(query.next()) {
        std::unique_ptr<Board> board(new Board());
        board->setId(query.value("id").toInt());
        board->setName(query.value("name").toString());
        boardList->push_back(std::move(board));
    }
    return boardList;
}
