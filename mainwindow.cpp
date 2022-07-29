#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<mybutton.h>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    f= new RunPython;
    connect(ui->MyButton,&MyButton::clicked,f,&RunPython::run);
}

MainWindow::~MainWindow()
{
    delete ui;
}

