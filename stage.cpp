#include "stage.h"
#include "config.h"
#include "tool.h"
#include <cmath>
#include <QTimer>
#include <QApplication>
#include <QDebug>

//这里按声明顺序定义所有函数
Stage::Stage()//构造基本属性
{
    background=new QPixmap;
    background->load(":/picture/background/background_test1.png");//绘制初始界面
    mapname=":/picture/background/background_test1.png";//记录背景的名称
    setPlayer();
}
Stage::~Stage(){}//析构
void Stage::setPlayer()
{
    //角色生命恢复
    player=new Player;//生成玩家
    HP=new PlayerStatus(player,"HP");//生命值初始化
    MP=new PlayerStatus(player,"MP");
    money= new PlayerStatus(player,"money");
    number=new PlayerStatus(player,"number");
    wave=new PlayerStatus(player,"wave");
    score=new PlayerStatus(player,"score");
    stagenumber=1;//波数恢复
    laststagenumber=0;//上一关卡数恢复
    secondCounter=0;
    lose=false;
}
void Stage::setStage(QString map_name)//游戏大框架的构建
{
    QApplication::setQuitOnLastWindowClosed(false);//qt自带函数，意思是在关闭最后一个窗口时程序结束
    //基本设置*
    secondCounter=0.0;//计时器归零
    manualMod=false;//初始时手动控制为关闭
    //背景设置*
    mapname=map_name;//将背景名称传进来，方便后续记录和加载
    delete background;//将原始数据清空
    background=new QPixmap;
    background->load(mapname);//加载新背景

    setPlayer();//生成玩家


    //游戏元素设置*
    //待选择炮塔

    Tower* displaytower;//通过一个临时变量displaytower将要画的塔都构造出来

    //测试塔
    displaytower=new Tower("tower_test");
    displaytower->setCenterPos(MAINWINDOW_WIDTH-TOWER_TEST_WIDTH/2
                               ,TOWER_TEST_HEIGHT/2);//设置塔选择位置
    choose_towers.push_back(displaytower);//将其存入待选择塔列表中
    //测试塔1
    displaytower=new Tower("tower_test1");//通过一个临时变量displaytower将要画的塔都构造出来
    displaytower->setCenterPos(MAINWINDOW_WIDTH-TOWER_TEST1_WIDTH/2
                               ,TOWER_TEST_HEIGHT+TOWER_TEST1_HEIGHT/2);//设置塔1选择位置
    choose_towers.push_back(displaytower);//将其存入待选择塔列表中


    //塔1
    displaytower=new Tower("tower1");//通过一个临时变量displaytower将要画的塔都构造出来
    displaytower->setCenterPos(MAINWINDOW_WIDTH-TOWER1_WIDTH/2
                               ,TOWER_TEST_HEIGHT+TOWER_TEST1_HEIGHT+TOWER1_HEIGHT/2);//设置塔1选择位置
    choose_towers.push_back(displaytower);//将其存入待选择塔列表中


    //塔2
    displaytower=new Tower("tower2");//通过一个临时变量displaytower将要画的塔都构造出来
    displaytower->setCenterPos(MAINWINDOW_WIDTH-TOWER2_WIDTH/2
                               ,TOWER_TEST_HEIGHT+TOWER_TEST1_HEIGHT
                               +TOWER1_HEIGHT+TOWER2_HEIGHT/2);//设置塔2选择位置
    choose_towers.push_back(displaytower);//将其存入待选择塔列表中


    //塔3
    displaytower=new Tower("tower3");//通过一个临时变量displaytower将要画的塔都构造出来
    displaytower->setCenterPos(MAINWINDOW_WIDTH-TOWER3_WIDTH/2
                               ,TOWER_TEST_HEIGHT+TOWER_TEST1_HEIGHT+TOWER1_HEIGHT
                               +TOWER2_HEIGHT+TOWER3_HEIGHT/2);//设置塔3选择位置
    choose_towers.push_back(displaytower);//将其存入待选择塔列表中

    //塔4
    displaytower=new Tower("tower4");//通过一个临时变量displaytower将要画的塔都构造出来
    displaytower->setCenterPos(MAINWINDOW_WIDTH-TOWER4_WIDTH/2
                               ,TOWER_TEST_HEIGHT+TOWER_TEST1_HEIGHT+TOWER1_HEIGHT
                               +TOWER2_HEIGHT+TOWER3_HEIGHT+TOWER4_HEIGHT/2);//设置塔4选择位置
    choose_towers.push_back(displaytower);//将其存入待选择塔列表中

    //塔4
    displaytower=new Tower("tower5");//通过一个临时变量displaytower将要画的塔都构造出来
    displaytower->setCenterPos(MAINWINDOW_WIDTH-TOWER5_WIDTH/2
                               ,TOWER_TEST_HEIGHT+TOWER_TEST1_HEIGHT+TOWER1_HEIGHT
                               +TOWER2_HEIGHT+TOWER3_HEIGHT+TOWER4_HEIGHT+TOWER5_HEIGHT/2);//设置塔4选择位置
    choose_towers.push_back(displaytower);//将其存入待选择塔列表中

}
void Stage::actMouseMove(QMouseEvent *e)//鼠标移动，炮塔跟随实现
{
    mousepoint.setMousePoint(e);//将鼠标坐标传给记录点
    for(int i=0;i<drag_towers.size();i++){
        //drag_towers[i]->setCenterPos(150*(int)(e->x()/150)+75,160*(int)(e->y()/160)+80);
        //利用取整函数可以实现植物大战僵尸的那种定位式炮塔摆放
        drag_towers[i]->setCenterPos(e->x(),e->y());//鼠标移动时也能跟随
    }
    for(int i=0;i<choose_towers.size();i++){
        if(choose_towers[i]->isMouseIn(e)){
            choose_towers[i]->setChecked(true);
            //qDebug()<<"鼠标在塔上";
        }else{
            choose_towers[i]->setChecked(false);
        }
    }
}
void Stage::actMousePress(QMouseEvent *e)//左右键基本功能实现
{
    int i;
    if(e->button()==Qt::LeftButton&&manualMod==false){
        //如果点击鼠标左键并且处于非手动模式
//        for(i=0;i<towers.size();i++){//逐个检查是否点击了已放置的塔
//            if(towers[i]->isMouseIn(e)){
//                //如果第i个塔被点击
//                towers[i]->setIsChosen(true);//这个塔被选中
//                towers[i]->setRotateReady(true);//设置其为完成旋转(因为此时鼠标点击了塔,，保证能一边旋转一边开火)
//                this->manualMod=true;//手动模式开启
//            }
//        }//这种写法会使得叠加的塔被同时操作
        for(i=towers.size()-1;i>=0;i--){
            if(towers[i]->isMouseIn(e)&&manualMod==false){//底下的塔不会被选中
                towers[i]->setIsChosen(true);//这个塔被选中
                towers[i]->setRotateReady(true);//设置其为完成旋转(因为此时鼠标点击了塔,，保证能一边旋转一边开火)
                this->manualMod=true;//手动模式开启
            }
        }//比较平衡游戏性的写法
        for(i=0;i<choose_towers.size();i++){//逐个检查待选择的塔
            if(i<stagenumber*TOWER_UPDATENUMBER){//对于可以购买的塔进行判断
                if(choose_towers[i]->isMouseIn(e)){
                    //当塔被点击时
                    if(player->getTowerNum()>0){//当可以建塔时
                        for(int j=0;j<drag_towers.size();j++){
                            delete drag_towers[j];
                        }
                        drag_towers.clear();//先把拖动列表清空
                        Tower* tmp=new Tower(choose_towers[i]->getType());//定义一个临时变量，存储所选炮塔的信息
                        tmp->setCenterPos(e->x(),e->y());//跟随鼠标
                        drag_towers.push_back(tmp);//将当前塔的信息存入拖动塔之中
                    }
                    return;//跳出函数，防止多次点击
                }
            }

        }
        for(int j=0;j<drag_towers.size();j++){//如果放置正在拖动的塔
            if(player->getMoney()<drag_towers[j]->getPrice()||player->getMp()<drag_towers[j]->getNeedMP()){
                //没钱
                qDebug()<<"没钱";
                break;
            }else{
                //有钱
                towers.push_back(drag_towers[j]);//把正在拖动的这个塔的信息存入在场列表中
                player->setMoney(player->getMoney()-drag_towers[j]->getPrice());//扣钱
                player->setMp(player->getMp()-drag_towers[j]->getNeedMP());//消耗魔力
                player->setTowerNum(player->getTowerNum()-1);
            }
        }
        drag_towers.clear();//判断完上述后要清除拖动

        for(int j=0;j<enemies.size();j++){//逐个检查是否点击了敌人
            if(enemies[j]->isMouseIn(e)){
                enemies[j]->setIsChosen(true);
            }
        }
    }else if(e->button()==Qt::LeftButton&&manualMod==true){
        //当鼠标左键点击并且处于手动模式
        pressed=true;
        for(i=0;i<towers.size();i++){//尝试另一种取消控制的方式
            if(towers[i]->isMouseIn(e)&&towers[i]->getIsChosen()){
                towers[i]->setIsChosen(false);
                manualMod=false;
                break;
            }
        }//可以用

    //上方是左键功能———————————————————————————————————————以下是右键功能
    }else if(e->button()==Qt::RightButton){
        //当鼠标右键点击
        for(i=0;i<drag_towers.size();i++){//检查拖动塔列表
            Tower* tmp=drag_towers[i];
            drag_towers.remove(i,1);//这个操作是将列表中的第i-1个元素移除
            i--;
            delete tmp;
        }
//        for(i=0;i<towers.size();i++){//逐个检查场景中的塔
//            if(towers[i]->isMouseIn(e)){//如果被右击
//                Tower* tmp=towers[i];
//                delete towers[i];//从列表中清除这个塔
//                towers.erase(towers.begin()+i);
//                i--;//因为列表中第i个元素刚被删除，所以i要自减
//                delete tmp;
//                break;//优化，保证一次只删掉一个塔
//            }
//        }//这块处理的不好，应该要删掉最上面那个塔
        for(int j=towers.size()-1;j>=0;j--){
            if(towers[j]->isMouseIn(e)){
                player->setMoney(player->getMoney()+(int)(towers[j]->getPrice()/2));//优化，回复该塔1/2的金钱
                player->setTowerNum(player->getTowerNum()+1);
                if(towers[j]->getIsChosen()){
                    manualMod=false;//取消手动模式
                }
                delete towers[j];
                towers.erase(towers.begin()+j);
                //qDebug()<<"卖塔";//测试
                break;//一次只删一个塔
            }
        }
    }
}
void Stage::actMouseRelease(QMouseEvent *e)//未点击检测
{
    if(e->button()==Qt::LeftButton){
        pressed=false;//当释放左键时状态为未点击
    }
}
void Stage::actKeyPress(QKeyEvent *e)//按下x取消手动模式
{
    if(e->key()==Qt::Key_X){
        for(int i=0;i<towers.size();i++){
            towers[i]->setIsChosen(false);//将塔全设为未选中状态
        }
        manualMod=false;//取消手动模式
    }

    if(e->key()==Qt::Key_Z&&this->manualMod==true){//塔的升级
        for(int i=0;i<towers.size();i++){
            if(towers[i]->getIsChosen()){//先判断是否被选中
                if(towers[i]->getLevel()<towers[i]->getMaxLevel()){//当塔未满级才能进行以下操作
                    if(player->getMoney()>=towers[i]->getPrice()*2
                            &&player->getMp()>=towers[i]->getNeedMP()){//金钱和魔力达到
                        player->setMoney(player->getMoney()-towers[i]->getPrice()*2);
                        player->setMp(player->getMp()-towers[i]->getNeedMP());
                        towers[i]->levelUp();
                        qDebug()<<"升级成功，当前等级："<<towers[i]->getLevel();
                    }else{
                        qDebug()<<"没钱升级";
                    }
                }else{
                    qDebug()<<"已到达顶级";
                }
                break;//找到选中塔之后即可跳出
            }
        }
    }

}
void Stage::manageHatred()//炮塔的仇恨管理
{
    int i,j;
    for(i=0;i<towers.size();i++){
        for(j=0;j<enemies.size();j++){
            float dis=Tool::distance(towers[i]->getPos(),enemies[j]->getPos());
            int index=towers[i]->hatred.indexOf(enemies[j]);
            //这一步是检测在第i个塔的仇恨列表中是否有第j个敌人，如果没有，indexOf()则返回-1,如果有，则返回其位置/地址
            if(dis<=towers[i]->getRange()&&index==-1&&enemies[j]->getHp()>0){
                //当敌人在攻击范围之内，敌人不在仇恨列表之内并且敌人存活
                towers[i]->hatred.push_back(enemies[j]);
            }
            if(index!=-1&&(dis>towers[i]->getRange()||enemies[j]->getHp()<=0)){
                //当敌人在列表中，但它跑出了攻击范围或者它挂了，就要把它从仇恨列表中删除
                towers[i]->hatred.erase(towers[i]->hatred.begin()+index);
            }
        }
    }
}
void Stage::rotateTower()//炮塔旋转处理
{
    int i;
    for(i=0;i<towers.size();i++){//所有塔逐个修改
        Point aim;//目标的坐标
        Point zero(towers[i]->getPos());//炮塔所在位置
        Point vec_toaim;//表示塔到目标的向量
        float ang_toaim;//表示塔与目标的夹角
        if(!towers[i]->hatred.isEmpty()&&!towers[i]->getIsChosen()){
            //当塔仇恨列表中有敌人，且塔未被选中
            aim=(towers[i]->hatred[0]->getPos());//炮塔的目标设置成最先仇恨的
        }else if(towers[i]->getIsChosen()&&manualMod){
            //当塔被选中并且处于手动模式
            aim=mousepoint;//将鼠标所在点设为目标
        }
        vec_toaim.setX(aim.getX()-zero.getX());
        vec_toaim.setY(aim.getY()-zero.getY());//得到连线向量
        ang_toaim=Tool::VectorToAngle(vec_toaim);//向量转化成角度
        if((!towers[i]->hatred.isEmpty()&&!towers[i]->getIsChosen())
                ||towers[i]->getIsChosen()){
            //当炮塔有仇恨没被选中，或者炮塔被选中时，进行旋转角操作
            if(abs(ang_toaim - towers[i]->getAngle()) > towers[i]->getVRotation()/FPS
                    &&abs(ang_toaim - towers[i]->getAngle()) - 360 < -towers[i]->getVRotation()/FPS){//未转到
                /*说明：当炮塔方向与连线最小夹角大于每帧旋转的角度，则要继续进行旋转
                       第一个条件代表判断其中一个夹角，第二个条件判断另一个夹角
                       然后再根据这两个角判断是应该顺时针转还是逆时针转以达到最小转角*/
                if(abs(ang_toaim-towers[i]->getAngle())<=180){//顺时针旋转
                        towers[i]->setAngle(towers[i]->getAngle()
                                        +Tool::sign(ang_toaim-towers[i]->getAngle())
                                        *towers[i]->getVRotation()/FPS);
                        if(!towers[i]->getIsChosen()){//当未被选中时，塔的旋转状态为未完成
                            towers[i]->setRotateReady(false);
                        }
                }else{//逆时针旋转
                         towers[i]->setAngle(towers[i]->getAngle()
                                        -Tool::sign(ang_toaim-towers[i]->getAngle())
                                             *towers[i]->getVRotation()/FPS);
                         if(!towers[i]->getIsChosen()){//当未被选中时，塔的旋转状态为未完成
                             towers[i]->setRotateReady(false);
                         }
                }
            }else{
                //转到了
                towers[i]->setAngle(ang_toaim);
                towers[i]->setRotateReady(true);//旋转完成
            }
        }
    }
}
void Stage::moveAction()//移动敌人和子弹
{
    int i;
    //int random_y;
    for(i=0;i<enemies.size();i++){//移动所有在场敌人
        //random_y=1+qrand()%2;
        if(enemies[i]->getPos_y()>=DOWN_WALL){
            enemies[i]->towards=-1;
        }else if(enemies[i]->getPos_y()<=UP_WALL){
            enemies[i]->towards=1;
        }
        //防止出界
        float xPre = enemies[i]->getPos().getX();
        float yPre = enemies[i]->getPos().getY();
        float x = xPre + enemies[i]->getSpeed()*enemies[i]->getDirection_x()/FPS;
        float y = yPre + enemies[i]->towards*enemies[i]->getSpeed()*enemies[i]->getDirection_y()/FPS;

        //两个轴上的移动速度(其实第二个没实际意义，但对某些怪有效)
        enemies[i]->setCenterPos(x,y);
    }
    for(i=0;i<bullets.size();i++){//移动所有在场子弹
        float xPre = bullets[i]->getPos().getX();
        float yPre = bullets[i]->getPos().getY();
        float x = xPre + bullets[i]->getSpeed()*bullets[i]->getDirection_x()/FPS;
        float y = yPre + bullets[i]->getSpeed()*bullets[i]->getDirection_y()/FPS;
        bullets[i]->setCenterPos(x,y);
    }
}
void Stage::createBullet()//子弹生成
{
    int i;
    for(i=0;i<towers.size();i++){
        if(!towers[i]->hatred.isEmpty()
                &&towers[i]->getFireReady()
                &&towers[i]->getRotateReady()
                &&!towers[i]->getIsChosen()){
            //当炮塔有目标，冷却完成，旋转完成，并且没有被控制
            Enemy* target=towers[i]->hatred[0];
            //qDebug()<<"子弹0";
            towers[i]->fireReset();//恢复冷却时间
           // qDebug()<<"子弹1";
            Bullet* b=new Bullet(towers[i],target);
            //qDebug()<<"子弹+";
            bullets.push_back(b);//加入子弹列表

            if(towers[i]->getType().compare("tower2")==0){//塔二的散射效果实现
                if(towers[i]->getLevel()==2){
                    Bullet* b[5];
                    for(int k=0;k<5;k++){
                        //qDebug()<<"多子弹1";
                        b[k]=new Bullet(towers[i],target);
                        bullets.push_back(b[k]);
                    }
                }else{
                    Bullet* b[4];
                    for(int k=0;k<4;k++){
                        //qDebug()<<"多子弹1";
                        b[k]=new Bullet(towers[i],target);
                        bullets.push_back(b[k]);
                    }
                }
            }

            if(towers[i]->getType().compare("tower3")==0){//塔三的多发效果实现
                if(towers[i]->getLevel()==2){
                    Bullet* b;
                    Bullet* b1;//副炮子弹
                    b=new Bullet(towers[i],target);
                    b1=new Bullet(towers[i],target);
                    Point p(target->getPos_x()-towers[i]->getPos_x(),target->getPos_y()-towers[i]->getPos_y());
                    float a=Tool::VectorToAngle(p)*PI/180;
                    //qDebug()<<"("<<target->getPos_x()<<","<<target->getPos_y()<<")";
                    b->setCenterPos(b->getPos_x()+(sin(a)*towers[i]->getHeight()/6),
                                    b->getPos_y()-(cos(a)*towers[i]->getHeight()/6));
                    b1->setCenterPos(b1->getPos_x()-(cos(a)*towers[i]->getWidth()/4)
                                     -(sin(a)*towers[i]->getHeight()/4),
                                     b1->getPos_y()-(sin(a)*towers[i]->getWidth()/4)
                                     +(cos(a)*towers[i]->getHeight()/4));
                    bullets.push_back(b);
                    bullets.push_back(b1);
                }else{
                    Bullet* b;
                    b=new Bullet(towers[i],target);
                    Point p(target->getPos_x()-towers[i]->getPos_x(),target->getPos_y()-towers[i]->getPos_y());
                    float a=Tool::VectorToAngle(p)*PI/180;
                    //qDebug()<<"("<<target->getPos_x()<<","<<target->getPos_y()<<")";
                    b->setCenterPos(b->getPos_x()+(sin(a)*towers[i]->getHeight()/6),
                                    b->getPos_y()-(cos(a)*towers[i]->getHeight()/6));
                    bullets.push_back(b);
                }

            }

        }else if(towers[i]->getIsChosen()
                 &&towers[i]->getFireReady()
                 &&towers[i]->getRotateReady()
                 &&pressed
                 &&manualMod){
            //手动模式下，炮塔被控制，按下鼠标，冷却，旋转完成
            towers[i]->fireReset();
            Bullet* b=new Bullet(towers[i],Tool::AngleToVector(towers[i]->getAngle()));
            bullets.push_back(b);//用第二种方法构造了新的子弹
            //qDebug()<<"子弹"<<bullets[0]->getSpeed()<<bullets.size();

            if(towers[i]->getType().compare("tower2")==0){
                if(towers[i]->getLevel()==2){
                    Bullet* b[5];
                    for(int k=0;k<5;k++){
                        //qDebug()<<"多子弹2";
                        b[k]=new Bullet(towers[i],Tool::AngleToVector(towers[i]->getAngle()));
                        bullets.push_back(b[k]);
                    }
                }else{
                    Bullet* b[4];
                    for(int k=0;k<4;k++){
                        //qDebug()<<"多子弹2";
                        b[k]=new Bullet(towers[i],Tool::AngleToVector(towers[i]->getAngle()));
                        bullets.push_back(b[k]);
                    }
                }
            }//一次创造多颗子弹

            if(towers[i]->getType().compare("tower3")==0){
                if(towers[i]->getLevel()==2){
                    Bullet* b;
                    Bullet* b1;
                    b=new Bullet(towers[i],Tool::AngleToVector(towers[i]->getAngle()));
                    b1=new Bullet(towers[i],Tool::AngleToVector(towers[i]->getAngle()));
                    Point p(Tool::AngleToVector(towers[i]->getAngle()));
                    float a=Tool::VectorToAngle(p)*PI/180;
                    b->setCenterPos(b->getPos_x()+(sin(a)*towers[i]->getHeight()/6),
                                    b->getPos_y()-(cos(a)*towers[i]->getHeight()/6));
                    b1->setCenterPos(b1->getPos_x()-(cos(a)*towers[i]->getWidth()/4)
                                     -(sin(a)*towers[i]->getHeight()/4),
                                     b1->getPos_y()-(sin(a)*towers[i]->getWidth()/4)
                                     +(cos(a)*towers[i]->getHeight()/4));
                    bullets.push_back(b);
                    bullets.push_back(b1);
                }else{
                    Bullet* b;
                    b=new Bullet(towers[i],Tool::AngleToVector(towers[i]->getAngle()));
                    Point p(Tool::AngleToVector(towers[i]->getAngle()));
                    float a=Tool::VectorToAngle(p)*PI/180;
                    b->setCenterPos(b->getPos_x()+(sin(a)*towers[i]->getHeight()/6),
                                    b->getPos_y()-(cos(a)*towers[i]->getHeight()/6));
                    bullets.push_back(b);
                }

            }

        }
    }
}
void Stage::confirmDamage()//伤害确认,清除子弹
{
    //主要是子弹和敌人的交互
    int i,j;
    for(i=0;i<enemies.size();i++){//遍历敌人
        for(j=0;j<bullets.size();j++){//遍历子弹
            if(enemies[i]->isPointIn(bullets[j]->getPos())||bullets[j]->isPointIn(enemies[i]->getPos())){
                enemies[i]->setDamage(true);//被击中后，就可以显伤了
                if(enemies[i]->getDefence()<bullets[j]->getDamage()){//防御力判断
                  enemies[i]->setHp(enemies[i]->getHp()
                                    -bullets[j]->getDamage()+enemies[i]->getDefence());
                  //扣血，但伤害要减去防御力数值
                }

                if(bullets[j]->getSlow()>0&&!enemies[i]->getIsInIce()){//减速操作，当敌人没有被冻伤且子弹有减速效果
                    //可以为敌人保留备用速度，如果在被冻伤的情况下每秒钟可以恢复速度，当速度完全恢复时冻伤解除
                    //即：如果冻伤，不接受减速，每秒钟恢复；如果没冻伤，则进行减速（该功能已实现）
                    enemies[i]->setSpeed(enemies[i]->getSpeed()-bullets[j]->getSlow()-enemies[i]->getIceTime());
                    enemies[i]->reSetIce();
                    qDebug()<<i<<"被冻伤";
                }else if(bullets[j]->getSlow()>0&&enemies[i]->getIsInIce()){
                    enemies[i]->reSetIce();//如果冻伤状态下被击中会继续冻伤
                }//这是冻伤处理

                if(bullets[j]->getToxic()>0&&!enemies[i]->getIsInToxic()){//中毒操作，当敌人没有中毒且子弹有中毒效果
                    enemies[i]->reSetToxic();
                    enemies[i]->setToxicDamage(bullets[j]->getToxic());
                    qDebug()<<i<<"中毒";
                }else if(bullets[j]->getToxic()>0&&enemies[i]->getIsInToxic()){//已经在中毒状态下
                    enemies[i]->reSetToxic();//持续中毒
                    if(bullets[j]->getToxic()>enemies[i]->getToxicDamage()){
                        enemies[i]->setToxicDamage(bullets[j]->getToxic());
                        qDebug()<<i<<"中毒更深了";
                    }//如果新中的子弹毒性更大，就要更新中毒伤害
                }//这是中毒处理

                bullets[j]->subCollisionTimes();
                if(bullets[j]->getCollisionTimes()<=0){
                    delete bullets[j];
                    bullets.erase(bullets.begin()+j);
                    j--;//删除这个子弹
                }//子弹碰撞检测

            }
        }
    }
}
void Stage::deleteObject()//敌人死亡,子弹出界,收入结算,伤害结算,游戏结束判定
{
    int i;
    for(i=0;i<enemies.size();i++){
        if(enemies[i]->getHp()<=0){
            addMoney(enemies[i]->getEarn());//加对应的金钱
            addMP(enemies[i]->getAddMP());//加对应的魔力
            player->setScore(player->getScore()+1);//分数加一
            for(int j=0;j<towers.size();j++){
                int index=towers[j]->hatred.indexOf(enemies[i]);//从每个塔里的仇恨列表找
                if(index!=-1){
                    towers[j]->hatred.erase(towers[j]->hatred.begin()+index);
                }
            }//从所有塔的仇恨列表清除
            delete enemies[i];
            delete lives[i];
            enemies.erase(enemies.begin()+i);
            lives.erase(lives.begin()+i);
            i--;//删除敌人及其血条
            if(i<0){continue;}//如果删掉的是第一个敌人，就要重新开始循环，防止越界（越界程序会异常结束）
        }

        if(enemies[i]->getPos_x()>=RIGHT){//如果怪物到了终点
            player->setHp(player->getHp()-enemies[i]->getLose());//玩家扣血
            for(int j=0;j<towers.size();j++){
                int index=towers[j]->hatred.indexOf(enemies[i]);//从每个塔里的仇恨列表找
                if(index!=-1){//在列表中
                    towers[j]->hatred.erase(towers[j]->hatred.begin()+index);
                }
            }//从所有塔的仇恨列表清除
            enemies.erase(enemies.begin()+i);
            lives.erase(lives.begin()+i);
            i--;//删除敌人及其血条
            if(i<0){continue;}//如果删掉的是第一个敌人，就要重新开始循环
        }

        if(enemies[i]->getIsInToxic()){//如果怪物处于中毒状态
            enemies[i]->handleToxicTime();//受到伤害间隔倒计时一次
            if(enemies[i]->getToxicInterval()<=0){//如果倒计时结束
                enemies[i]->setHp(enemies[i]->getHp()-enemies[i]->getToxicDamage());//受到中毒伤害一次
                enemies[i]->setToxicInterval();//伤害间隔重置
            }
            enemies[i]->coverageToxic();//中毒恢复倒计时
        }
    }
    //以上是敌人部分——————————————————————————————————————————————————————————————
    for(int i=0;i<bullets.size();i++){//子弹出界检查
        if(bullets[i]->getPos_x()<LEFT||bullets[i]->getPos_x()>RIGHT
                ||bullets[i]->getPos_y()<TOP||bullets[i]->getPos_y()>BUTTOM
                ||bullets[i]->IsOutOfRange()){
            delete bullets[i];
            bullets.erase(bullets.begin()+i);
            i--;
        }
    }
    //以上是子弹部分——————————————————————————————————————————————————————————————
    if(player->getHp()<=0){
        lose=true;
        //没血了，游戏结束
    }
    //以上是玩家部分——————————————————————————————————————————————————————————————
}
//void Stage::showLife(QMouseEvent *e)//显示敌人血条，但由于其他函数已经实现了，就没有定义
void Stage::generEnemy()//生成敌人，生成boss，记录关卡
{
    int a,b;
    static bool alreadymid=false;//判断是否到了关卡的一半
    Enemy* tmp = nullptr;//装敌人的临时变量
    EnemyHp* thp;//装敌人血条的临时变量

    //普通怪生成
    b=4;//一次性生成4个敌人
    for(int i=0;i<b;i++){
        a=stagenumber+qrand()%(stagenumber*2+1);//生成的种类
        switch (a) {
        /*说明：
            test:普通
            test1:希望怪
            1:病毒1
            2:护盾普通
            4:高温普通
            5:病毒2
            6:剧毒普通
            8:水晶
            9:病毒3
            10:谎言怪
            12:小飞碟
        */
        case 1:tmp=new Enemy("enemy_test");break;
        case 2:tmp=new Enemy("enemy1");break;
        case 3:tmp=new Enemy("enemy_test1");break;

        case 4:tmp=new Enemy("enemy10");break;
        case 5:tmp=new Enemy("enemy2");break;

        case 6:tmp=new Enemy("enemy4");break;
        case 7:tmp=new Enemy("enemy5");break;

        case 8:tmp=new Enemy("enemy6");break;
        case 9:tmp=new Enemy("enemy9");break;

        case 10:tmp=new Enemy("enemy8");break;
        default:tmp=new Enemy("enemy12");break;//在关卡后期强怪的比例会增加，所以default情况用比较强的怪
        }
        tmp->setCenterPos(LEFT,160+i*160);//设置生成点
        enemies.push_back(tmp);
        thp=new EnemyHp(tmp);
        lives.push_back(thp);//生成对应血条
    }

    //关卡中段小boss
    if(secondCounter>=ROUND_TIME/2&&!alreadymid){//半场且没有进行过敌人生成
        qDebug()<<"小BOSS战"<<stagenumber;
        alreadymid=true;
        if(stagenumber==1){//第一关
            for(int i=0;i<11;i++){
                tmp=new Enemy("enemy_test");
                tmp->setCenterPos(LEFT,110+60*i);
                enemies.push_back(tmp);
                thp=new EnemyHp(tmp);
                lives.push_back(thp);
            }
        }else if(stagenumber==2){//第二关
            for(int i=0;i<4;i++){
                tmp=new Enemy("enemy_test1");
                tmp->setCenterPos(LEFT,180+120*i);
                enemies.push_back(tmp);
                thp=new EnemyHp(tmp);
                lives.push_back(thp);
            }

            for(int i=0;i<4;i++){
                tmp=new Enemy("enemy10");
                tmp->setCenterPos(LEFT,240+120*i);
                enemies.push_back(tmp);
                thp=new EnemyHp(tmp);
                lives.push_back(thp);
            }

        }else if(stagenumber==3){//第三关
            for(int i=0;i<8;i++){
                tmp=new Enemy("enemy8");
                tmp->setCenterPos(LEFT,120+80*i);
                enemies.push_back(tmp);
                thp=new EnemyHp(tmp);
                lives.push_back(thp);
            }

            tmp=new Enemy("enemy3");
            tmp->setCenterPos(LEFT,BUTTOM*2/3);
            enemies.push_back(tmp);
            thp=new EnemyHp(tmp);
            lives.push_back(thp);

            tmp=new Enemy("enemy3");
            tmp->setCenterPos(LEFT,BUTTOM/3);
            enemies.push_back(tmp);
            thp=new EnemyHp(tmp);
            lives.push_back(thp);

        }else if(stagenumber==4){//第四关
            for(int i=0;i<8;i++){
                tmp=new Enemy("enemy8");
                tmp->setCenterPos(LEFT,100+80*i);
                enemies.push_back(tmp);
                thp=new EnemyHp(tmp);
                lives.push_back(thp);
            }

            for(int i=0;i<11;i++){
                tmp=new Enemy("enemy4");
                tmp->setCenterPos(LEFT,110+60*i);
                enemies.push_back(tmp);
                thp=new EnemyHp(tmp);
                lives.push_back(thp);
            }

            for(int i=0;i<11;i++){
                tmp=new Enemy("enemy6");
                tmp->setCenterPos(LEFT,110+60*i);
                enemies.push_back(tmp);
                thp=new EnemyHp(tmp);
                lives.push_back(thp);
            }
        }else if(stagenumber==5){//第五关
            tmp=new Enemy("enemy7");
            tmp->setCenterPos(LEFT,BUTTOM/4);
            enemies.push_back(tmp);
            thp=new EnemyHp(tmp);
            lives.push_back(thp);

            tmp=new Enemy("enemy3");
            tmp->setCenterPos(LEFT,BUTTOM*3/4);
            enemies.push_back(tmp);
            thp=new EnemyHp(tmp);
            lives.push_back(thp);

            tmp=new Enemy("enemy11");
            tmp->setCenterPos(LEFT,BUTTOM/2);
            enemies.push_back(tmp);
            thp=new EnemyHp(tmp);
            lives.push_back(thp);
        }

    }

    //boss生成
    /*说明：
        3：大石头
        7：活尸
        11：大飞碟
        13：Smile
    */
    if(secondCounter>=ROUND_TIME){
        secondCounter=0;
        alreadymid=false;
        qDebug()<<"BOSS战"<<stagenumber;
        if(stagenumber==1){//第一关
            tmp=new Enemy("enemy3");
            tmp->setCenterPos(LEFT,BUTTOM/2);
            enemies.push_back(tmp);
            thp=new EnemyHp(tmp);
            lives.push_back(thp);
        }else if(stagenumber==2){//第二关
            for(int i=0;i<7;i++){
                tmp=new Enemy("enemy12");
                tmp->setCenterPos(LEFT,120+90*i);
                enemies.push_back(tmp);
                thp=new EnemyHp(tmp);
                lives.push_back(thp);
            }

            tmp=new Enemy("enemy11");
            tmp->setCenterPos(LEFT,BUTTOM/3);
            enemies.push_back(tmp);
            thp=new EnemyHp(tmp);
            lives.push_back(thp);

            tmp=new Enemy("enemy11");
            tmp->setCenterPos(LEFT,BUTTOM*2/3);
            enemies.push_back(tmp);
            thp=new EnemyHp(tmp);
            lives.push_back(thp);

        }else if(stagenumber==3){//第三关
            for(int i=0;i<5;i++){
                tmp=new Enemy("enemy5");
                tmp->setCenterPos(LEFT,120+120*i);
                enemies.push_back(tmp);
                thp=new EnemyHp(tmp);
                lives.push_back(thp);
            }

            for(int i=0;i<5;i++){
                tmp=new Enemy("enemy9");
                tmp->setCenterPos(LEFT,180+120*i);
                enemies.push_back(tmp);
                thp=new EnemyHp(tmp);
                lives.push_back(thp);
            }

            tmp=new Enemy("enemy7");
            tmp->setCenterPos(LEFT,BUTTOM/2);
            enemies.push_back(tmp);
            thp=new EnemyHp(tmp);
            lives.push_back(thp);

        }else if(stagenumber==4){//第四关
            tmp=new Enemy("enemy13");
            tmp->setCenterPos(LEFT,BUTTOM/2);
            enemies.push_back(tmp);
            thp=new EnemyHp(tmp);
            lives.push_back(thp);
        }

        givePrize();//每到一个boss战都会得到相应奖励
        this->frequency--;//出怪速度要加快
    }

}
void Stage::givePrize()//奖励机制
{
    HP->setNewNumber();
    MP->setNewNumber();
    money->setNewNumber();
    number->setNewNumber();//属性条规格修改

    player->setMaxHp(player->getMaxHp()+10);
    player->setMaxMp(player->getMaxMp()+10);
    player->setMaxMoney(player->getMaxMoney()+200);
    player->setMaxNumber(player->getMaxNumber()+1);//属性上限提升

    player->setTowerNum(player->getTowerNum()+1);
    this->addHP(20);
    this->addMP(10);
    this->addMoney(stagenumber*100);//属性恢复以及奖励

    stagenumber++;//场景数改变
    player->setWave(player->getWave()+1);//玩家波数记录
}
void Stage::clearStage()//清除所有实例
{
    savedstage=0;//被保存的场景清零
    for(int i=0;i<bullets.size();i++){
        delete bullets[i];
        bullets.erase(bullets.begin()+i);
        i--;
    }//删子弹
    for(int i=0;i<enemies.size();i++){
        delete enemies[i];
        enemies.erase(enemies.begin()+i);
        i--;
    }//删敌人
    for(int i=0;i<towers.size();i++){
        delete towers[i];
        towers.erase(towers.begin()+i);
        i--;
    }//删炮塔
    for(int i=0;i<choose_towers.size();i++){
        delete choose_towers[i];
        choose_towers.erase(choose_towers.begin()+i);
        i--;
    }//删待选炮塔
    for(int i=0;i<lives.size();i++){
        delete lives[i];
        lives.erase(lives.begin()+i);
        i--;
    }//删血条
    delete HP;
    delete MP;
    delete money;
    delete number;
    delete tcircle;//后来发现这些不用
    delete background;//清空数据
    background=new QPixmap;
    background->load(":/picture/background/background_test1.png");
    mapname=":/picture/background/background_test1.png";//背景恢复成主界面
}
void Stage::addMoney(int a)//给玩家增加金钱的操作
{
    if(player->getMoney()+a<player->getMaxMoney()){
        player->setMoney(player->getMoney()+a);//设置为当前金钱+a
    }else{
        player->setMoney(player->getMaxMoney());
    }
    //qDebug()<<"当前金钱"<<player->getMoney();

}
void Stage::addMP(int a)//回蓝操作
{
    if(player->getMp()+a<player->getMaxMp()){
        player->setMp(player->getMp()+a);
    }else{
        player->setMp(player->getMaxMp());
    }
}
void Stage::addHP(int a)//回血操作
{
    if(player->getHp()+a<player->getMaxHp()){
        player->setHp(player->getHp()+a);
    }else{
        player->setHp(player->getMaxHp());
    }
}
void Stage::changeBackGround()//根据关卡改变背景
{
    if(stagenumber==1){
        background->load(":/picture/background/background1.png");
    }else if(stagenumber==2){
        background->load(":/picture/background/background2.png");
    }else if(stagenumber==3){
        background->load(":/picture/background/background3.png");
    }else if(stagenumber==4){
        background->load(":/picture/background/background4.png");
    }else if(stagenumber==5){
        background->load(":/picture/background/background5.png");
    }else{
        background->load(":/picture/background/background5.png");
    }
}
void Stage::saveStage()//存档
{
    delete background;
    background=new QPixmap;
    background->load(":/picture/background/background_test1.png");
    mapname1=mapname;//记录退出时所在场景
    mapname=":/picture/background/background_test1.png";
}
void Stage::returnStage()//读档
{
    delete background;//清除当前背景
    background=new QPixmap;
    background->load(mapname1);//加载之前记录的背景
    mapname=mapname1;//记录当前背景
}
void Stage::show(QPainter *p)//最终的舞台整体绘制
{
    int i;
    secondCounter += 1.0/FPS;//每绘制一次计时器加一次时间
    //qDebug()<<secondCounter;

    p->drawPixmap(0,0,MAINWINDOW_WIDTH,MAINWINDOW_HEIGHT,*background);//画当前地图

    manageHatred();//仇恨管理
    //负面状态处理——————————————————————————————————
    for(i=0;i<towers.size();i++){
        towers[i]->coolDown();
    }//处理冷却
    for(i=0;i<enemies.size();i++){
        enemies[i]->coverageIce();
    }//处理冻伤
    //————————————————————————————————————————————
    rotateTower();//旋转塔
    moveAction();//移动
    createBullet();//生成子弹
    confirmDamage();//伤害确认
    if(((secondCounter - (int)(secondCounter/frequency)*frequency) >= 0.0)
            && ((secondCounter - (int)(secondCounter/frequency)*frequency) < 1.0/FPS)){
        generEnemy();//当完成一次计时周期，即一秒
        //secondCounter=0;//归零
        //qDebug()<<secondCounter;
    }
    deleteObject();//结算
    if(mapname!=":/picture/background/background_test1.png"){
        //如果不在开始界面，就把一切都画一遍

        for(i=0;i<drag_towers.size();i++){
            drag_towers[i]->show(p);
        }//画所有正在拖动的塔

        for(i=0;i<enemies.size();i++){
            enemies[i]->show(p);
        }//画所有敌人

        for(i=0;i<lives.size();i++){
            lives[i]->show(p);
        }//画所有敌人血条

        for(i=0;i<towers.size();i++){
            towers[i]->show(p);
            if(towers[i]->getIsChosen()){//绘制选中符号和攻击范围
                towers[i]->tsign=new TowerSign(towers[i]->getPos());
                towers[i]->tsign->show(p);
                tcircle=new TowerRangeCircle(towers[i]);
                tcircle->show(p);
            }
        }//画场景上所有塔

        for(i=0;i<bullets.size();i++){
            bullets[i]->show(p);
        }//画所有子弹

        //这里打算将塔设置为可以按照波数依次显示的模式
        for(i=0;i<choose_towers.size();i++){
            if(i<stagenumber*TOWER_UPDATENUMBER){//随着特定的关卡得到的炮塔在改变
                choose_towers[i]->show(p);

                if(choose_towers[i]->getChecked()){
                    choose_towers[i]->ti=new TowerIntroduction(choose_towers[i]->getPos());
                    choose_towers[i]->ti->setIntroIcon(choose_towers[i]->getType());
                    choose_towers[i]->ti->show(p);
                    //qDebug()<<"信息";
                }//顺便显示一下炮塔信息
            }
        }//画待购买的塔
        //注意：这里绘画顺序的先后有图层关系，先执行的会先画

        if(mapname!=":/picture/background/background_test1.png"){//当不在主场景时才要进行这些操作
            this->changeBackGround();//换背景
            HP->show(p);
            MP->show(p);
            money->show(p);
            number->show(p);//当不在主场景时绘制属性条
            wave->show(p);
            score->show(p);
        }

    }
}

//基本完成
