#ifndef STAGE_H
#define STAGE_H

#include <QString>
#include <QPainter>
#include <vector>
#include <QPixmap>
#include <QTime>
#include <QDialog>
#include <QMessageBox>
#include "objectinteract.h"
#include "tower.h"
#include "enemy.h"
#include "bullet.h"
#include "player.h"
#include "playerstatus.h"
#include "enemyhp.h"
#include "towersign.h"
#include "towerrangecircle.h"

/*
说明：
最重要的类
进行游戏的平台
包括了游戏中各个元素交互相关的所有操作
*/

class Stage
{
public:
    Stage();//构造和初始化
    ~Stage();//析构和内存清理
    //无类内定义
    //类外定义
    //———————————————————————————————————————————————————————
    //场景设置
    void setStage(QString map_name);//用来更换背景，同时进行地图类的初始化
    void setPlayer();//用来生成玩家数据，可以节省代码量
    //玩家操作—————————————————————————————————————————————————
    //鼠标操作相关
    void actMouseMove(QMouseEvent* e);//处理鼠标移动
    void actMousePress(QMouseEvent* e);//处理鼠标点击
    void actMouseRelease(QMouseEvent* e);//处理鼠标释放
    //键盘操作相关
    void actKeyPress(QKeyEvent* e);//处理按键操作
    /*备注：这里的主要想法是
           鼠标放置：可以查看炮塔属性(待实现)
           鼠标左键：选择炮塔，放置炮塔，控制炮塔，查看敌人
           鼠标右键：删除选中的炮塔，取消炮塔的购买
           键盘x：取消对炮塔的控制
           键盘z：对选中的炮塔进行升级
    */
    //————————————————————————————————————————————————————————
    //系统更新操作
    void manageHatred();//管理仇恨列表（仇恨列表定义在Tower类中）
    void rotateTower();//旋转炮塔
    void moveAction();//使子弹和敌人进行移动
    void createBullet();//生成子弹
    void confirmDamage();//确认造成伤害
    void deleteObject();//对象删除
    /*对象删除的条件：
      敌人：血量为0，到达终点
      子弹：出界，触碰到敌人
      炮塔：被拆
      玩家：游戏结束
      操作流程为：仇恨——>冷却(Tower类中)——>炮塔旋转——>敌人移动
                ——>生成敌人——>制造子弹——>伤害判定——>删除
    */
    //————————————————————————————————————————————————————————
    //其他操作
    //static float distance(Point a,Point b);//测距，后来加到Tool类中
    void showLife(QMouseEvent* e);//显示敌人血条,未定义
    void generEnemy();//生成敌人
    void givePrize();//关卡过后的奖励
    void clearStage();//退出时清除场景
    void addMoney(int a);//加钱
    void addMP(int a);//回复MP
    void addHP(int a);//回复HP(未添加，可以考虑有生命奖励的怪)
    //————————————————————————————————————————————————————————
    //拓展操作
    void changeBackGround();//每关更换背景
    void saveStage();//存档(已定义函数，但暂时不考虑添加)
    void returnStage();//读档(已定义函数，但暂时不考虑添加)
    //————————————————————————————————————————————————————————
    //最终绘制
    void show(QPainter* p);//绘制用函数，在更新后绘制场景中所有内容

    //————————————————————————————————————————————————————————
    //其他公有变量
    Player* player;//玩家，放在public里方便调用和修改数值
    QString mapname,mapname1;//背景名称和备用背景，用于背景更换
    TowerRangeCircle* tcircle;//场景中塔的攻击范围
    int frequency;//敌人生成的频率，关卡越往后越快
    int level;//敌人生成的等级，等级越高越有可能出现强敌
    int weakness;//最弱敌人的等级，随着关卡变化这个值会提升
    int towernumber;//最多拥有的塔的数量

    int stagenumber;//关卡数
    int laststagenumber;//上一关卡数，当两关卡数不同时显示敌人信息
    //两者搭配起来可以共同调整关卡难度，关卡背景

    bool lose;//判断是否输
    bool savedstage;//判断是否有已经被保存的场景
    bool alreadyplayed=false;//判断是否已经玩过一把游戏

private:
    //场景中的各种元素
    QVector<Tower*> towers;//被摆放的所有防御塔列表
    QVector<Tower*> choose_towers;//待选择的所有防御塔类型
    QVector<Tower*> drag_towers;//被鼠标拖动的塔
    QVector<Enemy*> enemies;//已经生成的所有敌人的列表
    QVector<EnemyHp*> lives;//被击中或选中的所有敌人的血条
    QVector<Bullet*> bullets;//场景中所有子弹的列表
    QPixmap* background;//背景
    PlayerStatus* HP;//玩家的生命值
    PlayerStatus* MP;//玩家的魔法值
    PlayerStatus* money;//玩家的金钱
    PlayerStatus* number;//拥有塔的数量
    PlayerStatus* wave;//玩家当前处于的波数
    PlayerStatus* score;//玩家当前的分数
    //操作属性
    Point mousepoint;//监听鼠标事件得到的坐标，用来判断点击的是哪里
    float secondCounter;//计时器，用做炮塔冷却和关卡更新
    bool manualMod;//是否能够用鼠标操作，是则为1
    bool pressed;//是否处于已经被点中的状态，是则为1
};

#endif // STAGE_H
