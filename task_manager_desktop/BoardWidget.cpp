#include "BoardWidget.h"
#include "ui_BoardWidget.h"

#include <QInputDialog>
#include <QFileDialog>

#include <model/BoardModel.h>
#include <model/TaskModel.h>

BoardWidget::BoardWidget(QWidget *parent): 
	QWidget(parent),
	ui(new Ui::BoardWidget),
	boardModel(nullptr),
	boardSelectionModel(nullptr),
	taskModel(nullptr),
	taskSelectionModel(nullptr)
{
	ui->setupUi(this);
    clearUi();

    ui->taskListView->setSpacing(5);

}

BoardWidget::~BoardWidget()
{

}

void BoardWidget::clearUi()
{

}
