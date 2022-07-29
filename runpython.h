#ifndef RUNPYTHON_H
#define RUNPYTHON_H

#include <QObject>
class RunPython : public QObject
{
    Q_OBJECT
public:
    explicit RunPython(QObject *parent = nullptr);

signals:

public slots:
    void run();
};

#endif // RUNPYTHON_H
