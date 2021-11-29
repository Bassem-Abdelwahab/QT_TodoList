#ifndef CREATETASKDIALOG_H
#define CREATETASKDIALOG_H

#include <QDialog>
#include <QString>

namespace Ui {
class createTaskDialog;
}

class createTaskDialog : public QDialog
{
    Q_OBJECT

public:
    explicit createTaskDialog(QWidget *parent = nullptr);
    ~createTaskDialog();

signals:
    void on_createTaskButton_clicked(QString TaskName);

private slots:
    void on_createButton_clicked();

    void on_cancelButton_clicked();

private:
    Ui::createTaskDialog *ui;
};

#endif // CREATETASKDIALOG_H
