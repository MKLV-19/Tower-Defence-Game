#ifndef TOOL_H
#define TOOL_H

#include "point.h"

/*
说明：
工具类
用于提供向量，角度，符号等各种计算方法
因为QT的坐标原点在左上角，x，y轴正向分别是向右，向下的
所以旋转角的起点为水平向右的直线，旋转方向为顺时针
*/

class Tool
{
public:
    Tool();

    //类外定义
    static float VectorToAngle(Point p);//向量化角
    static Point AngleToVector(float angle);//角化向量
    static int sign(float x);//取符号/方向
    static float abs(float d);//绝对值
    static float distance(Point a,Point b);//求距离
};

#endif // TOOL_H
