#include "createtaskdialog.h"
#include "ui_createtaskdialog.h"

createTaskDialog::createTaskDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::createTaskDialog)
{
    ui->setupUi(this);
}

createTaskDialog::~createTaskDialog()
{
    delete ui;
}

void createTaskDialog::on_createButton_clicked()
{
    emit on_createTaskButton_clicked(ui->taskNameLineEdit->text());
    this->close();
}


void createTaskDialog::on_cancelButton_clicked()
{
    this->close();
}

