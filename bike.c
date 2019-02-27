#include "bike.h"

/**********************************************************
Function：   bicycle

Description：  在SVGA模式下,以Linex函数为基础，画出ofo小黄车函数

Input：     x   车把手与车架交点的横坐标
            y   车把手与车架交点的纵坐标

Output：   将画好的ofo小黄车输出到屏幕上

Return：   空

Others：   无
**********************************************************/

void bicycle(int x,int y)    //小黄车的图片模型，40000表示为橘黄色,50000为粉红色
{
    int i,j,k,m,n;

    Linex(x,y,x+15,y,40000);    //车子的三脚架，车梯
    Linex(x+10,y+9,x+25,y+9,40000);
    for(i=0;i<=9;i++)
    {
        Linex(x+i,y+i,x+i,y+i,40000);
        Linex(x+i+1,y+i,x+i+1,y+i,40000);
    }
    for(j=0;j<=9;j++)
    {
        Linex(x+j+15,y+j,x+j+15,y+j,40000);
        Linex(x+j+16,y+j,x+j+16,y+j,40000);
    }
    for(k=19;k>=6;k--)
    {
        Linex(x+k,y-k+15,x+k,y-k+15,40000);
        Linex(x+k+1,y-k+15,x+k+1,y-k+15,40000);
    }

    Linex(x+17,y-4,x+18,y-4,40000);     //车子的车座

    // Linex(x+7,y+13,x+9,y+13,40000);     //车子的脚蹬

    for(m=0;m<=5;m++)       //车把手和前部支架
    {
        Linex(x-m,y+2*m,x-m,y+2*m,40000);
    }
    for(n=0;n<=4;n++)
    {
        Linex(x+n,y-2*n,x+n,y-2*n,40000);
        Linex(x+3,y-8,x+6,y-8,40000);
    }

    circley(x-5,y+10,9,50000);   //左车轮

    circley(x+25,y+10,9,50000);   //右车轮
}

void bicycle2(int x,int y,int color)    //小黄车的图片模型，40000表示为橘黄色,50000为粉红色
{
    int i,j,k,m,n;

    Linex(x,y,x+15,y,color);    //车子的三脚架，车梯
    Linex(x+10,y+9,x+25,y+9,color);
    for(i=0;i<=9;i++)
    {
        Linex(x+i,y+i,x+i,y+i,color);
        Linex(x+i+1,y+i,x+i+1,y+i,color);
    }
    for(j=0;j<=9;j++)
    {
        Linex(x+j+15,y+j,x+j+15,y+j,color);
        Linex(x+j+16,y+j,x+j+16,y+j,color);
    }
    for(k=19;k>=6;k--)
    {
        Linex(x+k,y-k+15,x+k,y-k+15,color);
        Linex(x+k+1,y-k+15,x+k+1,y-k+15,color);
    }

    Linex(x+17,y-4,x+18,y-4,color);     //车子的车座

    // Linex(x+7,y+13,x+9,y+13,color);     //车子的脚蹬

    for(m=0;m<=5;m++)       //车把手和前部支架
    {
        Linex(x-m,y+2*m,x-m,y+2*m,color);
    }
    for(n=0;n<=4;n++)
    {
        Linex(x+n,y-2*n,x+n,y-2*n,color);
        Linex(x+3,y-8,x+6,y-8,color);
    }

    circley(x-5,y+10,9,color);   //左车轮

    circley(x+25,y+10,9,color);   //右车轮
}