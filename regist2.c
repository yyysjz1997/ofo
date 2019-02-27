#include "regist2.h"

void Register()  //注册的函数
{

    /*状态参数，用于判断用户名和密码是否成功获取*/
    int k[2];

    /*用于存储用户的用户名和密码*/
    char reg[2][20];

    /*用于存储注册时再一次输入时的密码值*/
    char check_password[1][20];

    char mima;

    int temp2=0;
    Initmouse(0,1024,0,768);
    Putbmp64k(0,0,"bmp\\denglu2.bmp");
    temp2=Getpixel64k(1000,10);

    /*该循环用于进行用户的注册，当点击确定或退出按钮之后推出循环*/
    while(1)
    {


        /*如果鼠标位于输入用户名的方框内，则进行输入用户名的操作*/
        if(Mouse_above(327,151,794,249))
        {
           Newxy3();
        }

        /*如果点击了鼠标,则进行用户名的输入*/
        if(Mouse_press(327,151,794,249))
        {
            k[0]=InputInformation(327,794,151,249,0,reg);
        }

        /*如果鼠标位于输入密码的方框内,则进行输入密码的操作*/
        if(Mouse_above(327,290,794,388))
        {
           Newxy3();
        }

        /*如果点击了鼠标,则进行密码的输入*/
        if(Mouse_press(327,290,794,388))
        {
            k[1]=InputInformation(327,794,290,388,1,reg);
        }

        if(Mouse_above(327,429,794,527))//确认密码框
        {
            Newxy3();
        }
        if(Mouse_press(327,429,794,527))
        {
            mima=InputInformation(327,794,429,527,1,check_password);  //输入密码
            // OutASC(data->name,48,65500,0,0,1000,600);
            // OutASC(data->password,48,65500,0,300,1000,600);
            // OutASC(check_password,48,65500,0,600,1000,800);
            if(strcmp(mima,k[1]))
            {
                Putbmp64k(327,151,"bmp\\kong.bmp");
                Putbmp64k(327,290,"bmp\\kong.bmp");
                Putbmp64k(327,429,"bmp\\kong.bmp");
                Putbmp64k(300,300,"bmp\\tishi2.bmp");
            }
        }

        /*清除按钮*/
        if(Mouse_above(431,581,524,631))
        {
            a7();
        }
        if(Mouse_press(431,581,524,631))
        {
            //Newxy2();
            Putbmp64k(327,151,"bmp\\kong.bmp");
            Putbmp64k(327,290,"bmp\\kong.bmp");
            Putbmp64k(327,429,"bmp\\kong.bmp");
        }

        /*如果点击了确定按钮，当信息输入成功时，则写入文件，不成功时，退回到信息输入界面*/
        if(Mouse_above(702,582,793,632))
        {
            a5();
        }
        if(Mouse_press(702,582,793,632))
        {
            if(strlen(reg[1])==0)
            {
                Putbmp64k(327,151,"bmp\\kong.bmp");
                Putbmp64k(327,290,"bmp\\kong.bmp");
                Putbmp64k(327,429,"bmp\\kong.bmp");
                Putbmp64k(300,300,"bmp\\tishi6.bmp");
                break;
            }
            // if(search(info,data)==1)//检验用户名是否已经存在
            // {
            //     Putbmp64k(327,151,"bmp\\kong.bmp");
            //     Putbmp64k(327,290,"bmp\\kong.bmp");
            //     Putbmp64k(327,429,"bmp\\kong.bmp");
            //     Putbmp64k(300,300,"bmp\\tishi7.bmp");
            //     break;
            // }
            if(strlen(reg[2])==0)
            {
                Putbmp64k(327,151,"bmp\\kong.bmp");
                Putbmp64k(327,290,"bmp\\kong.bmp");
                Putbmp64k(327,429,"bmp\\kong.bmp");
                Putbmp64k(300,300,"bmp\\tishi5.bmp");
                break;
            }

            /*如果用户名和密码都已成功获取，则将其写入文件*/
            else
            {
                if(k[0]==1&&k[1]==1)
                {

                    /*如果成功写入文件*/
                    if(Putfile(reg))
                    {
                        Putbmp64k(300,300,"bmp\\tishi3.bmp");
                        delay(1000);
                        Initmouse(0,1024,0,768);
                        Putbmp64k(0,0,"bmp\\zhu.bmp");
                        return 0;
                    }
                }
            }




            readbmp(0,0,"pic\\begin.bmp");
            readbmp_for_Logic_Without_Color(212,0,"pic\\anim\\word.bmp",0);
            InterFace(info,mouse);  /*退回到开始界面*/

            break;
        }

        /*如果点击了退出按钮，则直接退回到上一界面*/
        if(Mouse_above(189,584,272,631))         //退出
        {
            a6();
        }
        if(Mouse_press(189,584,272,631))         //按下左键
        {
            Initmouse(0,1024,0,768);//必须加
            Putbmp64k(0,0,"bmp\\zhu.bmp");
            return 0;
        }

        /*如果鼠标位于其他位置，则显示鼠标*/
       if(!Mouse_above(327,151,794,249)&&!Mouse_above(327,290,794,388)&&!Mouse_above(327,429,794,527)&&!
            Mouse_above(431,581,524,631)&&!Mouse_above(702,582,793,632)&&!Mouse_above(189,584,272,631))
        {
            Newxy();

            Linex(702,582,793,582,temp3);
            Liney(702,582,702,632,temp3);
            Linex(702,632,793,632,temp3);
            Liney(793,582,793,632,temp3);

            Linex(189,584,272,584,temp3);
            Liney(189,584,189,631,temp3);
            Linex(189,631,272,631,temp3);
            Liney(272,584,272,631,temp3);

            Linex(431,581,524,581,temp3);
            Liney(431,581,431,631,temp3);
            Linex(431,631,524,631,temp3);
            Liney(524,581,524,631,temp3);

        }

    }
}
/**********************************************************
Function：       InputInformation

Description：    用户信息输入函数，获取用户输入的用户名和密码，并存储到reg中

Input：          int x1      用户信息输入方框的横坐标最小值
                int x2      用户信息输入方框的横坐标最大值
                int y1      用户信息输入方框的纵坐标最小值
                int y2      用户信息输入方框的纵坐标最大值
                int pan     0表示进行用户名输入，1表示进行密码输入

                char reg[][20]
                            用户登录信息，用户名保存在reg[0]中
                            密码保存在reg[1]中
                MOUSE *mouse 鼠标变量

Output：     获取用户输入的用户名和密码

Return：     状态参数，0表示获取信息失败，1表示获取信息成功

Others：     None
**********************************************************/
int InputInformation(int x1,int x2,int y1,int y2,int pan,char reg[][20])
{

    /*用于获取输入的字符*/
    char ac;

    /*将获取的字符赋值给zac[0],进行输出*/
    char zac[2]={'\0'};

    /*用于记录输入字符的个数*/
    int n1=0;

    /*用于记录输出字符的位置*/
    int n2=x1+1;

    /*清除键盘缓存*/
    while(bioskey(1))
    {
        getch();
    }

    /*该循环用于获取用户输入的信息，当输入回车键时退出循环*/
    while((ac=getch())!=13)
    {
        /*如果当前输入用户名，则直接输出字符*/
        if(pan==0)
        {
            /*如果当前位置位于方框范围内，则进行输入操作*/
            if((n2>x1)&&(n2<(x2-21)))
            {
                /*如果输入字母和数字时，则将其获取输出*/
                if(((ac>='0')&&(ac<='9'))||((ac>='a')&&(ac<='z')))
                {
                    /*进行赋值操作*/
                    zac[0]=ac;
                    reg[pan][n1++]=ac;

                    /*进行输出*/

                    OutASC(zac,size,0,x,y,1024,768);

                    /*调整下一字符输出的位置*/
                    n2+=15;
                }

                // /*如果输入“Backspace”键,则后退一步*/
                // else if(ac==8&&n1>=1)
                // {
                //     n1--;
                //     n2-=15;

                //     /*画出矩形覆盖已输入字符*/
                //     bar_(n2+8,y1+1,n2+23,y1+18,-1);
                // }
            }
        }
        /*如果当前输入密码，则输出圆圈*/
        else if(pan==1)
        {
            /*如果当前位置位于方框范围内，则进行输入操作*/
            if((n2>x1)&&(n2<(x2-21)))
            {
                /*如果输入字母和数字时，则将其获取输出*/
                if(((ac>='0')&&(ac<='9'))||((ac>='a')&&(ac<='z')))
                {
                    /*进行赋值操作*/
                    zac[0]=ac;
                    reg[pan][n1++]=ac;

                    OutASC(zac,size,0,x,y,1024,768);

                    /*调整下一字符输出的位置*/
                    n2+=15;
                }

                // /*如果输入“Backspace”键,则后退一步*/
                // else if(ac==8&&n1>=1)
                // {
                //     n1--;
                //     n2-=15;

                //     /*画出矩形覆盖已输入字符*/
                //     bar_(n2+8,y1+1,n2+23,y1+18,-1);
                // }
            }
        }
    }

    reg[pan][n1]='\0';

    /*如果字符数不是在4-7位，则返回0，输入失败*/
    if(!(n1>=4&&n1<=7))
    {
        return 0;
    }

    return 1;
}
/**********************************************************
Function：       Putfile

Description：    将InputInformation中获取的用户名和密码写入文件

Input：          char reg[][20]
                            用户登录信息，用户名保存在reg[0]中
                            密码保存在reg[1]中
                INFO *info  房间信息
                MOUSE *mouse    鼠标变量

Output：     将用户信息写入文件

Return：     状态参数，0表示用用户名已存在写入失败，1表示写入成功

Others：     None
**********************************************************/
int Putfile(char reg[][20])
{
    /*文件指针*/
    FILE *fp;

    /*用于存储用户信息*/
    char userinfor[40];

    /*用于获得文件路径*/
    char path[12]={'\0'},newpath[25];
    char str[]=".txt";

    /*用于记录字符位置*/
    int n1;

    /*用于计数*/
    int i;

    /*获取当前文件路径,存入newpath*/
    strcpy(path,reg[0]);
    strcat(path,str);
    strcpy(newpath,"text\\");
    strcat(newpath,path);

    n1=0;

    /*该循环用于获取用户名，当获取完成时退出*/
    for(i=0;reg[0][i]!='\0';n1++,i++)
    {
       userinfor[n1]=reg[0][i];
    }
    userinfor[n1++]='=';

    /*该循环用于获取密码,当获取完成时退出*/
    for(i=0;reg[1][i]!='\0';n1++,i++)
    {
        userinfor[n1]=reg[1][i];
    }
    userinfor[n1++]='=';
    userinfor[n1]='\0';

    /*如果当前文件已存在，则写入失败，返回0值*/
    if((fp=fopen(newpath,"rb"))!=NULL)
    {
        Putbmp64k(300,300,"bmp\\tishi9.bmp");
        delay(1000);
        fclose(fp);
        return 0;
    }

    /*如果当前文件不存在，则将当前用户信息写入文件*/
    else if((fp=fopen(newpath,"wt+"))==NULL)
    {
        getch();
    }

    n1=0;

    while(userinfor[n1]!='\0')
    {
        fputc(userinfor[n1],fp);
        n1++;
    }

    fclose(fp);

    return 1;

}

