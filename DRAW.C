#include "draw.h"

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

int Linex(int x1,int y1,int x2, int y2,int color)   //画水平线的函数
{
  int i;
  if(x1>=1024||x2>=1024||y1>=768||y2>=768)
  return(0);

  if(x1<=0||x2<=0||y1<=0||y2<=0)
  return(0);

  if(y1!=y2||x1>x2)
  return(0);
  for(i=x1;i<=x2;i++)
  Putpixel64k(i,y1,color);
  return 0;
}

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

int Liney(int x1,int y1,int x2, int y2,int color)    //画竖直线的函数
{
  int i;
  if(x1>=1024||x2>=1024||y1>=768||y2>=768)
  return(0);

  if(x1<=0||x2<=0||y1<=0||y2<=0)
  return(0);

  if(x1!=x2||y1>y2)
  return(0);
  for(i=y1;i<=y2;i++)
  Putpixel64k(x1,i,color);
  return 0;
}

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

int Bar64k(int x1,int y1,int x2,int y2,int color)   //以前Liney函数为基础，画实心的矩形的函数
{
  int i;
  if(x1>=1024||x2>=1024||y1>=768||y2>=768)
  return(0);

  if(x1<=0||x2<=0||y1<=0||y2<=0)
  return(0);

  if(x1>=x2||y1>=y2)
  return(0);

  for(i=x1;i<=x2;i++)
  {
	Liney(i,y1,i,y2,color);
  }
  return 0;
}

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

void Tri_L(int x,int y,int color)      //以Liney函数为基础，画左三角形的函数
{
  int i;
  for(i=0;i<=39;i++)
  {
	Liney(x-i,y+(i+1)/2,x-i,y+40-(i+1)/2,color);
  }

}

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

void Tri_R(int x,int y,int color)     //以前Liney函数为基础，画右三角形的函数
{
  int i;
  for(i=0;i<=39;i++)
  {
	Liney(x+i,y+(i+1)/2,x+i,y+40-(i+1)/2,color);
  }
}

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

void circley(int x,int y,int r,int color)  //以前Liney函数为基础，画圆的函数
{
    int x0=0,y0=r;
    int d=1-r;

    while(y0>x0)
    {
        Liney(x0+x,y0+y,x0+x,y0+y,color);
        Liney(y0+x,x0+y,y0+x,x0+y,color);
        Liney(-x0+x,y0+y,-x0+x,y0+y,color);
        Liney(-y0+x,x0+y,-y0+x,x0+y,color);
        Liney(-x0+x,-y0+y,-x0+x,-y0+y,color);
        Liney(-y0+x,-x0+y,-y0+x,-x0+y,color);
        Liney(x0+x,-y0+y,x0+x,-y0+y,color);
        Liney(y0+x,-x0+y,y0+x,-x0+y,color);
        if(d<0)
            d=d+2*x0+3;
        else
        {
            d=d+2*(x0-y0)+5;
            y0--;
        }
        x0++;
    }
}

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

void circle_fill(int x,int y,int r,int color)   //以前Liney函数以及circley函数为基础，画实心圆的函数
{
   int i;
   for(i=1;i<=r;i++)
   {
      circley(x,y,i,color);
   }
}

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

int Bar_em(int x,int y,int x1,int y1,int color)
{
    Linex(x,y,x1,y,color);
    Liney(x,y,x,y1,color);
    Linex(x,y1,x1,y1,color);
    Liney(x1,y,x1,y1,color);
    return 0;
}