#include "newb.h"

int newbike(BIK *data2)
{
    FILE *fp;
    int temp1=0;
    int temp2=0;
    int n=0;
    int i=0;
     int flag=0;
    Initmouse(0,1024,0,768);
    Putbmp64k(0,0,"bmp\\newbike.bmp");

    temp1=Getpixel64k(1000,10);
    temp2=Getpixel64k(400,200);
                       for(i=0;i<10;i++)
      {
      data2->bike_name[0]='\0';
      data2->bike_password[0]='\0';
      data2->bike_x[0]='\0';
      data2->bike_y[0]='\0';
      }

    //int flag=0;
    while(1)
    {
        if(flag==1)
        {
            Initmouse(0,1024,0,768);
            Putbmp64k(0,0,"bmp\\newbike.bmp");
            flag=0;
        }
        if(Mouse_above(355,125,822,225))//鼠标移到车牌号码上方
        {
            Newxy6();
            bicycle(777,175);
        }
        if(Mouse_press(355,125,822,225))//按下
        {

            input_BIK(data2->bike_name,355,125,temp2);//输入车牌号
            Initmouse(0,1024,0,768);
        }
        if(Mouse_above(355,250,822,350))//鼠标移到解锁码上方
        {
            Newxy6();
            bicycle(777,300);
        }
        if(Mouse_press(355,250,822,350))
        {
            input_BIK(data2->bike_password,355,250,temp2);//输入解锁码
            Initmouse(0,1024,0,768);
        }
        if(Mouse_above(355,375,822,475))   //鼠标移到车辆x坐标上方
        {
            Newxy6();
            bicycle(777,425);
        }
        if(Mouse_press(355,375,822,475))
        {
            input_BIK(data2->bike_x,355,375,temp2);//输入x坐标
            Initmouse(0,1024,0,768);
        }
        if(Mouse_above(355,500,822,600))   //鼠标移到车辆y坐标上方
        {
            Newxy6();
            bicycle(777,550);
        }
        if(Mouse_press(355,500,822,600))
        {
            input_BIK(data2->bike_y,355,500,temp2);//输入y坐标
            Initmouse(0,1024,0,768);
        }

        if(Mouse_above(440,646,528,700))
        {
            bike_sq2();
        }
        if(Mouse_press(440,646,528,700))
        {
            Putbmp64k(355,125,"bmp\\kong.bmp");
            Putbmp64k(355,250,"bmp\\kong.bmp");
            Putbmp64k(355,375,"bmp\\kong.bmp");
            Putbmp64k(355,500,"bmp\\kong.bmp");
                        for(i=0;i<10;i++)
      {
      data2->bike_name[0]='\0';
      data2->bike_password[0]='\0';
      data2->bike_x[0]='\0';
      data2->bike_y[0]='\0';
      }
        }
        if(Mouse_above(745,646,835,700))
        {
            bike_sq3();
        }
        if(Mouse_press(745,646,835,700))
        {
            if(strlen(data2->bike_name)==0)
            {
                 Putbmp64k(355,125,"bmp\\kong.bmp");
                 Putbmp64k(355,250,"bmp\\kong.bmp");
                 Putbmp64k(355,375,"bmp\\kong.bmp");
                 Putbmp64k(355,500,"bmp\\kong.bmp");
                Putbmp64k(300,300,"bmp\\tishi17.bmp");
                        for(i=0;i<10;i++)
      {
      data2->bike_name[0]='\0';
      data2->bike_password[0]='\0';
      data2->bike_x[0]='\0';
      data2->bike_y[0]='\0';
      }
                delay(2000);
                Putbmp64k(0,0,"bmp\\newbike.bmp");
                flag=1;
                continue;
            }
            if(search_BIK(*data2)==1)
            {
                  Putbmp64k(355,125,"bmp\\kong.bmp");
                 Putbmp64k(355,250,"bmp\\kong.bmp");
                 Putbmp64k(355,375,"bmp\\kong.bmp");
                 Putbmp64k(355,500,"bmp\\kong.bmp");
                  Putbmp64k(300,300,"bmp\\tishi16.bmp");
                       for(i=0;i<10;i++)
      {
      data2->bike_name[0]='\0';
      data2->bike_password[0]='\0';
      data2->bike_x[0]='\0';
      data2->bike_y[0]='\0';
      }
                delay(2000);
                Putbmp64k(0,0,"bmp\\newbike.bmp");
                flag=1;
                continue;
            }

            if(strlen(data2->bike_password)==0)
            {
                 Putbmp64k(355,125,"bmp\\kong.bmp");
                 Putbmp64k(355,250,"bmp\\kong.bmp");
                 Putbmp64k(355,375,"bmp\\kong.bmp");
                 Putbmp64k(355,500,"bmp\\kong.bmp");
                Putbmp64k(300,300,"bmp\\tishi18.bmp");
                        for(i=0;i<10;i++)
      {
      data2->bike_name[0]='\0';
      data2->bike_password[0]='\0';
      data2->bike_x[0]='\0';
      data2->bike_y[0]='\0';
      }
                delay(2000);
                Putbmp64k(0,0,"bmp\\newbike.bmp");
                flag=1;
                continue;
            }

             if(strlen(data2->bike_x)==0)
            {
                 Putbmp64k(355,125,"bmp\\kong.bmp");
                 Putbmp64k(355,250,"bmp\\kong.bmp");
                 Putbmp64k(355,375,"bmp\\kong.bmp");
                 Putbmp64k(355,500,"bmp\\kong.bmp");
                Putbmp64k(300,300,"bmp\\tishi19.bmp");
                       for(i=0;i<10;i++)
      {
      data2->bike_name[0]='\0';
      data2->bike_password[0]='\0';
      data2->bike_x[0]='\0';
      data2->bike_y[0]='\0';
      }
                delay(2000);
                Putbmp64k(0,0,"bmp\\newbike.bmp");
                flag=1;
                continue;
            }
             if(strlen(data2->bike_y)==0)
            {
                 Putbmp64k(355,125,"bmp\\kong.bmp");
                 Putbmp64k(355,250,"bmp\\kong.bmp");
                 Putbmp64k(355,375,"bmp\\kong.bmp");
                 Putbmp64k(355,500,"bmp\\kong.bmp");
                Putbmp64k(300,300,"bmp\\tishi20.bmp");
                       for(i=0;i<10;i++)
      {
      data2->bike_name[0]='\0';
      data2->bike_password[0]='\0';
      data2->bike_x[0]='\0';
      data2->bike_y[0]='\0';
      }
                delay(2000);
                Putbmp64k(0,0,"bmp\\newbike.bmp");
                flag=1;
                continue;
            }
            if((!(data2->bike_password[0]=='\0'))||(!(data2->bike_name[0]=='\0'))||
                    (!(data2->bike_x[0]=='\0'))||(!(data2->bike_y[0]=='\0'))||
                    (!(search_BIK(*data2)==1)))
                {
                    fp=fopen("numedit4.txt","r+");
                    fscanf(fp,"%d",&n);
                    n++;
                    fclose(fp);

                    fp=fopen("numedit4.txt","r+");
                    fprintf(fp,"%d",n);
                    fclose(fp);

      data2->bike_repair[0]='0';
      data2->bike_repair[1]='\0';
      data2->bike_fee[0]='0';
      data2->bike_fee[1]='\0';


                    // data2->bike_repair[1]="\0";
                    // data2->bike_fee[1]="\0";
                    save_BIK(*data2);
                         for(i=0;i<10;i++)
      {
      data2->bike_name[0]='\0';
      data2->bike_password[0]='\0';
      data2->bike_x[0]='\0';
      data2->bike_y[0]='\0';
      }
                    //break;
                }
                Putbmp64k(300,300,"bmp\\tishi21.bmp");
                delay(1000);
                Initmouse(0,1024,0,768);
                flag=1;
            }

       if(Mouse_above(157,646,242,700))
        {
             bike_sq1();
        }
        if(Mouse_press(157,646,242,700))
        {
             Initmouse(0,1024,0,768);
             return 0;
        }
        if(!Mouse_above(355,125,822,225)&&!Mouse_above(355,250,822,350)&&!
            Mouse_above(355,375,822,475)&&!Mouse_above(355,500,822,600)&&!
            Mouse_above(440,646,528,700)&&!Mouse_above(745,646,835,700)&&!
            Mouse_above(157,646,242,700))
        {
            Newxy();

             Linex(157,646,242,646,temp1);
             Liney(157,646,157,700,temp1);
             Linex(157,700,242,700,temp1);
             Liney(242,646,242,700,temp1);


             Linex(440,646,528,646,temp1);
             Liney(440,646,440,700,temp1);
             Linex(440,700,528,700,temp1);
             Liney(528,646,528,700,temp1);


             Linex(746,646,835,646,temp1);
             Liney(746,646,746,700,temp1);
             Linex(746,700,835,700,temp1);
             Liney(835,646,835,700,temp1);

            bicycle2(777,175,temp2);
            bicycle2(777,300,temp2);
            bicycle2(777,425,temp2);
            bicycle2(777,550,temp2);

        }
    }
}

