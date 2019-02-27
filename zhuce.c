#include "zhuce.h"


void clear(char *p,int x,int y);
void free_link(PER *head);
void save(PER *head);
void read(PER *head);
int search(PER *info,PER *data,char flag);
void inputs(char *p,int x,int y,int flag);
void zhuce(PER *info,PER *data);
void login(struct mousemsg *mouse,struct system *syst,PER *data);

void login(struct mousemsg *mouse,struct system *syst,PER *data)
{
    PER *info;
    PER *head;
    // short far *save_corr;
    // short far *save_save;
    int n;

    // if((save_corr=(short far *)malloc(30*30*2))==NULL)
    //     return;
    // if((save_save=(short far *)malloc(30*30*2))==NULL)
    //     return;
    if((head=(PER*)malloc(sizeof(PER)))==NULL)
        return;
    read(head);
    info=head->next;

    Putbmp64k(0,0,"bmp\\denglu.bmp");

    Newxy();

    while(1)
    {
        if(Mouse_above(0,0,0,0))//用户名框
        {
           Newxy3();
        if(Mouse_press(0,0,0,0))//在框内按下左键
        {
                //mouse_recover(mouse,syst);    //不显示光标
                inputs(data->name,335,434,0);    //输入账号
                //mouse_reset(mouse,1,syst);
        }
        else if(Mouse_above(0,0,0,0))//密码框
        {
           Newxy3();
        if(Mouse_press(0,0,0,0))
        {
                //mouse_recover(mouse,syst);
                inputs(data->password,335,532,1);                                              //输入密码
                //mouse_reset(mouse,1,syst);
        }
        else if(Mouse_above(0,0,0,0))        //注册
        {
            Newxy2();
            if(Mouse_press(0,0,0,0))
            {
                zhuce(info,data);
                data->next=head->next;
                head->next=data;
                save(head);
                break;
            }
        }

        else if(Mouse_above(0,0,0,0))      //确认
        {
            Newxy2();
            if(Mouse_press(0,0,0,0))
            {
                if(strlen(data->name)==0)
                {
                    clear(data->name,335,434);
                }
                else if(search(info,data,1)==0)//检验用户名
                {
                    clear(data->name,335,434);
                }
                else if(strlen(data->password)==0)
                {
                    clear(data->password,335,532);
                }
                else if(search(info,data,2)==0)//检验密码
                {
                    clear(data->password,335,532);
                }
                else
                {
                    save(head);
                    break;
                }

            }

        }
        else if(Mouse_above(0,0,0,0))         //退出
        {
            Newxy3();
            if(Mouse_press(0,0,0,0))         //按下左键
                Initmouse(0,1024,0,768);
                Putbmp64k(0,0,"bmp\\zhu.bmp");
                return 0;
        }
        else
        {
          Newxy();
        }
        //mouse_position(mouse);
    }
    free_link(&head);
  }


void zhuce(PER *info,PER *data)
{

    char check_password[7],num[20]="bmp\\";
    int flag=0;
    //SetSVGA64k();
    Putbmp64k(0,0,"bmp\\zhuce.bmp");
    Initmouse(0,1024,0,768);
    while(1)
    {
        if(Mouse_above(0,0,0,0))//用户名框
        {
            Newxy3();
            if(Mouse_press(0,0,0,0))//在框内按下左键
            {
                //mouse_recover(mouse,syst);    //不显示光标
                inputs(data->name,336,79,0);    //输入账号
                //mouse_reset(mouse,1,syst);
            }
        }
        else if(Mouse_above(0,0,0,0))//密码框
        {
            Newxy3();
            if(Mouse_press(0,0,0,0))
            {
                //mouse_recover(mouse,syst);
                inputs(data->password,336,205,1);                                              //输入密码
                //mouse_reset(mouse,1,syst);
            }
        }
        else if(Mouse_above(0,0,0,0))//确认密码框
        {
            Newxy3();
            if(Mouse_press(0,0,0,0))
            {
                //mouse_recover(mouse,syst);
                inputs(check_password,336,338,1);                                              //输入密码
                if(!strcmp(check_password,data->password))
                {
                    clear(data->password,335,205);
                    clear(data->password,335,338);
                }
                //mouse_reset(mouse,1,syst);
            }
        }
        else if(Mouse_above(0,0,0,0))      //确认
        {
            Newxy2();
            if(Mouse_press(0,0,0,0))
            {
                if(strlen(data->name)==0)
                {
                    clear(data->name,335,79);
                }
                else if(search(info,data,1)==1)//检验用户名是否已经存在
                {
                    clear(data->name,335,79);
                }
                else if(strlen(data->password)==0)
                {
                    clear(data->password,335,205);
                    clear(data->password,335,338);
                }
                else
                    break;
            }

        }
        else if(Mouse_above(0,0,0,0))         //退出
        {
            Newxy2();
            if(Mouse_press(0,0,0,0))         //按下左键
                Initmouse(0,1024,0,768);
                Putbmp64k(0,0,"bmp\\zhu.bmp");
                return 0;
        }
        else
        {
          Newxy();
        }
        //mouse_position(mouse);
    }
}


void inputs(char *p,int x,int y,int flag)      //数字输入函数，输入可为空,flag:0为可视，1为不可视
{
    char input[7]={0,0,0,0,0,0,0},z[2],key;
    int n=0,color;
    char num[20]="bmp\\";
    int i,j;
    SetSVGA64k();
    while(bioskey(1))
        bioskey(0);
    while(1)
    {
        if(kbhit()) //检查当前键盘是否有输入
        {
            key=bioskey(0);
            z[0]=key;
            z[1]='\0';
            if(('0'<=key&&key<='9')||('a'<=key&&key<='z'))//用户名输入及显示
            {
                if(flag==0)
                {
                    strcat(num,z);
                    strcat(num,".bmp");
                    input[n]=key;
                    Putbmp64k(x+n*35,y,num);
                    n++;
                    strcpy(num,"bmp\\");
                    if(n>5)
                    {
                        input[n]='\0';
                        break;
                    }
                }
                else
                {
                    input[n]=key;
                    Putbmp64k(x+n*35,y,".\\bmp\\password.bmp");
                    n++;
                    if(n>5)
                    {
                        input[n]='\0';
                        break;
                    }
                }

            }
            if(!(('0'<=key&&key<='9')||('a'<=key&&key<='z')||(key==0xD)||(key==0x08)))
                continue;
            if(key==0x08 )                                               //退格键作用代码
            {
                if(n<1)
                    continue;
                n-=1;
                input[n]='\0';
                for(i=0;i<30;i++)
                    for(j=0;j<36;j++)
                        Putpixel64k(x+n*35+i,y+j,0xffff);

            }
            else if(key==0xD)
            {
                input[n]='\0';
                break;                                          //回车退出
            }

        }
    }
    strcpy(p,input);
}


// int search(PER *info,PER *data,char flag)
// {
//     if(flag==1)
//     {
//          while(info!=NULL)
//         {
//             if(!strcmp(data->name,info->name))
//                 break;
//             info=info->next;
//         }
//         if(info==NULL)
//             return 0;
//         else
//             return 1;
//     }                                                                           //1代表找到相同的
//     else if(flag==2)
//     {
//          while(info!=NULL)
//         {
//             if((!strcmp(data->name,info->name))&&(!strcmp(data->password,info->password)))
//                 break;
//             info=info->next;
//         }
//         if(info==NULL)
//             return 0;
//         else
//             return 1;

//     }
//     return -1;
// }

// void read(PER *head)                            //读文件函数，动态生成链表，返回链表头指针
// {
//     FILE *fp;
//     char flag[2];
//     char p[10];
//     PER *info=(PER *)malloc(sizeof(PER));
//     head->next=info;
//     if((fp=fopen("\\yh.txt","rt"))==NULL)
//         exit(1);
//     for(;(fgetc(fp))!=EOF;)
//     {

//             fscanf(fp,"%7s", info->name);
//             fscanf(fp,"%7s", info->password);

//             fscanf(fp,"%2s", p );
//             if(fgetc(fp)!=EOF)  //检验是否到文件尾
//             {
//                 info->next=(PER *)malloc(sizeof(PER));
//                 info=info->next;
//             }
//     }
//     info->next=NULL;
//     fclose(fp);
// }
// void save(PER *head)                          //保存链表到文件
// {
//     FILE *fp;
//     char flag[2];
//     if((fp=fopen("\\yh.txt","wt"))==NULL)
//         exit(1);
//     head=head->next;
//     while(head!=NULL)
//     {

//         fprintf(fp,"%7s",head->name);
//         fprintf(fp,"%7s",head->password);

//         fprintf(fp,"%2s", ";");
//         head=head->next;
//     }
//     fclose(fp);
// }

// void free_link(PER *head)                          //释放链表
// {
//     while((head)!=NULL)
//     {
//         head=head->next;
//         free(head);

//     }
// }

// void clear(char *p,int x,int y)          //清除输入框函数
// {
//     int n,i,j;
//     strcpy(p,"\0");
//     for(n=0;n<6;n++)
//     {
//         for(i=0;i<30;i++)  //字符大小
//         {
//             for(j=0;j<36;j++)
//             {
//                 Putpixel64k(x+n*35+i,y+j,0xffff);
//             }
//         }
//     }
// }
