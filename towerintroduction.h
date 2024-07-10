#ifndef TOWERINTRODUCTION_H
#define TOWERINTRODUCTION_H

#include <QString>
#include "point.h"
#include "objectinteract.h"
#include "config.h"

using namespace std;
/*
说明：
这个类是优化内容
用于显示塔的各项属性
*/

class TowerIntroduction:public ObjectInteract
{
public:
    TowerIntroduction(Point p);
    ~TowerIntroduction(){delete icon;}
    //类外定义
    void setIntroIcon(string name);//根据炮塔的种类选择内容
};

#endif // TOWERINTRODUCTION_H
