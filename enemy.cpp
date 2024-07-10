#include "enemy.h"
#include "config.h"
#include <QPixmap>
#include <QDebug>

//敌人类型都在这里写
Enemy::Enemy(string name)//敌人生成
{
    type=name;
    damage=false;//刚生成使未对玩家造成伤害
    CenterPos.setX(0);
    CenterPos.setY(600);//初始化生成点
    direction_x=1;
    direction_y=0;//敌人的移动方向永远水平向右(某些敌人可能会纵向移动)
    if(type.compare("enemy_test")==0){//普通怪
        icon=new QPixmap;
        icon->load(":/picture/enemy/enemy_test2.png");//初始测试怪
        width=ENEMY_TEST_WIDTH;//初始化宽度
        height=ENEMY_TEST_HEIGET;//高度
        hp=ENEMY_TEST_LIFE;//生命
        fullhp=ENEMY_TEST_LIFE;//最大生命值
        speed=ENEMY_TEST_SPEED;//速度
        protospeed=ENEMY_TEST_SPEED;//原始速度
        earn=ENEMY_TEST_EARN;//奖励
        addmp=ENEMY_TEST_ADDMP;//魔力奖励
        defence=ENEMY_TEST_DEFENCE;//防御力
        lose=ENEMY_TEST_LIFELOSE;//生命损失
        icetime=ENEMY_TEST_ICEDEFENCE;//冻伤时间
        icecoverage=ENEMY_TEST_ICEDEFENCE;//冻伤恢复
        toxictime=ENEMY_TEST_TOXICDEFENCE;//中毒时间
        toxiccoverage=ENEMY_TEST_TOXICDEFENCE;//中毒恢复
    }else if(type.compare("enemy_test1")==0){//希望怪
        icon=new QPixmap;
        icon->load(":/picture/enemy/enemy_test1.png");
        width=ENEMY_TEST1_WIDTH;//初始化宽度
        height=ENEMY_TEST1_HEIGET;//高度
        hp=ENEMY_TEST1_LIFE;//生命
        fullhp=ENEMY_TEST1_LIFE;//最大生命值
        speed=ENEMY_TEST1_SPEED;//速度
        protospeed=ENEMY_TEST1_SPEED;//原始速度
        earn=ENEMY_TEST1_EARN;//奖励
        addmp=ENEMY_TEST1_ADDMP;//魔力奖励
        defence=ENEMY_TEST1_DEFENCE;//防御力
        lose=ENEMY_TEST1_LIFELOSE;//生命损失
        icetime=ENEMY_TEST1_ICEDEFENCE;//冻伤时间
        icecoverage=ENEMY_TEST1_ICEDEFENCE;//冻伤恢复
        toxictime=ENEMY_TEST1_TOXICDEFENCE;//中毒时间
        toxiccoverage=ENEMY_TEST1_TOXICDEFENCE;//中毒恢复
        direction_y=5;//特殊的纵向移动
    }else if(type.compare("enemy1")==0){//病毒1
        icon=new QPixmap;
        icon->load(":/picture/enemy/enemy1.png");
        width=ENEMY1_WIDTH;//初始化宽度
        height=ENEMY1_HEIGET;//高度
        hp=ENEMY1_LIFE;//生命
        fullhp=ENEMY1_LIFE;//最大生命值
        speed=ENEMY1_SPEED;//速度
        protospeed=ENEMY1_SPEED;//原始速度
        earn=ENEMY1_EARN;//奖励
        addmp=ENEMY1_ADDMP;//魔力奖励
        defence=ENEMY1_DEFENCE;//防御力
        lose=ENEMY1_LIFELOSE;//生命损失
        icetime=ENEMY1_ICEDEFENCE;//冻伤时间
        icecoverage=ENEMY1_ICEDEFENCE;//冻伤恢复
        toxictime=ENEMY1_TOXICDEFENCE;//中毒时间
        toxiccoverage=ENEMY1_TOXICDEFENCE;//中毒恢复
    }else if(type.compare("enemy2")==0){//防御普通怪
        icon=new QPixmap;
        icon->load(":/picture/enemy/enemy2.png");
        width=ENEMY2_WIDTH;//初始化宽度
        height=ENEMY2_HEIGET;//高度
        hp=ENEMY2_LIFE;//生命
        fullhp=ENEMY2_LIFE;//最大生命值
        speed=ENEMY2_SPEED;//速度
        protospeed=ENEMY2_SPEED;//原始速度
        earn=ENEMY2_EARN;//奖励
        addmp=ENEMY2_ADDMP;//魔力奖励
        defence=ENEMY2_DEFENCE;//防御力
        lose=ENEMY2_LIFELOSE;//生命损失
        icetime=ENEMY2_ICEDEFENCE;//冻伤时间
        icecoverage=ENEMY2_ICEDEFENCE;//冻伤恢复
        toxictime=ENEMY2_TOXICDEFENCE;//中毒时间
        toxiccoverage=ENEMY2_TOXICDEFENCE;//中毒恢复
    }else if(type.compare("enemy3")==0){//大石头
        icon=new QPixmap;
        icon->load(":/picture/enemy/enemy3.png");
        width=ENEMY3_WIDTH;//初始化宽度
        height=ENEMY3_HEIGET;//高度
        hp=ENEMY3_LIFE;//生命
        fullhp=ENEMY3_LIFE;//最大生命值
        speed=ENEMY3_SPEED;//速度
        protospeed=ENEMY3_SPEED;//原始速度
        earn=ENEMY3_EARN;//奖励
        addmp=ENEMY3_ADDMP;//魔力奖励
        defence=ENEMY3_DEFENCE;//防御力
        lose=ENEMY3_LIFELOSE;//生命损失
        icetime=ENEMY3_ICEDEFENCE;//冻伤时间
        icecoverage=ENEMY3_ICEDEFENCE;//冻伤恢复
        toxictime=ENEMY3_TOXICDEFENCE;//中毒时间
        toxiccoverage=ENEMY3_TOXICDEFENCE;//中毒恢复
    }else if(type.compare("enemy4")==0){//高温普通
        icon=new QPixmap;
        icon->load(":/picture/enemy/enemy4.png");
        width=ENEMY4_WIDTH;//初始化宽度
        height=ENEMY4_HEIGET;//高度
        hp=ENEMY4_LIFE;//生命
        fullhp=ENEMY4_LIFE;//最大生命值
        speed=ENEMY4_SPEED;//速度
        protospeed=ENEMY4_SPEED;//原始速度
        earn=ENEMY4_EARN;//奖励
        addmp=ENEMY4_ADDMP;//魔力奖励
        defence=ENEMY4_DEFENCE;//防御力
        lose=ENEMY4_LIFELOSE;//生命损失
        icetime=ENEMY4_ICEDEFENCE;//冻伤时间
        icecoverage=ENEMY4_ICEDEFENCE;//冻伤恢复
        toxictime=ENEMY4_TOXICDEFENCE;//中毒时间
        toxiccoverage=ENEMY4_TOXICDEFENCE;//中毒恢复
    }else if(type.compare("enemy5")==0){//病毒2
        icon=new QPixmap;
        icon->load(":/picture/enemy/enemy5.png");
        width=ENEMY5_WIDTH;//初始化宽度
        height=ENEMY5_HEIGET;//高度
        hp=ENEMY5_LIFE;//生命
        fullhp=ENEMY5_LIFE;//最大生命值
        speed=ENEMY5_SPEED;//速度
        protospeed=ENEMY5_SPEED;//原始速度
        earn=ENEMY5_EARN;//奖励
        addmp=ENEMY5_ADDMP;//魔力奖励
        defence=ENEMY5_DEFENCE;//防御力
        lose=ENEMY5_LIFELOSE;//生命损失
        icetime=ENEMY5_ICEDEFENCE;//冻伤时间
        icecoverage=ENEMY5_ICEDEFENCE;//冻伤恢复
        toxictime=ENEMY5_TOXICDEFENCE;//中毒时间
        toxiccoverage=ENEMY5_TOXICDEFENCE;//中毒恢复
    }else if(type.compare("enemy6")==0){//剧毒普通
        icon=new QPixmap;
        icon->load(":/picture/enemy/enemy6.png");
        width=ENEMY6_WIDTH;//初始化宽度
        height=ENEMY6_HEIGET;//高度
        hp=ENEMY6_LIFE;//生命
        fullhp=ENEMY6_LIFE;//最大生命值
        speed=ENEMY6_SPEED;//速度
        protospeed=ENEMY6_SPEED;//原始速度
        earn=ENEMY6_EARN;//奖励
        addmp=ENEMY6_ADDMP;//魔力奖励
        defence=ENEMY6_DEFENCE;//防御力
        lose=ENEMY6_LIFELOSE;//生命损失
        icetime=ENEMY6_ICEDEFENCE;//冻伤时间
        icecoverage=ENEMY6_ICEDEFENCE;//冻伤恢复
        toxictime=ENEMY6_TOXICDEFENCE;//中毒时间
        toxiccoverage=ENEMY6_TOXICDEFENCE;//中毒恢复
    }else if(type.compare("enemy7")==0){//活尸
        icon=new QPixmap;
        icon->load(":/picture/enemy/enemy7.png");
        width=ENEMY7_WIDTH;//初始化宽度
        height=ENEMY7_HEIGET;//高度
        hp=ENEMY7_LIFE;//生命
        fullhp=ENEMY7_LIFE;//最大生命值
        speed=ENEMY7_SPEED;//速度
        protospeed=ENEMY7_SPEED;//原始速度
        earn=ENEMY7_EARN;//奖励
        addmp=ENEMY7_ADDMP;//魔力奖励
        defence=ENEMY7_DEFENCE;//防御力
        lose=ENEMY7_LIFELOSE;//生命损失
        icetime=ENEMY7_ICEDEFENCE;//冻伤时间
        icecoverage=ENEMY7_ICEDEFENCE;//冻伤恢复
        toxictime=ENEMY7_TOXICDEFENCE;//中毒时间
        toxiccoverage=ENEMY7_TOXICDEFENCE;//中毒恢复
    }else if(type.compare("enemy8")==0){//水晶
        icon=new QPixmap;
        icon->load(":/picture/enemy/enemy8.png");
        width=ENEMY8_WIDTH;//初始化宽度
        height=ENEMY8_HEIGET;//高度
        hp=ENEMY8_LIFE;//生命
        fullhp=ENEMY8_LIFE;//最大生命值
        speed=ENEMY8_SPEED;//速度
        protospeed=ENEMY8_SPEED;//原始速度
        earn=ENEMY8_EARN;//奖励
        addmp=ENEMY8_ADDMP;//魔力奖励
        defence=ENEMY8_DEFENCE;//防御力
        lose=ENEMY8_LIFELOSE;//生命损失
        icetime=ENEMY8_ICEDEFENCE;//冻伤时间
        icecoverage=ENEMY8_ICEDEFENCE;//冻伤恢复
        toxictime=ENEMY8_TOXICDEFENCE;//中毒时间
        toxiccoverage=ENEMY8_TOXICDEFENCE;//中毒恢复
    }else if(type.compare("enemy9")==0){//病毒3
        icon=new QPixmap;
        icon->load(":/picture/enemy/enemy9.png");
        width=ENEMY9_WIDTH;//初始化宽度
        height=ENEMY9_HEIGET;//高度
        hp=ENEMY9_LIFE;//生命
        fullhp=ENEMY9_LIFE;//最大生命值
        speed=ENEMY9_SPEED;//速度
        protospeed=ENEMY9_SPEED;//原始速度
        earn=ENEMY9_EARN;//奖励
        addmp=ENEMY9_ADDMP;//魔力奖励
        defence=ENEMY9_DEFENCE;//防御力
        lose=ENEMY9_LIFELOSE;//生命损失
        icetime=ENEMY9_ICEDEFENCE;//冻伤时间
        icecoverage=ENEMY9_ICEDEFENCE;//冻伤恢复
        toxictime=ENEMY9_TOXICDEFENCE;//中毒时间
        toxiccoverage=ENEMY9_TOXICDEFENCE;//中毒恢复
    }else if(type.compare("enemy10")==0){//谎言怪
        icon=new QPixmap;
        icon->load(":/picture/enemy/enemy10.png");
        width=ENEMY10_WIDTH;//初始化宽度
        height=ENEMY10_HEIGET;//高度
        hp=ENEMY10_LIFE;//生命
        fullhp=ENEMY10_LIFE;//最大生命值
        speed=ENEMY10_SPEED;//速度
        protospeed=ENEMY10_SPEED;//原始速度
        earn=ENEMY10_EARN;//奖励
        addmp=ENEMY10_ADDMP;//魔力奖励
        defence=ENEMY10_DEFENCE;//防御力
        lose=ENEMY10_LIFELOSE;//生命损失
        icetime=ENEMY10_ICEDEFENCE;//冻伤时间
        icecoverage=ENEMY10_ICEDEFENCE;//冻伤恢复
        toxictime=ENEMY10_TOXICDEFENCE;//中毒时间
        toxiccoverage=ENEMY10_TOXICDEFENCE;//中毒恢复
        direction_y=8;//特殊的纵向移动
    }else if(type.compare("enemy11")==0){//大飞碟
        icon=new QPixmap;
        icon->load(":/picture/enemy/enemy11.png");
        width=ENEMY11_WIDTH;//初始化宽度
        height=ENEMY11_HEIGET;//高度
        hp=ENEMY11_LIFE;//生命
        fullhp=ENEMY11_LIFE;//最大生命值
        speed=ENEMY11_SPEED;//速度
        protospeed=ENEMY11_SPEED;//原始速度
        earn=ENEMY11_EARN;//奖励
        addmp=ENEMY11_ADDMP;//魔力奖励
        defence=ENEMY11_DEFENCE;//防御力
        lose=ENEMY11_LIFELOSE;//生命损失
        icetime=ENEMY11_ICEDEFENCE;//冻伤时间
        icecoverage=ENEMY11_ICEDEFENCE;//冻伤恢复
        toxictime=ENEMY11_TOXICDEFENCE;//中毒时间
        toxiccoverage=ENEMY11_TOXICDEFENCE;//中毒恢复
    }else if(type.compare("enemy12")==0){//小飞碟
        icon=new QPixmap;
        icon->load(":/picture/enemy/enemy12.png");
        width=ENEMY12_WIDTH;//初始化宽度
        height=ENEMY12_HEIGET;//高度
        hp=ENEMY12_LIFE;//生命
        fullhp=ENEMY12_LIFE;//最大生命值
        speed=ENEMY12_SPEED;//速度
        protospeed=ENEMY12_SPEED;//原始速度
        earn=ENEMY12_EARN;//奖励
        addmp=ENEMY12_ADDMP;//魔力奖励
        defence=ENEMY12_DEFENCE;//防御力
        lose=ENEMY12_LIFELOSE;//生命损失
        icetime=ENEMY12_ICEDEFENCE;//冻伤时间
        icecoverage=ENEMY12_ICEDEFENCE;//冻伤恢复
        toxictime=ENEMY12_TOXICDEFENCE;//中毒时间
        toxiccoverage=ENEMY12_TOXICDEFENCE;//中毒恢复
    }else if(type.compare("enemy13")==0){//Smile
        icon=new QPixmap;
        icon->load(":/picture/enemy/enemy13.png");
        width=ENEMY13_WIDTH;//初始化宽度
        height=ENEMY13_HEIGET;//高度
        hp=ENEMY13_LIFE;//生命
        fullhp=ENEMY13_LIFE;//最大生命值
        speed=ENEMY13_SPEED;//速度
        protospeed=ENEMY13_SPEED;//原始速度
        earn=ENEMY13_EARN;//奖励
        addmp=ENEMY13_ADDMP;//魔力奖励
        defence=ENEMY13_DEFENCE;//防御力
        lose=ENEMY13_LIFELOSE;//生命损失
        icetime=ENEMY13_ICEDEFENCE;//冻伤时间
        icecoverage=ENEMY13_ICEDEFENCE;//冻伤恢复
        toxictime=ENEMY13_TOXICDEFENCE;//中毒时间
        toxiccoverage=ENEMY13_TOXICDEFENCE;//中毒恢复
    }

}
void Enemy::coverageIce()//敌人的冻伤恢复
{
    if(isinice){
       icecoverage-=1.0/FPS;
    }
    if(icecoverage<0){
        isinice=false;
        icecoverage=icetime;
        speed=protospeed;
        qDebug()<<"冻伤恢复了";
    }
}
void Enemy::coverageToxic()//敌人的中毒恢复,与冻伤处理相同
{
    if(isintoxic){
        toxiccoverage-=1.0/FPS;
    }
    if(toxiccoverage<0){
        isintoxic=false;
        toxiccoverage=toxictime;
        qDebug()<<"中毒恢复了";
    }
}

//基本完成
