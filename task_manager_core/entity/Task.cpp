#include "Task.h"

Task::Task(const QString &name, const QString &description):
    id(0), name(name), description(description)
{

}

unsigned int Task::getId() const
{
    return id;
}

void Task::setId(unsigned int value)
{
    id = value;
}

QString Task::getName() const
{
    return name;
}

void Task::setName(const QString &value)
{
    name = value;
}

QString Task::getDescription() const
{
    return description;
}

void Task::setDescription(const QString &value)
{
    description = value;
}
