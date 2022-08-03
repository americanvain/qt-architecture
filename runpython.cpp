#include "runpython.h"
#include<QDebug>
#include<Python.h>
//#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "pythreadstatelock.h"
RunPython::RunPython(QObject *parent) : QObject(parent)
{
}
void PythonInit()
{
    if (!Py_IsInitialized())
    {
        //1.初始化Python解释器，这是调用操作的第一步
        Py_Initialize();
        if (!Py_IsInitialized()) {
            qDebug("Initial Python failed!");
//            emit failed();
        }
        else {

            //执行单句Python语句，用于给出调用模块的路径，否则将无法找到相应的调用模块
            PyRun_SimpleString("import sys");
            QString setSysPath = QString("sys.path.append('%1')").arg(QCoreApplication::applicationDirPath());
            PyRun_SimpleString(setSysPath.toStdString().c_str());
            // 初始化线程支持
//            PyEval_InitThreads();
            // 启动子线程前执行，为了释放PyEval_InitThreads获得的全局锁，否则子线程可能无法获取到全局锁。
            PyEval_ReleaseThread(PyThreadState_Get());
            qDebug("Initial Python Success!");

        }
    }

}
void RunPython::run()
{
    PythonInit();
    qDebug() << "run it!";
//    Py_SetPythonHome((const wchar_t *)(L"C:/Users/zxf-pingban/AppData/Local/Programs/Python/Python310"));//设置环境变量
//    //进行初始化
//    Py_Initialize();
//    //如果初始化失败，返回
//    if(!Py_IsInitialized())
//    {
//        qDebug()<<"erro 1";
//        PyErr_Print();
//    }
//    //加载模块，模块名称为myModule，就是myModule.py文件
//    PyObject *pModule = PyImport_ImportModule("mainpytest");//D:/qt_doc/python_test2/debug/
//    //如果加载失败，则返回
//    if(!pModule)
//    {
//        qDebug()<<"erro 2";
//        PyErr_Print();
//        return;
//    }
//    //加载函数greatFunc
//    PyObject * pFuncHello = PyObject_GetAttrString(pModule, "printhaha");
//    //如果失败则返回
//    if(!pFuncHello)
//    {
//        qDebug()<<"erro 3";
//        PyErr_Print();
//        return ;
//    }
//    //调用函数
//    PyObject *fe = PyObject_CallNoArgs(pFuncHello);
//    if(fe==NULL)
//    {
//        qDebug()<<"erro 4";
//        PyErr_Print();
//        return ;
//    }
//    char* res ;
//        //读出结果
//    PyArg_Parse(fe,"s",&res);
//  //输出结果
//    qDebug()<<res;
//    //退出
//    PyErr_Print();
//    Py_Finalize();

    class PyThreadStateLock PyThreadLock;//获取全局锁
       PyObject* pModule = PyImport_ImportModule("mainpytest");
       if (!pModule) {
            qDebug() << "Cant open python file!\n";
            return;
       }

       PyObject *pFunhello = PyObject_GetAttrString(pModule, "printhaha");
       if(!pFunhello){
           qDebug() << "Get function hello failed!\n";
       }
   //    PyObject *pConstruct = PyInstanceMethod_New(pFunhello);
//       PyObject_CallFunction(pFunhello,NULL);
           //调用函数
       PyObject *pConstruct = PyInstanceMethod_New(pFunhello);
       PyObject *fe = PyObject_CallNoArgs(pConstruct);
       if(fe==NULL)
       {
           qDebug()<<"erro 4";
           PyErr_Print();
           return ;
       }
       char* res ;
           //读出结果
       PyArg_Parse(fe,"s",&res);
     //输出结果
       qDebug()<<res;
//       Py_Finalize();

}

void RunPython::run_xieru()
{
    qDebug() << "写入中";
    Py_SetPythonHome((const wchar_t *)(L"C:/Users/zxf-pingban/AppData/Local/Programs/Python/Python310"));//设置环境变量
    //进行初始化
    Py_Initialize();
    //如果初始化失败，返回
    if(!Py_IsInitialized())
    {
        qDebug()<<"erro 1";
        PyErr_Print();
    }
    //加载模块，模块名称为myModule，就是myModule.py文件
    PyObject *pModule = PyImport_ImportModule("mainpytest");//D:/qt_doc/python_test2/debug/
    //如果加载失败，则返回
    if(!pModule)
    {
        qDebug()<<"erro 2";
        PyErr_Print();
        return;
    }
    //加载函数greatFunc
    PyObject * pFuncHello = PyObject_GetAttrString(pModule, "excel_xieru");
    //如果失败则返回
    if(!pFuncHello)
    {
        qDebug()<<"erro 3";
        PyErr_Print();
        return ;
    }
    PyObject* pArgs;
    pArgs=PyTuple_New(2);
    //调用函数
    const char *ch1,*ch2;           //将qstring转换为const char*,先将qstring转为std::string,再转为const char*
    std::string ch =this->cui->lineEdit_hunningtudengji->text().toStdString();
    ch1=ch.c_str();
    ch =this->cui->lineEdit_zhanglakongzhixishu->text().toStdString();
    ch2=ch.c_str();;
    PyTuple_SetItem(pArgs, 0, Py_BuildValue("s", ch1));
    PyTuple_SetItem(pArgs, 1, Py_BuildValue("s", ch2));
    qDebug()<<this->cui->lineEdit_hunningtudengji->text();
    qDebug()<<this->cui->lineEdit_zhanglakongzhixishu->text();
     //调用hello函数
    PyObject* pReturn=PyObject_CallObject(pFuncHello,pArgs);

    if(pReturn==NULL)
    {
        qDebug()<<"erro 4";
        PyErr_Print();
        return ;
    }
    char* res ;
        //读出结果
    PyArg_Parse(pReturn,"s",&res);
  //输出结果
    qDebug()<<res;
    //退出
    PyErr_Print();
//    Py_Finalize();
}
