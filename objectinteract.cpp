#include "objectinteract.h"
#include <cmath>

ObjectInteract::ObjectInteract():icon()//构造函数初始化，但实质是什么也没有
{
    icon=new QPixmap;
    icon->load(":/picture/tower/tower_test0.png");//空地址，表示什么也没有
    width=100;
    height=100;
}
ObjectInteract::~ObjectInteract(){}//析构
void ObjectInteract::setCenterPos(float x, float y)
{
    CenterPos.setX(x);
    CenterPos.setY(y);//传入的是中心点坐标
}
void ObjectInteract::show(QPainter *p)
{
    p->drawPixmap(CenterPos.getX()-width/2,CenterPos.getY()-height/2,width,height,*icon);
    //画图操作，前两个值为左上角坐标，要用中心点减去二分之一长度
}
bool ObjectInteract::isMouseIn(QMouseEvent *e)//检测鼠标是否在图片上
{
    if(abs(e->x()-CenterPos.getX())<width/2&&abs(e->y()-CenterPos.getY())<height/2){
        return true;
    }else{
        return false;
    }
}
bool ObjectInteract::isPointIn(Point p)//检测点是否与图片重合
{
    if(abs(p.getX()-CenterPos.getX())<width/2&&abs(p.getY()-CenterPos.getY())<height/2){
        return true;
    }else{
        return false;
    }
}

//基本完成
