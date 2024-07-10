#include "playerstatus.h"
#include "player.h"
#include "config.h"
#include <QProgressBar>

//绘制方法与敌人十分相似
PlayerStatus::PlayerStatus(Player* player,string type)
{
    this->player=player;
    this->type=type;
    setMinimum(0);
    if(type.compare("HP")==0){
        setMaximum(player->getMaxHp());
        rect_bottom=QRect(player->getPos_x(),player->getPos_y()-60,150,20);//分别是横纵坐标，长宽
        rect_text=QRect(player->getPos_x(),player->getPos_y()-60,150,20);//生命
        below=QPixmap(":/picture/blood/blood_buttom.png");
        above=QPixmap(":/picture/blood/blood_fill.png");
        f=QFont("Microsoft Yahei",10,QFont::Bold);//初始化图片和字体
    }else if(type.compare("MP")==0){
        setMaximum(player->getMaxMp());
        rect_bottom=QRect(player->getPos_x(),player->getPos_y()-30,150,20);
        rect_text=QRect(player->getPos_x(),player->getPos_y()-30,150,20);//魔力
        below=QPixmap(":/picture/blood/blood_buttom.png");
        above=QPixmap(":/picture/blood/blood_fill.png");
        f=QFont("Microsoft Yahei",10,QFont::Bold);//初始化图片和字体
    }else if(type.compare("money")==0){
        setMaximum(player->getMaxMoney());
        rect_bottom=QRect(player->getPos_x(),player->getPos_y(),150,20);
        rect_text=QRect(player->getPos_x(),player->getPos_y(),150,20);//金钱
        below=QPixmap(":/picture/blood/blood_buttom.png");
        above=QPixmap(":/picture/blood/blood_fill.png");
        f=QFont("Microsoft Yahei",10,QFont::Bold);//初始化图片和字体
    }else if(type.compare("number")==0){
        setMaximum(player->getMaxNumber());
        rect_bottom=QRect(player->getPos_x(),player->getPos_y()+30,150,20);
        rect_text=QRect(player->getPos_x(),player->getPos_y()+30,150,20);//数量
        below=QPixmap(":/picture/blood/blood_buttom.png");
        above=QPixmap(":/picture/blood/blood_fill.png");
        f=QFont("Microsoft Yahei",10,QFont::Bold);//初始化图片和字体
    }else if(type.compare("wave")==0){
        setMaximum(10);
        rect_bottom=QRect(player->getPos_x()+160,player->getPos_y()-60,200,50);
        rect_text=QRect(player->getPos_x()+160,player->getPos_y()-60,200,50);//波数
        below=QPixmap(":/picture/blood/blood_buttom1.png");
        above=QPixmap(":/picture/blood/blood_fill1.png");
        f=QFont("Microsoft Yahei",20,QFont::Bold);//初始化图片和字体
    }else if(type.compare("score")==0){
        setMaximum(2000);
        rect_bottom=QRect(player->getPos_x()+160,player->getPos_y(),400,50);
        rect_text=QRect(player->getPos_x()+160,player->getPos_y(),400,50);//分数
        below=QPixmap(":/picture/blood/blood_buttom1.png");
        above=QPixmap(":/picture/blood/blood_fill1.png");
        f=QFont("Microsoft Yahei",20,QFont::Bold);//初始化图片和字体
    }


}
void PlayerStatus::setNewNumber()//提高属性值
{
    setMinimum(0);
    if(type.compare("HP")==0){
        setMaximum(player->getMaxHp()+10);
    }else if(type.compare("MP")==0){
        setMaximum(player->getMaxMp()+10);
    }else if(type.compare("money")==0){
        setMaximum(player->getMaxMoney()+200);
    }else if(type.compare("number")==0){
        setMaximum(player->getMaxNumber()+1);
    }
}
void PlayerStatus::show(QPainter *p)
{
    if(type.compare("HP")==0){
        this->setValue(player->getHp());
    }else if(type.compare("MP")==0){
        this->setValue(player->getMp());
    }else if(type.compare("money")==0){
        this->setValue(player->getMoney());
    }else if(type.compare("number")==0){
        this->setValue(player->getTowerNum());
    }else if(type.compare("wave")==0){
        this->setValue(player->getWave());
    }else if(type.compare("score")==0){
        this->setValue(player->getScore());
    }
    //通过player类设定值

    ratio=(float)(value()-minimum())/(maximum()-minimum());
    len=(int)(rect_bottom.width()*ratio);
    rect_top=rect_bottom.adjusted(0,0,len-rect_bottom.width(),0);
    //绘制
    p->drawPixmap(rect_bottom,below);
    p->drawPixmap(rect_top,above);
    //显示文字
    p->setFont(f);
    if(type.compare("wave")==0||type.compare("score")==0){//使用不同颜色和对齐方式的字体
        p->setPen(QColor("#000000"));
        p->drawText(rect_text,Qt::AlignLeft,valuestr);
    }else{
        p->setPen(QColor("#666666"));
        p->drawText(rect_text,Qt::AlignCenter,valuestr);
    }
    valuestr=QString::fromStdString(type)+QString(": %1").arg(QString::number(value()));
    //value()函数的作用是取当前值
}

//基本完成
