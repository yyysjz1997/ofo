#ifndef _BIKE_H_
#define _BIKE_H_

#include "svgamode.h"
#include "draw.h"
#include <stdio.h>

/**********************************************************
Function：   bicycle

Description：  在SVGA模式下,以Linex函数为基础，画出ofo小黄车函数

Input：     x   车把手与车架交点的横坐标
            y   车把手与车架交点的纵坐标

Output：   将画好的ofo小黄车输出到屏幕上

Return：   空

Others：   无
**********************************************************/

void bicycle(int x,int y); //小黄车的图片模型，40000表示为橘黄色，50000为粉红色

#endif