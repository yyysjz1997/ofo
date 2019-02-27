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
    t1=timesave();   //记录开始用车时间。
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
                t2=timesave();   //记录结束用车时间。
                t3=total_time(t1,t2);   //记录总时间。
                d2=total_mile(d1);      //记录总换算距离。
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