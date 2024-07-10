#ifndef ENEMYHP_H
#define ENEMYHP_H

#include <QProgressBar>
#include "objectinteract.h"
#include "enemy.h"
#include "point.h"

/*
说明：
这个类是敌人的血量条
基类是QT的加载条类
*/
class EnemyHp:public QProgressBar
{
public:
    EnemyHp(Enemy* parent);//通过对应敌人的各项数据完成构造

    //类外定义
    void show(QPainter* p);//绘制血条的函数

private:
    Enemy* parent;//它爸爸
    QRect rect_hp;//画血槽的矩形
    QRect rect_text;//文本框
    QRect rect_fill;//血条填充
    QFont f;//字体
    float ratio;//当前血量占比
    float len;//当前血条长度

    QString valuestr;//当前血量数值
    QPixmap below;//血槽背景
    QPixmap above;//血条填充
};

#endif // ENEMYHP_H
