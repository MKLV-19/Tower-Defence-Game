#include "point.h"

Point::Point(){}//默认构造
Point::Point(float x,float y)//普通构造
{
    _x=x;
    _y=y;
}
Point::Point(const Point& p)//复制构造
{
    _x=p.getX();
    _y=p.getY();
}
Point::Point(QMouseEvent* e)//鼠标构造
{
    _x=e->x();
    _y=e->y();
}
void Point::setMousePoint(QMouseEvent *e)//用鼠标坐标修改点的坐标
{
    _x=e->x();
    _y=e->y();
}

//完成
