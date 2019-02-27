#include "bikemove.h"



//extern int bike_sq[120][120];   //è¿è¡Œbikemoveå‡½æ??å¿??¡»åœ¨å??é¢å®šä¹??€?
// int bike_sq[H][H]={0};



int bikeuse(BIK *data2)
{
    int t1=0,t2=0,t3=0,d1=0;
    int i;
    int d2,zong;
    int z;
    char *ptr_time;
    char *ptr_dis;
    char *ptr_fee;
    char *str1= (char*)malloc(sizeof(char)*10);
    char *str2= (char*)malloc(sizeof(char)*10);
    if((ptr_time=(char *)malloc(sizeof(char)*6))==NULL)
    {
      printf("fail to malloc");
       return 0;
    }
    if((ptr_dis=(char *)malloc(sizeof(char)*6))==NULL)
     {
      printf("fail to malloc");
       return 0;
    }
    if((ptr_fee=(char *)malloc(sizeof(char)*6))==NULL)
     {
      printf("fail to malloc");
      return 0;
    }

    Putbmp64k(0,0,"bmp\\ditu.bmp");
    Putbmp64k_TMW(600,600,"bmp\\anniu2.bmp");
    Putbmp64k_TMW(800,600,"bmp\\jieshu2.bmp");
    Initmouse(0,1024,0,768);
    // Putbmp64k(0,0,"bmp\\jiaofei.bmp");
    t1=timesave();   //录脟脗录驴陋脢录脫脙鲁碌脢卤录盲隆拢
    while(1)
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
                // Putbmp64k(0,0,"bmp\\jiaofei.bmp");
                d1=bikemove(data2);

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
                Putbmp64k(0,0,"bmp\\jiaofei.bmp");
                t2=timesave();   //录脟脗录陆谩脢酶脫脙鲁碌脢卤录盲隆拢
                t3=total_time(t1,t2);   //录脟脗录脳脺脢卤录盲隆拢
                d2=total_mile(d1);      //录脟脗录脳脺禄禄脣茫戮脿脌毛隆拢
                zong=total_fee(t3,d2);
                // d3=change_num(d2);
                // zong2=change_num(zong);

                // gcvt(t3, 5, ptr_time);
                // Putbmp64k(0,0,"bmp\\zhu.bmp");
                // gcvt(d3, 5, ptr_dis);
                // gcvt(zong2,5,ptr_fee);
                itoa(t3,ptr_time,10);
                itoa(d2,ptr_dis,10);
                itoa(zong,ptr_fee,10);
                // Putbmp64k(0,0,"bmp\\jiaofei.bmp");
                // Putbmp64k(0,0,"bmp\\zhu.bmp");
                itoflo(str1,ptr_dis);
                itoflo(str2,ptr_fee);
                OutASC(ptr_time,64,65000,354,416,1024,768);
                OutASC(str1,64,65000,354,293,1024,768);
                OutASC(str2,64,65000,306,525,1024,768);
                free(ptr_time);
                free(ptr_dis);
                free(ptr_fee);
                free(str1);
                free(str2);
                z=atoi(data2->bike_fee);
                z=z+zong;
                itoa(z,data2->bike_fee,10);
                backmenu();
                break;


            }
        }
        else
            Newxy();
    }
    return 0;
}





