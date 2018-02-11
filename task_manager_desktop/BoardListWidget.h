#ifndef BOARDLISTWIDGET_H
#define BOARDLISTWIDGET_H

#include <QItemSelectionModel>
#include <QWidget>

namespace Ui {
    class BoardListWidget;
}

class BoardModel;

class BoardListWidget: public QWidget
{
    Q_OBJECT
public:
    explicit BoardListWidget(QWidget* parent = 0);
    ~BoardListWidget();

    void setModel(BoardModel *model);
    void setSelectionModel(QItemSelectionModel *selectionModel);

private slots:
    void createBoard();

private:
    Ui::BoardListWidget* ui;
    BoardModel* boardModel;
};

#endif // BOARDLISTWIDGET_H