int unlock(BIK *data2)
{
      FILE *fp;
      // BIK info2;
      int temp1=0;
      int flag1=0;
      int i;
      int n=0;

      Putbmp64k(0,0,"bmp\\yongche.bmp");
      Putbmp64k_TMW(97,566,"bmp\\baoxiu2.bmp");
      Putbmp64k_TMW(770,566,"bmp\\anniu2.bmp");
      Putbmp64k_TMW(433,566,"bmp\\fh2.bmp");
      Initmouse(0,1024,0,768);
      temp1=Getpixel64k(200,360);
      for(i=0;i<10;i++)
      {
      data2->bike_name[0]='\0';
      data2->bike_password[0]='\0';
      data2->bike_x[0]='\0';
      data2->bike_y[0]='\0';
      }
      while(1)
      {
            if(Mouse_above(184,339,840,451))//录入
            {
            Newxy6();
            bicycle(740,400);
            }
            if(Mouse_press(184,339,840,451))
            {
              input_BIK(data2->bike_name,200,350,temp1);
              Initmouse(0,1024,0,768);
              fp=fopen("numedit4.txt","r+");
              fscanf(fp,"%d",&n);
              fclose(fp);
              if(search_BIK2(*data2)!=(-1))
              {
                flag1=search_BIK2(*data2)+1;  //flag1 是输入的车牌号的位置
              }
              else
              {
                Putbmp64k(184,339,"bmp\\kong1.bmp");
                Putbmp64k(300,300,"bmp\\tishi22.bmp");
              for(i=0;i<10;i++)
              {
                 data2->bike_name[0]='\0';
                 data2->bike_password[0]='\0';
                 data2->bike_x[0]='\0';
                 data2->bike_y[0]='\0';
              }
                delay(2000);
                Putbmp64k(0,0,"bmp\\yongche.bmp");
                Putbmp64k_TMW(97,566,"bmp\\baoxiu2.bmp");
                Putbmp64k_TMW(770,566,"bmp\\anniu2.bmp");
                Putbmp64k_TMW(433,566,"bmp\\fh2.bmp");
                }
            }
            if(Mouse_above(433,566,533,666))//返回
            {
               Newxy6();
               Putbmp64k_TMW(433,566,"bmp\\fh.bmp");
            }
            if(Mouse_press(433,566,533,666))
            {
       for(i=0;i<10;i++)
      {
      data2->bike_name[0]='\0';
      data2->bike_password[0]='\0';
      data2->bike_x[0]='\0';
      data2->bike_y[0]='\0';
      }
                 Initmouse(0,1024,0,768);
                 Putbmp64k(0,0,"bmp\\zhu.bmp");
                 return 0;
            }
            if(Mouse_above(97,566,197,666))//±¨ÐÞ
            {
                 Newxy6();
                 Putbmp64k_TMW(97,566,"bmp\\baoxiu1.bmp");
            }
            if(Mouse_press(97,566,197,666))//保修
            {
                  if(strlen(data2->bike_name)==0)
                   {
                   Putbmp64k(184,339,"bmp\\kong1.bmp");
                   Putbmp64k(300,300,"bmp\\tishi17.bmp");
                           for(i=0;i<10;i++)
      {
      data2->bike_name[0]='\0';
      data2->bike_password[0]='\0';
      data2->bike_x[0]='\0';
      data2->bike_y[0]='\0';
      }
                   delay(2000);
                   Putbmp64k(0,0,"bmp\\yongche.bmp");
                  Putbmp64k_TMW(97,566,"bmp\\baoxiu2.bmp");
                  Putbmp64k_TMW(770,566,"bmp\\anniu2.bmp");
                  Putbmp64k_TMW(433,566,"bmp\\fh2.bmp");
                   }
                   else if(search_BIK2(*data2)==(-1))//¼ìÑéÓÃ»§Ãû
                   {
                   Putbmp64k(184,339,"bmp\\kong1.bmp");
                   Putbmp64k(300,300,"bmp\\tishi22.bmp");
                          for(i=0;i<10;i++)
      {
      data2->bike_name[0]='\0';
      data2->bike_password[0]='\0';
      data2->bike_x[0]='\0';
      data2->bike_y[0]='\0';
      }
                   delay(2000);
                   Putbmp64k(0,0,"bmp\\yongche.bmp");
                   Putbmp64k_TMW(97,566,"bmp\\baoxiu2.bmp");
                   Putbmp64k_TMW(770,566,"bmp\\anniu2.bmp");
                   Putbmp64k_TMW(433,566,"bmp\\fh2.bmp");
                   }
                   else
                   {
                      read_BIK(data2,flag1);
                      data2->bike_repair[0]='1';
                      data2->bike_repair[1]='\0';
                      save_BIK3(*data2,flag1);
                            for(i=0;i<10;i++)
      {
      data2->bike_name[0]='\0';
      data2->bike_password[0]='\0';
      data2->bike_x[0]='\0';
      data2->bike_y[0]='\0';
      }
                       Putbmp64k(300,300,"bmp\\tishi23.bmp");
                       delay(1000);
                       Putbmp64k(0,0,"bmp\\yongche.bmp");
                       Putbmp64k_TMW(97,566,"bmp\\baoxiu2.bmp");
                       Putbmp64k_TMW(770,566,"bmp\\anniu2.bmp");
                       Putbmp64k_TMW(433,566,"bmp\\fh2.bmp");
                    }
            }
            if(Mouse_above(770,566,870,666))//确认
            {
                Newxy6();
                Putbmp64k_TMW(770,566,"bmp\\anniu1.bmp");
            }
            if(Mouse_press(770,566,870,666))
            {
                   read_BIK(data2,flag1);
                   if(strlen(data2->bike_name)==0)
                   {
                   Putbmp64k(184,339,"bmp\\kong1.bmp");
                   Putbmp64k(300,300,"bmp\\tishi17.bmp");
                       for(i=0;i<10;i++)
      {
      data2->bike_name[0]='\0';
      data2->bike_password[0]='\0';
      data2->bike_x[0]='\0';
      data2->bike_y[0]='\0';
      }
                   delay(2000);
                    Putbmp64k(0,0,"bmp\\yongche.bmp");
                    Putbmp64k_TMW(97,566,"bmp\\baoxiu2.bmp");
                    Putbmp64k_TMW(770,566,"bmp\\anniu2.bmp");
                    Putbmp64k_TMW(433,566,"bmp\\fh2.bmp");
                   }
                   else if(search_BIK2(*data2)==(-1))//¼ìÑéÓÃ»§Ãû
                   {
                   Putbmp64k(184,339,"bmp\\kong1.bmp");
                   Putbmp64k(300,300,"bmp\\tishi22.bmp");
                        for(i=0;i<10;i++)
      {
      data2->bike_name[0]='\0';
      data2->bike_password[0]='\0';
      data2->bike_x[0]='\0';
      data2->bike_y[0]='\0';
      }
                   delay(2000);
                    Putbmp64k(0,0,"bmp\\yongche.bmp");
                    Putbmp64k_TMW(97,566,"bmp\\baoxiu2.bmp");
                    Putbmp64k_TMW(770,566,"bmp\\anniu2.bmp");
                    Putbmp64k_TMW(433,566,"bmp\\fh2.bmp");
                   }
                   else if(data2->bike_repair[0]=='1')
                   {
                   Putbmp64k(184,339,"bmp\\kong1.bmp");
                   Putbmp64k(300,300,"bmp\\tishi24.bmp");
                       for(i=0;i<10;i++)
      {
      data2->bike_name[0]='\0';
      data2->bike_password[0]='\0';
      data2->bike_x[0]='\0';
      data2->bike_y[0]='\0';
      }
                   delay(2000);
                    Putbmp64k(0,0,"bmp\\yongche.bmp");
                    Putbmp64k_TMW(97,566,"bmp\\baoxiu2.bmp");
                    Putbmp64k_TMW(770,566,"bmp\\anniu2.bmp");
                    Putbmp64k_TMW(433,566,"bmp\\fh2.bmp");
                   }

                    else
                    {
                        // read_BIK(data2,flag1);
                        Putbmp64k(0,0,"bmp\\jiazai.bmp");
                        delay(2000);


                    Putbmp64k(0,0,"bmp\\kaisuo.bmp");
                    OutASC(data2->bike_password,180,65000,350,210,1024,768);

                    Putbmp64k(192,487,"bmp\\daoshu5.bmp");
                    delay(1000);
                    Putbmp64k(192,487,"bmp\\daoshu4.bmp");
                    delay(1000);
                    Putbmp64k(192,487,"bmp\\daoshu3.bmp");
                    delay(1000);
                    Putbmp64k(192,487,"bmp\\daoshu2.bmp");
                    delay(1000);
                    Putbmp64k(192,487,"bmp\\daoshu1.bmp");
                    delay(1000);
                    // Putbmp64k(0,0,"bmp\\ditu.bmp");
                    bikeuse(data2);
                    save_BIK3(*data2,flag1);
                        for(i=0;i<10;i++)
      {
      data2->bike_name[0]='\0';
      data2->bike_password[0]='\0';
      data2->bike_x[0]='\0';
      data2->bike_y[0]='\0';
      }
                    Putbmp64k(0,0,"bmp\\zhu.bmp");
                    return 1;
                    }

            }
            if(!Mouse_above(184,339,840,451)&&!Mouse_above(97,566,197,666)&&!Mouse_above(433,566,533,666)&&!Mouse_above(770,566,870,666))
            {
            Newxy();
            Putbmp64k_TMW(433,566,"bmp\\fh2.bmp");
            Putbmp64k_TMW(97,566,"bmp\\baoxiu2.bmp");
            Putbmp64k_TMW(770,566,"bmp\\anniu2.bmp");
            bicycle2(740,400,temp1);
            }
       }
}



