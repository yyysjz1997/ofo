#include"mouse2.h"

union REGS regs;   //定义REGS结构体
int mx=0,my=0,buttons=0;
int mouse_sq[20][24]={0};    //存储鼠标后背景的二维数组
int default1=0;

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

void Cursor(int x,int y,int color)  //箭头鼠标函数
{
     Liney(x,y,x,y,color);
	   Liney(x+1,y,x+1,y+2,color);
	   Liney(x+2,y+1,x+2,y+4,color);
	   Liney(x+3,y+1,x+3,y+6,color);
	   Liney(x+4,y+2,x+4,y+8,color);
	   Liney(x+5,y+2,x+5,y+10,color);
	   Liney(x+6,y+3,x+6,y+12,color);
	   Liney(x+7,y+3,x+7,y+14,color);
	   Liney(x+8,y+4,x+8,y+16,color);
	   Liney(x+9,y+4,x+9,y+8,color);
	   Liney(x+10,y+5,x+10,y+8,color);
	   Liney(x+11,y+5,x+11,y+8,color);
	   Liney(x+12,y+6,x+12,y+8,color);
	   Liney(x+13,y+6,x+13,y+8,color);
	   Liney(x+14,y+7,x+14,y+8,color);
	   Liney(x+15,y+7,x+15,y+8,color);
	   Liney(x+16,y+8,x+16,y+8,color);
}

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

void Cursor2(int x,int y,int color)   //手型鼠标函数
{
  Liney(x,y+13,x,y+14,color);
  Liney(x+1,y+12,x+1,y+15,color);
  Liney(x+2,y+12,x+2,y+16,color);
  Liney(x+3,y+13,x+3,y+18,color);
  Liney(x+4,y+13,x+4,y+19,color);
  Liney(x+5,y+1,x+5,y+20,color);
  Liney(x+6,y,x+6,y+21,color);
  Liney(x+7,y,x+7,y+22,color);
  Liney(x+8,y+1,x+8,y+22,color);
  Liney(x+9,y+5,x+9,y+23,color);
  Liney(x+10,y+5,x+10,y+23,color);
  Liney(x+11,y+6,x+11,y+23,color);
  Liney(x+12,y+6,x+12,y+23,color);
  Liney(x+13,y+6,x+13,y+22,color);
  Liney(x+14,y+7,x+14,y+22,color);
  Liney(x+15,y+7,x+15,y+21,color);
  Liney(x+16,y+7,x+16,y+21,color);
  Liney(x+17,y+8,x+17,y+19,color);
}

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

void Cursor3(int x,int y,int color)   //“I”型鼠标函数
{
   Linex(x+1,y+1,x+4,y+1,color-color);
   Linex(x+5,y+1,x+8,y+1,color-color);
   Liney(x+4,y+1,x+4,y+18,color-color);
   Linex(x+1,y+18,x+4,y+18,color-color);
   Linex(x+5,y+18,x+8,y+18,color-color);
}

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

int Initmouse(int xmi,int xma,int ymi,int yma)  //初始化鼠标函数
{
  int retcode;
  regs.x.ax=0;
  int86(51,&regs,&regs);
  retcode=regs.x.ax;
  if(retcode==0)
  {
	   return 0;
  }
  regs.x.ax=7;
  regs.x.cx=xmi;
  regs.x.dx=xma;
  int86(51,&regs,&regs);
  regs.x.ax=8;
  regs.x.cx=ymi;
  regs.x.dx=yma;
  int86(51,&regs,&regs);

  regs.x.ax=4;              //自己新加的
  regs.x.cx=0;
  regs.x.dx=0;
  int86(51,&regs,&regs);
  default1=0;

  return retcode;
}

/**********************************************************
Function：   Readmouse

Description：  读取鼠标位置函数

Input：     无

Output：   记录每一次鼠标运动前的位置

Return：   无

Others：   无
**********************************************************/

int Readmouse()          //读取鼠标位置函数
{
  int xnew,ynew;
	regs.x.ax=3;
	int86(51,&regs,&regs);
	xnew=regs.x.cx;
	ynew=regs.x.dx;
	buttons=regs.x.bx;
	delay(20);
  mx=xnew;
  my=ynew;
  return (0);
}

/**********************************************************
Function：   Newxy

Description：  绘出新鼠标的函数

Input：     无

Output：   在鼠标移动的方向隔20ms重新画一个鼠标

Return：   无

Others：   引用了Readmouse函数、Mouse_putbk函数、Mouse_savebk函数、Cursor函数等等
**********************************************************/

