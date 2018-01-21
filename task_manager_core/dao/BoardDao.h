#ifndef BOARD_DAO_H
#define BOARD_DAO_H

#include <vector>
#include <memory>

class QSqlDatabase;
class Board;

class BoardDao
{
public:
    BoardDao(QSqlDatabase& database);
    void init() const;

    const Board getBoard(const int boardId) const;
    void addBoard(Board& board) const;
    void removeBoard(const int boardId) const;
    void updateBoard(Board& board) const;

    std::unique_ptr<std::vector<std::unique_ptr<Board>>> boards() const;
private:
    QSqlDatabase& database;
};

#endif // BOARD_DAO_H