void input_BIK(char *info2,int x,int y,int color)
{
    char *input= (char*)malloc(sizeof(char)*7);
    char key;
    int n=0;
    int i;
    int j;
    int k;


    for(i=0;i<=6;i++)
    {
        info2[i]='\0';
    }
    while(bioskey(1))
        bioskey(0);
    while(1)
    {
        if(kbhit()) //¼ì²éµ±Ç°¼üÅÌÊÇ·ñÓÐÊäÈë
        {
            key=bioskey(0);

            if('0'<=key&&key<='9')//ÓÃ»§ÃûÊäÈë¼°ÏÔÊ¾
            {

                    input[n]=key;
                    n++;
                    OutChar(input[n-1],size,x+n*size,y+22,0);
                    if(n>5)
                    {
                        input[n]='\0';
                        break;
                    }


            }
            if(!(('0'<=key&&key<='9')||(key==0xD)||(key==0x08)))
                continue;
            if(key==0x08 )                                               //ÍË¸ñ¼ü×÷ÓÃ´úÂë
            {
                if(n<1)
                    continue;
                n-=1;
                input[n]='\0';
                for(k=0;k<size;k++)
                {
                    for(j=0;j<size;j++)
                    {
                        Putpixel64k(x+(n+1)*size+k,y+(size/2)+2+j,color);
                    }
                }

            }
            else if(key==0xD)
            {
                input[n]='\0';
                break;           //»Ø³µÍË³ö
            }

        }
    }
    strcpy(info2,input);
    free(input);
}