void Login()
{
    /*文件指针*/
    FILE *fp;

    /*获取文件路径*/
    char *str=".txt";
    char path[15]={'\0'} ,newpath[30];

    /*用于存储用户的密码和用户名*/
    char account[15],password[15];

    // /*打开用户信息输入界面*/
    // readbmp(264,254,"pic\\login.bmp");

    /*用户进行输入，将填入的用户名存入account,密码存入password*/
    Input(account,password);

    /*获取文件路径，存入newpath*/
    strcpy(path,account);
    strcat(path,str);
    strcpy(newpath,"text\\");
    strcat(newpath,path);

    /*如果用户名不存在，则登录失败*/
    if((fp=fopen(newpath,"rb"))==NULL)
    {
        fclose(fp);


        delay(2000);
    }

    /*如果用户名存在，则判断密码是否正确*/
    else
    {
        fclose(fp);
        Putbmp64k(300,300,"bmp\\tishi8.bmp");
        /*如果密码正确，则修改当前登录状态*/
        if(!JudgePassword(password,newpath))   //判断密码是否正确
        {

            Putbmp64k(300,300,"bmp\\tishi1.bmp");
            delay(2000);
        }
    }

    /*读取开始界面的图片*/
    Putbmp64k(0,0,"bmp\\yongche.bmp");



}
/**********************************************************
Function：       Input

Description：    用户信息输入函数
                输入用户的用户名和密码

Input：          INFO *info  房间信息
                char *account
                            用户名
                char *password
                            密码
                MOUSE *mouse
                            鼠标变量

Output：     将用户输入的用户名存入account
                密码存入password

Return：     None

Others：     None
**********************************************************/
void Input(char *account,char *password)
{

    int temp2=0;

    /*临时存储用户名和密码*/
    char log[2][20]={'\0','\0'};

    Initmouse(0,1024,0,768);
    Putbmp64k(0,0,"bmp\\denglu2.bmp");
    temp2=Getpixel64k(1000,10);


    while(1)
    {
        if(Mouse_above(452,529,540,581))
        {
            a2();
        }
        if(Mouse_press(452,529,540,581))
        {
            //Newxy2();
            Putbmp64k(305,190,"bmp\\kong.bmp");
            Putbmp64k(305,361,"bmp\\kong.bmp");
        }
        if(Mouse_above(570,671,732,712))        //新用户注册
        {
            a1();
        }
        if(Mouse_press(570,671,732,712))
        {

            Register();

            break;
        }

        if(Mouse_above(305,190,772,288)) //输入用户名
        {
            Newxy3();
        }
        if(Mouse_press(305,190,772,288))
        {
            InputInformation(305,772,190,288,0,log);
            strcpy(account,log[0]);
        }
        if(Mouse_above(305,363,772,461)) //输入密码
        {
            Newxy3();
        }
        if(Mouse_press(305,363,772,461))
        {
            InputInformation(305,772,363,461,1,log);
            strcpy(password,log[1]);
        }
        if(Mouse_above(723,525,815,578))
        {
            a3();
        }
        if(Mouse_press(723,525,815,578))   //点击确定
        {
           Putbmp64k(0,0,"bmp\\yongche.bmp");
        }
        // else if(mouse->pos_x>526&&mouse->pos_x<611&&mouse->pos_y>448&&mouse->pos_y<478&&mouse->button==1)   //点击忘记密码
        // {
        //     free(buf);
        //     ForgetPassword(info,mouse);
        //     break;
        // }
        if(Mouse_above(126,532,328,578))         //返回主页面
        {
            a4();
        }
        if(Mouse_press(126,532,328,578))         //按下左键
        {
            //Newxy2();
            Initmouse(0,1024,0,768);
            Putbmp64k(0,0,"bmp\\zhu.bmp");
            return 0;
        }
        if(!Mouse_above(305,190,772,288)&&!Mouse_above(305,363,772,461)&&!Mouse_above(570,671,732,712)
            &&!Mouse_above(452,529,540,581)&&!Mouse_above(723,525,815,578)&&!Mouse_above(126,532,328,578))
        {
            Newxy();
            Linex(570,671,732,671,temp2);
            Liney(570,671,570,712,temp2);
            Linex(570,712,732,712,temp2);
            Liney(732,671,732,712,temp2);

            Linex(452,529,540,529,temp2);
            Liney(452,529,452,581,temp2);
            Linex(452,581,540,581,temp2);
            Liney(540,529,540,581,temp2);

            Linex(723,525,815,525,temp2);
            Liney(723,525,723,578,temp2);
            Linex(723,578,815,578,temp2);
            Liney(815,525,815,578,temp2);

            Linex(126,532,328,532,temp2);
            Liney(126,532,126,578,temp2);
            Linex(126,578,328,578,temp2);
            Liney(328,532,328,578,temp2);

        }



    }
}
// /**********************************************************
// Function：       Input1

