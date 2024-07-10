#ifndef CONFIG_H
#define CONFIG_H
/*
说明：
这是一个用来存储游戏基础数值的头文件
所有的宏定义数据都放在这里
只需要改变这个头文件里的数据就能对游戏进行调整
其中速度类数据以秒计
炮塔的属性：宽度，高度，伤害，范围，火力(冷却间隔)，转速，价格
子弹的属性：宽度，高度，速度，减速能力
敌人的属性：宽度，高度，速度，生命，奖励，防御力，生命损失
玩家的属性：宽度，高度，生命，魔力，金钱
*/
//——————————————————————————————————————————————————————————————
//数学类数据*****
#define PI 3.14159265358979323846
//——————————————————————————————————————————————————————————————
//背景类数据*****
#define MAINWINDOW_HEIGHT 800//主页面高度
#define MAINWINDOW_WIDTH 1200//主页面宽度
#define LEFT 0//左侧判定边界
#define RIGHT 1200//右侧判定边界
#define TOP 0//上端判定边界
#define BUTTOM 800//下端判定边界
#define UP_WALL 160//上端墙壁判定边界
#define DOWN_WALL 640//下端墙壁判定边界
//——————————————————————————————————————————————————————————————
//玩家类数据*****
#define PLAYER_WIDTH 40//宽度
#define PLAYER_HEIGHT 80//高度
#define PLAYER_MAXHP 100//生命最大值
#define PLAYER_MAXMP 1000//魔力最大值
#define PLAYER_MAXMONEY 20000//金钱最大值
#define PLAYER_LIFE_START 100//初始生命值
#define PLAYER_MAGIC_START 1000//初始魔力值
#define PLAYER_MONEY_START 20000//初始金钱
#define PLAYER_HASTOWERNUM 10//最大炮塔拥有数量
#define PLAYER_PROTOSCORE 0//原始分数
#define PLAYER_PROTOWAVE 1//原始波数

//——————————————————————————————————————————————————————————————
//炮塔类数据*****
//炮塔升级成长值
#define TOWER_LEVELUP1 1.5//一级塔成长
#define TOWER_LEVELUP2 2//二级塔成长
#define TOWER_LEVELUP3 1.5//三级塔成长

//测试用炮塔数据
#define TOWER_TEST_WIDTH 120//宽度
#define TOWER_TEST_HEIGHT 100//高度
#define TOWER_TEST_DAMAGE 15//伤害
#define TOWER_TEST_RANGE 350//范围
#define TOWER_TEST_FIREINTERVAL 0.2//火力
#define TOWER_TEST_VROTATION 300//转速
#define TOWER_TEST_PRICE 100//价格
#define TOWER_TEST_COSTMP 0//魔力花费

//测试用炮塔1数据
#define TOWER_TEST1_WIDTH 110//宽度
#define TOWER_TEST1_HEIGHT 130//高度
#define TOWER_TEST1_DAMAGE 200//伤害
#define TOWER_TEST1_RANGE 500//范围
#define TOWER_TEST1_FIREINTERVAL 2//火力
#define TOWER_TEST1_VROTATION 500//转速
#define TOWER_TEST1_PRICE 200//价格
#define TOWER_TEST1_COSTMP 0//魔力花费

//炮塔1数据
#define TOWER1_WIDTH 190//宽度
#define TOWER1_HEIGHT 110//高度
#define TOWER1_DAMAGE 50//伤害
#define TOWER1_RANGE 300//范围
#define TOWER1_FIREINTERVAL 0.5//火力
#define TOWER1_VROTATION 200//转速
#define TOWER1_PRICE 100//价格
#define TOWER1_COSTMP 15//魔力花费

//炮塔2数据
#define TOWER2_WIDTH 120//宽度
#define TOWER2_HEIGHT 120//高度
#define TOWER2_DAMAGE 8//伤害
#define TOWER2_RANGE 250//范围
#define TOWER2_FIREINTERVAL 0.1//火力
#define TOWER2_VROTATION 1000//转速
#define TOWER2_PRICE 300//价格
#define TOWER2_COSTMP 0//魔力花费

//炮塔3数据
#define TOWER3_WIDTH 200//宽度
#define TOWER3_HEIGHT 110//高度
#define TOWER3_DAMAGE 7//伤害
#define TOWER3_RANGE 800//范围
#define TOWER3_FIREINTERVAL 0.05//火力
#define TOWER3_VROTATION 400//转速
#define TOWER3_PRICE 280//价格
#define TOWER3_COSTMP 5//魔力花费

//炮塔4数据
#define TOWER4_WIDTH 200//宽度
#define TOWER4_HEIGHT 80//高度
#define TOWER4_DAMAGE 6//伤害
#define TOWER4_RANGE 700//范围
#define TOWER4_FIREINTERVAL 0.01//火力
#define TOWER4_VROTATION 100//转速
#define TOWER4_PRICE 200//价格
#define TOWER4_COSTMP 40//魔力花费