int search_BIK(BIK info2)
{
    int i;
    int n;
    FILE *fp;
    BIK temp;
   fp=fopen("numedit4.txt","r+");

    fscanf(fp,"%d",&n);
    fclose(fp);
    for(i=0;i<n;i++)
    {
        read_BIK(&temp,i+1);
        if(!strcmp(info2.bike_name,temp.bike_name))
        {
            return 1;
        }
    }
     return 0;
}

int search_BIK2(BIK info2)
{
    int i;
    int n;
    FILE *fp;
    BIK temp;
   fp=fopen("numedit4.txt","r+");
    fscanf(fp,"%d",&n);
    fclose(fp);
    for(i=0;i<n;i++)
    {
        read_BIK(&temp,i+1);
        if(strcmp(info2.bike_name,temp.bike_name)==0)
        {
            return i;
        }
    }
    return(-1);
}


void read_BIK(BIK *info2,int n)          //  read(&info[2],2);                //¶ÁÎÄ¼þº¯Êý£¬¶¯Ì¬Éú³ÉÁ´±í£¬·µ»ØÁ´±íÍ·Ö¸Õë
{
    FILE *fp;
    int i;
    if((fp=fopen(".\\numedit5.txt","r+"))==NULL)
        exit(1);
for(i=0;i<10;i++)
{
    info2->bike_name[i]=0;
    info2->bike_password[i]=0;
    info2->bike_x[i]=0;
    info2->bike_y[i]=0;
    info2->bike_repair[i]=0;
    info2->bike_fee[i]=0;
}

    for(i=0;i<n;i++)
    {

        fscanf(fp,"%10s", info2->bike_name);
        fscanf(fp,"%10s", info2->bike_password);
        fscanf(fp,"%10s", info2->bike_x);
        fscanf(fp,"%10s", info2->bike_y);
        fscanf(fp,"%10s",info2->bike_repair);
        fscanf(fp,"%10s",info2->bike_fee);

    }
  fclose(fp);
}


