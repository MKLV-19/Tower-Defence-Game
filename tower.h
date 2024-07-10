#ifndef TOWER_H
#define TOWER_H

#include <QPainter>
#include <vector>
#include <QMouseEvent>
#include <QVector>
#include <QString>
#include "objectinteract.h"
#include "enemy.h"
#include "towersign.h"
#include "towerintroduction.h"

using namespace std;

/*
说明：
这个类是炮塔
ObjectInteract的子类
每个塔要有一个仇恨列表，用来记录攻击的先后顺序
*/

class Tower:public ObjectInteract//继承
{
public:
    explicit Tower(string name);//用炮塔名字进行判断并构造
    ~Tower();//析构

    //类内定义
    QVector<Enemy*> hatred;//仇恨列表，记录攻击的先后顺序
    TowerSign* tsign;//选中标志
    TowerIntroduction* ti;//待选中塔的介绍
    //取值//
    string getType(){return type;}//返回炮台类型
    int getDamage()const{return damage;}//返回伤害值
    int getRange()const{return range;}//返回索敌范围
    int getPrice()const{return price;}//返回价格
    int getNeedMP()const{return needmp;}//返回魔力消耗
    int getLevel()const{return level;}//返回等级
    int getMaxLevel()const{return maxlevel;}//返回最大等级
    float getVRotation()const{return v_rotation;}//返回转速
    float getInterval()const{return interval;}//返回间隔
    float getAngle()const{return angel;}//返回角度
    bool getIsChosen(){return ischosen;}//返回是否被选中
    bool getChecked(){return checked;}//返回鼠标是否在图片上
    bool getFireReady()const{return fireready;}//返回是否可以开火（开火的条件：冷却完成&&对准目标）
    bool getRotateReady()const{return rotateready;}//返回是否旋转完成（完成的条件：和目标向量夹角小于一定值）

    //操作//
    void setDamage(int d){damage=d;}//改变伤害
    void setRange(int r){range=r;}//改变范围
    void setPrice(int p){price=p;}//改变塔的当前价格
    void setRotateReady(bool whether){rotateready=whether;}//设置完成旋转情况
    void setFireReady(bool whether){fireready=whether;}//设置开火状态
    void setIsChosen(bool whether){ischosen=whether;}//设置选中状态
    void setChecked(bool whether){checked=whether;}//设置鼠标放置状态
    void fireReset(){fireready=false;cool=interval;}//开火后重置冷却状态，不能开火
    void setAngle(float a){angel=a;}//设置，修改角度

    //类外定义
    void coolDown();//用来进行冷却倒计时的操作
    void show(QPainter* p);//ObjectInteract类show函数的更新，用来绘制炮塔旋转
    void levelUp();//炮塔升级，初始是0级，顶级是3级

private:
    //静态属性
    string type;//炮塔类型，用于字符串比较生成特定炮塔
    int damage;//伤害
    int range;//索敌范围
    int price;//价格
    int needmp;//魔力消耗
    int maxlevel;//塔的最大等级
    float interval;//两次开火间隔
    float v_rotation;//炮台转速

    //动态属性
    int level;//当前等级
    float cool;//冷却倒计时
    float angel;//炮塔角度
    bool rotateready;//是否完成旋转
    bool fireready;//是否结束冷却
    bool ischosen;//是否被选中
    bool checked;//鼠标是否在图片上

};

#endif // TOWER_H
