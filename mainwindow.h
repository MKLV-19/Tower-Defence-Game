#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QWidget>
#include <QKeyEvent>
#include <QMouseEvent>
#include <QTimer>
#include <QPainter>
#include <QPushButton>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include "stage.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    //类外定义
    void paintEvent(QPaintEvent* e);//重载paintEvent函数
    int checkScore();

protected:
    void keyPressEvent(QKeyEvent* e);
    void mousePressEvent(QMouseEvent* e);
    void mouseMoveEvent(QMouseEvent* e);
    void mouseReleaseEvent(QMouseEvent* e);//重载操作函数

private slots:
    void add_money();
    void set_Stage();
    void show_Lose();
    void show_Win();
    void on_pushButton_play_clicked();
    void on_pushButton_help_clicked();


private:
    Ui::MainWindow *ui;


    Stage world;//游戏主体
    QPixmap* mainBG;//游戏主场景

    QMediaPlaylist* bgmlist;//背景播放列表
    QMediaPlayer* bgm;//游戏背景音乐

    QTimer* refresher;//刷新
    QTimer* addmoney;//定时加金币
    QTimer* setstage;//定时切换场景

};

#endif // MAINWINDOW_H
