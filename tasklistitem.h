#ifndef TASKLISTITEM_H
#define TASKLISTITEM_H

#include <QWidget>
#include <QCheckBox>
#include <QLabel>
#include <QPushButton>
#include <QString>
#include <QHBoxLayout>

class TaskListItem : public QWidget
{
    Q_OBJECT
public:
    explicit TaskListItem(QWidget *parent = nullptr , QString inputName="(Default task name)" , int index = 0);
    void renameTask(QString name);
    void reindex(int newIndex);

signals:
    void on_editButton_clicked(int index);
    void on_deleteButton_clicked(int index);

private slots:
    void editButton_clicked();
    void deleteButton_clicked();



private:
    QCheckBox *stateCheckBox;
    QLabel *nameLabel;
    QPushButton *deleteButton;
    QPushButton *editButton;
    int index;
};

#endif // TASKLISTITEM_H
