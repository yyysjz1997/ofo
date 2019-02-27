#include "process.h"

//贴图的初始化函数
SetSVGA64k();
      Putbmp64k(0,0,"bmp\\shuoming.bmp");


 //kaiche.bmp中车辆号码的贴图坐标（6位数的车辆）
 Putbmp64k(0,0,"bmp\\kaiche.bmp");
    Putbmp64k(191,117,"bmp\\1.bmp");
    Putbmp64k(299,117,"bmp\\2.bmp");
    Putbmp64k(407,117,"bmp\\3.bmp");
    Putbmp64k(515,117,"bmp\\4.bmp");
    Putbmp64k(623,117,"bmp\\5.bmp");
    Putbmp64k(731,117,"bmp\\6.bmp");

 //鼠标点击某一区域，进行换页操作。
  Initmouse(0,1024,0,768);
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
            Bar64k(828,630,837,715,0);
            Bar64k(828,630,951,642,0);
            Bar64k(943,642,951,715,0);
            Bar64k(837,704,951,715,0);
        }
        if(Mouse_press(830,630,951,716))
        {
           Initmouse(0,1024,0,768);//必须加
           Putbmp64k(0,0,"bmp\\zhu.bmp");
           Newxy();
        }
     }



 int temp=0;
        SetSVGA64k();     //SVGA?图?某?始?????
        // Putbmp64k(0,0,"bmp\\hello.bmp");
        // getch();          //??????????一?图
        // Putbmp64k(0,0,"bmp\\hello5.bmp");
        // delay(1000);
        // Putbmp64k(0,0,"bmp\\hello2.bmp");
        // delay(3000);
     Putbmp64k(0,0,"bmp\\zhu.bmp");
         temp=Getpixel64k(0,0);
        Initmouse(0,1024,0,768);
        while(!kbhit())
        {
            if(Mouse_above(301,217,731,311))   //鼠标在 “ 用户登录 ” 按钮上方
            {
                aloginy();
            }
            if(Mouse_press(301,217,731,311))     //鼠标在 “ 用户登录 ” 按钮上按键
            {
                loginy();
            }
            if(Mouse_above(301,351,731,445))  //鼠标在 “ 管理员登录 ” 按钮上方
            {
                Newxy2();
                Linex(301,351,731,351,60000);
                Liney(301,351,301,445,60000);
                Linex(301,445,731,445,60000);
                Liney(731,351,731,445,60000);
            }
            if(Mouse_above(301,486,731,579))      //鼠标在 “ 使用说明 ” 按钮上方
            {
                aexplainy();
            }
            if(Mouse_press(301,486,731,579))   //鼠标在 “ 用户说明 ” 按钮上按键
            {
                explainy();
            }
            if(Mouse_above(301,619,731,713))   //鼠标在 “ 退出系统 ” 按钮上方
            {

                Newxy2();
                Linex(301,619,731,619,60000);
                Liney(301,619,301,713,60000);
                Linex(301,713,731,713,60000);
                Liney(731,619,731,713,60000);
            }
            if(!Mouse_above(301,217,731,311)&&!Mouse_above(301,351,731,445)&&!Mouse_above(301,486,731,579)&&!Mouse_above(301,619,731,713))  //鼠标在非按钮上方显示 “ 箭头型鼠标函数 ”
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

/***************************************************************************************
            else if(Mouse_press(301,351,731,445))   //鼠标在 “ 管理员系统 ” 按钮上按键
            {
                Initmouse(0,1024,0,768);//???
                Putbmp64k(0,0,"bmp\\.bmp");     //??????
                Mouse_savebk(0,0);//???
                Newxy();
            }

***************************************************************************************/

            if(Mouse_press(301,619,731,713))    //鼠标在 “ 退出系统 ” 按钮上按键
            {
                Putbmp64k(0,0,"bmp\\tuichu1.bmp");
                delay(100);
                Putbmp64k(0,0,"bmp\\tuichu2.bmp");
                exit(0);
            }
        }


