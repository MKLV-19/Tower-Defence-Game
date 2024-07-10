#ifndef BULLET_H
#define BULLET_H

#include "tower.h"
#include "point.h"
#include "objectinteract.h"
#include "tool.h"

/*
说明：
这个类是子弹
ObjectInteract的子类
构造要依赖于塔和敌人，或塔和鼠标两个点，构造函数必须有两个参数
子弹的样式取决于发射它的炮塔
*/
class Bullet:public ObjectInteract
{
public:
    Bullet(Tower* parent,Enemy* target);//炮塔——敌人构造法
    Bullet(Tower* parent,Point target);//炮塔——鼠标构造法，传进去的是一个单位向量
    ~Bullet(){delete icon;}//析构，同时要删除子弹图片所占内存

    //类内定义
    int getDamage(){return damage;}//返回伤害
    int getSpeed(){return speed;}//返回速度
    int getSlow(){return slow;}//返回减速值
    int getToxic(){return toxic;}//返回中毒值
    int getCollisionTimes(){return collisontimes;}//返回碰撞次数
    float getDirection_x(){return direction_x;}
    float getDirection_y(){return direction_y;}//返回方向
    float getAngle(){return angle;}//返回朝向
    float getArea(){return Tool::distance(this->parent->getPos(),this->getPos());}//返回子弹与塔的距离
    float getLimit(){return this->parent->getRange();}//返回炮塔的攻击范围

    void subCollisionTimes(){collisontimes=collisontimes-1;}//可碰撞次数下降

    bool IsOutOfRange(){return ((getArea()>getLimit())?1:0);}

    //类外定义
    void show(QPainter* p);

protected:
    //静态属性
    Tower* parent;//发射子弹的炮塔
    //通过调用parent的type可以构造子弹的类型，从而确定以下各值
    int damage;//子弹伤害
    int speed;//子弹速度
    int slow;//子弹减速（只有特定子弹才会减速）
    int toxic;//子弹中毒（只有特定子弹才有中毒效果，每过一秒钟扣除一定血量）
    int collisontimes;//最大碰撞次数（属于更新内容，碰撞相应次数后才会消失）

    //动态属性
    float direction_x;
    float direction_y;//子弹方向(对应三角函数值）
    float angle;//子弹朝向，为了使画面更美观

};

#endif // BULLET_H
