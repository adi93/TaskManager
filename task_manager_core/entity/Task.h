#ifndef TASK_H
#define TASK_H

#include <QString>

#include "task_manager_core_global.h"
#include "Board.h"

class TASK_MANAGER_CORESHARED_EXPORT Task
{
public:
    explicit Task(const QString& name = "", const QString& description = "");
    unsigned int getId() const;
    void setId(unsigned int value);

    QString getName() const;
    void setName(const QString &value);

    QString getDescription() const;
    void setDescription(const QString &value);

    int getBoardId() const;
    void setBoardId(int value);

private:
    unsigned int id;
    QString name;
    QString description;
    int boardId;
};

#endif // TASK_H
