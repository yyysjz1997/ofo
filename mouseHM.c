#include "mouse.h"
#include "bmp.h"


//2-外部 0—边界 1-内部
int MouseDraw[10][16]={
{1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0},     
{1,2,2,2,2,2,2,2,2,2,2,2,1,0,0,0},                                   
{0,1,2,2,2,2,2,2,2,2,2,1,0,0,0,0},
{0,0,1,2,2,2,2,2,2,2,2,0,0,0,0,0},
{0,0,0,1,2,2,2,2,2,2,2,1,1,0,0,0},
{0,0,0,0,1,2,2,2,2,2,2,2,2,1,1,0},  
{0,0,0,0,0,1,2,2,2,2,1,2,2,2,2,1},
{0,0,0,0,0,0,1,2,2,1,0,1,1,2,2,2},
{0,0,0,0,0,0,0,1,2,0,0,0,0,1,1,2},
{0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1} };


int Mousebk[10][16];

STATUS Mouseinit(int xmin,int xmax,int ymin,int ymax)
{
    union REGS mouse_regs;

    mouse_regs.x.ax=0;
    int86(0x33,&mouse_regs,&mouse_regs);
    if(mouse_regs.x.ax==0)
    {
      printf("can not install the mouse");
      sleep(3);
      return ERROR;
    }

    mouse_regs.x.ax=7;
    mouse_regs.x.cx=xmin;
    mouse_regs.x.dx=xmax;
    int86(0x33,&mouse_regs,&mouse_regs);

    mouse_regs.x.ax=8;
    mouse_regs.x.cx=ymin;
    mouse_regs.x.dx=ymax;
    int86(0x33,&mouse_regs,&mouse_regs);

    mouse_regs.x.ax=4;
    mouse_regs.x.cx=0;
    mouse_regs.x.dx=0;
	int86(0x33,&mouse_regs,&mouse_regs);
	Mousestorebk(0,0);
	return OK;
}


void Readmouse(MOUSE *mouse)
{

   union REGS mouse_regs;
   int x0=mouse->x;
   int y0=mouse->y;
   int b0=mouse->button;

   mouse_regs.x.ax=3;

   do
   {
      int86(0x33,&mouse_regs,&mouse_regs);  
      mouse->x=mouse_regs.x.cx;
      mouse->y=mouse_regs.x.dx;
      mouse->button=mouse_regs.x.bx;
   }while(mouse->x==x0&&mouse->y==y0&&mouse->button==b0); 
}


STATUS Mousestatus(int x1,int y1,int x2,int y2)
{
	MOUSE *mouse   ;
  
  mouse->button=0;
   
	Readmouse(mouse);

	if(mouse->x>=x1&&mouse->x<=x2&&mouse->y>=y1&&mouse->y<=y2&&mouse->button==1)
		return 1;
	else if(mouse->x>=x1&&mouse->x<=x2&&mouse->y>=y1&&mouse->y<=y2&&mouse->button==2)
			return 2;
		 else  return 0;
}


void Mousestorebk(int x,int y)
{
   int i,j;

	for(j=0;j<16;j++)
	{
	   for(i=0;i<10;i++)
	   {
		   if(MouseDraw[i][j]==0)
		   {
			  continue;
		   }
		   Mousebk[i][j]=Getpixel64K(i+x,j+y);
	   }
	}
}


void Mouseputbk(int x,int y)
{
  int i,j;

  for(j=0;j<16;j++)
  {
	for(i=0;i<10;i++)
	{
	   if(MouseDraw[i][j]==0)
	   {
		  continue;
	   }
	   Putpixel64K(COPY,i+x,j+y,Mousebk[i][j]);
	}
  }
}



void Mouseshow(MOUSE mouse)
{
   int i,j;

   for(i=0;i<10;i++)
   {
	  for(j=0;j<16;j++)
	  {
		if(MouseDraw[i][j]==0)
				continue;
		else if(MouseDraw[i][j]==1)
				Putpixel64K(COPY,mouse.x+i,j+mouse.y,0);
		else if(MouseDraw[i][j]==2)
				Putpixel64K(COPY,mouse.x+i,mouse.y+j,0xffff);
	  }
   }
}


