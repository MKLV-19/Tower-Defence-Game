#include "mainwindow.h"
#include <QApplication>
#include <QDebug>
#include <QtGlobal>
#include <QTime>

int main(int argc, char *argv[])
{
    QTime time;
    time=QTime::currentTime();//设置为当前系统时间
    qsrand(time.msec()+time.second()*1000);//随机种子
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("普通的塔防");
    a.connect(&a,SIGNAL(lastWindowClosed()),&a,SLOT(quit()));//最后一个窗口关闭才退出
    w.show();
    return a.exec();
}
