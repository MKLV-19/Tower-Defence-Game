#include "towerrangecircle.h"

TowerRangeCircle::TowerRangeCircle(Tower* t)
{
    this->CenterPos=t->getPos();
    this->icon=new QPixmap;
    this->icon->load(":/picture/sign/circle_test.png");
    this->width=t->getRange()*2;
    this->height=t->getRange()*2;
}
