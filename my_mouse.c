#include"my_mouse.h"
#include<dos.h>
#include<stdio.h>

union REGS regs;
void cursor(int x,int y);
int init(int xmi,int xma,int ymi,int yma);
int read(int *mx,int *my,int *mbutt);
void newxy(int *mx,int *my,int *mbutt);
void MousePutBk(int x, int y);
void MouseStoreBk(int x, int y);
unsigned int mouse_bk[18][18]={0};

void cursor(int x,int y)     //画鼠标的函数
{
	Liney(x,y,x,y,65530);
	Liney(x+1,y,x+1,y+2,65530);
	Liney(x+2,y+1,x+2,y+4,65530);
	Liney(x+3,y+1,x+3,y+6,65530);
	Liney(x+4,y+2,x+4,y+8,65530);
	Liney(x+5,y+2,x+5,y+10,65530);
	Liney(x+6,y+3,x+6,y+12,65530);
	Liney(x+7,y+3,x+7,y+14,65530);
	Liney(x+8,y+4,x+8,y+16,65530);
	Liney(x+9,y+4,x+9,y+8,65530);
	Liney(x+10,y+5,x+10,y+8,65530);
	Liney(x+11,y+5,x+11,y+8,65530);
	Liney(x+12,y+6,x+12,y+8,65530);
	Liney(x+13,y+6,x+13,y+8,65530);
	Liney(x+14,y+7,x+14,y+8,65530);
	Liney(x+15,y+7,x+15,y+8,65530);
	Liney(x+16,y+8,x+16,y+8,65530);
}

int init(int xmi,int xma,int ymi,int yma)    //鼠标器初始化函数
{
	int retcode;
	regs.x.ax=0;
	int86(51,&regs,&regs);
	retcode=regs.x.ax;
	if(retcode==0)
	{
		//printf("regs\n");
		return 0;          //返回0表示鼠标或鼠标驱动程序未安装
	}
	regs.x.ax=7;
	regs.x.cx=xmi;
	regs.x.dx=xma;
	int86(51,&regs,&regs);
	regs.x.ax=8;
	regs.x.cx=ymi;
	regs.x.dx=yma;
	int86(51,&regs,&regs);       //表示鼠标器和驱动程序已安装
	return retcode;
}

int read(int *mx,int *my,int *mbutt)     //读鼠标的位置和按钮状态函数
{
	int xx0=*mx,yy0=*my,buto=0;
	int xnew,ynew;
	do{
		regs.x.ax=3;
		int86(51,&regs,&regs);
		xnew=regs.x.cx;
		ynew=regs.x.dx;
		*mbutt=regs.x.bx;
	}while(xnew==xx0&&ynew==yy0&&*mbutt==buto);
	*mx=xnew;
	*my=ynew;
	if(*mbutt)
	{
		*mx=xnew;
		*my=ynew;
		return -1;
	}
	else
	{
		*mx=xnew;
		*my=ynew;
		return 1;
	}
}

void newxy(int *mx,int *my,int *mbutt)     //是否有按钮按下，若按下，在新位置画鼠标
{
	int ch,xx0=*mx,yy0=*my,x,y;
	int xm,ym;
	ch=read(&xm,&ym,mbutt);
	if(ch>0)
	{
		cursor(xx0,yy0);
		cursor(xm,ym);
	}
	else
	{
		cursor(xx0,yy0);
		cursor(xm,ym);
		Putpixel64k(xm,ym,7);
	}
	*mx=xm;
	*my=ym;


}

void MouseStoreBk(int x, int y)
{
	int i, j;
	for (i = 0; i < 17; i++)
	{
		for (j = 0; j < 17; j++)
		{
			//if (mouse_shape[i][j] == 0)
			//{
			//	continue;
			//}
			mouse_bk[i][j] = (unsigned int) Getpixel64k(i + x, j + y);
		}
	}
}

void MousePutBk(int x, int y)
{
	int i, j;
	for (i = 0; i < 17; i++)
	{
		for (j = 0; j < 17; j++)
		{
			//if (mouse_shape[i][j] == 0)
			//{
			//	continue;
			//}

			Putpixel64k(i + x, j + y, mouse_bk[i][j]);
		}
	}
}

