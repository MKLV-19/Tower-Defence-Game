#include "tool.h"
#include <cmath>
#include"config.h"

Tool::Tool(){}
float Tool::VectorToAngle(Point p)//向量换角度，长度会丢失
{
    /*注意：asin函数只能输出±π/2之间的角度
           acos函数只能输出0到π之间的角度
           asin,acos,atan返回值都是弧度制，需要自行转换角度制*/
    float lenth=sqrt(p.getX()*p.getX()+p.getY()*p.getY());
    float _sin=p.getY()/lenth;
    float _cos=p.getX()/lenth;//求出向量对应的正余弦值
    float angs=asin(_sin);//用正弦值算出的角度
    float angc=acos(_cos);//用余弦值算出的角度
    float angle;
    if(_sin>=0&&_cos>=0){angle=angs;}//第一象限
    if(_sin>=0&&_cos<0){angle=angc;}//第二象限
    if(_sin<0&&_cos<0){angle=2*PI-angc;}//第三象限
    if(_sin<0&&_cos>=0){angle=angs+2*PI;}//第四象限
    return angle*180/PI;//返回一个角度值
}
Point Tool::AngleToVector(float angle)//角度换向量,转换出来的是单位方向向量
{
    float a=angle/180*PI;
    return Point(cos(a),sin(a));
}
int Tool::sign(float x)//大于0返回1，否则返回-1
{
    return (x>0?1:-1);
}
float Tool::abs(float d)//返回绝对值
{
    return (d>0?d:-d);
}
float Tool::distance(Point a, Point b)//返回两点间距离
{
    return sqrt((a.getX()-b.getX())*(a.getX()-b.getX())
                +(a.getY()-b.getY())*(a.getY()-b.getY()));
}
//提示：sin和cos的参数是弧度
//完成
