#ifndef OBJECTINTERACT_H
#define OBJECTINTERACT_H

#include <QPainter>
#include <QPixmap>
#include <QMouseEvent>
#include "point.h"

/*
说明：
这个类是游戏的关键
因为是塔防类游戏，游戏中的各个元素必须有交互
这个类是炮塔，子弹，敌人等需要进行交互的各个类的基类
包含了游戏元素的最基本的信息：中心坐标，图片地址，长度，宽度

*/

class ObjectInteract
{
public:
    ObjectInteract();//默认构造
    ~ObjectInteract();//析构

    //类内定义
    Point getPos(){return CenterPos;}//返回中心点
    float getPos_x(){return CenterPos.getX();}
    float getPos_y(){return CenterPos.getY();}//返回中心点的横纵坐标
    int getWidth(){return width;}
    int getHeight(){return height;}//返回长度和高度

    //类外定义
    void setCenterPos(float x, float y);
    void show(QPainter* p);//每个实例都要进行绘制
    bool isMouseIn(QMouseEvent* e);//检测鼠标事件
    bool isPointIn(Point p);//检测两个点是否接触，即碰撞

protected:
    Point CenterPos;//每个物体的中点
    int width,height;//物体的长和高
    QPixmap* icon;//每个物体对应的素材图片
};

#endif //OBJECTINTERACT_H
