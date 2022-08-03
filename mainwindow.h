#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "runpython.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    RunPython* f;         //新加
private slots:
    void on_but_txt_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