void Newxy()             //绘出新鼠标(箭头型鼠标)的函数
{
  int xx0=mx,yy0=my,x,y;
  Readmouse();
  if(xx0!=mx||yy0!=my)
  {
    if(default1)
      Mouse_putbk(xx0,yy0);
    Mouse_savebk(mx,my);
    Cursor(mx,my,63103);   //63103为颜色（灰白色）
    default1=1;
  }
  //delay(20);
}

/**********************************************************
Function：   Newxy2

Description：  绘出新鼠标的函数

Input：     无

Output：   在鼠标移动的方向隔20ms重新画一个鼠标

Return：   无

Others：   引用了Readmouse函数、Mouse_putbk函数、Mouse_savebk函数、Cursor2函数等等
**********************************************************/

void Newxy2()               //绘出新鼠标(手型鼠标)的函数
{
  int xx0=mx,yy0=my,x,y;
  Readmouse();
  if(xx0!=mx||yy0!=my)
  {
    if(default1)
        Mouse_putbk(xx0,yy0);
    Mouse_savebk(mx,my);
    Cursor2(mx,my,63103);   //63103为颜色（灰白色）
    default1=1;
  }
  //delay(20);
}

/**********************************************************
Function：   Newxy3

Description：  绘出新鼠标的函数

Input：     无

Output：   在鼠标移动的方向隔20ms重新画一个鼠标

Return：   无

Others：   引用了Readmouse函数、Mouse_putbk函数、Mouse_savebk函数、Cursor3函数等等
**********************************************************/

void Newxy3()               //绘出新鼠标(“I”型鼠标)的函数
{
  int xx0=mx,yy0=my,x,y;
  Readmouse();
  if(xx0!=mx||yy0!=my)
  {
    if(default1)
      Mouse_putbk(xx0,yy0);
    Mouse_savebk(mx,my);
    Cursor3(mx,my,63103);   //63103为颜色（灰白色）
    default1=1;
  }
  //delay(20);
}

/**********************************************************
Function：   Mouse_savebk

Description：  存储前一位置鼠标背景颜色的函数

Input：     x   鼠标顶点的横坐标
            y   鼠标顶点的纵坐标

Output：   把鼠标的前一位置背景的颜色信息存储到了二维数组mouse_sq[][]中

Return：   无

Others：   引用了SVGAmode.c文件中的Getpixel64k函数来读取每一个像素点的背景颜色
**********************************************************/

void Mouse_savebk(int x, int y)   //存储前一位置鼠标背景颜色
{
  int i,j;
  for(i=0;i<=17;i++)
  for(j=0;j<=23;j++)
  mouse_sq[i][j]=Getpixel64k(x+i,y+j);
}

/**********************************************************
Function：   Mouse_putbk

Description：  覆盖前一位置鼠标背景颜色的函数

Input：     x   鼠标顶点的横坐标
            y   鼠标顶点的纵坐标

Output：   把鼠标的前一位置背景的颜色信息也就是二维数组mouse_sq[][]中信息释放出来

Return：   无

Others：   引用了SVGAmode.c文件中的Putpixel64k函数来释放每一个像素点的背景颜色
**********************************************************/

void Mouse_putbk(int x,int y)    //覆盖前一位置鼠标的背景颜色的函数
{
  int i,j;
  for(i=0;i<=17;i++)
  for(j=0;j<=23;j++)
  Putpixel64k(x+i,y+j,mouse_sq[i][j]);
}

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

int Mouse_press(int x1,int y1,int x2,int y2)     //判断鼠标是否在规定区域按键的函数
{
  if(mx>=x1&&mx<=x2&&my>=y1&&my<=y2&&buttons)   //按键区域范围

  return(1);
  else
  return(0);
}

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

int Mouse_above(int x1,int y1,int x2,int y2)   //判断鼠标是否在规定区域上的函数
{
  if(mx>=x1&&mx<=x2&&my>=y1&&my<=y2)   //所在区域范围
  return(1);
  else
  return(0);
}

void Newxy6()
{
  int xx0=mx,yy0=my,x,y;
  Readmouse();
  if(xx0!=mx||yy0!=my)
  {
    if(default1)
      Mouse_putbk(xx0,yy0);
    Mouse_savebk(mx,my);
    default1=1;
  }
  //delay(20);
}

