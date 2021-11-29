#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
#include "tasklistitem.h"
#include "createtaskdialog.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)

{
    ui->setupUi(this);
    editMapper = new QSignalMapper(parent);
    deleteMapper = new QSignalMapper(parent);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_addTaskButton_clicked()
{
    createTaskDialog dialog;

    dialog.setModal(true);
    connect(&dialog , &createTaskDialog::on_createTaskButton_clicked , this , &MainWindow::on_task_created);
    dialog.exec();
}

void MainWindow::on_task_created(QString taskName)
{
    TaskListItem *tempListItem = new TaskListItem(ui->listWidget , taskName , ui->listWidget->count());
    QListWidgetItem *tempwidgeitem = new QListWidgetItem(ui->listWidget);
//    connect(tempListItem , &TaskListItem::on_editButton_clicked , this , &MainWindow::on_itemEdit_clicked);
//    connect(tempListItem , &TaskListItem::on_editButton_clicked , editMapper, &QSignalMapper::map);
//    connect(tempListItem , &TaskListItem::on_editButton_clicked , editMapper , SLOT(QSignalMapper::map()));
//    editMapper->setMapping(tempListItem , ui->listWidget->count());
    connect(tempListItem , &TaskListItem::on_editButton_clicked , this , &MainWindow::on_itemEdit_clicked);

//    connect(tempListItem , &TaskListItem::on_deleteButton_clicked , deleteMapper, &QSignalMapper::map);
//    deleteMapper->setMapping(tempListItem , ui->listWidget->count());
    connect(tempListItem , &TaskListItem::on_deleteButton_clicked , this , &MainWindow::on_itemDelete_clicked);

    tempwidgeitem->setFlags(Qt::NoItemFlags);
    ui->listWidget->addItem(tempwidgeitem);
    ui->listWidget->setItemWidget(tempwidgeitem,tempListItem);
}

void MainWindow::on_itemEdit_clicked(int index)
{
    ((TaskListItem*)ui->listWidget->itemWidget(ui->listWidget->item(index)))->renameTask("Kaaak");
}

void MainWindow::on_itemDelete_clicked(int index)
{
    for(int i = index+1 ; i < ui->listWidget->count() ; i++)
    {
        ((TaskListItem*)ui->listWidget->itemWidget(ui->listWidget->item(i)))->reindex(i-1);
    }
    delete ui->listWidget->item(index);
}