void save_BIK(BIK info2)
{
    FILE *fp;
    int i;
    //char flag[2];

    if((fp=fopen(".\\numedit5.txt","r+"))==NULL)
        exit(1);
    fseek(fp,0L,2);



        fprintf(fp,"%10s   ",info2.bike_name);
        fprintf(fp,"%10s   ",info2.bike_password);
        fprintf(fp,"%10s   ",info2.bike_x);
        fprintf(fp,"%10s   ",info2.bike_y);
        fprintf(fp,"%10s   ",info2.bike_repair);
        fprintf(fp,"%10s\n",info2.bike_fee);




        fclose(fp);
}

// void save_BIK2(BIK info2,int flag)                          //±£´æÁ´±íµ½ÎÄ¼þ
// {
//     FILE *fp;
//     int i;
//     BIK temp;
//     BIK temp2;
//     if((fp=fopen(".\\numedit5.txt","r+"))==NULL)
//         exit(1);
//     if(flag==0)
//     {
//         // fprintf(fp,"%s   ",info.name);
//         // fprintf(fp,"%s\n",info.password);
//         fscanf(fp,"%s",temp2.bike_name);
//         fscanf(fp,"%s",temp2.bike_password);
//         fscanf(fp,"%s",temp2.bike_x);
//         fscanf(fp,"%s",temp2.bike_y);
//         fprintf(fp,"   %s   ",info2.bike_repair);
//         fprintf(fp,"%s\n",info2.bike_fee);



