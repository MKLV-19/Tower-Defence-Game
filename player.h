#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include "objectinteract.h"
#include "point.h"

/*
说明：
这是用于记录玩家数据的类
如生命值，金钱
ObjectInteract的子类
这个类的作用在于实时进行修改，然后再将其变量传入playerstatus进行绘制
*/

class Player:public ObjectInteract
{
public:
    Player();//默认构造函数

    //类内定义
    int getHp(){return hp;}
    int getMp(){return mp;}
    int getMoney(){return money;}
    int getTowerNum(){return towernum;}//返回生命，魔法，金钱,当前塔量
    int getMaxHp(){return maxhp;}
    int getMaxMp(){return maxmp;}
    int getMaxMoney(){return maxmoney;}
    int getMaxNumber(){return maxnumber;}//返回上限
    int getWave(){return wave;}//返回波数
    int getScore(){return score;}//返回分数

    void setHp(int h){hp=h;}
    void setMp(int m){mp=m;}
    void setMoney(int m){money=m;}
    void setTowerNum(int n){towernum=n;}//修改生命，魔法，金钱，当前塔量
    void setMaxHp(int mh){maxhp=mh;}
    void setMaxMp(int mm){maxmp=mm;}
    void setMaxMoney(int mm){maxmoney=mm;}
    void setMaxNumber(int mn){maxnumber=mn;}//修改上限
    void setWave(int w){wave=w;}//修改波数
    void setScore(int s){score=s;}//修改分数

protected:
    int hp;//生命值
    int mp;//魔法值，后续可能会添加特殊攻击或魔法塔
    int money;//金钱
    int towernum;//塔量
    int maxmoney;//金钱上限
    int maxhp;//生命上限
    int maxmp;//魔法上限
    int maxnumber;//塔数上限
    int score;//玩家得分
    int wave;//当前波数
};

#endif // PLAYER_H