//炮塔5数据
#define TOWER5_WIDTH 175//宽度
#define TOWER5_HEIGHT 80//高度
#define TOWER5_DAMAGE 3//伤害
#define TOWER5_RANGE 500//范围
#define TOWER5_FIREINTERVAL 0.4//火力
#define TOWER5_VROTATION 600//转速
#define TOWER5_PRICE 400//价格
#define TOWER5_COSTMP 25//魔力花费
//——————————————————————————————————————————————————————————————
//子弹类数据*****
//子弹升级成长值
#define BULLET_LEVELUP 1.2//子弹按照某一比率成长即可

//测试用子弹数据
#define BULLET_TEST_WIDTH 20//宽度
#define BULLET_TEST_HEIGHT 20//高度
#define BULLET_TEST_SPEED 500//速度
#define BULLET_TEST_SLOW 0//减速能力
#define BULLET_TEST_TOXIC 0//中毒能力
#define BULLET_TEST_COLLISIONTIMES 1//最大碰撞次数

//测试用子弹1数据
#define BULLET_TEST1_WIDTH 200
#define BULLET_TEST1_HEIGHT 40
#define BULLET_TEST1_SPEED 150
#define BULLET_TEST1_SLOW 0
#define BULLET_TEST1_TOXIC 0
#define BULLET_TEST1_COLLISIONTIMES 1

//子弹1数据
#define BULLET1_WIDTH 35
#define BULLET1_HEIGHT 35
#define BULLET1_SPEED 400
#define BULLET1_SLOW 15
#define BULLET1_TOXIC 0
#define BULLET1_COLLISIONTIMES 1

//子弹2数据
#define BULLET2_WIDTH 60
#define BULLET2_HEIGHT 60
#define BULLET2_SPEED 500
#define BULLET2_SLOW 0
#define BULLET2_TOXIC 0
#define BULLET2_COLLISIONTIMES 1

//子弹3数据
#define BULLET3_WIDTH 10
#define BULLET3_HEIGHT 10
#define BULLET3_SPEED 2000
#define BULLET3_SLOW 0
#define BULLET3_TOXIC 0
#define BULLET3_COLLISIONTIMES 1

//子弹4数据
#define BULLET4_WIDTH 180
#define BULLET4_HEIGHT 15
#define BULLET4_SPEED 5000
#define BULLET4_SLOW 0
#define BULLET4_TOXIC 0
#define BULLET4_COLLISIONTIMES 10

//子弹5数据
#define BULLET5_WIDTH 70
#define BULLET5_HEIGHT 20
#define BULLET5_SPEED 500
#define BULLET5_SLOW 0
#define BULLET5_TOXIC 80
#define BULLET5_COLLISIONTIMES 1
//——————————————————————————————————————————————————————————————
//敌人类数据*****
#define ENEMY_TYPE 15//敌人的种类数

//测试用敌人数据(普通类：基础普通怪)
#define ENEMY_TEST_WIDTH 50//宽度
#define ENEMY_TEST_HEIGET 50//高度
#define ENEMY_TEST_SPEED 80//速度
#define ENEMY_TEST_LIFE 70//生命
#define ENEMY_TEST_EARN 5//奖励
#define ENEMY_TEST_ADDMP 0//魔力奖励
#define ENEMY_TEST_DEFENCE 0//防御力
#define ENEMY_TEST_LIFELOSE 5//生命损失
#define ENEMY_TEST_ICEDEFENCE 10//对冻伤的抵抗力，越大代表冻伤时间越长(s)
#define ENEMY_TEST_TOXICDEFENCE 5//对中毒的抵抗力，越大代表中毒时间越长(s)

//测试用敌人1数据(特殊类：希望怪)
#define ENEMY_TEST1_WIDTH 160//宽度
#define ENEMY_TEST1_HEIGET 140//高度
#define ENEMY_TEST1_SPEED 60//速度
#define ENEMY_TEST1_LIFE 500//生命
#define ENEMY_TEST1_EARN 20//奖励
#define ENEMY_TEST1_ADDMP 1//魔力奖励
#define ENEMY_TEST1_DEFENCE 0//防御力
#define ENEMY_TEST1_LIFELOSE 20//生命损失
#define ENEMY_TEST1_ICEDEFENCE 5//对冻伤的抵抗力，越大代表冻伤时间越长
#define ENEMY_TEST1_TOXICDEFENCE 15//对中毒的抵抗力，越大代表中毒时间越长(s)