//     }
//     else
//     {
//         for(i=0;i<=flag-1;i++)
//         {
//             // fscanf(fp,"%s",temp.name);
//             // fscanf(fp,"%s",temp.password);
//             fscanf(fp,"%s",temp.bike_name);
//             fscanf(fp,"%s",temp.bike_password);
//             fscanf(fp,"%s",temp.bike_x);
//             fscanf(fp,"%s",temp.bike_y);
//             fscanf(fp,"%s",temp.bike_repair);
//             fscanf(fp,"%s",temp.bike_fee);



//         }
//         // fprintf(fp,"%s   ",info.name);
//         // fprintf(fp,"%s\n",info.password);
//         fscanf(fp,"%s",temp.bike_name);
//         fscanf(fp,"%s", temp.bike_password);
//         fscanf(fp,"%s", temp.bike_x);
//         fscanf(fp,"%s   ", temp.bike_y);
//         fseek(fp,0L,1);
//         fprintf(fp,"%s   ",info2.bike_repair);
//         fprintf(fp,"%s",info2.bike_fee);
//      //   fprintf(fp,"%s   ","zxcvbn");
//       //  fprintf(fp,"%s\r\n","yuiopo");
//         // fprintf(fp,"%1s",";");
//     }
//     fclose(fp);
// }

