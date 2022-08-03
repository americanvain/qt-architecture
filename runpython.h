#ifndef RUNPYTHON_H
#define RUNPYTHON_H

#include <QObject>
#include "ui_mainwindow.h"
class RunPython : public QObject
{
    Q_OBJECT
public:
    explicit RunPython(QObject *parent = nullptr);

signals:

public slots:
    void run();
    void run_xieru();

public:
    Ui::MainWindow *cui;
};

#endif // RUNPYTHON_H