//敌人1数据(病毒类：体液传播)
#define ENEMY1_WIDTH 120//宽度
#define ENEMY1_HEIGET 130//高度
#define ENEMY1_SPEED 100//速度
#define ENEMY1_LIFE 150//生命
#define ENEMY1_EARN 10//奖励
#define ENEMY1_ADDMP 0//魔力奖励
#define ENEMY1_DEFENCE 0//防御力
#define ENEMY1_LIFELOSE 5//生命损失
#define ENEMY1_ICEDEFENCE 20//对冻伤的抵抗力，越大代表冻伤时间越长
#define ENEMY1_TOXICDEFENCE 0//对中毒的抵抗力，越大代表中毒时间越长(s)

//敌人2数据(普通类：护盾普通怪)
#define ENEMY2_WIDTH 70//宽度
#define ENEMY2_HEIGET 70//高度
#define ENEMY2_SPEED 60//速度
#define ENEMY2_LIFE 100//生命
#define ENEMY2_EARN 15//奖励
#define ENEMY2_ADDMP 0//魔力奖励
#define ENEMY2_DEFENCE 10//防御力
#define ENEMY2_LIFELOSE 10//生命损失
#define ENEMY2_ICEDEFENCE 10//对冻伤的抵抗力，越大代表冻伤时间越长
#define ENEMY2_TOXICDEFENCE 5//对中毒的抵抗力，越大代表中毒时间越长(s)

//敌人3数据(BOSS类：大石头)
#define ENEMY3_WIDTH 300//宽度
#define ENEMY3_HEIGET 300//高度
#define ENEMY3_SPEED 40//速度
#define ENEMY3_LIFE 350//生命
#define ENEMY3_EARN 50//奖励
#define ENEMY3_ADDMP 5//魔力奖励
#define ENEMY3_DEFENCE 150//防御力
#define ENEMY3_LIFELOSE 40//生命损失
#define ENEMY3_ICEDEFENCE 5//对冻伤的抵抗力，越大代表冻伤时间越长
#define ENEMY3_TOXICDEFENCE 8//对中毒的抵抗力，越大代表中毒时间越长(s)

//敌人4数据(普通类：高温普通怪)
#define ENEMY4_WIDTH 50//宽度
#define ENEMY4_HEIGET 50//高度
#define ENEMY4_SPEED 90//速度
#define ENEMY4_LIFE 150//生命
#define ENEMY4_EARN 10//奖励
#define ENEMY4_ADDMP 1//魔力奖励
#define ENEMY4_DEFENCE 5//防御力
#define ENEMY4_LIFELOSE 15//生命损失
#define ENEMY4_ICEDEFENCE 0//对冻伤的抵抗力，越大代表冻伤时间越长
#define ENEMY4_TOXICDEFENCE 4//对中毒的抵抗力，越大代表中毒时间越长(s)

//敌人5数据(病毒类：空气传播)
#define ENEMY5_WIDTH 120//宽度
#define ENEMY5_HEIGET 130//高度
#define ENEMY5_SPEED 120//速度
#define ENEMY5_LIFE 200//生命
#define ENEMY5_EARN 20//奖励
#define ENEMY5_ADDMP 0//魔力奖励
#define ENEMY5_DEFENCE 5//防御力
#define ENEMY5_LIFELOSE 15//生命损失
#define ENEMY5_ICEDEFENCE 25//对冻伤的抵抗力，越大代表冻伤时间越长
#define ENEMY5_TOXICDEFENCE 0//对中毒的抵抗力，越大代表中毒时间越长(s)

//敌人6数据(普通类：剧毒普通怪)
#define ENEMY6_WIDTH 50//宽度
#define ENEMY6_HEIGET 50//高度
#define ENEMY6_SPEED 60//速度
#define ENEMY6_LIFE 200//生命
#define ENEMY6_EARN 15//奖励
#define ENEMY6_ADDMP 1//魔力奖励
#define ENEMY6_DEFENCE 2//防御力
#define ENEMY6_LIFELOSE 50//生命损失
#define ENEMY6_ICEDEFENCE 4//对冻伤的抵抗力，越大代表冻伤时间越长
#define ENEMY6_TOXICDEFENCE 0//对中毒的抵抗力，越大代表中毒时间越长(s)

//敌人7数据(Boss类：活尸)
#define ENEMY7_WIDTH 450//宽度
#define ENEMY7_HEIGET 350//高度
#define ENEMY7_SPEED 40//速度
#define ENEMY7_LIFE 10000//生命
#define ENEMY7_EARN 800//奖励
#define ENEMY7_ADDMP 15//魔力奖励
#define ENEMY7_DEFENCE 8//防御力
#define ENEMY7_LIFELOSE 80//生命损失
#define ENEMY7_ICEDEFENCE 5//对冻伤的抵抗力，越大代表冻伤时间越长
#define ENEMY7_TOXICDEFENCE 5//对中毒的抵抗力，越大代表中毒时间越长(s)