void save_BIK3(BIK info2,int flag)                          //±£´æÁ´±íµ½ÎÄ¼þ
{
    FILE *fp;
    int i;
    BIK temp;
    if((fp=fopen(".\\numedit5.txt","r+"))==NULL)
        exit(1);
    if(flag-1==0)
    {
        fseek(fp,0L,0);
        fprintf(fp,"%10s   ",info2.bike_name);
        fprintf(fp,"%10s   ",info2.bike_password);
        fprintf(fp,"%10s   ",info2.bike_x);
        fprintf(fp,"%10s   ",info2.bike_y);
        fprintf(fp,"%10s   ",info2.bike_repair);
        fprintf(fp,"%10s",info2.bike_fee);



    }
    else
    {
        for(i=0;i<flag-1;i++)
        {
            // fscanf(fp,"%s",temp.name);
            // fscanf(fp,"%s",temp.password);
            fscanf(fp,"%10s",temp.bike_name);
            fscanf(fp,"%10s",temp.bike_password);
            fscanf(fp,"%10s",temp.bike_x);
            fscanf(fp,"%10s",temp.bike_y);
            fscanf(fp,"%10s",temp.bike_repair);
            fscanf(fp,"%10s",temp.bike_fee);
        }
        // fprintf(fp,"%s   ",info.name);
        // fprintf(fp,"%s\n",info.password);
        fscanf(fp,"%10s",temp.bike_name);
        fscanf(fp,"%10s",temp.bike_password);
        fseek(fp,0L,1);
        fprintf(fp,"   %10s",info2.bike_x);
        fprintf(fp,"   %10s",info2.bike_y);
        fprintf(fp,"   %10s",info2.bike_repair);
        fprintf(fp,"   %10s",info2.bike_fee);
    }

    fclose(fp);
}



int bike_sq1(void)  //返回
{
    Newxy2();
    Linex(157,646,242,646,60000);
    Liney(157,646,157,700,60000);
    Linex(157,700,242,700,60000);
    Liney(242,646,242,700,60000);
    return 0;
}

int bike_sq2(void)  //清除
{
    Newxy2();
    Linex(440,646,528,646,60000);
    Liney(440,646,440,700,60000);
    Linex(440,700,528,700,60000);
    Liney(528,646,528,700,60000);
    return 0;
}

int bike_sq3(void)  //确定
{
    Newxy2();
    Linex(746,646,835,646,60000);
    Liney(746,646,746,700,60000);
    Linex(746,700,835,700,60000);
    Liney(835,646,835,700,60000);
    return 0;
}


