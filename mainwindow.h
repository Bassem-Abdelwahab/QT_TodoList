#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSignalMapper>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_addTaskButton_clicked();
    void on_task_created(QString taskName);
    void on_itemEdit_clicked(int index);
    void on_itemDelete_clicked(int index);

private:
    Ui::MainWindow *ui;
    QSignalMapper *editMapper;
    QSignalMapper *deleteMapper;


};
#endif // MAINWINDOW_H