//敌人8数据(障碍类：水晶)
#define ENEMY8_WIDTH 150//宽度
#define ENEMY8_HEIGET 150//高度
#define ENEMY8_SPEED 45//速度
#define ENEMY8_LIFE 100//生命
#define ENEMY8_EARN 5//奖励
#define ENEMY8_ADDMP 1//魔力奖励
#define ENEMY8_DEFENCE 25//防御力
#define ENEMY8_LIFELOSE 0//生命损失
#define ENEMY8_ICEDEFENCE 0//对冻伤的抵抗力，越大代表冻伤时间越长
#define ENEMY8_TOXICDEFENCE 0//对中毒的抵抗力，越大代表中毒时间越长(s)

//敌人9数据(病毒类：随便传播)
#define ENEMY9_WIDTH 120//宽度
#define ENEMY9_HEIGET 130//高度
#define ENEMY9_SPEED 150//速度
#define ENEMY9_LIFE 200//生命
#define ENEMY9_EARN 30//奖励
#define ENEMY9_ADDMP 0//魔力奖励
#define ENEMY9_DEFENCE 8//防御力
#define ENEMY9_LIFELOSE 25//生命损失
#define ENEMY9_ICEDEFENCE 30//对冻伤的抵抗力，越大代表冻伤时间越长
#define ENEMY9_TOXICDEFENCE 0//对中毒的抵抗力，越大代表中毒时间越长(s)

//敌人10数据(特殊类：谎言怪)
#define ENEMY10_WIDTH 180//宽度
#define ENEMY10_HEIGET 110//高度
#define ENEMY10_SPEED 75//速度
#define ENEMY10_LIFE 300//生命
#define ENEMY10_EARN 20//奖励
#define ENEMY10_ADDMP 1//魔力奖励
#define ENEMY10_DEFENCE 2//防御力
#define ENEMY10_LIFELOSE 20//生命损失
#define ENEMY10_ICEDEFENCE 15//对冻伤的抵抗力，越大代表冻伤时间越长
#define ENEMY10_TOXICDEFENCE 5//对中毒的抵抗力，越大代表中毒时间越长(s)

//敌人11数据(Boss类：大飞碟)
#define ENEMY11_WIDTH 450//宽度
#define ENEMY11_HEIGET 180//高度
#define ENEMY11_SPEED 100//速度
#define ENEMY11_LIFE 1000//生命
#define ENEMY11_EARN 250//奖励
#define ENEMY11_ADDMP 10//魔力奖励
#define ENEMY11_DEFENCE 30//防御力
#define ENEMY11_LIFELOSE 60//生命损失
#define ENEMY11_ICEDEFENCE 2//对冻伤的抵抗力，越大代表冻伤时间越长
#define ENEMY11_TOXICDEFENCE 1//对中毒的抵抗力，越大代表中毒时间越长(s)

//敌人12数据(机械类：小飞碟)
#define ENEMY12_WIDTH 90//宽度
#define ENEMY12_HEIGET 40//高度
#define ENEMY12_SPEED 220//速度
#define ENEMY12_LIFE 120//生命
#define ENEMY12_EARN 15//奖励
#define ENEMY12_ADDMP 0//魔力奖励
#define ENEMY12_DEFENCE 0//防御力
#define ENEMY12_LIFELOSE 10//生命损失
#define ENEMY12_ICEDEFENCE 3//对冻伤的抵抗力，越大代表冻伤时间越长
#define ENEMY12_TOXICDEFENCE 1//对中毒的抵抗力，越大代表中毒时间越长(s)

//敌人13数据(Boss类：Smile)
#define ENEMY13_WIDTH 400//宽度
#define ENEMY13_HEIGET 400//高度
#define ENEMY13_SPEED 25//速度
#define ENEMY13_LIFE 100000//生命
#define ENEMY13_EARN 10000//奖励
#define ENEMY13_ADDMP 1000//魔力奖励
#define ENEMY13_DEFENCE 0//防御力
#define ENEMY13_LIFELOSE 999999//生命损失
#define ENEMY13_ICEDEFENCE 0//对冻伤的抵抗力，越大代表冻伤时间越长
#define ENEMY13_TOXICDEFENCE 5//对中毒的抵抗力，越大代表中毒时间越长(s)

//——————————————————————————————————————————————————————————————
//时间/频率类数据*****
#define FPS 60//游戏的帧速是60帧/s，控制游戏速度
#define ROUND_TIME 80//一轮游戏的时间(s)
#define ENEMY_FREQUENCY 6//初始出怪速度
#define TOWER_UPDATENUMBER 7//一次更新的塔的数量

//——————————————————————————————————————————————————————————————
//其它类型数据*****
//炮塔选中标识
#define SIGN_WIDTH 45
#define SIGN_HEIGHT 50

//炮塔说明框
#define INTRODUCTION_WIDTH 300
#define INTRODUCTION_HEIGHT 180

#endif // CONFIG_H
