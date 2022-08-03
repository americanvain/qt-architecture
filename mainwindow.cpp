#include <Python.h>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<mybutton.h>
#include"excel_data.h"
#include<QFile>
#include<QTextStream>
#include<QFileDialog>
#include<QMessageBox>

#include<QJsonObject>
#include<QJsonDocument>

//void PythonInit()
//{
//    if (!Py_IsInitialized())
//    {
//        //1.初始化Python解释器，这是调用操作的第一步
//        Py_Initialize();
//        if (!Py_IsInitialized()) {
//            qDebug("Initial Python failed!");
////            emit failed();
//        }
//        else {

//            //执行单句Python语句，用于给出调用模块的路径，否则将无法找到相应的调用模块
//            PyRun_SimpleString("import sys");
//            QString setSysPath = QString("sys.path.append('%1')").arg(QCoreApplication::applicationDirPath());
//            PyRun_SimpleString(setSysPath.toStdString().c_str());
//            // 初始化线程支持
////            PyEval_InitThreads();
//            // 启动子线程前执行，为了释放PyEval_InitThreads获得的全局锁，否则子线程可能无法获取到全局锁。
//            PyEval_ReleaseThread(PyThreadState_Get());
//            qDebug("Initial Python Success!");

//        }
//    }

//}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
//    PythonInit();
    ui->setupUi(this);
    f= new RunPython;
    f->cui=ui;
    connect(ui->MyButton,&MyButton::clicked,f,&RunPython::run);
    connect(ui->But_daying,&QPushButton::clicked,f,&RunPython::run_xieru);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_but_txt_clicked()
{
    //选择保存路径
    QString textfileName = QFileDialog::getSaveFileName(this, tr("save text"),
                                                     "",
                                                     tr("json(*.json)"));
    QFile file(textfileName);
    if(!file.open(QFile::WriteOnly|QFile::Text))
    {
        QMessageBox::information(this,"警告","请选择正确的文件！");
        return;
    }
    QTextStream out(&file);  //QTextStream会自动将 Unicode 编码同操作系统的编码进行转换

    Excel_data a;
    a.set_name(ui->label_2->text());
    a.value_=ui->lineEdit_hunningtudengji->text();

//    out<<"name"<<a.get_name()<<":";
    Excel_data b;
    b.set_name(ui->label->text());
    b.value_=ui->lineEdit_zhanglakongzhixishu->text();
//    out<<ui->lineEdit_zhanglakongzhixishu->text();
    // 使用QJsonObject对象插入键值对。
    QJsonObject jsonObject;
    jsonObject.insert(a.get_name(), a.value_);
    jsonObject.insert(b.get_name(), b.value_);
    jsonObject.insert("SerialNumber", "123abc");

    // 使用QJsonDocument设置该json对象
    QJsonDocument jsonDoc;
    jsonDoc.setObject(jsonObject);

    // 将json以文本形式写入文件并关闭文件。
    file.write(jsonDoc.toJson());
    file.close();
}

