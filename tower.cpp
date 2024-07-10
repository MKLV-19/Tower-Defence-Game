#include "tower.h"
#include "config.h"
#include <QPixmap>
#include <QtDebug>

Tower::Tower(string name)//塔的构造
{
    //塔在这里添加
    this->type=name;
    if(name.compare("tower_test")==0){//测试塔
        icon->load(":/picture/tower/tower_test2.png");
        damage=TOWER_TEST_DAMAGE;//设置伤害
        width=TOWER_TEST_WIDTH;//宽
        height=TOWER_TEST_HEIGHT;//高
        range=TOWER_TEST_RANGE;//范围
        price=TOWER_TEST_PRICE;//价格
        needmp=TOWER_TEST_COSTMP;//魔力消耗
        interval=TOWER_TEST_FIREINTERVAL;//冷却时间
        cool=TOWER_TEST_FIREINTERVAL;//冷却时间顺便重置
        v_rotation=TOWER_TEST_VROTATION;//转速
        angel=180;//设置塔的初始旋转角永远是180度，即向左
        fireready=false;//冷却状态为未冷却
        ischosen=false;//选择状态为未选择
        checked=false;//查看状态为未查看
        level=0;//当前等级为0
        maxlevel=1;//最大等级
    }else if(name.compare("tower_test1")==0){//未来塔
        icon->load(":/picture/tower/tower_test1.png");
        damage=TOWER_TEST1_DAMAGE;//设置伤害
        width=TOWER_TEST1_WIDTH;//宽
        height=TOWER_TEST1_HEIGHT;//高
        range=TOWER_TEST1_RANGE;//范围
        price=TOWER_TEST1_PRICE;//价格
        needmp=TOWER_TEST1_COSTMP;//魔力消耗
        interval=TOWER_TEST1_FIREINTERVAL;//冷却时间
        cool=TOWER_TEST1_FIREINTERVAL;//冷却时间顺便重置
        v_rotation=TOWER_TEST1_VROTATION;//转速
        angel=180;//设置塔的初始旋转角永远是180度，即向左
        fireready=false;//冷却状态为未冷却
        ischosen=false;//选择状态为未选择
        checked=false;//查看状态为未查看
        level=0;//当前等级为0
        maxlevel=1;//最大等级
    }else if(name.compare("tower1")==0){//塔1，冰冻
        icon->load(":/picture/tower/tower1.png");
        damage=TOWER1_DAMAGE;//设置伤害
        width=TOWER1_WIDTH;//宽
        height=TOWER1_HEIGHT;//高
        range=TOWER1_RANGE;//范围
        price=TOWER1_PRICE;//价格
        needmp=TOWER1_COSTMP;//魔力消耗
        interval=TOWER1_FIREINTERVAL;//冷却时间
        cool=TOWER1_FIREINTERVAL;//冷却时间顺便重置
        v_rotation=TOWER1_VROTATION;//转速
        angel=180;//设置塔的初始旋转角永远是180度，即向左
        fireready=false;//冷却状态为未冷却
        ischosen=false;//选择状态为未选择
        checked=false;//查看状态为未查看
        level=0;//当前等级为0
        maxlevel=1;//最大等级
    }else if(name.compare("tower2")==0){//塔2，散弹
        icon->load(":/picture/tower/tower2.png");
        damage=TOWER2_DAMAGE;//设置伤害
        width=TOWER2_WIDTH;//宽
        height=TOWER2_HEIGHT;//高
        range=TOWER2_RANGE;//范围
        price=TOWER2_PRICE;//价格
        needmp=TOWER2_COSTMP;//魔力消耗
        interval=TOWER2_FIREINTERVAL;//冷却时间
        cool=TOWER2_FIREINTERVAL;//冷却时间顺便重置
        v_rotation=TOWER2_VROTATION;//转速
        angel=180;//设置塔的初始旋转角永远是180度，即向左
        fireready=false;//冷却状态为未冷却
        ischosen=false;//选择状态为未选择
        checked=false;//查看状态为未查看
        level=0;//当前等级为0
        maxlevel=2;//最大等级
    }else if(name.compare("tower3")==0){//塔3，双发
        icon->load(":/picture/tower/tower3.png");
        damage=TOWER3_DAMAGE;//设置伤害
        width=TOWER3_WIDTH;//宽
        height=TOWER3_HEIGHT;//高
        range=TOWER3_RANGE;//范围
        price=TOWER3_PRICE;//价格
        needmp=TOWER3_COSTMP;//魔力消耗
        interval=TOWER3_FIREINTERVAL;//冷却时间
        cool=TOWER3_FIREINTERVAL;//冷却时间顺便重置
        v_rotation=TOWER3_VROTATION;//转速
        angel=180;//设置塔的初始旋转角永远是180度，即向左
        fireready=false;//冷却状态为未冷却
        ischosen=false;//选择状态为未选择
        checked=false;//查看状态为未查看
        level=0;//当前等级为0
        maxlevel=2;//最大等级
    }else if(name.compare("tower4")==0){//塔4，镭射
        icon->load(":/picture/tower/tower4.png");
        damage=TOWER4_DAMAGE;//设置伤害
        width=TOWER4_WIDTH;//宽
        height=TOWER4_HEIGHT;//高
        range=TOWER4_RANGE;//范围
        price=TOWER4_PRICE;//价格
        needmp=TOWER4_COSTMP;//魔力消耗
        interval=TOWER4_FIREINTERVAL;//冷却时间
        cool=TOWER4_FIREINTERVAL;//冷却时间顺便重置
        v_rotation=TOWER4_VROTATION;//转速
        angel=180;//设置塔的初始旋转角永远是180度，即向左
        fireready=false;//冷却状态为未冷却
        ischosen=false;//选择状态为未选择
        checked=false;//查看状态为未查看
        level=0;//当前等级为0
        maxlevel=1;//最大等级
    }else if(name.compare("tower5")==0){//塔5，剧毒
        icon->load(":/picture/tower/tower5.png");
        damage=TOWER5_DAMAGE;//设置伤害
        width=TOWER5_WIDTH;//宽
        height=TOWER5_HEIGHT;//高
        range=TOWER5_RANGE;//范围
        price=TOWER5_PRICE;//价格
        needmp=TOWER5_COSTMP;//魔力消耗
        interval=TOWER5_FIREINTERVAL;//冷却时间
        cool=TOWER5_FIREINTERVAL;//冷却时间顺便重置
        v_rotation=TOWER5_VROTATION;//转速
        angel=180;//设置塔的初始旋转角永远是180度，即向左
        fireready=false;//冷却状态为未冷却
        ischosen=false;//选择状态为未选择
        checked=false;//查看状态为未查看
        level=0;//当前等级为0
        maxlevel=1;//最大等级
    }
}
Tower::~Tower()//析构
{
    delete icon;//清除图片内存
}
void Tower::coolDown()//冷却计算
{
    cool-=1.0/FPS;//含义是每秒冷却减去1(以(1000/FPS)ms为计时单位连续变化)
    if(cool<0){
        fireready=true;
        cool=interval;
    }
}
void Tower::levelUp()//炮塔的升级
{
//说明：实质是改变塔的外观，各项属性都赋一个成长值
    //改变外观操作，这个要按塔的类型进行识别
    //测试塔1
    if(this->getType().compare("tower_test")==0){
        this->type="tower_test_level1";//改变塔的名字,这样子弹的样子也可以改变
        this->icon->load(":/picture/tower/tower_test2_up1.png");
    }

    //测试塔2
    if(this->getType().compare("tower_test1")==0){
        this->type="tower_test1_level1";
        this->icon->load(":/picture/tower/tower_test1_up1.png");
        this->interval/=1.2;//炮塔攻击提速
    }

    //塔1
    if(this->getType().compare("tower1")==0){
        this->type="tower1_level1";
        this->icon->load(":/picture/tower/tower1_up1.png");
        this->interval/=1.2;//炮塔攻击提速
    }

    //塔2
    if(this->getType().compare("tower2")==0&&this->level==0){//考虑只变化图片，不改名字，便于生成子弹
        this->icon->load(":/picture/tower/tower2_up1.png");
        this->width*=1.1;
        this->height*=1.1;
    }
    if(this->getType().compare("tower2")==0&&this->level==1){
        this->icon->load(":/picture/tower/tower2_up2.png");
        this->width*=1.1;
        this->height*=1.1;
    }

    //塔3
    if(this->getType().compare("tower3")==0&&this->level==0){
        this->icon->load(":/picture/tower/tower3_up1.png");
    }
    if(this->getType().compare("tower3")==0&&this->level==1){
        this->icon->load(":/picture/tower/tower3_up2.png");
    }

    //塔4
    if(this->getType().compare("tower4")==0){
        this->icon->load(":/picture/tower/tower4_up1.png");
    }

    //塔5
    if(this->getType().compare("tower5")==0){
        this->icon->load(":/picture/tower/tower5_up1.png");
    }

    //成长操作,设定每次升级价格翻番，这个要按塔的等级识别
    if(this->level==0){
        level++;//升一级
        this->setDamage(this->getDamage()*TOWER_LEVELUP1);
        this->setRange(this->getRange()*TOWER_LEVELUP1);
        this->setPrice(this->getPrice()*2);//一级塔价格翻倍
    }else if(this->level==1){
        level++;//升一级
        this->setDamage(this->getDamage()*TOWER_LEVELUP2);
        this->setRange(this->getRange()*TOWER_LEVELUP2);
        this->setPrice(this->getPrice()*2);//二级塔价格翻倍

    }else if(this->level==2){
        level++;//升一级
        this->setDamage(this->getDamage()*TOWER_LEVELUP3);
        this->setRange(this->getRange()*TOWER_LEVELUP3);
        this->setPrice(this->getPrice()*2);//三级塔价格翻倍
    }

}
void Tower::show(QPainter *p)//塔的旋转绘制
{
    //画笔的默认位置为界面左上角
    p->translate(CenterPos.getX(),CenterPos.getY());//确定旋转中心，即把画笔设置到当前位置
    p->rotate(angel);//将画笔方向旋转至当前角度，即相当于旋转图片到一定角度
    p->drawPixmap(-width/2,-height/2,width,height,*icon);
    //绘制操作，注意此时笔的位置在图片中心，所以求得左上角的坐标为减去半长
    p->rotate(-angel);
    p->translate(-CenterPos.getX(),-CenterPos.getY());
    //最后使用两步逆变换恢复画笔位置和角度
}



//基本完成
