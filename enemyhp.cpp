#include "enemyhp.h"
#include <QPainter>
#include <QtDebug>

EnemyHp::EnemyHp(Enemy* parent)//构造，初始化
{
    this->parent=parent;
    setMinimum(0);//设置下限
    setMaximum(100);//设置上限
    rect_hp=QRect(parent->getPos_x()-15,parent->getPos_y()-30,60,15);//设置血槽位置和宽高
    rect_text=QRect(parent->getPos_x()-15,parent->getPos_y()-30,60,15);//文本框同样
    below=QPixmap(":/picture/blood/blood_buttom.png");//设置血槽
    above=QPixmap(":/picture/blood/blood_fill.png");//设置血条
    f=QFont("Microsoft YaHei",10,QFont::Bold);//设置字体，微软雅黑，大小10，粗体
}
void EnemyHp::show(QPainter *p)
{
    if(parent->getDamage()||parent->getIsChosen()){//受到伤害或被选中
        ratio=(float)(value()-minimum())/(maximum()-minimum());//血条占血槽比例
        len=(int)(rect_hp.width()*ratio);//血条长度
        rect_fill=rect_hp.adjusted(0,0,len-rect_hp.width(),0);
        //调整它的宽和高，前两个数值是坐标改变量，后两个数值是长度改变量
        this->setValue(100*(parent->getHp())/(parent->getFullHp()));//计算比例的百分数值
        //绘制
        rect_hp.moveTo(parent->getPos_x()-15,parent->getPos_y()-30);
        rect_text.moveTo(parent->getPos_x()-15,parent->getPos_y()-30);
        rect_fill.moveTo(parent->getPos_x()-15,parent->getPos_y()-30);//设置绘制位置
        p->drawPixmap(rect_hp,below);
        p->drawPixmap(rect_fill,above);//绘制血槽和其按比例填充
        //数值显示
        p->setFont(f);
        p->setPen(QColor("#666666"));
        p->drawText(rect_text,Qt::AlignCenter,valuestr);//文本框，居中，显示百分比数值
        valuestr=QString("%1%").arg(QString::number(value()));//显示的百分比设置
        //这句代码的意思是用valuestr的值替代字符串中的%1
    }
}

//基本完成
