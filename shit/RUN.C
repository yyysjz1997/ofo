#include "svgamode.h"
#include "mouse2.h"
#include "draw.h"
#include "login.h"
#include "bike.h"
#include "explain.h"
#include "bikemove.h"
#include "asc.h"
#include "fee.h"
#include "regist3.h"
#include "music.h"
#include "struct.h"
#include "remenu.h"
#include "unlock.h"
//#include "guanli.h"
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// typedef struct PERSON
// {
//     char name[7];            //用户名
//     char password[7];            //密码
// }PER;


//#define a 15641869



int main()
{

    unlock();

    bikeuse();
    return 0;

    // char out;
    // out='s';
    //  SetSVGA64k();

    //  OutChar(out ,16,100,100,40000);
    // PER info;

    // read(&info,1);
    // printf("%s\n",info.name);
    // printf("%s\n",info.password);
    // SetSVGA64k();
    // Putbmp64k(0,0,"bmp\\kaisuo.bmp");
    // Putbmp64k(192,487,"bmp\\daoshu5.bmp");
    // delay(1000);
    // Putbmp64k(192,487,"bmp\\daoshu4.bmp");
    // delay(1000);
    // Putbmp64k(192,487,"bmp\\daoshu3.bmp");
    // delay(1000);
    // Putbmp64k(192,487,"bmp\\daoshu2.bmp");
    // delay(1000);
    // Putbmp64k(192,487,"bmp\\daoshu1.bmp");

    // getch();
    // return 0;
    // int t1=0,t2=0,t3=0,d1=0;
    // int i;
    // float d2,zong,d3,zong2;
    // char *ptr_time="string1";
    // char *ptr_dis="string2";
    // char *ptr_fee="string3";

    // SetSVGA64k();
    // Putbmp64k(0,0,"bmp\\ditu.bmp");
    // Putbmp64k_TMW(600,600,"bmp\\anniu2.bmp");
    // Putbmp64k_TMW(800,600,"bmp\\jieshu2.bmp");
    // Initmouse(0,1024,0,768);
    // t1=timesave();   //记录开始用车时间。
    // while(!kbhit())
    // {

    //     if(Mouse_above(600,600,700,700))
    //     {
    //         Newxy6();
    //         Putbmp64k_TMW(600,600,"bmp\\anniu1.bmp");

    //         if(!Mouse_above(600,600,700,700))
    //         {
    //             //Newxy2();
    //             Putbmp64k_TMW(600,600,"bmp\\anniu2.bmp");
    //         }
    //         else if(Mouse_press(600,600,700,700))
    //         {

    //             d1=bikemove();

    //         }
    //     }
    //     else if(Mouse_above(800,600,900,700))
    //     {
    //         Newxy6();
    //         Putbmp64k_TMW(800,600,"bmp\\jieshu1.bmp");
    //         if(!Mouse_above(800,600,900,700))
    //         {
    //             //Newxy2();
    //             Putbmp64k_TMW(800,600,"bmp\\jieshu2.bmp");
    //         }
    //         else if(Mouse_press(800,600,900,700))
    //         {
    //             t2=timesave();   //记录结束用车时间。
    //             t3=total_time(t1,t2);   //记录总时间。
    //             d2=total_mile(d1);      //记录总换算距离。
    //             zong=total_fee(t3,d2);
    //             d3=change_num(d2);
    //             zong2=change_num(zong);

    //             gcvt(t3, 5, ptr_time);
    //             gcvt(d3, 5, ptr_dis);
    //             gcvt(zong2,5,ptr_fee);
    //             Putbmp64k(0,0,"bmp\\jiaofei.bmp");
    //             OutASC(ptr_dis,64,65000,354,293,1024,768);
    //             OutASC(ptr_time,64,65000,354,416,1024,768);
    //             OutASC(ptr_fee,64,65000,306,525,1024,768);
    //             backmenu();


    //         }
    //     }
    //     else
    //         Newxy();
    // }
    // return 0;
    //******************************************************
   //   delay(1000);
    //t2=timesave();   //记录结束用车时间。


     //记录总费用。





   //   printf("a value=%s\n", ptr_time);
   //   printf("%f\n a value=%s\n",d2, ptr_dis);
   //   printf("a value=%s\n", ptr_fee);
    //char str[]="100.00&*^" ;
     //SetSVGA64k();

      //  getch();

    // char y[80];

    // inputs(y,100,100);
    // OutASC(y,32,65000,100,100,1024,764);


    // SetSVGA64k();

    // OutASC(y,32,50000,200,400,400,700);
    // extern int bike_sq[120][120]; //运行bikemove函数必须在前面定义。
    //  bikemove();

         //SetSVGA64k();     //SVGA?图?某?始?????
        // bicycle(100,100);
        // delay(100);
         //Putbmp64k(0,0,"bmp\\xiao2.bmp");
        // delay(100);
        // Putbmp64k(0,0,"bmp\\hello2.bmp");
        // delay(1000);
        // Putbmp64k(0,0,"bmp\\zhu.bmp");
        // Bar64k(301,217,321,311,a);
        // getch();
        // Initmouse(0,1024,0,768);
        // Mouse_savebk(0,0);
        // while(!kbhit())
        // {
        //     if(Mouse_above(301,217,731,311))   //?????? ?????? ?? ??钮???
        //     {
        //         Newxy2();
        //         Bar64k(301,217,321,311,a);
        //         Bar64k(301,217,731,237,a);
        //         Bar64k(711,217,731,311,a);
        //         Bar64k(301,291,731,311,a);
        //     }
            // else if(Mouse_above(301,351,731,445))  //?????? ??????? ?? ??钮???
            // {
            //     Newxy2();
            //     Bar64k(301,351,321,445,30000);
            //     Bar64k(301,351,731,371,30000);
            //     Bar64k(711,351,731,445,30000);
            //     Bar64k(301,425,731,445,30000);
            // }
            // else if(Mouse_above(301,486,731,579))   //?????? 使?说? ?? ??钮???
            // {
            //     Newxy2();
            //     Bar64k(301,486,321,579,30000);
            //     Bar64k(301,486,731,506,30000);
            //     Bar64k(711,486,731,579,30000);
            //     Bar64k(301,559,731,579,30000);
            // }
            // else if(Mouse_above(301,619,731,713))   //?????? ???系统 ?? ??钮???
            // {
            //     Newxy2();
            //     Bar64k(301,619,321,713,30000);
            //     Bar64k(301,619,731,639,30000);
            //     Bar64k(711,619,731,713,30000);
            //     Bar64k(301,693,731,713,30000);

        // SetSVGA64k();     //SVGA?图?某?始?????
        // Putbmp64k(0,0,"bmp\\num1.bmp");
        // delay(1000);
        // Putbmp64k(0,0,"bmp\\pnum1.bmp");
        // Putbmp64k(200,200,"bmp\\num2.bmp");
        // delay(1000);
        // Putbmp64k(200,200,"bmp\\pnum2.bmp");

        //SetSVGA64k();     //?图?某?始?????
        // Putbmp64k(0,0,"bmp\\hello.bmp");
        // getch();
        // Putbmp64k(0,0,"bmp\\xiao.bmp");
        // delay(100);
        // Putbmp64k(0,0,"bmp\\xiao2.bmp");
        // delay(100);
        // Putbmp64k(0,0,"bmp\\hello2.bmp");

/***********************************************************
       SetSVGA64k();
        Putbmp64k(0,0,"bmp\\zhu.bmp");
       Putbmp64k(0,0,"bmp\\shuoming.bmp");
      delay (2000);
      Putbmp64k(0,0,"bmp\\zhu.bmp");
    Putbmp64k(299,117,"bmp\\2.bmp");
    Putbmp64k(407,117,"bmp\\3.bmp");
    Putbmp64k(515,117,"bmp\\4.bmp");
    Putbmp64k(623,117,"bmp\\5.bmp");
    Putbmp64k(731,117,"bmp\\6.bmp");
    Initmouse(0,1024,0,768);
    Mouse_savebk(0,0);
    while(!kbhit())
    {

        if(Mouse_above(830,630,951,716))
        {
            Newxy2();
            Bar64k(828,630,837,715,20000);
            Bar64k(828,630,951,642,20000);
            Bar64k(943,642,951,715,20000);
            Bar64k(837,704,951,715,20000);
        }
        else if(!Mouse_above(830,630,951,716))

        {
            Newxy();
            Bar64k(828,630,837,715,30000);
            Bar64k(828,630,951,642,30000);
            Bar64k(943,642,951,715,30000);
            Bar64k(837,704,951,715,30000);
        }
        if(Mouse_press(830,630,951,716))
        {
           Initmouse(0,1024,0,768);
           Putbmp64k(0,0,"bmp\\shuoming.bmp");
           //Mouse_savebk(0,0);
           Newxy();
        }
     }
   getch();
   **********************************************************/


  // SetSVGA64k();
  // Putbmp64k(0,0,"bmp\\zhuce.bmp");
  // delay(2000);
  // Putbmp64k(327,151,"bmp\\kong.bmp");
   // ***********************************************************************


//         int temp=0;
//         //PER *data;
//         SetSVGA64k();
//         // Putbmp64k(0,0,"bmp\\hello.bmp");
//         // getch();
//         // Putbmp64k(0,0,"bmp\\xiao.bmp");
//         // delay(1000);
//         // Putbmp64k(0,0,"bmp\\xiao2.bmp");
//         // delay(1000);
//         // Putbmp64k(0,0,"bmp\\hello2.bmp");
//         // delay(3000);
//         Putbmp64k(0,0,"bmp\\zhu.bmp");
//         temp=Getpixel64k(0,0);
//         Initmouse(0,1024,0,768);
//         while(1)
//         {
//             if(Mouse_above(301,217,731,311))   //鼠标在 “ 用户登录 ” 按钮上方
//             {
//                 aloginy();
//             }
//             if(Mouse_press(301,217,731,311))     //鼠标在 “ 用户登录 ” 按钮上按键
//             {
//                 loginy();
//             }
//             if(Mouse_above(301,351,731,445))  //鼠标在 “ 管理员登录 ” 按钮上方
//             {
//                 Newxy2();
//                 Linex(301,351,731,351,60000);
//                 Liney(301,351,301,445,60000);
//                 Linex(301,445,731,445,60000);
//                 Liney(731,351,731,445,60000);
//             }
//             if(Mouse_above(301,486,731,579))      //鼠标在 “ 使用说明 ” 按钮上方
//             {
//                 aexplainy();
//             }
//             if(Mouse_press(301,486,731,579))   //鼠标在 “ 用户说明 ” 按钮上按键
//             {
//                 explainy();
//             }
//             if(Mouse_above(301,619,731,713))   //鼠标在 “ 退出系统 ” 按钮上方
//             {

//                 Newxy2();
//                 Linex(301,619,731,619,60000);
//                 Liney(301,619,301,713,60000);
//                 Linex(301,713,731,713,60000);
//                 Liney(731,619,731,713,60000);
//             }
//             if(!Mouse_above(301,217,731,311)&&!Mouse_above(301,351,731,445)&&!Mouse_above(301,486,731,579)&&!Mouse_above(301,619,731,713))  //鼠标在非按钮上方显示 “ 箭头型鼠标函数 ”
//             {
//                 Newxy();
//                 Linex(301,619,731,619,temp);
//                 Liney(301,619,301,713,temp);
//                 Linex(301,713,731,713,temp);
//                 Liney(731,619,731,713,temp);

//                 Linex(301,351,731,351,temp);
//                 Liney(301,351,301,445,temp);
//                 Linex(301,445,731,445,temp);
//                 Liney(731,351,731,445,temp);

//                 Linex(301,486,731,486,temp);
//                 Liney(301,486,301,579,temp);
//                 Linex(301,579,731,579,temp);
//                 Liney(731,486,731,579,temp);

//                 Linex(301,217,731,217,temp);
//                 Liney(301,217,301,311,temp);
//                 Linex(301,311,731,311,temp);
//                 Liney(731,217,731,311,temp);




//             }
// /**
//             if(Mouse_press(301,351,731,445))   //鼠标在 “ 管理员系统 ” 按钮上按键
//             {
//                 guanli();
//             }
// **/


//             if(Mouse_press(301,619,731,713))    //鼠标在 “ 退出系统 ” 按钮上按键
//             {
//                 Putbmp64k(0,0,"bmp\\tuichu1.bmp");
//                 delay(100);
//                 Putbmp64k(0,0,"bmp\\tuichu2.bmp");
//                 exit(1);
//             }
//         }

 }

