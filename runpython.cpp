#include "runpython.h"
#include<QDebug>
#include<Python.h>
RunPython::RunPython(QObject *parent) : QObject(parent)
{
}

void RunPython::run()
{
    qDebug() << "run it!";
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
    PyObject * pFuncHello = PyObject_GetAttrString(pModule, "excel_process");
    //如果失败则返回
    if(!pFuncHello)
    {
        qDebug()<<"erro 3";
        PyErr_Print();
        return ;
    }
    //调用函数
    PyObject *fe = PyObject_CallNoArgs(pFuncHello);
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
    //退出
    PyErr_Print();
//    Py_Finalize();
}
