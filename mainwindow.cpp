#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "config.h"
#include "stage.h"
#include <windows.h>
#include <QTime>
#include <QDebug>
#include <QMessageBox>
#include <sstream>
#include <iostream>
#include <string>

//以下函数按声明顺序构造
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    world()//初始化游戏
{
    ui->setupUi(this);
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));//用当前时间作为所有随机事件的种子

    setMouseTracking(true);//随时监听鼠标位置
    centralWidget()->setMouseTracking(true);//将界面中心设为参考点
    setWindowFlag(Qt::WindowCloseButtonHint);//界面样式
    setFixedSize(MAINWINDOW_WIDTH,MAINWINDOW_HEIGHT);//界面大小
}
MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::paintEvent(QPaintEvent* e)//绘制
{
    QPainter* p=new QPainter;//新建一个画笔
    p->begin(this);//画笔需要激活
    this->world.show(p);
    p->end();
    delete p;//删除画笔
}
void MainWindow::keyPressEvent(QKeyEvent* e)
{
    world.actKeyPress(e);
}
void MainWindow::mousePressEvent(QMouseEvent* e)
{
    world.actMousePress(e);
}
void MainWindow::mouseMoveEvent(QMouseEvent* e)
{
    world.actMouseMove(e);
}
void MainWindow::mouseReleaseEvent(QMouseEvent* e)
{
    world.actMouseRelease(e);
}
void MainWindow::add_money()//感觉没什么用...
{
    world.addMoney(PLAYER_MAXMONEY);
}
void MainWindow::set_Stage()//切换关卡的函数
{
    //qDebug()<<"stage更新";
    if(world.stagenumber-world.laststagenumber==1&&!world.alreadyplayed){
        world.laststagenumber++;
        refresher->stop();


        if(world.stagenumber==1){//以下是每关的提示
            QMessageBox message1(QMessageBox::NoIcon,"开始新的一轮游戏","欢迎来到这个游戏\n让我们来简单熟悉一下游戏规则");
            message1.exec();
            QMessageBox message2(QMessageBox::NoIcon,"游戏规则","右边是当前可购买的炮塔\n"
                                                            "将鼠标放在上面可查看炮塔属性");
            message2.exec();
            QMessageBox message3(QMessageBox::NoIcon,"游戏规则","左上角是你的各项属性");
            message3.exec();
            QMessageBox message4(QMessageBox::NoIcon,"游戏规则","HP 代表了你的生命总量\n"
                                                            "敌人到达最右端时会扣除相应值\n"
                                                            "当其归零时游戏会结束");
            message4.exec();
            QMessageBox message5(QMessageBox::NoIcon,"游戏规则","MP 和 Money 是购买炮塔的必需品\n"
                                                            "缺少其中一样都无法购买炮塔\n"
                                                            "Money 可通过击败任意敌人获得\n"
                                                            "MP 只能通过击败特定敌人获得");
            message5.exec();
            QMessageBox message6(QMessageBox::NoIcon,"游戏规则","Number 是你当前能购买的最大炮塔数量\n");
            message6.exec();
            QMessageBox message(QMessageBox::NoIcon,"游戏规则","每关结束后能得到一定的补给\n"
                                                            "同时各项属性上限都会得到提升");
            message.exec();
            QMessageBox message7(QMessageBox::NoIcon,"游戏开始","祝游戏愉快！\n\n"
                                                            "注意：各个关卡的Boss不同程度地精神污染，可能会引起不适");
            message7.exec();
            QMessageBox message8(QMessageBox::NoIcon,"这是一个提示","在每一关的开头，你可以知道新出现敌人的特性");
            message8.exec();
            QMessageBox message9(QMessageBox::NoIcon,"新敌人","普通类型：\n\n"
                                                           "普通怪\n"
                                                           "特性：无，这是最弱的怪物\n"
                                                           "它就和自己的名字一样普通");
            message9.setIconPixmap(QPixmap(":/picture/enemy/enemy_test2.png"));
            message9.exec();
            QMessageBox message10(QMessageBox::NoIcon,"新敌人","病毒类型：\n\n"
                                                           "体液传播\n"
                                                           "特性：普通的病毒\n"
                                                            "病毒类怪物免疫中毒\n"
                                                           "但它们似乎不适应冰冻");
            message10.setIconPixmap(QPixmap(":/picture/enemy/enemy1.png"));
            message10.exec();
            QMessageBox message11(QMessageBox::NoIcon,"新敌人","特殊类型：\n\n"
                                                           "希望怪\n"
                                                           "特性：一只充满希望的生物\n"
                                                            "希望的垫脚石\n"
                                                           "血比较厚\n"
                                                            "对中毒的抗性较低\n"
                                                            "特殊类敌人拥有走位能力\n\n"
                                                            "   斯巴拉西~");
            message11.setIconPixmap(QPixmap(":/picture/enemy/enemy_test1.png"));
            message11.exec();
        }else if(world.stagenumber==2){
            QMessageBox message1(QMessageBox::NoIcon,"新敌人","普通类型：\n\n"
                                                           "护盾普通怪\n"
                                                           "特性：带有护盾的普通怪特异种\n"
                                                           "子弹伤害高于一定程度才能对其造成伤害");
            message1.setIconPixmap(QPixmap(":/picture/enemy/enemy2.png"));
            message1.exec();
            QMessageBox message2(QMessageBox::NoIcon,"新敌人","特殊类型：\n\n"
                                                           "谎言怪\n"
                                                           "特性：一只喜爱撒谎的生物\n"
                                                            "自称最讨厌撒谎\n"
                                                           "对冰冻的抗性较低\n\n"
                                                            "   泥嘻嘻~");
            message2.setIconPixmap(QPixmap(":/picture/enemy/enemy10.png"));
            message2.exec();
            QMessageBox message3(QMessageBox::NoIcon,"新敌人","BOSS：\n\n"
                                                           "平淡无奇的普通石头\n"
                                                           "特性：速度慢\n"
                                                            "防御力极高\n"
                                                           "尝试使用威力大的炮塔");
            message3.setIconPixmap(QPixmap(":/picture/enemy/enemy3.png"));
            message3.exec();
        }else if(world.stagenumber==3){
            QMessageBox message(QMessageBox::NoIcon,"新敌人","障碍类型：\n\n"
                                                           "水晶\n"
                                                           "特性：障碍物\n"
                                                           "不会冻伤，也不会中毒，只能用威力大的炮塔消灭\n"
                                                           "它们会干扰炮塔的攻击，导致炮塔无法及时瞄准其他敌人\n"
                                                           "建议尽早消灭\n\n"
                                                           "不过它们不会造成伤害");
            message.setIconPixmap(QPixmap(":/picture/enemy/enemy8.png"));
            message.exec();
            QMessageBox message1(QMessageBox::NoIcon,"新敌人","普通类型：\n\n"
                                                           "高温普通怪\n"
                                                           "特性：免疫冻伤的普通怪特异种");
            message1.setIconPixmap(QPixmap(":/picture/enemy/enemy4.png"));
            message1.exec();
            QMessageBox message2(QMessageBox::NoIcon,"新敌人","病毒类型：\n\n"
                                                           "空气传播\n"
                                                           "特性：更强一些的病毒\n"
                                                            "对冰冻的抗性更弱了");
            message2.setIconPixmap(QPixmap(":/picture/enemy/enemy5.png"));
            message2.exec();
            QMessageBox message3(QMessageBox::NoIcon,"新敌人","机械类型：\n\n"
                                                           "小飞碟\n"
                                                           "特性：在所有敌人中速度最快\n"
                                                           "慢速的子弹很难击中");
            message3.setIconPixmap(QPixmap(":/picture/enemy/enemy12.png"));
            message3.exec();
            QMessageBox message4(QMessageBox::NoIcon,"新敌人","BOSS：\n\n"
                                                           "普通但美丽的飞碟\n"
                                                           "特性：防御力比较高\n"
                                                           "速度最快的BOSS\n\n"
                                                           "但本身相对脆弱");
            message4.setIconPixmap(QPixmap(":/picture/enemy/enemy11.png"));
            message4.exec();
        }else if(world.stagenumber==4){
            QMessageBox message1(QMessageBox::NoIcon,"新敌人","普通类型：\n\n"
                                                           "剧毒普通怪\n"
                                                           "特性：伤害极高的普通怪特异种\n"
                                                           "尽量避免让他们到达终点，否则损失会很严重");
            message1.setIconPixmap(QPixmap(":/picture/enemy/enemy6.png"));
            message1.exec();
            QMessageBox message2(QMessageBox::NoIcon,"新敌人","病毒类型：\n\n"
                                                           "随便传播\n"
                                                           "特性：更更强一些的病毒\n"
                                                           "对冰冻的抗性更更弱了");
            message2.setIconPixmap(QPixmap(":/picture/enemy/enemy9.png"));
            message2.exec();
            QMessageBox message3(QMessageBox::NoIcon,"新敌人","BOSS：\n\n"
                                                           "精神污染\n"
                                                           "特性：血比较厚\n"
                                                            "少许的防御力\n");
            message3.setIconPixmap(QPixmap(":/picture/enemy/enemy7.png"));
            message3.exec();
        }else if(world.stagenumber==5){
            QMessageBox message1(QMessageBox::NoIcon,"新敌人","BOSS：\n\n"
                                                           "Smile\n"
                                                           "特性：最终的BOSS，血量100000，伤害999999\n"
                                                           "防御力为0，所有的炮塔都能对其造成伤害\n"
                                                           "但要注意周围新生成的怪物\n\n\n"
                                                           "ps：这个BOSS是我的Logo哦~");
            message1.setIconPixmap(QPixmap(":/picture/enemy/enemy13.png"));
            message1.exec();
            QMessageBox message2(QMessageBox::NoIcon,"提示","加油，这是最后一波哦！");
            message2.exec();
        }

    refresher->start(1000/FPS);
    }//1到2
}
void MainWindow::show_Lose()
{
    if(world.lose==1){
        refresher->stop();
        bgm->stop();
        delete bgm;

//        addmoney->stop();
//        setstage->stop();
//        int a=QMessageBox::warning(NULL, "游戏结束", "你输辽!",QMessageBox::Yes, QMessageBox::Yes);
//        if(QMessageBox::Yes==a){//如果按下Yes(其实也没其他选择)
//            world.clearStage();
//            ui->frame->show();//主菜单按钮出现
//        }

//        int a=QMessageBox::warning(nullptr,"游戏结束","你输辽......",QMessageBox::Yes, QMessageBox::Yes);
//        if(QMessageBox::Yes==a){
//            world.clearStage();
//            world.lose=false;
//            ui->frame->show();
//        }
        int a=checkScore();
        QString res = "你输惹！\n\n最终得分：";
        QString num= QString::number(a);
        res+=num;
        QMessageBox message(QMessageBox::NoIcon,"游戏结束",res);
        message.exec();

        world.alreadyplayed=true;
        world.clearStage();
        world.lose=false;
        ui->frame->show();
    }
}
void MainWindow::show_Win()
{
    if(world.stagenumber>=6){
        refresher->stop();
        bgm->stop();
        delete bgm;

        int a=checkScore();
        QString res = "你赢惹！\n\n最终得分：";
        QString num= QString::number(a);
        res+=num;
        QMessageBox message(QMessageBox::NoIcon,"恭喜",res);
        message.exec();

        world.alreadyplayed=true;
        world.clearStage();
        world.lose=false;
        ui->frame->show();
    }
}
int MainWindow::checkScore()
{
    int sum=0;
    sum=world.player->getHp()*100+world.player->getScore()*50
            +world.player->getMp()*50+world.player->getMoney()*10+world.player->getWave()*5000;
    return sum;
}
void MainWindow::on_pushButton_play_clicked()//开始游戏的按钮
{
//    if(world.savedstage==1){
//        world.clearStage();//判断是否有旧游戏，如果有就删档
//    }
    ui->frame->hide();//隐藏按钮
    world.setStage(":/picture/background/background1.png");//加载第一关图片
//    world.savedstage=1;//有存档
    world.lose=0;
    world.frequency=ENEMY_FREQUENCY;//出怪速度
//    world.player->setHp(PLAYER_LIFE_START);
//    world.player->setMp(PLAYER_MAGIC_START);
//    world.player->setMoney(PLAYER_MONEY_START);
    //各项数值初始化
    this->refresher=new QTimer;
    refresher->start(1000/FPS);//刷新速率

    this->bgmlist=new QMediaPlaylist;
    bgmlist->setCurrentIndex(1);
    bgmlist->setPlaybackMode(QMediaPlaylist::CurrentItemInLoop);//循环播放
    bgmlist->addMedia(QUrl("qrc:/sound/BGM/BGM.mp3"));
    this->bgm=new QMediaPlayer;//背景音乐
    bgm->setPlaylist(bgmlist);
    bgm->setVolume(60);//音量
    bgm->play();

    QObject::connect(refresher,SIGNAL(timeout()),this,SLOT(set_Stage()));//关卡更新
    QObject::connect(refresher,SIGNAL(timeout()),this,SLOT(show_Win()));//成功检测
    QObject::connect(refresher,SIGNAL(timeout()),this,SLOT(update()));//每到一次时间更新一次
    QObject::connect(refresher,SIGNAL(timeout()),this,SLOT(show_Lose()));//失败检测
//    qDebug()<<"yes";

//    this->addmoney=new QTimer;
//    addmoney->start(10000);//十秒加一次钱
//    QObject::connect(addmoney,SIGNAL(timeout()),this,SLOT(add_money));
}
void MainWindow::on_pushButton_help_clicked()
{
    QString s="游戏:普通的塔防v1.0\n"
              "游戏操作:\n"
              "炮塔购买:鼠标左键单击击右侧炮塔,再单击界面进行放置(拥有炮塔的数量不能超过上限)\n"
              "炮塔出售:鼠标右键单击炮塔可以对已经购买的炮塔进行出售,并获得一半的金钱(注意这时魔力值无法恢复)\n"
              "炮塔控制:鼠标左键单击炮塔进行控制,可以自行控制炮塔攻击\n"
              "炮塔升级:选中炮塔后按下键盘“Z”可以升级炮塔\n"
              "取消控制:按下键盘“X”或鼠标左键单击已选中炮塔可以取消对炮塔的控制\n"
              "祝游戏愉快！:D\n\n"
              "注意：各个关卡的Boss不同程度地精神污染，可能会引起不适";
    QMessageBox::about(nullptr,"游戏帮助",s);

}

//
