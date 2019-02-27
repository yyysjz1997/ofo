#include "regist3.h"


int regist(PER *data)
{
    FILE *fp;
    int temp3=0;
    int temp4=0;
    int n=0;
    char *check_password= (char*)malloc(sizeof(char)*7);
     PER info;
     int flag=0;
     int i=0;
     int j=0;
    Initmouse(0,1024,0,768);
    Putbmp64k(0,0,"bmp\\zhuce.bmp");

    temp3=Getpixel64k(1000,10);
    temp4=Getpixel64k(400,200);

    data->name[0]='\0';
    data->password[0]='\0';
    check_password[0]='\0';


    //int flag=0;
    while(1)
    {
        if(flag==1)
        {
            Initmouse(0,1024,0,768);
            Putbmp64k(0,0,"bmp\\zhuce.bmp");
            flag=0;
        }
        if(Mouse_above(327,151,794,249))//ÓÃ»§Ãû¿ò
        {
            Newxy6();
            bicycle(750,200);
        }
        if(Mouse_press(327,151,794,249))//ÔÚ¿òÄÚ°´ÏÂ×ó¼ü
        {

            inputs(data->name,327,151,temp4);    //ÊäÈëÕËºÅ
            Initmouse(0,1024,0,768);
        }
        if(Mouse_above(327,290,794,388))//ÃÜÂë¿ò
        {
            Newxy6();
            bicycle(750,339);
        }
        if(Mouse_press(327,290,794,388))
        {
            inputs2(data->password,327,290,temp4);            //ÊäÈëÃÜÂë
            Initmouse(0,1024,0,768);
        }
        if(Mouse_above(327,429,794,527))   //È·ÈÏÃÜÂë¿ò
        {
            Newxy6();
            bicycle(750,478);
        }
        if(Mouse_press(327,429,794,527))
        {
            inputs2(check_password,327,429,temp4);
            Initmouse(0,1024,0,768);
            // OutASC(data->name,48,65500,0,0,1000,600);
            // OutASC(data->password,48,65500,0,300,1000,600);
            // OutASC(check_password,48,65500,0,600,1000,800);
            // getch();                                             //ÊäÈëÃÜÂë
            if(strcmp(check_password,data->password))
            {
                Putbmp64k(327,151,"bmp\\kong.bmp");
                Putbmp64k(327,290,"bmp\\kong.bmp");
                Putbmp64k(327,429,"bmp\\kong.bmp");
                Putbmp64k(300,300,"bmp\\tishi2.bmp");
                for(i=0;i<10;i++)
                 {
                    data->name[i]='\0';
                    data->password[i]='\0';

                 }
                 for(j=0;j<7;j++)
                 {
                    check_password[j]='\0';
                 }

                delay(2000);
                Putbmp64k(0,0,"bmp\\zhuce.bmp");
            }
        }
        if(Mouse_above(431,581,524,631))   //Çå³ý¼ü
        {
            a7();
        }
        if(Mouse_press(431,581,524,631))
        {
            //Newxy2();
            for(i=0;i<10;i++)
                 {
                    data->name[i]='\0';
                    data->password[i]='\0';
                 }
                 for(j=0;j<7;j++)
                 {
                    check_password[j]='\0';
                 }
            Putbmp64k(327,151,"bmp\\kong.bmp");
            Putbmp64k(327,290,"bmp\\kong.bmp");
            Putbmp64k(327,429,"bmp\\kong.bmp");
        }
        if(Mouse_above(702,582,793,632))      //È·ÈÏ
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
                delay(2000);
                for(i=0;i<10;i++)
                 {
                    data->name[i]='\0';
                    data->password[i]='\0';

                 }
                 for(j=0;j<7;j++)
                 {
                    check_password[j]='\0';
                 }
                Putbmp64k(0,0,"bmp\\zhuce.bmp");
                flag=1;
                continue;
            }
            else if(search(*data)==1)//¼ìÑéÓÃ»§ÃûÊÇ·ñÒÑ¾­´æÔÚ
            {
                Putbmp64k(327,151,"bmp\\kong.bmp");
                Putbmp64k(327,290,"bmp\\kong.bmp");
                Putbmp64k(327,429,"bmp\\kong.bmp");
                Putbmp64k(300,300,"bmp\\tishi7.bmp");
                delay(2000);
                for(i=0;i<10;i++)
                 {
                    data->name[i]='\0';
                    data->password[i]='\0';

                 }
                 for(j=0;j<7;j++)
                 {
                    check_password[j]='\0';
                 }
                Putbmp64k(0,0,"bmp\\zhuce.bmp");
                flag=1;
                continue;
            }
            else if(strlen(data->password)==0)
            {
                Putbmp64k(327,151,"bmp\\kong.bmp");
                Putbmp64k(327,290,"bmp\\kong.bmp");
                Putbmp64k(327,429,"bmp\\kong.bmp");
                Putbmp64k(300,300,"bmp\\tishi5.bmp");
                delay(2000);
                for(i=0;i<10;i++)
                 {
                    data->name[i]='\0';
                    data->password[i]='\0';

                 }
                 for(j=0;j<7;j++)
                 {
                    check_password[j]='\0';
                 }
                Putbmp64k(0,0,"bmp\\zhuce.bmp");
                flag=1;
                continue;
            }
            else if(strlen(check_password)==0)
            {
                Putbmp64k(327,151,"bmp\\kong.bmp");
                Putbmp64k(327,290,"bmp\\kong.bmp");
                Putbmp64k(327,429,"bmp\\kong.bmp");
                Putbmp64k(300,300,"bmp\\tishi5.bmp");
                delay(2000);
                for(i=0;i<10;i++)
                 {
                    data->name[i]='\0';
                    data->password[i]='\0';

                 }
                 for(j=0;j<7;j++)
                 {
                    check_password[j]='\0';
                 }
                Putbmp64k(0,0,"bmp\\zhuce.bmp");
                flag=1;
                continue;
            }

            else
            {
                if((!(data->password[0]=='\0'))&&(!(data->name[0]=='\0'))&&(!(check_password[0]=='\0'))&&
                    (!(search(*data)==1)))
                {
                    fp=fopen("num.txt","r+");    /// remain to be corrected
                    fscanf(fp,"%d",&n);
                    n++;
                    fclose(fp);

                    fp=fopen("num.txt","r+");
                    fprintf(fp,"%d",n);
                    fclose(fp);

                    fp=fopen("num66.txt","r+");    /// remain to be corrected
                    fscanf(fp,"%d",&n);
                    n++;
                    fclose(fp);

                    fp=fopen("num66.txt","r+");
                    fprintf(fp,"%d",n);
                    fclose(fp);
                    save(*data);
                    for(i=0;i<10;i++)
                 {
                    data->name[i]='\0';
                    data->password[i]='\0';
                 }
                 for(j=0;j<7;j++)
                 {
                    check_password[j]='\0';
                 }
                    //break;
                }
                Putbmp64k(300,300,"bmp\\tishi3.bmp");
                delay(1000);
                Initmouse(0,1024,0,768);
                free(check_password);
                return 1;
            }
        }
       if(Mouse_above(189,584,272,631))         //ÍË³ö
        {
             a6();
        }
        if(Mouse_press(189,584,272,631))         //°´ÏÂ×ó¼ü
        {
            Initmouse(0,1024,0,768);//±ØÐë¼Ó
            free(check_password);
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
            bicycle2(750,200,temp4);
            bicycle2(750,339,temp4);
            bicycle2(750,478,temp4);
        }
    }
    //return (-1);
}

