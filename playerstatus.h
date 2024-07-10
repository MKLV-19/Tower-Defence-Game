#ifndef PLAYERSTATUS_H
#define PLAYERSTATUS_H

#include <QProgressBar>
#include <QString>
#include "point.h"
#include "player.h"

using namespace std;

/*
说明：
这个类用来显示玩家状态：血条，金钱条
基类是QT的加载条类
其原理和敌人的血条是一样的
*/

class PlayerStatus:public QProgressBar
{
public:
    PlayerStatus(Player* player,string type);//玩家和数据类型

    //类外定义
    void setNewNumber();//增加各属性上限
    void show(QPainter* p);//绘制
private:
    Player* player;//和敌人一样，血条用玩家类来构造
    string type;

    QRect rect_bottom;//槽
    QRect rect_top;//条
    QRect rect_text;//文字
    QFont f;//字体
    float ratio;//比率
    float len;//比率长

    QString valuestr;//显示数值
    QPixmap below;//背景
    QPixmap above;//填充
};

#endif // PLAYERSTATUS_H
