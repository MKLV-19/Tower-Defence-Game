#include "towersign.h"
#include "config.h"

TowerSign::TowerSign(Point p)
{
    this->p=p;
    this->icon=new QPixmap;
    this->icon->load(":/picture/sign/sign_test.png");
    setCenterPos(p.getX(),p.getY()-60);
    this->width=SIGN_WIDTH;
    this->height=SIGN_HEIGHT;
}