// Description：    用户信息输入函数
//                 用于忘记密码时输入用户的用户名和密码

// Input：          INFO *info  房间信息
//                 char *account
//                             用户名
//                 char *password
//                             密码
//                 MOUSE *mouse
//                             鼠标变量

// Output：     将用户输入的用户名存入account
//                 密码存入password

// Return：     None

// Others：     None
// **********************************************************/
// void Input1(char *account,char *password,INFO *info,MOUSE *mouse)
// {
//     /*用于鼠标*/
//     void *buf;

//     /*临时存储用户的信息*/
//     char reg[2][20]={'\0','\0'};

//     buf=malloc(32*32*2);

//     /*该循环用于输入用于信息，当信息输入完成时退出*/
//     while(1)
//     {
//         /*获取鼠标位置*/
//         mouse_position(mouse);

//         /*绘制鼠标*/
//         drawmouse(mouse);

//         /*如果鼠标位于输入用户名的位置，则进行用户名输入*/
//         if(mouse->pos_x>507&&mouse->pos_x<632&&mouse->pos_y>349&&mouse->pos_y<368)
//         {
//             mouse_recover(mouse);
//             MouseShape(buf);
//             if(mouse->button==1)
//             {
//                 InputInformation(507,632,349,368,0,reg,mouse);
//                 strcpy(account,reg[0]);
//             }
//             mouse_reset(mouse);

