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
#include "struct2.h"
#include "remenu.h"
#include "guanli.h"
#include "above.h"
#include "newb.h"
#include "bikegav.h"
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <process.h>

int main()
{
       // BIK *data2;
       // SetSVGA64k();
       // Initmouse(0,1024,0,768);

       // bikegar(data2);
       // return 0;
        int flag1=4,flag3=0,flag4=2;//flag5=0,flag6=0,flag7=0,flag8=0;
        int temp=0;
        //int end=0;
        PER *data;
        GOV *gov;
        BIK *data2;

        SetSVGA64k();
        Putbmp64k(0,0,"bmp\\hello.bmp");
        getch();
        Putbmp64k(0,0,"bmp\\hello2.bmp");
        delay(2000);
        Putbmp64k(0,0,"bmp\\zhu.bmp");
        temp=Getpixel64k(0,0);
        Initmouse(0,1024,0,768);

        while(1)
        {
            if(Mouse_above(301,217,731,311))   //?????? ?????? ?? ??ť???
            {
                aloginy();
            }
            if(Mouse_press(301,217,731,311))     //?????? ?????? ?? ??ť?????
            {
                while(1)
                {
                     flag1=loginy();
                     switch(flag1)
                         {
                            case 0: {
                                     flag3=2;
                                     break;
                                    }

                            case 1:{
                                   unlock(data2);
                                   flag3=2;
                                   break;
                                   }

                            case 2: {
                                    regist(data);
                                    flag3=1;
                                    break;
                                    }

                            default:{
                                     break;
                                     }
                          }

                 if(flag3==2)
                    {
                    break;
                    }
                }
            }
            if(Mouse_above(301,351,731,445))  //?????? ??????? ?? ??ť???
            {
                aguanli();
            }
            if(Mouse_press(301,351,731,445))   //?????? ????ϵͳ ?? ??ť?????
            {
                while(1)
                {
                 flag4=govern(gov);
                if(flag4==0)
                {
                      break;
                }
                if(flag4==1)
                {
                      bikegar(data2);
                      Initmouse(0,1024,0,768);
                      Putbmp64k(0,0,"bmp\\zhu.bmp");
                      break;
                }
                else
                {
                    break;
                }
                }

            }
            if(Mouse_above(301,486,731,579))      //?????? ʹ?˵? ?? ??ť???
            {
                aexplainy();
            }
            if(Mouse_press(301,486,731,579))   //?????? ???˵? ?? ??ť?????
            {
                explainy();
            }
            if(Mouse_above(301,619,731,713))   //?????? ???ϵͳ ?? ??ť???
            {
                atuichu();
            }
            if(!Mouse_above(301,217,731,311)&&!Mouse_above(301,351,731,445)&&!Mouse_above(301,486,731,579)&&!Mouse_above(301,619,731,713))  //???ڷǰ?ť????ʾ ?? ??ͷ???꺯? ??
            {
                Newxy();
                Linex(301,619,731,619,temp);
                Liney(301,619,301,713,temp);
                Linex(301,713,731,713,temp);
                Liney(731,619,731,713,temp);

                Linex(301,351,731,351,temp);
                Liney(301,351,301,445,temp);
                Linex(301,445,731,445,temp);
                Liney(731,351,731,445,temp);

                Linex(301,486,731,486,temp);
                Liney(301,486,301,579,temp);
                Linex(301,579,731,579,temp);
                Liney(731,486,731,579,temp);

                Linex(301,217,731,217,temp);
                Liney(301,217,301,311,temp);
                Linex(301,311,731,311,temp);
                Liney(731,217,731,311,temp);
            }


            if(Mouse_press(301,619,731,713))    //?????? ???ϵͳ ?? ??ť?????
            {
                // Putbmp64k(0,0,"bmp\\tuichu1.bmp");
                // delay(100);
                Putbmp64k(0,0,"bmp\\tuichu2.bmp");
                delay(1000);
                // end=1;
                 exit (0);
                // return (end);
            }
            // if(end==1)
            // {
            //     exit (0);
            // }

        }
         // return 0;
}

