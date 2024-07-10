#include "player.h"
#include "config.h"
#include <QRect>

Player::Player()
{
    icon=new QPixmap;
    icon->load(":/picture/enemy/enemy_test0.png");//传一个空图片
    CenterPos.setX(50);
    CenterPos.setY(80);//属性条的初始参考位置
    width=PLAYER_WIDTH;
    height=PLAYER_HEIGHT;//这两条没有实际意义
    hp=PLAYER_LIFE_START;//初始生命
    mp=PLAYER_MAGIC_START;//魔力
    money=PLAYER_MONEY_START;//金钱
    towernum=PLAYER_HASTOWERNUM;//可持有塔数量
    maxhp=PLAYER_MAXHP;
    maxmp=PLAYER_MAXMP;
    maxmoney=PLAYER_MAXMONEY;//存储人物属性上限
    maxnumber= PLAYER_HASTOWERNUM;
    wave=PLAYER_PROTOWAVE;
    score=PLAYER_PROTOSCORE;
}

//基本完成
