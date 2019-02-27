#include "regist.h"

int regist(PER *info,PER *data)
{
    int temp3=0;
    char check_password[7];
    Initmouse(0,1024,0,768);
    Putbmp64k(0,0,"bmp\\zhuce.bmp");

    temp3=Getpixel64k(1000,10);
    while(1)
    {

		if(Mouse_above(327,151,794,249))//用户名框
        {
            Newxy3();
        }
        if(Mouse_press(327,151,794,249))//在框内按下左键
        {
            //Newxy6();
            inputs(data->name,327,151);    //输入账号
        }
        if(Mouse_above(327,290,794,388))//密码框
        {
			Newxy3();
        }
        if(Mouse_press(327,290,794,388))
        {
            //Newxy6();
            inputs(data->password,327,290);    //输入密码
        }
        if(Mouse_above(327,429,794,527))//确认密码框
        {
            Newxy3();

		}
        if(Mouse_press(327,429,794,527))
        {
            //Newxy6();
			inputs(check_password,327,429);   //输入密码
            OutASC(data->name,48,65500,0,0,1000,600);
            OutASC(data->password,48,65500,0,300,1000,600);
            OutASC(check_password,48,65500,0,600,1000,800);
            if(strcmp(check_password,data->password))
            {
                Putbmp64k(327,151,"bmp\\kong.bmp");
                Putbmp64k(327,290,"bmp\\kong.bmp");
                Putbmp64k(327,429,"bmp\\kong.bmp");
				Putbmp64k(300,300,"bmp\\tishi2.bmp");
            }
        }
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
        if(Mouse_above(702,582,793,632))      //确认
        {
            a5();
        }
        if(Mouse_press(702,582,793,632))
        {
            //Newxy2();
			if(strlen(data->name)==0)
            {
                Putbmp64k(327,151,"bmp\\kong.bmp");
                Putbmp64k(327,290,"bmp\\kong.bmp");
                Putbmp64k(327,429,"bmp\\kong.bmp");
                Putbmp64k(300,300,"bmp\\tishi6.bmp");
                break;
            }
            if(search(info,data)==1)//检验用户名是否已经存在
            {
				Putbmp64k(327,151,"bmp\\kong.bmp");
                Putbmp64k(327,290,"bmp\\kong.bmp");
                Putbmp64k(327,429,"bmp\\kong.bmp");
                Putbmp64k(300,300,"bmp\\tishi7.bmp");
                break;
            }
            if(strlen(data->password)==0)
            {
                Putbmp64k(327,151,"bmp\\kong.bmp");
                Putbmp64k(327,290,"bmp\\kong.bmp");
				Putbmp64k(327,429,"bmp\\kong.bmp");
                Putbmp64k(300,300,"bmp\\tishi5.bmp");
                break;
            }
            else
            {
                Putbmp64k(300,300,"bmp\\tishi3.bmp");
                delay(1000);
                Initmouse(0,1024,0,768);
                Putbmp64k(0,0,"bmp\\zhu.bmp");
				return 0;
            }
        }
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
    return 0;
}

int log_in(PER *data)  //每次初始化SVGA？
{
    int temp2=0;
	PER *info;
	PER *head;
	head=(PER*)malloc(sizeof(PER));
	//info=(PER*)malloc(sizeof(PER));  //自己加的

	if((head==NULL))
		return 0;
	// if((info==NULL))
	//     return 0;

	read(head);
	info=head->next;


	Initmouse(0,1024,0,768);
	Putbmp64k(0,0,"bmp\\denglu2.bmp");
    temp2=Getpixel64k(1000,10);
	while(1)
	{
		if(Mouse_above(305,190,772,288))//用户名框
		{
		    Newxy3();
        }
		if(Mouse_press(305,190,772,288))//在框内按下左键
        {
           //Newxy6();
           inputs(data->name,305,190);
        }
        if(Mouse_above(305,363,772,461))//密码框
        {
		   Newxy3();
        }
        if(Mouse_press(305,363,772,461))
		{
            //Newxy6();
            inputs(data->password,305,363);            //输入密码
        }
        if(Mouse_above(570,671,732,712))        //新用户注册
        {
            a1();
        }
        if(Mouse_press(570,671,732,712))
        {
			//Newxy2();
            regist(info,data);
            data->next=head->next;
            head->next=data;
            save(head);
		    break;
		}
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
		if(Mouse_above(723,525,815,578))      //确认
		{
            a3();
		}
		if(Mouse_press(723,525,815,578))
		{
			//Newxy2();
			if(strlen(data->name)==0)
			{
				Putbmp64k(305,190,"bmp\\kong.bmp");
				Putbmp64k(305,361,"bmp\\kong.bmp");
				Putbmp64k(300,300,"bmp\\tishi6.bmp");
			}
			else if(search(info,data)==0)//检验用户名
			{
				Putbmp64k(305,190,"bmp\\kong.bmp");
				Putbmp64k(305,361,"bmp\\kong.bmp");
				Putbmp64k(300,300,"bmp\\tishi8.bmp");
			}
			else if(strlen(data->password)==0)
			{
				Putbmp64k(305,190,"bmp\\kong.bmp");
				Putbmp64k(305,361,"bmp\\kong.bmp");
				Putbmp64k(300,300,"bmp\\tishi5.bmp");
			}
			else if(search(info,data)<0)//检验密码
			{
				Putbmp64k(305,190,"bmp\\kong.bmp");
				Putbmp64k(305,361,"bmp\\kong.bmp");
				Putbmp64k(300,300,"bmp\\tishi5.bmp");
			}
			else
			{
				save(head);
				Putbmp64k(0,0,"bmp\\yongche.bmp");
			}

		}
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
	free_link(&head);
  	return 0;
}

void inputs(char *p,int x,int y)
{
    char input[7]={0,0,0,0,0,0,0};
    char key;
    int n=0;
	int i,j;
	for(i=0;i<=6;i++)
    {
		p[i]='0';
    }
    while(bioskey(1))
        bioskey(0);
    while(1)
    {
        if(kbhit()) //检查当前键盘是否有输入
        {
			key=bioskey(0);

			if(('0'<=key&&key<='9')||('a'<=key&&key<='z'))//用户名输入及显示
            {
                    input[n]=key;
                    n++;
                    OutASC(input,size,0,x,y,1024,768);
                    if(n>5)
                    {
                        input[n]='\0';
						break;
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
                // for(i=0;i<30;i++)
                //     for(j=0;j<36;j++)
                //         Putpixel64k(x+n*35+i,y+j,0xffff);

            }
            else if(key==0xD)
            {
				input[n]='\0';
                break;           //回车退出
			}

        }
    }
    strcpy(p,input);
}

int search(PER *info,PER *data)
{

	while(info!=NULL)
    {
        if(strcmp(data->name,info->name)==0)
            return 1;
        info=info->next;
	}

        return 0;


}

void read(PER *head)                            //读文件函数，动态生成链表，返回链表头指针
{
    FILE *fp;
	//char p[10];
    PER *info;
    info=(PER *)malloc(sizeof(PER));
	head->next=info;
   if((fp=fopen(".\\yh.txt","r"))==NULL)
		exit(1);
    for(;(fgetc(fp))!=EOF;)
    {

            fscanf(fp,"%7s", info->name);
			fscanf(fp,"%7s", info->password);
            //fscanf(fp,"%2s", p );
            if(fgetc(fp)!=EOF)  //检验是否到文件尾
			{
                info->next=(PER *)malloc(sizeof(PER));
				info=info->next;
            }
    }
    info->next=NULL;
	fclose(fp);
	free_link(&info);
}

void save(PER *head)                          //保存链表到文件
{
	FILE *fp;
    if((fp=fopen(".\\yh.txt","wt"))==NULL)
        exit(1);
    head=head->next;
    while(head!=NULL)
	{

        fprintf(fp,"%7s",head->name);
        fprintf(fp,"%7s",head->password);
        head=head->next;
	}
    fclose(fp);
}

void free_link(PER **head)                          //释放链表
{
    while((*head)!=NULL)
    {
        free(*head);
        (*head)=(*head)->next;

    }
}

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








