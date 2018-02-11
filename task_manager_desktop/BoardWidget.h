#ifndef BOARDWIDGET_H
#define BOARDWIDGET_H

#include <QWidget>

class BoardModel;
class QItemSelectionModel;
class TaskModel;
namespace Ui {
	class BoardWidget;
}
class BoardWidget: public QWidget
{
    Q_OBJECT
public:
    explicit BoardWidget(QWidget *parent = 0);
    ~BoardWidget();

    void setBoardModel(BoardModel* boardModel);
    void setBoardSelectionModel(QItemSelectionModel *selectionModel);
    void setTaskModel(TaskModel* taskModel);
    void setTaskSelectionModel(QItemSelectionModel *selectionModel);

signals:
    void taskActivated(const QModelIndex& taskIndex);

private:
    void clearUi();
    void loadBoard(const QModelIndex& boardIndex);

private:
	Ui::BoardWidget* ui;

	BoardModel* boardModel;
	QItemSelectionModel* boardSelectionModel;

	TaskModel* taskModel;
	QItemSelectionModel* taskSelectionModel;

};

#endif // BOARDWIDGET_H