// #include<stdio.h>
// #include<string.h>
// #include"svgamode.h"
// #include"asc.h"
// int num_write(void);
// int num_read(char *str);
// #include <stdlib.h>
// #define N 3


// int  num_sq[120][120]={0};

// void num_savebk(int x,int y);
// void num_putbk(int x,int y);


// void main()
// {
//       char str_num[7]={0};
//       char *str1="111111";
//       char *str4="000000";
//       int a,i;
//       int k;

//       num_write();

//       SetSVGA64k();
//       Putbmp64k(0,0,"bmp\\yongche.bmp");
//       num_savebk(186,339);
//       for(i=0;i<6;i++)
//       {
//            while(1)
//            {
//                   a=i;
//                   while(!kbhit())
//                   {
//                           int direct=getch();
//                           if((direct>='0')&&(direct<='9'))
//                           {
//                                  str_num[i]=(char)direct;
//                                  OutASC(&str_num[i],64,0,190+109*i,349,1024,768);
//                                  i++;
//                                  break;
//                           }
//                           if((direct=='\b')&&(i>=1))
//                           {
//                                 str_num[i-1]='\0';
//                                 num_putbk(184+109*(i-1),339);
//                                //   OutASC(str_num,64,65000,190+109*i,349,1024,768);
//                                 i=i-1;
//                                 break;
//                           }

