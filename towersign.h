#ifndef TOWERSIGN_H
#define TOWERSIGN_H

#include "point.h"
#include "objectinteract.h"
#include "config.h"

/*
说明：
这个类是优化内容
用于显示被选中的炮塔
*/
class TowerSign:public ObjectInteract
{
public:
    TowerSign(Point p);//由它的塔给出构造
    ~TowerSign(){delete icon;}//析构

private:
    Point p;
};

#endif // TOWERSIGN_H