//         }

//         /*如果鼠标位于输入密码的位置，则进行密码的输入*/
//         else if(mouse->pos_x>507&&mouse->pos_x<632&&mouse->pos_y>392&&mouse->pos_y<413)
//         {
//             mouse_recover(mouse);
//             MouseShape(buf);
//             if(mouse->button==1)
//             {
//                 InputInformation(507,632,392,413,1,reg,mouse);
//                 strcpy(password,reg[1]);
//                 if(!(strlen(password)>=4&&strlen(password)<=15))
//                 {
//                     readbmp(264,254,"pic\\fail1.bmp");
//                     delay(2000);
//                     ForgetPassword(info,mouse);
//                     break;
//                 }
//             }
//             mouse_reset(mouse);

//         }

//         /*如果点击了确定按钮，则退出*/
//         else if(mouse->pos_x>639&&mouse->pos_x<724&&mouse->pos_y>448&&mouse->pos_y<478&&mouse->button==1)   //点击确定
//         {

//             free(buf);
//             break;
//         }

//         /*如果点击了退出按钮，则退出*/
//         else if(mouse->pos_x>723&&mouse->pos_x<754&&mouse->pos_y>254&&mouse->pos_y<273&&mouse->button==1)   //点击退出按钮
//         {

//             free(buf);

