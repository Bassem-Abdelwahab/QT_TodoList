#include "tasklistitem.h"


TaskListItem::TaskListItem(QWidget *parent , QString inputName , int index) : QWidget(parent)
{
    this->index = index;
    stateCheckBox = new QCheckBox("",parent);
    nameLabel = new QLabel(inputName , parent);
    deleteButton = new QPushButton("🗑" ,parent);
    editButton = new QPushButton("📝",parent);
    stateCheckBox->setSizePolicy(QSizePolicy::Maximum,QSizePolicy::Preferred);
    nameLabel->setSizePolicy(QSizePolicy::MinimumExpanding,QSizePolicy::Preferred);
    nameLabel->setAlignment(Qt::AlignCenter);
    deleteButton->setSizePolicy(QSizePolicy::Maximum,QSizePolicy::Preferred);
    deleteButton->setMinimumWidth(20);
    connect(deleteButton , &QPushButton::clicked , this , &TaskListItem::deleteButton_clicked);
    editButton->setSizePolicy(QSizePolicy::Maximum,QSizePolicy::Preferred);
    editButton->setMinimumWidth(20);
    connect(editButton , &QPushButton::clicked , this , &TaskListItem::editButton_clicked);
    QHBoxLayout *tempLayout =new QHBoxLayout(parent);
    tempLayout->setSizeConstraint(QLayout::SetMinimumSize);
    tempLayout->addWidget(stateCheckBox);
    tempLayout->addWidget(nameLabel);
    tempLayout->addWidget(deleteButton);
    tempLayout->addWidget(editButton);
    setLayout(tempLayout);
    setSizePolicy(QSizePolicy::MinimumExpanding , QSizePolicy::Preferred);
}

void TaskListItem::renameTask(QString name)
{
    nameLabel->setText(name);
}

void TaskListItem::reindex(int newIndex)
{
    index = newIndex;
}

void TaskListItem::editButton_clicked()
{
    emit this->on_editButton_clicked(index);
}

void TaskListItem::deleteButton_clicked()
{
    emit this->on_deleteButton_clicked(index);
}
