#ifndef BOARD_H
#define BOARD_H
#include "task_manager_core_global.h"

#include <QString>

class TASK_MANAGER_CORESHARED_EXPORT Board
{
public:
    explicit Board(const QString& name = "");

    int getId() const;
    void setId(int value);

    QString getName() const;
    void setName(const QString &value);

private:
    unsigned int id;
    QString name;
};

#endif // BOARD_H
