#ifndef TOWERRANGECIRCLE_H
#define TOWERRANGECIRCLE_H

#include "point.h"
#include "objectinteract.h"
#include "config.h"
#include "tower.h"

/*
说明：
这个类是优化内容
用于显示被选中的炮塔的攻击范围
每个塔自带一个圈
*/

class TowerRangeCircle:public ObjectInteract
{
public:
    TowerRangeCircle(Tower* t);
    ~TowerRangeCircle(){delete icon;}
};

#endif // TOWERRANGECIRCLE_H
