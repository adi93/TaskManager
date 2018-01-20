#ifndef TASK_H
#define TASK_H

#include <QString>



class Task
{
public:
    explicit Task(const QString& name = "", const QString& description = "");
    unsigned int getId() const;
    void setId(unsigned int value);

    QString getName() const;
    void setName(const QString &value);

    QString getDescription() const;
    void setDescription(const QString &value);

private:
    unsigned int id;
    QString name;
    QString description;
};

#endif // TASK_H
