#include "Board.h"

Board::Board(const QString &name):
    id(0), name(name)
{

}

int Board::getId() const
{
    return id;
}

void Board::setId(int value)
{
    id = value;
}

QString Board::getName() const
{
    return name;
}

void Board::setName(const QString &value)
{
    name = value;
}