int bikemove(BIK *data2)
{
  int x=0,y=0,i,j,k=0,r=0;
  char direct=0;
 // int bike_sq[H][H]={0};
  x=atoi(data2->bike_x);
  y=atoi(data2->bike_y);

  // Putbmp64k(0,0,"bmp\\zhu.bmp");
   Putbmp64k(0,0,"bmp\\ditu.bmp");
   Putbmp64k_TMW(600,600,"bmp\\anniu2.bmp");
  Putbmp64k_TMW(800,600,"bmp\\jieshu2.bmp");
   //bike_savebk(x,y,bike_sq);
   Putbmp64k_TMB(x,y,"bmp\\che6.bmp");

  while(bioskey(1))
    bioskey(0);
  while(1)
  {
      while(kbhit())
      {
      // Putbmp64k(0,0,"bmp\\zhu.bmp");
      direct=bioskey(0);

      // Putbmp64k(0,0,"bmp\\jiaofei.bmp");
      r=bike_limit(x,y);
      // Putbmp64k(0,0,"bmp\\jiaofei.bmp");
      if(direct=='w'||direct=='a'||direct=='s'||direct=='d'||direct=='p')
      {
      //bike_putbk(x,y,bike_sq);
        Put_back(x,y);

         switch(direct)
         {
        case'w':
        {
          if(r==2||r==3||r==5||r==6||r==7||r==10||r==11)
          {
             // Putbmp64k(0,0,"bmp\\jiaofei.bmp");
            y-=20;
            k++;
          }
          else
          {
            y=y;
          }
          break;
        }
        case's':
        {
          if(r==2||r==4||r==5||r==6||r==7||r==8||r==9)
          {
            y+=20;
            k++;
          }
          else
          {
            y=y;
          }
          break;
        }

        case'd':
        {
          if(r==1||r==3||r==4||r==6||r==7||r==8||r==10)
          {
            x+=20;
            k++;
          }
          else
          {

            x=x;
          }
          break;
        }
        case'a':
        {
          if(r==1||r==3||r==4||r==5||r==7||r==9||r==11)
          {
            x-=20;
            k++;
          }
          else
          {
            x=x;
          }
          break;
        }
            case'p':
        {
          itoa(x,data2->bike_x,10);
          itoa(y,data2->bike_y,10);
          return(k);
        }

        }
    //bike_savebk(x,y,bike_sq);
    Putbmp64k_TMB(x,y,"bmp\\che6.bmp");


      }
    else
    break;
  }
    }
}

int bike_limit(int x,int y)
 {
   if(((y==280||y==340||y==380||y==440||y==540)&&((x>0&&x<60)||(x>60&&x<140)||(x>140&&x<240)||(x>240&&x<320)||(x>320&&x<380)))
     ||(y==300&&(x>380&&x<700))
     ||(y==320&&((x>700&&x<800)||(x>800&&x<940)))
     ||(y==360&&(x>800&&x<820))
     ||(y==400&&(x>820&&x<940))
     )
     {
     return(1);
     }                                       //记录所有仅能进行左右操作的点。
   if(((x==0||x==60||x==140||x==240||x==320)&&((y>280&&y<340)||(y>340&&y<380)||(y>380&&y<440)||(y>440&&y<540)))
      ||(x==380&&((y>280&&y<300)||(y>300&&y<340)||(y>340&&y<380)||(y>380&&y<440)||(y>440&&y<540)))
      ||(x==700&&(y>300&&y<320))
      ||(x==800&&(y>320&&y<360))
      ||(x==820&&(y>360&&y<400))
      ||(x==940&&(y>320&&y<400))
     )
     {
     return(2);
     }                                      //记录所有仅能进行上下操作的点。
   if(y==540&&(x==60||x==140||x==240||x==320)
     )
     {
     return(3);
     }                                      //记录所有仅能进行上左右的点。
   if((y==280&&(x==60||x==140||x==240||x==320))
       ||(x==800&&y==320)
     )
     {
     return(4);
     }                                     //记录所有仅能进行下左右的点。
   if(x==380&&(y==340||y==380||y==440)
     )
     {
     return(5);
     }                                     //记录所有仅能进行上下左操作的点。
   if((x==0&&(y==340||y==380||y==440))
       ||(x==380&&y==300)
     )
    {
     return(6);
     }                                   //记录所有仅能进行上下右操作的点。
   if((x==60||x==140||x==240||x==320)&&(y==340||y==380||y==440))
     {
     return(7);
     }                                    //记录所有仅能进行上下左右左右操作的点。
   if(x==0&&y==280)
     {
     return(8);
     }                                    //记录所有仅能进行下右操作的点。
   if((x==380&&y==280)||(x==700&&y==300)||(x==940&&y==320)||(x==820&&y==360))
     {
     return(9);
     }                                    //记录所有仅能进行下左作的点.
   if((x==0&&y==540)||(x==700&&y==320)||(x==800&&y==360)||(x==820&&y==400))
    {
     return(10);
     }                                 //记录所有仅能进行上右操作的点。
   if((x==380&&y==540)||(x==940&&y==400))
    {
     return(11);
     }
     else
     {
      return 0;
     }                               //记录所有仅能进行上左操作的点。
 }