//             readbmp(0,0,"pic\\begin.bmp");
//             readbmp_for_Logic_Without_Color(212,0,"pic\\anim\\word.bmp",0);
//             InterFace(info,mouse);
//             break;
//         }



//     }
// }
/**********************************************************
Function：       JudgePassword

Description：    判断密码函数
                用于用户输入密码是否正确

Input：          char *password  用户密码
                char *path      文件路径

Output：     None

Return：     若密码正确，则返回1
                若密码错误，则返回0
**********************************************************/
int JudgePassword(char *password,char *path)
{
    /*文件指针*/
    FILE *fp;

    /*用于存储用户的密码*/
    char userpassword[32];

    /*循环变量*/
    int i;

    /*指向'='第一次出现的位置*/
    char *p1;

    /*指向'=’第二次出现的位置*/
    char *p2;

    fp=fopen(path,"rt");
    fread(userpassword,64,1,fp);

    /*获取用户的原密码*/
    p1=strchr(userpassword,'=');
    p1++;
    p2=strchr(p1,'=');
    for(i=0;p2-p1>0;p1++,i++)
    {
        userpassword[i]=*p1;
    }
    userpassword[i]='\0';

    fclose(fp);

    /*如果密码正确，则返回1*/
    if(strcmp(password,userpassword)==0)
    {
        return 1;
    }

    /*如果密码错误，则返回0*/
    else
    {
        return 0;
    }

}
// /**********************************************************
// Function：       ForgetPassword

// Description：    忘记密码函数
//                 用于用户忘记密码时进行的操作

