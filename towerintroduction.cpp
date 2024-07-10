#include "towerintroduction.h"

TowerIntroduction::TowerIntroduction(Point p)
{
    this->CenterPos=p;
    this->icon=new QPixmap;
    this->icon->load(":/picture/introduction/tower_test_introduction0.png");
    this->width=INTRODUCTION_WIDTH;
    this->height=INTRODUCTION_HEIGHT;
}
void TowerIntroduction::setIntroIcon(string name)//根据炮塔名来初始化
{
    if(name.compare("tower_test")==0){
        this->setCenterPos(CenterPos.getX()-this->width/2-TOWER_TEST_WIDTH/2,
                           CenterPos.getY()+this->height/2-TOWER_TEST_HEIGHT/2-15);//重新设置中心点
        this->icon->load(":/picture/introduction/tower_test_introduction.png");
    }
    if(name.compare("tower_test1")==0){
        this->setCenterPos(CenterPos.getX()-this->width/2-TOWER_TEST_WIDTH/2,
                           CenterPos.getY()+this->height/2-TOWER_TEST1_HEIGHT/2-15);//重新设置中心点
        this->icon->load(":/picture/introduction/tower_test1_introduction.png");
    }
    if(name.compare("tower1")==0){
        this->setCenterPos(CenterPos.getX()-this->width/2-TOWER_TEST_WIDTH/2,
                           CenterPos.getY()+this->height/2-TOWER1_HEIGHT/2-15);//重新设置中心点
        this->icon->load(":/picture/introduction/tower1_introduction.png");
    }
    if(name.compare("tower2")==0){
        this->setCenterPos(CenterPos.getX()-this->width/2-TOWER_TEST_WIDTH/2,
                           CenterPos.getY()+this->height/2-TOWER2_HEIGHT/2-15);//重新设置中心点
        this->icon->load(":/picture/introduction/tower2_introduction.png");
    }
    if(name.compare("tower3")==0){
        this->setCenterPos(CenterPos.getX()-this->width/2-TOWER_TEST_WIDTH/2,
                           CenterPos.getY()+this->height/2-TOWER3_HEIGHT/2-15);//重新设置中心点
        this->icon->load(":/picture/introduction/tower3_introduction.png");
    }
    if(name.compare("tower4")==0){
        this->setCenterPos(CenterPos.getX()-this->width/2-TOWER_TEST_WIDTH/2,
                           CenterPos.getY()+this->height/2-TOWER4_HEIGHT/2-15);//重新设置中心点
        this->icon->load(":/picture/introduction/tower4_introduction.png");
    }
    if(name.compare("tower5")==0){
        this->setCenterPos(CenterPos.getX()-this->width/2-TOWER_TEST_WIDTH/2,
                           CenterPos.getY()+this->height/2-TOWER5_HEIGHT/2-15);//重新设置中心点
        this->icon->load(":/picture/introduction/tower5_introduction.png");
    }
}
