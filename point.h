#ifndef POINT_H
#define POINT_H

#include <QMouseEvent>

/*
说明：
自定义的点类
用于表示位置，向量，进行碰撞检测
*/

class Point
{
public:
    Point();
    Point(float x,float y);//构造函数
    Point(const Point& p);//复制构造函数
    Point(QMouseEvent* e);//用鼠标事件来构造一个点

    void setMousePoint(QMouseEvent* e);//用鼠标的坐标来给点赋值
    void setX(float x){_x=x;}
    void setY(float y){_y=y;}//单纯的赋坐标
    float getX()const{return _x;}
    float getY()const{return _y;}//返回坐标值

private:
    float _x,_y;//横纵坐标
};

#endif //POINT_H
