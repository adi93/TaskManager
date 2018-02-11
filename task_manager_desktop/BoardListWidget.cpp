
#include "BoardListWidget.h"
#include "ui_BoardListWidget.h"

#include <QInputDialog>
#include <model/BoardModel.h>

BoardListWidget::BoardListWidget(QWidget *parent):
    QWidget(parent),
    ui(new Ui::BoardListWidget),
    boardModel(nullptr)
{
    ui->setupUi(this);
    connect(ui->createBoardButton, &QPushButton::clicked, this, &BoardListWidget::createBoard);
}

BoardListWidget::~BoardListWidget()
{
    delete ui;
}

void BoardListWidget::setModel(BoardModel *model)
{
    boardModel = model;
    ui->boardList->setModel(boardModel);
}

void BoardListWidget::setSelectionModel(QItemSelectionModel *selectionModel)
{
    ui->boardList->setSelectionModel(selectionModel);
}

void BoardListWidget::createBoard()
{
    if (!boardModel)
        return;
    bool ok;
    QString boardName = QInputDialog::getText(this, "Create a new board", "Choose a name", QLineEdit::Normal, "New Board", &ok );
    if (ok && !boardName.isEmpty()) {
        Board board(boardName);
        QModelIndex index = boardModel->addBoard(board);
        ui->boardList->setCurrentIndex(index);
    }
}
