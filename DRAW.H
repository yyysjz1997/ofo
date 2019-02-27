#ifndef _DRAW_H_
#define _DRAW_H_

#include "svgamode.h"

#define LENGTH 1024    //SVGA中的图长
#define WIDTH  768     //SVGA中的图宽

/**********************************************************
Function：   Linex

Description：  在SVGA模式下画出水平线的函数

Input：     x1   起始点的横坐标
            y1   起始点的纵坐标
            x2   终止点的横坐标
            y2   终止点的纵坐标
            color   线的颜色值

Output：   将画好的线输出到屏幕上

Return：   空

Others：   无
**********************************************************/

int Linex(int x1,int y1,int x2,int y2,int color);     //画水平线的函数

/**********************************************************
Function：   Liney

Description：  在SVGA模式下画出竖直线的函数

Input：     x1   起始点的横坐标
            y1   起始点的纵坐标
            x2   终止点的横坐标
            y2   终止点的纵坐标
            color   线的颜色值

Output：   将画好的线输出到屏幕上

Return：   空

Others：   无
**********************************************************/

int Liney(int x1,int y1,int x2,int y2,int color);     //画竖直线的函数

/**********************************************************
Function：   Bar64k

Description：  在SVGA模式下,以Liney函数为基础，画实心的矩形的函数

Input：     x1   矩形左上角点的横坐标
            y1   矩形左上角点的纵坐标
            x2   矩形右下角点的横坐标
            y2   矩形右下角点的纵坐标
            color   矩形的颜色值

Output：   将画好的矩形输出到屏幕上

Return：   空

Others：   无
**********************************************************/

int Bar64k(int x1,int y1,int x2,int y2,int color);    //以Liney函数为基础，画实心的矩形的函数

/**********************************************************
Function：   Tri_L

Description：  在SVGA模式下,以Liney函数为基础，画左三角形的函数

Input：     x   三角形顶点的横坐标
            y   三角形顶点的纵坐标
            color   矩形的颜色值

Output：   将画好的左三角形输出到屏幕上

Return：   空

Others：   无
**********************************************************/

void Tri_L(int x,int y,int color);      //以Liney函数为基础，画左三角形的函数

/**********************************************************
Function：   Tri_R

Description：  在SVGA模式下,以Liney函数为基础，画右三角形的函数

Input：     x   三角形顶点的横坐标
            y   三角形顶点的纵坐标
            color   矩形的颜色值

Output：   将画好的右三角形输出到屏幕上

Return：   空

Others：   无
**********************************************************/

void Tri_R(int x,int y,int color);      //以Liney函数为基础，画右三角形的函数

/**********************************************************
Function：   circley

Description：  在SVGA模式下,以Liney函数为基础，画圆的函数

Input：     x   圆心的横坐标
            y   圆心的纵坐标
            r   圆的半径
            color   圆环的颜色值

Output：   将画好的圆输出到屏幕上

Return：   空

Others：   无
**********************************************************/

void circley(int x,int y,int r,int color);     //以前Liney函数为基础，画圆的函数

/**********************************************************
Function：   circle_fill

Description：  在SVGA模式下,以Liney以及circley函数为基础，画实心圆的函数

Input：     x   圆心的横坐标
            y   圆心的纵坐标
            r   圆的半径
            color   圆环的颜色值

Output：   将画好的实心圆输出到屏幕上

Return：   空

Others：   无
**********************************************************/

void circle_fill(int x,int y,int r,int color);   //以前Liney函数以及circley函数为基础，画实心圆的函数

/**********************************************************
Function：   Bar_em

Description：  在SVGA模式下,以Liney以及Linex函数为基础，画空心矩形的函数

Input：     x  矩形左上角的横坐标
            y  矩形左上角的纵坐标
            x1  矩形右下角的横坐标
            y1  矩形右下角的纵坐标
            color  矩形的颜色值

Output：   将画好的空心矩形输出到屏幕上，自己定义颜色

Return：   0

Others：   常用
**********************************************************/

int Bar_em(int x,int y,int x1,int y1,int color);

#endif