//                   }
//                   if(i!=a)
//                   {
//                       i--;
//                   }
//                      break;
//            }


// }
//       str1=str_num;
//       k=num_read(str1);
//       itoa(k,str4,10);

//     SetSVGA64k();
//     Putbmp64k(0,0,"bmp\\kaisuo.bmp");
//     OutASC(str4,180,65000,100,210,1024,768);


//     Putbmp64k(192,487,"bmp\\daoshu5.bmp");
//     delay(1000);
//     Putbmp64k(192,487,"bmp\\daoshu4.bmp");
//     delay(1000);
//     Putbmp64k(192,487,"bmp\\daoshu3.bmp");
//     delay(1000);
//     Putbmp64k(192,487,"bmp\\daoshu2.bmp");
//     delay(1000);
//     Putbmp64k(192,487,"bmp\\daoshu1.bmp");


//     Putbmp64k(0,0,"bmp\\kaisuo.bmp");

// }

// void num_savebk(int x,int y)
//  {
//    int i,j;
//    for(i=0;i<=111;i++)
//    for(j=0;j<=111;j++)
//    num_sq[i][j]=Getpixel64k(x+i,y+j);
//  }

//  void num_putbk(int x,int y)
//  {
//    int i,j;
//    for(i=0;i<=111;i++)
//    for(j=0;j<=111;j++)
//    Putpixel64k(x+i,y+j,num_sq[i][j]);

//  }





// int num_write(void)
// {
//     int i=0;
//     char num[N][7]={0};
//     char unlock[N][5]={0};

//     FILE *fp=fopen("numedit.txt","w");
//     for(i=0;i<N;i++)
//     {
//         gets(num[i]);
//         gets(unlock[i]);

//         fputs(num[i],fp);
//         fputs(unlock[i],fp);

//     }
//      fclose(fp);/*关闭文件*/
//      return 0;
// }

// int num_read(char *str)
// {
//        int i=0;
//        int p=0;
//        char *str2="0000";
//        char num[N][7]={0};
//        char unlock[N][5]={0};

//         FILE *fp=fopen("numedit.txt","r");
//         for(i=0;i<N;i++)
//         {
//              fread(num[i],6,1,fp);
//              fread(unlock[i],4,1,fp);
//              if(strcmp(num[i],str)==0)
//              {
//                   str2=unlock[i];
//                   printf("%s\n",str2);
//                   p=atoi(str2);
//                   fclose(fp);
//                   return p;
//              }
//         }
//        return 0;
// }