#ifndef ENEMY_H
#define ENEMY_H

#include <vector>
#include <string>
#include "objectinteract.h"
#include "point.h"
#include "config.h"

using namespace std;
/*
说明：
这个类是敌人
ObjectInteract的子类
因为打算设定敌人都向右走，所以不用安排特定路线
敌人的防御力为拓展类内容，可以不搞
*/

class Enemy:public ObjectInteract
{
public:
    explicit Enemy(string name);//构造函数，名字用于字符串比较生成特定敌人
    ~Enemy(){delete icon;}//析构，删除对应图片

    //类内定义
    //取值//
    string getType(){return type;}//返回名称
    int getSpeed(){return speed;}//返回速度
    int getProtoSpeed(){return protospeed;}//返回原始速度
    int getHp(){return hp;}//返回血量
    int getDefence(){return defence;}//返回防御力
    int getLose(){return lose;}//返回生命损失
    int getFullHp(){return fullhp;}//返回最大血量
    int getEarn(){return earn;}//返回回报值
    int getAddMP(){return addmp;}//返回魔力回报值
    int getToxicInterval(){return toxicinterval;}//返回受到伤害剩余时间
    int getToxicDamage(){return toxicdamage;}//返回敌人的中毒伤害
    float getDirection_x(){return direction_x;}
    float getDirection_y(){return direction_y;}//返回运动方向
    float getIceTime(){return icetime;}//返回冻伤间隔
    float getToxicTime(){return toxictime;}//返回中毒间隔
    bool getDamage(){return damage;}//返回伤害状况
    bool getIsChosen(){return ischosen;}//返回选中状态
    bool getIsInIce(){return isinice;}//返回冻伤状态
    bool getIsInToxic(){return isintoxic;}//返回中毒状态


    //操作//
    void setHp(int h){hp=h;}//设置，改变血量（接触子弹，血量下降）
    void setSpeed(int v){speed=v;}//设置，改变速度（减速子弹可以使其减速）
    void setDefence(int d){defence=d;}//设置，改变防御力
    void setDamage(bool whether){damage=whether;}//设置被造成伤害状况
    void setIsInice(bool whether){isinice=whether;}//改变冻伤状态
    void setIsInToxic(bool whether){isintoxic=whether;}//改变中毒状态
    void setToxicInterval(){toxicinterval=FPS;}//恢复中毒倒计时
    void setToxicDamage(int d){toxicdamage=d;}//相应子弹的中毒伤害
    void reSetIce(){isinice=true;icecoverage=icetime;}//进入冻伤状态
    void reSetToxic(){isintoxic=true;toxiccoverage=toxictime;}//进入中毒状态
    void handleToxicTime(){toxicinterval--;}//中毒状态倒计时

    //类外定义
    void coverageIce();//冻伤恢复
    void coverageToxic();//中毒恢复

    //一个拓展
    int towards=1;

public slots:
    void setIsChosen(bool whether){ischosen=whether;}//设置选中状态

protected:
    //静态属性
    string type;//敌人类型
    int hp;//生命值
    int fullhp;//满血血量，用于制作血条
    int speed;//移动速度
    int protospeed;//记录原始速度用于减速
    int earn;//得到奖励
    int addmp;//得到魔力奖励
    int defence;//防御力(拓展内容，可以适当搞)
    int lose;//生命损失

    //动态属性
    float direction_x;
    float direction_y;//移动方向
    float icetime;//冰冻时间间隔
    float icecoverage;//冰冻恢复倒计时
    float toxictime;//中毒时间间隔
    float toxiccoverage;//中毒恢复倒计时
    int toxicinterval=FPS;//每次受到中毒的伤害的倒计时
    int toxicdamage;//敌人受到的中毒伤害
    bool damage=false;//是否被造成伤害(用于显伤)
    bool ischosen=false;//被选中状态
    bool isinice=false;//判断敌人是否处于冷冻状态之中
    bool isintoxic=false;//判断敌人是否处于中毒状态之中
};

#endif // ENEMY_H