int login(PER *data)
{
    FILE *fp;
    int temp2=0;
    int temp5=0;
    int i;
    PER temp;
    int flag1=0;


    int n = 0;
    // FILE *fp;


    Initmouse(0,1024,0,768);

    Putbmp64k(0,0,"bmp\\denglu2.bmp");
    temp2=Getpixel64k(1000,10);
    temp5=Getpixel64k(400,200);

    data->name[0]='\0';
    data->password[0]='\0';

    while(1)
    {
        if(Mouse_above(305,190,772,288))//ÓÃ»§Ãû¿ò
        {
            Newxy6();
            bicycle(722,239);
        }
        if(Mouse_press(305,190,772,288))//ÔÚ¿òÄÚ°´ÏÂ×ó¼ü
        {
            inputs(data->name,305,190,temp5);
            Initmouse(0,1024,0,768);
            fp=fopen("num.txt","r+");
            fscanf(fp,"%d",&n);
            fclose(fp);
            if(search3(*data)!=n)
            {
                flag1=search3(*data);  //flag1 是输入的用户的位置
            }
            else
            {
                Putbmp64k(305,190,"bmp\\kong.bmp");
                Putbmp64k(305,361,"bmp\\kong.bmp");
                Putbmp64k(300,300,"bmp\\tishi8.bmp");
                delay(2000);
                for(i=0;i<10;i++)
                 {
                    data->name[0]='\0';
                    data->password[0]='\0';
                 }

            }

        }
        if(Mouse_above(305,363,772,461))//ÃÜÂë¿ò
        {
            Newxy6();
            bicycle(722,412);
        }
        if(Mouse_press(305,363,772,461))
        {
            //Newxy6();
            inputs2(data->password,280,363,temp5);            //ÊäÈëÃÜÂë
            Initmouse(0,1024,0,768);
        }
        if(Mouse_above(570,671,732,712))        //×¢²á
        {
            a1();
        }
        if(Mouse_press(570,671,732,712))
        {
            for(i=0;i<10;i++)
                 {
                    data->name[0]='\0';
                    data->password[0]='\0';
                 }
            return 2;
         //   info[n]=*data;
            // if((!(data->password=='\0'))&&(!(data->name=='\0')))
            // {
            //    fp=fopen("num.txt","r+");    /// remain to be corrected
            //     fscanf(fp,"%d",&n);
            //     n++;
            //     fclose(fp);

            //     fp=fopen("num.txt","r+");
            //     fprintf(fp,"%d",n);
            //     fclose(fp);
            //     save(*data);
            //     break;
            // }

        }
        if(Mouse_above(452,529,540,581))  //Çå³ý¼ü
        {
            a2();
        }
        if(Mouse_press(452,529,540,581))
        {
            //Newxy2();
            for(i=0;i<10;i++)
                 {
                    data->name[0]='\0';
                    data->password[0]='\0';
                 }
            Putbmp64k(305,190,"bmp\\kong.bmp");
            Putbmp64k(305,361,"bmp\\kong.bmp");
        }
        if(Mouse_above(723,525,815,578))      //È·ÈÏ
        {
            a3();
        }
        if(Mouse_press(723,525,815,578))
        {
            //Newxy2();
            // OutASC(data->name,48,65500,0,0,1000,600);
            // OutASC(data->password,48,65500,0,300,1000,600);
            if(strlen(data->name)==0)
            {
                Putbmp64k(305,190,"bmp\\kong.bmp");
                Putbmp64k(305,361,"bmp\\kong.bmp");
                Putbmp64k(300,300,"bmp\\tishi6.bmp");
                delay(2000);
                for(i=0;i<10;i++)
                 {
                    data->name[0]='\0';
                    data->password[0]='\0';
                 }
                Putbmp64k(0,0,"bmp\\denglu2.bmp");
            }
            else if(search(*data)==0)//¼ìÑéÓÃ»§Ãû
            {
                Putbmp64k(305,190,"bmp\\kong.bmp");
                Putbmp64k(305,361,"bmp\\kong.bmp");
                Putbmp64k(300,300,"bmp\\tishi8.bmp");
                delay(2000);
                for(i=0;i<10;i++)
                 {
                    data->name[0]='\0';
                    data->password[0]='\0';
                 }
                Putbmp64k(0,0,"bmp\\denglu2.bmp");
            }
            else if(strlen(data->password)==0)
            {
                Putbmp64k(305,190,"bmp\\kong.bmp");
                Putbmp64k(305,361,"bmp\\kong.bmp");
                Putbmp64k(300,300,"bmp\\tishi5.bmp");
                delay(2000);
                for(i=0;i<10;i++)
                 {
                    data->name[0]='\0';
                    data->password[0]='\0';
                 }
                Putbmp64k(0,0,"bmp\\denglu2.bmp");
            }
            else if(search4(*data,flag1)==0)//¼ìÑéÃÜÂë
            {
                Putbmp64k(305,190,"bmp\\kong.bmp");
                Putbmp64k(305,361,"bmp\\kong.bmp");
                Putbmp64k(300,300,"bmp\\tishi1.bmp");
                delay(2000);
                for(i=0;i<10;i++)
                 {
                    data->name[0]='\0';
                    data->password[0]='\0';
                 }
                Putbmp64k(0,0,"bmp\\denglu2.bmp");
            }
            else
            {
                Putbmp64k(300,300,"bmp\\success2.bmp");
                delay(2000);
                for(i=0;i<10;i++)
                 {
                    data->name[0]='\0';
                    data->password[0]='\0';
                 }
                return 1;

            }

        }
        if(Mouse_above(126,532,328,578))         //·µ»ØÖ÷Ò³Ãæ
        {
            a4();

        }
        if(Mouse_press(126,532,328,578))         //°´ÏÂ×ó¼ü
        {
            //Newxy2();
            for(i=0;i<10;i++)
                 {
                    data->name[0]='\0';
                    data->password[0]='\0';
                 }
            Initmouse(0,1024,0,768);
            Putbmp64k(0,0,"bmp\\zhu.bmp");
            return 0;
        }

        if(Mouse_above(795,678,938,713))         //·µ»ØÖ÷Ò³Ãæ
        {
            a8();
        }
        if(Mouse_press(795,678,938,713))         //°´ÏÂ×ó¼ü
        {
            //Newxy2();
            for(i=0;i<10;i++)
                 {
                    data->name[0]='\0';
                    data->password[0]='\0';
                 }
            Initmouse(0,1024,0,768);
            change_pass(data);
            //del(data);
        }
        if(!Mouse_above(305,190,772,288)&&!Mouse_above(305,363,772,461)&&!Mouse_above(570,671,732,712)
            &&!Mouse_above(452,529,540,581)&&!Mouse_above(723,525,815,578)&&!Mouse_above(126,532,328,578)
            &&!Mouse_above(795,678,938,713))
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

            Linex(795,678,938,678,temp2);
            Liney(795,678,795,713,temp2);
            Linex(795,713,938,713,temp2);
            Liney(938,678,938,713,temp2);

            bicycle2(722,239,temp5);
            bicycle2(722,412,temp5);
        }
    }
    //return 0;
}

