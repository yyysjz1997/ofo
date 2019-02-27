#include "bikemove.h"



//extern int bike_sq[120][120];   //è¿è¡Œbikemoveå‡½æ�°å¿�é¡»åœ¨å�é¢å®šä¹�ã€�
int bike_sq[H][H]={0};


int bikeuse()
{
    int t1=0,t2=0,t3=0,d1=0;
    int i;
    float d2,zong,d3,zong2;
    char *ptr_time="string1";
    char *ptr_dis="string2";
    char *ptr_fee="string3";

    SetSVGA64k();
    Putbmp64k(0,0,"bmp\\ditu.bmp");
    Putbmp64k_TMW(600,600,"bmp\\anniu2.bmp");
    Putbmp64k_TMW(800,600,"bmp\\jieshu2.bmp");
    Initmouse(0,1024,0,768);
    t1=timesave();   //¼ÇÂ¼¿ªÊ¼ÓÃ³µÊ±¼ä¡£
    while(!kbhit())
    {

        if(Mouse_above(600,600,700,700))
        {
            Newxy6();
            Putbmp64k_TMW(600,600,"bmp\\anniu1.bmp");

            if(!Mouse_above(600,600,700,700))
            {
                //Newxy2();
                Putbmp64k_TMW(600,600,"bmp\\anniu2.bmp");
            }
            else if(Mouse_press(600,600,700,700))
            {

                d1=bikemove();

            }
        }
        else if(Mouse_above(800,600,900,700))
        {
            Newxy6();
            Putbmp64k_TMW(800,600,"bmp\\jieshu1.bmp");
            if(!Mouse_above(800,600,900,700))
            {
                //Newxy2();
                Putbmp64k_TMW(800,600,"bmp\\jieshu2.bmp");
            }
            else if(Mouse_press(800,600,900,700))
            {
                t2=timesave();   //¼ÇÂ¼½áÊøÓÃ³µÊ±¼ä¡£
                t3=total_time(t1,t2);   //¼ÇÂ¼×ÜÊ±¼ä¡£
                d2=total_mile(d1);      //¼ÇÂ¼×Ü»»Ëã¾àÀë¡£
                zong=total_fee(t3,d2);
                d3=change_num(d2);
                zong2=change_num(zong);

                gcvt(t3, 5, ptr_time);
                gcvt(d3, 5, ptr_dis);
                gcvt(zong2,5,ptr_fee);
                Putbmp64k(0,0,"bmp\\jiaofei.bmp");
                OutASC(ptr_dis,64,65000,354,293,1024,768);
                OutASC(ptr_time,64,65000,354,416,1024,768);
                OutASC(ptr_fee,64,65000,306,525,1024,768);
                backmenu();


            }
        }
        else
            Newxy();
    }
    return 0;
}





int bikemove()
{
  int x=918,y=318,i,j,k=0;

  SetSVGA64k();
	 Putbmp64k(0,0,"bmp\\ditu.bmp");
     Putbmp64k_TMW(600,600,"bmp\\anniu2.bmp");
     Putbmp64k_TMW(800,600,"bmp\\jieshu2.bmp");
	 bike_savebk(x,y);
	 Putbmp64k_TMB(x,y,"bmp\\che6.bmp");

	while(1)
	{
		  while(!kbhit())
		  {
			  int direct=getch();
			   bike_putbk(x,y);
			  switch(direct)
			  {
				  case'w':y-=20;
				  break;
				  case's':y+=20;
				  break;
				  case'd':x+=20;
				  break;
				  case'a':x-=20;
				  break;
				  case'p':return(k);
				  default:
				  break;

			   }
               k++;
               bike_savebk(x,y);
               Putbmp64k_TMB(x,y,"bmp\\che6.bmp");

		  }
		}
}

 int bike_savebk(int x,int y)
 {
   int i,j;
   for(i=0;i<=H-1;i++)
   for(j=0;j<=H-1;j++)
   bike_sq[i][j]=Getpixel64k(x+i-H/2,y+j-H/2);
   return 0;
 }

 int bike_putbk(int x,int y)
 {
	int i,j;
   for(i=0;i<=H-1;i++)
   for(j=0;j<=H-1;j++)
   Putpixel64k(x+i-H/2,y+j-H/2,bike_sq[i][j]);
   return 0;

 }