// Input：          INFO *info      房间信息
//                 MOUSE *mouse    鼠标变量

// Output：     None

// Return：     None
// **********************************************************/
// void ForgetPassword(INFO *info,MOUSE *mouse)
// {
//     /*文件指针*/
//     FILE *fp;

//     /*文件路径*/
//     char *str=".txt";
//     char path[15]={'\0'} ,newpath[30];
//     char account[15],password[15];

//     readbmp(264,254,"pic\\forget.bmp");
//     mouse_reset(mouse);

//     /*输入用户的用户名和密码*/
//     Input1(account,password,info,mouse);

//     /*获取文件路径*/
//     strcpy(path,account);
//     strcat(path,str);
//     strcpy(newpath,"text\\");
//     strcat(newpath,path);

//     /*如果用户名不存在，则返回*/
//     if((fp=fopen(newpath,"rb"))==NULL)
//     {

//         readbmp(264,254,"pic\\non.bmp");
//         delay(2000);
//     }

//     /*如果用户名存在，则进行修改密码操作*/
//     else
//     {
//         ReviseFile(account,password,newpath);

//         readbmp(264,254,"pic\\revised.bmp");

//         delay(2000);
//     }

//     fclose(fp);

//     readbmp(0,0,"pic\\begin.bmp");
//     readbmp_for_Logic_Without_Color(212,0,"pic\\anim\\word.bmp",0);
//     InterFace(info,mouse);
// }
// /**********************************************************
// Function：       ReviseFile

// Description：    修改密码函数

// Input：          char *account       用户名
//                 char *password      密码
//                 char *newpath       文件路径

// Output：     None

// Return：     None
// **********************************************************/
// void ReviseFile(char *account,char *password,char *newpath)//该函数用于修改密码
// {
//     /*循环变量*/
//     int n=0;

//     /*文件指针*/
//     FILE *fp;

//     /*临时存放信息*/
//     char *info;

//     /*将用户信息存入info*/
//     strcpy(info,account);
//     strcat(info,"=");
//     strcat(info,password);
//     strcat(info,"=");

//     fp=fopen(newpath,"wt+");

//     /*将信息写入文件*/
//     while(info[n]!='\0')
//     {
//         fputc(info[n],fp);
//         n++;
//     }
//     fclose(fp);
// }


int a1(void)   //登录 --新用户注册
{
    Newxy2();
    Linex(570,671,732,671,60000);
    Liney(570,671,570,712,60000);
    Linex(570,712,732,712,60000);
    Liney(732,671,732,712,60000);
    return 0;
}

int a2(void)   //登录 --清除键
{
    Newxy2();
    Linex(452,529,540,529,60000);
    Liney(452,529,452,581,60000);
    Linex(452,581,540,581,60000);
    Liney(540,529,540,581,60000);
    return 0;
}

int a3(void)  //登录 --确认键
{
    Newxy2();
    Linex(723,525,815,525,60000);
    Liney(723,525,723,578,60000);
    Linex(723,578,815,578,60000);
    Liney(815,525,815,578,60000);
    return 0;
}

int a4(void)  //登录 --返回主界面键
{
    Newxy2();
    Linex(126,532,328,532,60000);
    Liney(126,532,126,578,60000);
    Linex(126,578,328,578,60000);
    Liney(328,532,328,578,60000);
    return 0;
}

int a5(void)   //注册 --确定
{
    Newxy2();
    Linex(702,582,793,582,60000);
    Liney(702,582,702,632,60000);
    Linex(702,632,793,632,60000);
    Liney(793,582,793,632,60000);
    return 0;
}

int a6(void)  //注册 --退出
{
    Newxy2();
    Linex(189,584,272,584,60000);
    Liney(189,584,189,631,60000);
    Linex(189,631,272,631,60000);
    Liney(272,584,272,631,60000);
    return 0;
}

int a7(void)  //注册 --清除
{
    Newxy2();
    Linex(431,581,524,581,60000);
    Liney(431,581,431,631,60000);
    Linex(431,631,524,631,60000);
    Liney(524,581,524,631,60000);
    return 0;
}