void inputs(char *p,int x,int y,int color)
{
    char *input= (char*)malloc(sizeof(char)*7);
    char key;
    int n=0;
    int i;
    int j;
    int k;


    for(i=0;i<=6;i++)
    {
        p[i]='\0';
    }
    while(bioskey(1))
        bioskey(0);
    while(1)
    {
        if(kbhit()) //¼ì²éµ±Ç°¼üÅÌÊÇ·ñÓÐÊäÈë
        {
            key=bioskey(0);

            if(('0'<=key&&key<='9')||('a'<=key&&key<='z'))//ÓÃ»§ÃûÊäÈë¼°ÏÔÊ¾
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
            if(!(('0'<=key&&key<='9')||('a'<=key&&key<='z')||(key==0xD)||(key==0x08)))
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
    strcpy(p,input);
    free(input);
}

void inputs2(char *p,int x,int y,int color)
{
    char *input=(char*)malloc(sizeof(char)*7);
    char key;
    int n=0;
    int i;
    int j;
    int k;
    char out;


    out='*';


    for(i=0;i<=6;i++)
    {
        p[i]='\0';
    }
    while(bioskey(1))
        bioskey(0);
    while(1)
    {
        if(kbhit()) //¼ì²éµ±Ç°¼üÅÌÊÇ·ñÓÐÊäÈë
        {
            key=bioskey(0);

            if(('0'<=key&&key<='9')||('a'<=key&&key<='z'))//ÓÃ»§ÃûÊäÈë¼°ÏÔÊ¾
            {

                    input[n]=key;
                    n++;
                    OutChar(out,size2,x+n*size2,y+10,0);
                    if(n>5)
                    {
                        input[n]='\0';
                        break;
                    }


            }
            if(!(('0'<=key&&key<='9')||('a'<=key&&key<='z')||(key==0xD)||(key==0x08)))
                continue;
            if(key==0x08 )                                               //ÍË¸ñ¼ü×÷ÓÃ´úÂë
            {
                if(n<1)
                    continue;
                n-=1;
                input[n]='\0';
                for(k=0;k<size2;k++)
                {
                    for(j=0;j<size2;j++)
                    {
                        Putpixel64k(x+(n+1)*size2+k,y+(size2/2)-15+j,color);
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
    strcpy(p,input);
    free(input);
}


int search(PER data)
{
    int i;
    int n;
    FILE *fp;
    PER temp;
    fp=fopen("num.txt","r+");
    fscanf(fp,"%d",&n);
    fclose(fp);
    for(i=0;i<=n;i++)
    {
        read(&temp,i);
        if(!strcmp(data.name,temp.name))
        {
            return 1;
        }
    }


    return 0;



    // else if(flag==2)
    // {
    //     for(i=0;i<n;i++)
    //     {
    //         if((!strcmp(data->name,info[i].name))&&(!strcmp(data->password,info[i].password)))
    //             break;
    //     }
    //     if(i==n)
    //         return -1;
    //     else
    //         return i;


    //return 0;
}

int search2(PER data)
{
    int i;
    int n;
    FILE *fp;
    PER temp;
    fp=fopen("num.txt","r+");
    fscanf(fp,"%d",&n);
    fclose(fp);
    for(i=0;i<=n;i++)
    {
        read(&temp,i);
        if(!strcmp(data.password,temp.password))
        {
            return 1;
        }
    }
    return 0;
}

void read(PER *info,int n)          //  read(&info[2],2);                //¶ÁÎÄ¼þº¯Êý£¬¶¯Ì¬Éú³ÉÁ´±í£¬·µ»ØÁ´±íÍ·Ö¸Õë
{
    FILE *fp;
   // char flag[2];
    //char p[2];
    int i;
    if((fp=fopen(".\\yh.txt","r+"))==NULL)
        exit(1);
for(i=0;i<10;i++)
{
    info->password[i]=0;
    info->name[i]=0;

}

    for(i=0;i<=n;i++)
    {

        fscanf(fp,"%10s", info->name);
        fscanf(fp,"%10s", info->password);
      //OutASC(info[*n].password,48,65500,500,300,1000,600);
        // fscanf(fp,"%s", p );

    }
  fclose(fp);
}

void save(PER info)                          //±£´æÁ´±íµ½ÎÄ¼þ
{

    FILE *fp;
    int i;

    //char flag[2];
    if((fp=fopen(".\\yh.txt","r+"))==NULL)
        exit(1);

    fseek(fp,0L,2);




        fprintf(fp,"%10s   ",info.name);
        fprintf(fp,"%10s\n",info.password);

        // fprintf(fp,"%1s",";");

    fclose(fp);
}

int change_pass(PER *data)
{
    FILE *fp;
    int temp11=0;
    int temp12=0;
    char *check_newword= (char*)malloc(sizeof(char)*7);
    int flag=0;
    int flag1=0;
    int n;
    int i=0;
    int j=0;
    Initmouse(0,1024,0,768);
    Putbmp64k(0,0,"bmp\\gaimima.bmp");

    temp11=Getpixel64k(1000,10);
    temp12=Getpixel64k(400,200);

    data->name[0]='\0';
    data->password[0]='\0';

    //int flag=0;
    while(1)
    {
        if(flag==1)
        {
            Initmouse(0,1024,0,768);
            Putbmp64k(0,0,"bmp\\gaimima.bmp");
            flag=0;
        }
        if(Mouse_above(327,151,794,249))  //用户名
        {
            Newxy6();
            bicycle(750,200);
        }
        if(Mouse_press(327,151,794,249))  //用户名
        {

            inputs(data->name,327,151,temp12);    //ÊäÈëÕËºÅ
            Initmouse(0,1024,0,768);
            fp=fopen("num.txt","r+");
            fscanf(fp,"%d",&n);
            fclose(fp);
            if(search3(*data)!=n)
            {
                flag1=search3(*data);  //flag1 是输入的用户的位置
            }
            else
            {
                Putbmp64k(327,151,"bmp\\kong.bmp");
                Putbmp64k(327,290,"bmp\\kong.bmp");
                Putbmp64k(327,429,"bmp\\kong.bmp");
                Putbmp64k(300,300,"bmp\\tishi10.bmp");
                delay(2000);
                for(i=0;i<10;i++)
                 {
                    data->name[0]='\0';
                    data->password[0]='\0';
                 }
                 for(j=0;j<7;j++)
                 {
                    check_newword[j]='\0';
                 }
                Putbmp64k(0,0,"bmp\\gaimima.bmp");
            }
        }
        if(Mouse_above(327,290,794,388))  //原密码
        {
            Newxy6();
            bicycle(750,339);
        }
        if(Mouse_press(327,290,794,388))
        {
            inputs2(data->password,327,290,temp12);            //ÊäÈëÃÜÂë
            Initmouse(0,1024,0,768);
            if(search4(*data,flag1)==1)
            {
                   ;
            }
            else
            {
                Putbmp64k(327,151,"bmp\\kong.bmp");
                Putbmp64k(327,290,"bmp\\kong.bmp");
                Putbmp64k(327,429,"bmp\\kong.bmp");
                Putbmp64k(300,300,"bmp\\tishi11.bmp");
                delay(2000);
                for(i=0;i<10;i++)
                 {
                    data->name[0]='\0';
                    data->password[0]='\0';
                 }
                 for(j=0;j<7;j++)
                 {
                    check_newword[j]='\0';
                 }
                Putbmp64k(0,0,"bmp\\gaimima.bmp");
            }
        }
        if(Mouse_above(327,429,794,527))   //新密码
        {
            Newxy6();
            bicycle(750,478);
        }
        if(Mouse_press(327,429,794,527))
        {
            inputs2(check_newword,327,429,temp12);
            Initmouse(0,1024,0,768);
            // if(!(strcmp(check_newword,data->password))=0)
            // {
            //        ;
            // }
            // else
            // {
            //     Putbmp64k(327,151,"bmp\\kong.bmp");
            //     Putbmp64k(327,290,"bmp\\kong.bmp");
            //     Putbmp64k(327,429,"bmp\\kong.bmp");
            //     Putbmp64k(300,300,"bmp\\tishi14.bmp");
            //     delay(2000);
            //     Putbmp64k(0,0,"bmp\\gaimima.bmp");
            // }
        }
        if(Mouse_above(431,581,524,631))   //清除
        {
            a7();
        }
        if(Mouse_press(431,581,524,631))
        {
            //Newxy2();
            for(i=0;i<10;i++)
                 {
                    data->name[0]='\0';
                    data->password[0]='\0';
                 }
                 for(j=0;j<7;j++)
                 {
                    check_newword[j]='\0';
                 }
            Putbmp64k(327,151,"bmp\\kong.bmp");
            Putbmp64k(327,290,"bmp\\kong.bmp");
            Putbmp64k(327,429,"bmp\\kong.bmp");
        }
        if(Mouse_above(702,582,793,632))      //确定
        {
            a5();
        }
        if(Mouse_press(702,582,793,632))
        {
            if(strlen(data->name)==0)
            {
                Putbmp64k(327,151,"bmp\\kong.bmp");
                Putbmp64k(327,290,"bmp\\kong.bmp");
                Putbmp64k(327,429,"bmp\\kong.bmp");
                Putbmp64k(300,300,"bmp\\tishi6.bmp");
                delay(2000);
                for(i=0;i<10;i++)
                 {
                    data->name[0]='\0';
                    data->password[0]='\0';
                 }
                 for(j=0;j<7;j++)
                 {
                    check_newword[j]='\0';
                 }
                Putbmp64k(0,0,"bmp\\gaimima.bmp");
                flag=1;
                continue;
            }
            else if(strlen(data->password)==0)
            {
                Putbmp64k(327,151,"bmp\\kong.bmp");
                Putbmp64k(327,290,"bmp\\kong.bmp");
                Putbmp64k(327,429,"bmp\\kong.bmp");
                Putbmp64k(300,300,"bmp\\tishi12.bmp");
                delay(2000);
                for(i=0;i<10;i++)
                 {
                    data->name[0]='\0';
                    data->password[0]='\0';
                 }
                 for(j=0;j<7;j++)
                 {
                    check_newword[j]='\0';
                 }
                Putbmp64k(0,0,"bmp\\gaimima.bmp");
                flag=1;
                continue;
            }
            else if(strlen(check_newword)==0)
            {
                Putbmp64k(327,151,"bmp\\kong.bmp");
                Putbmp64k(327,290,"bmp\\kong.bmp");
                Putbmp64k(327,429,"bmp\\kong.bmp");
                Putbmp64k(300,300,"bmp\\tishi13.bmp");
                delay(2000);
                for(i=0;i<10;i++)
                 {
                    data->name[0]='\0';
                    data->password[0]='\0';
                 }
                 for(j=0;j<7;j++)
                 {
                    check_newword[j]='\0';
                 }
                Putbmp64k(0,0,"bmp\\gaimima.bmp");
                flag=1;
                continue;
            }

            else
            {
                if((!(data->password[0]=='\0'))&&(!(data->name[0]=='\0'))&&(!(check_newword[0]=='\0')))
                {

                    strcpy(data->password,check_newword);
                    // fp=fopen("num.txt","r+");    /// remain to be corrected
                    // fscanf(fp,"%d",&n);
                    // n++;
                    // fclose(fp);

                    // fp=fopen("num.txt","r+");
                    // fprintf(fp,"%d",n);
                    // fclose(fp);
                    save2(*data,flag1);
                    Putbmp64k(300,300,"bmp\\tishi4.bmp");
                    //break;
                }
                for(i=0;i<10;i++)
                 {
                    data->name[0]='\0';
                    data->password[0]='\0';
                 }
                 for(j=0;j<7;j++)
                 {
                    check_newword[j]='\0';
                 }
                delay(1000);
                Initmouse(0,1024,0,768);
                Putbmp64k(0,0,"bmp\\gaimima.bmp");

            }
        }
       if(Mouse_above(189,584,272,631))
        {
             a6();
        }
        if(Mouse_press(189,584,272,631))
        {
            for(i=0;i<10;i++)
                 {
                    data->name[0]='\0';
                    data->password[0]='\0';
                 }
                 for(j=0;j<7;j++)
                 {
                    check_newword[j]='\0';
                 }
            Initmouse(0,1024,0,768);
            Putbmp64k(0,0,"bmp\\denglu2.bmp");
            free(check_newword);
            return 0;
        }
        if(!Mouse_above(327,151,794,249)&&!Mouse_above(327,290,794,388)&&!Mouse_above(327,429,794,527)&&!
            Mouse_above(431,581,524,631)&&!Mouse_above(702,582,793,632)&&!Mouse_above(189,584,272,631))
        {
            Newxy();

            Linex(702,582,793,582,temp11);
            Liney(702,582,702,632,temp11);
            Linex(702,632,793,632,temp11);
            Liney(793,582,793,632,temp11);

            Linex(189,584,272,584,temp11);
            Liney(189,584,189,631,temp11);
            Linex(189,631,272,631,temp11);
            Liney(272,584,272,631,temp11);

            Linex(431,581,524,581,temp11);
            Liney(431,581,431,631,temp11);
            Linex(431,631,524,631,temp11);
            Liney(524,581,524,631,temp11);
            bicycle2(750,200,temp12);
            bicycle2(750,339,temp12);
            bicycle2(750,478,temp12);
        }
    }
    //return (-1);
}

int search3(PER data)
{
    int i;
    int n;
    FILE *fp;
    PER temp;
    fp=fopen("num.txt","r+");
    fscanf(fp,"%d",&n);
    fclose(fp);
    for(i=0;i<=n-1;i++)
    {
        read(&temp,i);
        if(strcmp(data.name,temp.name)==0)
        {
            return i;
        }
    }
    return 0;
}

int search4(PER data,int flag)
{
    int i;
    int n;
    FILE *fp;
    PER temp[20];
    fp=fopen("num.txt","r+");
    fscanf(fp,"%d",&n);
    fclose(fp);

    read(&temp[flag],flag);
    if(strcmp(data.password,temp[flag].password)==0)
    {
        return 1;
    }

    return 0;
}

void save2(PER info,int flag)                          //±£´æÁ´±íµ½ÎÄ¼þ
{
    FILE *fp;
    int i;
    PER temp;
    //char flag[2];
    if((fp=fopen(".\\yh.txt","r+"))==NULL)
        exit(1);
    //fseek(fp,(flag)*20L,1);
    if(flag==0)
    {
        fprintf(fp,"%10s   ",info.name);
        fprintf(fp,"%10s\n",info.password);
    }
    else
    {
        for(i=0;i<=flag-1;i++)
        {
            fscanf(fp,"%10s",temp.name);
            fscanf(fp,"%10s",temp.password);
        }
        fseek(fp,0L,1);
        fprintf(fp,"\n");
        fprintf(fp,"%10s   ",info.name);
        fprintf(fp,"%10s\n",info.password);
    }
    fclose(fp);
}

