#include "bullet.h"
#include <QPixmap>
#include <QDebug>
#include "config.h"
#include "point.h"
#include "tool.h"

//子弹类型在这里设定
//子弹的升级和构造有赖于塔的种类，所以可以在这里对子弹进行精细化设置
Bullet::Bullet(Tower* parent,Enemy* target)//第一种构造方式
{
    this->parent=parent;
    this->angle=parent->getAngle();
    //测试塔1
    if(parent->getType().compare("tower_test")==0){//level0
        //字符串比较，并赋各项设定值
        this->slow=BULLET_TEST_SLOW;
        this->toxic=BULLET_TEST_TOXIC;
        this->damage=parent->getDamage();
        this->icon=new QPixmap;
        icon->load(":/picture/bullet/bullet_test3.png");
        this->width=BULLET_TEST_WIDTH;
        this->height=BULLET_TEST_HEIGHT;
        this->speed=BULLET_TEST_SPEED;
        this->collisontimes=BULLET_TEST_COLLISIONTIMES;
    }
    if(parent->getType().compare("tower_test_level1")==0){//level1
        this->slow=BULLET_TEST_SLOW;
        this->toxic=BULLET_TEST_TOXIC;
        this->damage=parent->getDamage();
        this->icon=new QPixmap;
        icon->load(":/picture/bullet/bullet_test3_up1.png");
        this->width=BULLET_TEST_WIDTH;
        this->height=BULLET_TEST_HEIGHT;
        this->speed=BULLET_TEST_SPEED*BULLET_LEVELUP;
        this->collisontimes=BULLET_TEST_COLLISIONTIMES;
    }
    //测试塔2
    if(parent->getType().compare("tower_test1")==0){//level0
        //字符串比较，并赋各项设定值
        this->slow=BULLET_TEST1_SLOW;
        this->toxic=BULLET_TEST1_TOXIC;
        this->damage=parent->getDamage();
        this->icon=new QPixmap;
        icon->load(":/picture/bullet/bullet_test1.png");
        this->width=BULLET_TEST1_WIDTH;
        this->height=BULLET_TEST1_HEIGHT;
        this->speed=BULLET_TEST1_SPEED;
        this->collisontimes=BULLET_TEST1_COLLISIONTIMES;
    }
    if(parent->getType().compare("tower_test1_level1")==0){//level1
        this->slow=BULLET_TEST1_SLOW;
        this->toxic=BULLET_TEST1_TOXIC;
        this->damage=parent->getDamage();
        this->icon=new QPixmap;
        icon->load(":/picture/bullet/bullet_test1_up1.png");
        this->width=BULLET_TEST1_WIDTH;
        this->height=BULLET_TEST1_HEIGHT;
        this->speed=BULLET_TEST1_SPEED*BULLET_LEVELUP;
        this->collisontimes=BULLET_TEST1_COLLISIONTIMES;
    }

    //塔1
    if(parent->getType().compare("tower1")==0){
        //字符串比较，并赋各项设定值
        this->slow=BULLET1_SLOW;
        this->toxic=BULLET1_TOXIC;
        this->damage=parent->getDamage();
        this->icon=new QPixmap;
        icon->load(":/picture/bullet/bullet1.png");
        this->width=BULLET1_WIDTH;
        this->height=BULLET1_HEIGHT;
        this->speed=BULLET1_SPEED;
        this->collisontimes=BULLET1_COLLISIONTIMES;
    }
    if(parent->getType().compare("tower1_level1")==0){
        //字符串比较，并赋各项设定值
        this->slow=BULLET1_SLOW+10;
        this->toxic=BULLET1_TOXIC;
        this->damage=parent->getDamage();
        this->icon=new QPixmap;
        icon->load(":/picture/bullet/bullet1_up1.png");
        this->width=BULLET1_WIDTH;
        this->height=BULLET1_HEIGHT;
        this->speed=BULLET1_SPEED*BULLET_LEVELUP;
        this->collisontimes=BULLET1_COLLISIONTIMES;
    }

    //塔2
    if(parent->getType().compare("tower2")==0&&parent->getLevel()==0){
        //字符串比较，并赋各项设定值
        this->slow=BULLET2_SLOW;
        this->toxic=BULLET2_TOXIC;
        this->damage=parent->getDamage();
        this->icon=new QPixmap;
        icon->load(":/picture/bullet/bullet2.png");
        this->width=BULLET2_WIDTH;
        this->height=BULLET2_HEIGHT;
        this->speed=BULLET2_SPEED;
        this->collisontimes=BULLET2_COLLISIONTIMES;
    }
    if(parent->getType().compare("tower2")==0&&parent->getLevel()==1){
        //字符串比较，并赋各项设定值
        this->slow=BULLET2_SLOW;
        this->toxic=BULLET2_TOXIC;
        this->damage=parent->getDamage();
        this->icon=new QPixmap;
        icon->load(":/picture/bullet/bullet2_up1.png");
        this->width=BULLET2_WIDTH*2;
        this->height=BULLET2_HEIGHT*2;
        this->speed=BULLET2_SPEED*BULLET_LEVELUP;
        this->collisontimes=BULLET2_COLLISIONTIMES;
    }
    if(parent->getType().compare("tower2")==0&&parent->getLevel()==2){
        //字符串比较，并赋各项设定值
        this->slow=BULLET2_SLOW;
        this->toxic=BULLET2_TOXIC;
        this->damage=parent->getDamage();
        this->icon=new QPixmap;
        icon->load(":/picture/bullet/bullet2_up1.png");
        this->width=BULLET2_WIDTH*3;
        this->height=BULLET2_HEIGHT*3;
        this->speed=BULLET2_SPEED*BULLET_LEVELUP;
        this->collisontimes=BULLET2_COLLISIONTIMES;
    }

    //塔3
    if(parent->getType().compare("tower3")==0&&parent->getLevel()==0){
        //字符串比较，并赋各项设定值
        this->slow=BULLET3_SLOW;
        this->toxic=BULLET3_TOXIC;
        this->damage=parent->getDamage();
        this->icon=new QPixmap;
        icon->load(":/picture/bullet/bullet3.png");
        this->width=BULLET3_WIDTH;
        this->height=BULLET3_HEIGHT;
        this->speed=BULLET3_SPEED;
        this->collisontimes=BULLET3_COLLISIONTIMES;
    }
    if(parent->getType().compare("tower3")==0&&parent->getLevel()==1){
        //字符串比较，并赋各项设定值
        this->slow=BULLET3_SLOW;
        this->toxic=BULLET3_TOXIC;
        this->damage=parent->getDamage();
        this->icon=new QPixmap;
        icon->load(":/picture/bullet/bullet3_up1.png");
        this->width=BULLET3_WIDTH;
        this->height=BULLET3_HEIGHT;
        this->speed=BULLET3_SPEED*BULLET_LEVELUP;
        this->collisontimes=BULLET3_COLLISIONTIMES;
    }
    if(parent->getType().compare("tower3")==0&&parent->getLevel()==2){
        //字符串比较，并赋各项设定值
        this->slow=BULLET3_SLOW;
        this->toxic=BULLET3_TOXIC;
        this->damage=parent->getDamage();
        this->icon=new QPixmap;
        icon->load(":/picture/bullet/bullet3_up1.png");
        this->width=BULLET3_WIDTH;
        this->height=BULLET3_HEIGHT;
        this->speed=BULLET3_SPEED*BULLET_LEVELUP;
        this->collisontimes=BULLET3_COLLISIONTIMES;
    }

    //塔4
    if(parent->getType().compare("tower4")==0&&parent->getLevel()==0){
        //字符串比较，并赋各项设定值
        this->slow=BULLET4_SLOW;
        this->toxic=BULLET4_TOXIC;
        this->damage=parent->getDamage();
        this->icon=new QPixmap;
        icon->load(":/picture/bullet/bullet4.png");
        this->width=BULLET4_WIDTH;
        this->height=BULLET4_HEIGHT;
        this->speed=BULLET4_SPEED;
        this->collisontimes=BULLET4_COLLISIONTIMES;
    }
    if(parent->getType().compare("tower4")==0&&parent->getLevel()==1){
        //字符串比较，并赋各项设定值
        this->slow=BULLET4_SLOW;
        this->toxic=BULLET4_TOXIC;
        this->damage=parent->getDamage();
        this->icon=new QPixmap;
        icon->load(":/picture/bullet/bullet4_up.png");
        this->width=BULLET4_WIDTH*BULLET_LEVELUP;
        this->height=BULLET4_HEIGHT;
        this->speed=BULLET4_SPEED*BULLET_LEVELUP;
        this->collisontimes=BULLET4_COLLISIONTIMES+10;
    }

    //塔5
    if(parent->getType().compare("tower5")==0&&parent->getLevel()==0){
        //字符串比较，并赋各项设定值
        this->slow=BULLET5_SLOW;
        this->toxic=BULLET5_TOXIC;
        this->damage=parent->getDamage();
        this->icon=new QPixmap;
        icon->load(":/picture/bullet/bullet5.png");
        this->width=BULLET5_WIDTH;
        this->height=BULLET5_HEIGHT;
        this->speed=BULLET5_SPEED;
        this->collisontimes=BULLET5_COLLISIONTIMES;
    }
    if(parent->getType().compare("tower5")==0&&parent->getLevel()==1){
        //字符串比较，并赋各项设定值
        this->slow=BULLET5_SLOW;
        this->toxic=BULLET5_TOXIC*3;
        this->damage=parent->getDamage();
        this->icon=new QPixmap;
        icon->load(":/picture/bullet/bullet5_up1.png");
        this->width=BULLET5_WIDTH*BULLET_LEVELUP;
        this->height=BULLET5_HEIGHT;
        this->speed=BULLET5_SPEED*BULLET_LEVELUP;
        this->collisontimes=BULLET5_COLLISIONTIMES+1;
    }

    float len=Tool::distance(parent->getPos(),target->getPos());
    float x=target->getPos_x()-parent->getPos_x();
    float y=target->getPos_y()-parent->getPos_y();
    direction_x=(x/len);
    direction_y=(y/len);
    this->CenterPos.setX(parent->getPos_x()+direction_x*parent->getWidth()/2+direction_x*this->getWidth()/2);
    this->CenterPos.setY(parent->getPos_y()+direction_y*parent->getWidth()/2+direction_y*this->getWidth()/2);

    if(parent->getType().compare("tower2")==0){//塔2的攻击效果————散弹制作
        this->setCenterPos(parent->getPos_x(),parent->getPos_y());
        Point direct(direction_x,direction_y);//取方向向量
        float ang=Tool::VectorToAngle(direct)+qrand()%360-180;
        direction_x=Tool::AngleToVector(ang).getX();
        direction_y=Tool::AngleToVector(ang).getY();
    }

}
Bullet::Bullet(Tower* parent,Point target)//第二种构造方式
{
    this->parent=parent;
    this->angle=parent->getAngle();
    //测试塔1
    if(parent->getType().compare("tower_test")==0){//level0
        //字符串比较，并赋各项设定值
        this->slow=BULLET_TEST_SLOW;
        this->toxic=BULLET_TEST_TOXIC;
        this->damage=parent->getDamage();
        this->icon=new QPixmap;
        icon->load(":/picture/bullet/bullet_test3.png");
        this->width=BULLET_TEST_WIDTH;
        this->height=BULLET_TEST_HEIGHT;
        this->speed=BULLET_TEST_SPEED;
        this->collisontimes=BULLET_TEST_COLLISIONTIMES;
    }
    if(parent->getType().compare("tower_test_level1")==0){//level1
        this->slow=BULLET_TEST_SLOW;
        this->toxic=BULLET_TEST_TOXIC;
        this->damage=parent->getDamage();
        this->icon=new QPixmap;
        icon->load(":/picture/bullet/bullet_test3_up1.png");
        this->width=BULLET_TEST_WIDTH;
        this->height=BULLET_TEST_HEIGHT;
        this->speed=BULLET_TEST_SPEED*BULLET_LEVELUP;
        this->collisontimes=BULLET_TEST_COLLISIONTIMES;
    }
    //测试塔2
    if(parent->getType().compare("tower_test1")==0){//level0
        //字符串比较，并赋各项设定值
        this->slow=BULLET_TEST1_SLOW;
        this->toxic=BULLET_TEST1_TOXIC;
        this->damage=parent->getDamage();
        this->icon=new QPixmap;
        icon->load(":/picture/bullet/bullet_test1.png");
        this->width=BULLET_TEST1_WIDTH;
        this->height=BULLET_TEST1_HEIGHT;
        this->speed=BULLET_TEST1_SPEED;
        this->collisontimes=BULLET_TEST1_COLLISIONTIMES;
    }
    if(parent->getType().compare("tower_test1_level1")==0){//level1
        this->slow=BULLET_TEST1_SLOW;
        this->toxic=BULLET_TEST1_TOXIC;
        this->damage=parent->getDamage();
        this->icon=new QPixmap;
        icon->load(":/picture/bullet/bullet_test1_up1.png");
        this->width=BULLET_TEST1_WIDTH;
        this->height=BULLET_TEST1_HEIGHT;
        this->speed=BULLET_TEST1_SPEED*BULLET_LEVELUP;
        this->collisontimes=BULLET_TEST1_COLLISIONTIMES;
    }

    //塔1
    if(parent->getType().compare("tower1")==0){
        //字符串比较，并赋各项设定值
        this->slow=BULLET1_SLOW;
        this->toxic=BULLET1_TOXIC;
        this->damage=parent->getDamage();
        this->icon=new QPixmap;
        icon->load(":/picture/bullet/bullet1.png");
        this->width=BULLET1_WIDTH;
        this->height=BULLET1_HEIGHT;
        this->speed=BULLET1_SPEED;
        this->collisontimes=BULLET1_COLLISIONTIMES;
    }
    if(parent->getType().compare("tower1_level1")==0){
        //字符串比较，并赋各项设定值
        this->slow=BULLET1_SLOW+10;
        this->toxic=BULLET1_TOXIC;
        this->damage=parent->getDamage();
        this->icon=new QPixmap;
        icon->load(":/picture/bullet/bullet1_up1.png");
        this->width=BULLET1_WIDTH;
        this->height=BULLET1_HEIGHT;
        this->speed=BULLET1_SPEED*BULLET_LEVELUP;
        this->collisontimes=BULLET1_COLLISIONTIMES;
    }

    //塔2
    if(parent->getType().compare("tower2")==0&&parent->getLevel()==0){
        //字符串比较，并赋各项设定值
        this->slow=BULLET2_SLOW;
        this->toxic=BULLET2_TOXIC;
        this->damage=parent->getDamage();
        this->icon=new QPixmap;
        icon->load(":/picture/bullet/bullet2.png");
        this->width=BULLET2_WIDTH;
        this->height=BULLET2_HEIGHT;
        this->speed=BULLET2_SPEED;
        this->collisontimes=BULLET2_COLLISIONTIMES;
    }
    if(parent->getType().compare("tower2")==0&&parent->getLevel()==1){
        //字符串比较，并赋各项设定值
        this->slow=BULLET2_SLOW;
        this->toxic=BULLET2_TOXIC;
        this->damage=parent->getDamage();
        this->icon=new QPixmap;
        icon->load(":/picture/bullet/bullet2_up1.png");
        this->width=BULLET2_WIDTH*2;
        this->height=BULLET2_HEIGHT*2;
        this->speed=BULLET2_SPEED*BULLET_LEVELUP;
        this->collisontimes=BULLET2_COLLISIONTIMES;
    }
    if(parent->getType().compare("tower2")==0&&parent->getLevel()==2){
        //字符串比较，并赋各项设定值
        this->slow=BULLET2_SLOW;
        this->toxic=BULLET2_TOXIC;
        this->damage=parent->getDamage();
        this->icon=new QPixmap;
        icon->load(":/picture/bullet/bullet2_up1.png");
        this->width=BULLET2_WIDTH*3;
        this->height=BULLET2_HEIGHT*3;
        this->speed=BULLET2_SPEED*BULLET_LEVELUP;
        this->collisontimes=BULLET2_COLLISIONTIMES;
    }

    //塔3
    if(parent->getType().compare("tower3")==0&&parent->getLevel()==0){
        //字符串比较，并赋各项设定值
        this->slow=BULLET3_SLOW;
        this->toxic=BULLET3_TOXIC;
        this->damage=parent->getDamage();
        this->icon=new QPixmap;
        icon->load(":/picture/bullet/bullet3.png");
        this->width=BULLET3_WIDTH;
        this->height=BULLET3_HEIGHT;
        this->speed=BULLET3_SPEED;
        this->collisontimes=BULLET3_COLLISIONTIMES;
    }
    if(parent->getType().compare("tower3")==0&&parent->getLevel()==1){
        //字符串比较，并赋各项设定值
        this->slow=BULLET3_SLOW;
        this->toxic=BULLET3_TOXIC;
        this->damage=parent->getDamage();
        this->icon=new QPixmap;
        icon->load(":/picture/bullet/bullet3_up1.png");
        this->width=BULLET3_WIDTH;
        this->height=BULLET3_HEIGHT;
        this->speed=BULLET3_SPEED*BULLET_LEVELUP;
        this->collisontimes=BULLET3_COLLISIONTIMES;
    }
    if(parent->getType().compare("tower3")==0&&parent->getLevel()==2){
        //字符串比较，并赋各项设定值
        this->slow=BULLET3_SLOW;
        this->toxic=BULLET3_TOXIC;
        this->damage=parent->getDamage();
        this->icon=new QPixmap;
        icon->load(":/picture/bullet/bullet3_up1.png");
        this->width=BULLET3_WIDTH;
        this->height=BULLET3_HEIGHT;
        this->speed=BULLET3_SPEED*BULLET_LEVELUP;
        this->collisontimes=BULLET3_COLLISIONTIMES;
    }

    //塔4
    if(parent->getType().compare("tower4")==0&&parent->getLevel()==0){
        //字符串比较，并赋各项设定值
        this->slow=BULLET4_SLOW;
        this->toxic=BULLET4_TOXIC;
        this->damage=parent->getDamage();
        this->icon=new QPixmap;
        icon->load(":/picture/bullet/bullet4.png");
        this->width=BULLET4_WIDTH;
        this->height=BULLET4_HEIGHT;
        this->speed=BULLET4_SPEED;
        this->collisontimes=BULLET4_COLLISIONTIMES;
    }
    if(parent->getType().compare("tower4")==0&&parent->getLevel()==1){
        //字符串比较，并赋各项设定值
        this->slow=BULLET4_SLOW;
        this->toxic=BULLET4_TOXIC;
        this->damage=parent->getDamage();
        this->icon=new QPixmap;
        icon->load(":/picture/bullet/bullet4_up.png");
        this->width=BULLET4_WIDTH*BULLET_LEVELUP;
        this->height=BULLET4_HEIGHT;
        this->speed=BULLET4_SPEED*BULLET_LEVELUP;
        this->collisontimes=BULLET4_COLLISIONTIMES+10;
    }

    //塔5
    if(parent->getType().compare("tower5")==0&&parent->getLevel()==0){
        //字符串比较，并赋各项设定值
        this->slow=BULLET5_SLOW;
        this->toxic=BULLET5_TOXIC;
        this->damage=parent->getDamage();
        this->icon=new QPixmap;
        icon->load(":/picture/bullet/bullet5.png");
        this->width=BULLET5_WIDTH;
        this->height=BULLET5_HEIGHT;
        this->speed=BULLET5_SPEED;
        this->collisontimes=BULLET5_COLLISIONTIMES;
    }
    if(parent->getType().compare("tower5")==0&&parent->getLevel()==1){
        //字符串比较，并赋各项设定值
        this->slow=BULLET5_SLOW;
        this->toxic=BULLET5_TOXIC*3;
        this->damage=parent->getDamage();
        this->icon=new QPixmap;
        icon->load(":/picture/bullet/bullet5_up1.png");
        this->width=BULLET5_WIDTH*BULLET_LEVELUP;
        this->height=BULLET5_HEIGHT;
        this->speed=BULLET5_SPEED*BULLET_LEVELUP;
        this->collisontimes=BULLET5_COLLISIONTIMES+1;
    }

    direction_x=target.getX();
    direction_y=target.getY();
    this->CenterPos.setX(parent->getPos_x()+target.getX()*parent->getWidth()/2+direction_x*this->getWidth()/2);
    this->CenterPos.setY(parent->getPos_y()+target.getY()*parent->getWidth()/2+direction_y*this->getWidth()/2);


    if(parent->getType().compare("tower2")==0){
        this->setCenterPos(parent->getPos_x(),parent->getPos_y());
        float ang=Tool::VectorToAngle(target)+qrand()%360-180;
        direction_x=Tool::AngleToVector(ang).getX();
        direction_y=Tool::AngleToVector(ang).getY();
    }

}
void Bullet::show(QPainter *p)
{
    //画笔的默认位置为界面左上角
    p->translate(CenterPos.getX(),CenterPos.getY());//确定旋转中心，即把画笔设置到当前位置
    p->rotate(this->getAngle());//将画笔方向旋转至当前角度，即相当于旋转图片到一定角度
    p->drawPixmap(-width/2,-height/2,width,height,*icon);
    //绘制操作，注意此时笔的位置在图片中心，所以求得左上角的坐标为减去半长
    p->rotate(-this->getAngle());
    p->translate(-CenterPos.getX(),-CenterPos.getY());
    //最后使用两步逆变换恢复画笔位置和角度
}

//基本完成
