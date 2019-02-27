#ifndef _MOUSE_H2_
#define _MOUSE_H2_

#include "svgamode.h"
#include "draw.h"
#include <dos.h>
#include "time.h"

/**********************************************************
Function：   Cursor

Description：  画箭头型鼠标函数

Input：      x  顶点横坐标
             y  顶点纵坐标
             color   鼠标的颜色

Output：   显示鼠标

Return：   空

Others：   无
**********************************************************/

void Cursor(int x,int y,int color);   //画箭头型鼠标函数

/**********************************************************
Function：   Cursor2

Description：  画手型鼠标函数

Input：      x  顶点横坐标
             y  顶点纵坐标
             color   鼠标的颜色

Output：   显示手型鼠标

Return：   空

Others：   无
**********************************************************/

void Cursor2(int x,int y,int color);   // 画手型型鼠标函数

/**********************************************************
Function：   Cursor3

Description：  画 “I” 型鼠标函数

Input：      x  顶点横坐标
             y  顶点纵坐标
             color   鼠标的颜色

Output：   显示 “I” 型鼠标

Return：   空

Others：   无
**********************************************************/

void Cursor3(int x,int y,int color);   //“I”型鼠标函数

/**********************************************************
Function：   Initmouse

Description：  初始化鼠标函数

Input：      xmi  开辟的窗口的左上角点的横坐标
             xma  开辟的窗口的右下角点的横坐标
             ymi  开辟的窗口的左上角点的纵坐标
             yma  开辟的窗口的右下角点的纵坐标

Output：   进行初始化鼠标操作

Return：   retcode 成功初始化鼠标

Others：   无
**********************************************************/

int Initmouse(int xmi,int xma,int ymi,int yma);   //初始化鼠标函数

/**********************************************************
Function：   Readmouse

Description：  读取鼠标位置函数

Input：     无

Output：   记录每一次鼠标运动前的位置

Return：   无

Others：   无
**********************************************************/

int Readmouse(void);    //读取鼠标位置函数

/**********************************************************
Function：   Newxy

Description：  绘出新鼠标的函数

Input：     无

Output：   在鼠标移动的方向隔20ms重新画一个鼠标

Return：   无

Others：   引用了Readmouse函数、Mouse_putbk函数、Mouse_savebk函数、Cursor（Cursor2）（Cursor3）函数等等
**********************************************************/

void Newxy(void);   //绘出新鼠标的函数

/**********************************************************
Function：   Newxy2

Description：  绘出新鼠标的函数

Input：     无

Output：   在鼠标移动的方向隔20ms重新画一个鼠标

Return：   无

Others：   引用了Readmouse函数、Mouse_putbk函数、Mouse_savebk函数、Cursor2函数等等
**********************************************************/

void Newxy2(void);               //绘出新鼠标(手型鼠标)的函数

/**********************************************************
Function：   Newxy3

Description：  绘出新鼠标的函数

Input：     无

Output：   在鼠标移动的方向隔20ms重新画一个鼠标

Return：   无

Others：   引用了Readmouse函数、Mouse_putbk函数、Mouse_savebk函数、Cursor3函数等等
**********************************************************/

void Newxy3(void);               //绘出新鼠标(“I”型鼠标)的函数

/**********************************************************
Function：   Mouse_savebk

Description：  存储前一位置鼠标背景颜色的函数

Input：     x   鼠标顶点的横坐标
            y   鼠标顶点的纵坐标

Output：   把鼠标的前一位置背景的颜色信息存储到了二维数组mouse_sq[][]中

Return：   无

Others：   引用了SVGAmode.c文件中的Getpixel64k函数来读取每一个像素点的背景颜色
**********************************************************/

void Mouse_savebk(int x,int y);    //存储前一位置鼠标背景颜色的函数

/**********************************************************
Function：   Mouse_putbk

Description：  覆盖前一位置鼠标背景颜色的函数

Input：     x   鼠标顶点的横坐标
            y   鼠标顶点的纵坐标

Output：   把鼠标的前一位置背景的颜色信息也就是二维数组mouse_sq[][]中信息释放出来

Return：   无

Others：   引用了SVGAmode.c文件中的Putpixel64k函数来释放每一个像素点的背景颜色
**********************************************************/

void Mouse_putbk(int x,int y);   //覆盖前一位置鼠标背景颜色的函数


/**********************************************************
Function：   Mouse_press

Description：  判断鼠标是否在所规定区域内按键的函数

Input：     x1   需要判断的矩形区域内左上角的点的横坐标
            y1   需要判断的矩形区域内左上角的点的纵坐标
            x2   需要判断的矩形区域内右下角的点的横坐标
            y2   需要判断的矩形区域内右下角的点的纵坐标

Output：   鼠标是否满足if的条件

Return：   1代表 是，2代表 否

Others：   无
**********************************************************/

int Mouse_press(int x1,int y1,int x2,int y2);   //判断鼠标是否在所规定区域内按键的函数

/**********************************************************
Function：   Mouse_above

Description：  判断鼠标是否在所规定区域上的函数

Input：     x1   需要判断的矩形区域内左上角的点的横坐标
            y1   需要判断的矩形区域内左上角的点的纵坐标
            x2   需要判断的矩形区域内右下角的点的横坐标
            y2   需要判断的矩形区域内右下角的点的纵坐标

Output：   鼠标是否满足if的条件

Return：   1代表 是，2代表 否

Others：   无
**********************************************************/

int Mouse_above(int x1,int y1,int x2,int y2);   //判断鼠标是否在所规定区域上的函数

void Newxy6(void);



#endif