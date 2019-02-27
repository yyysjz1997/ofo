#include "yu_e.h"

int chongz(PER *data)
{
    FILE *fp;
    int temp6=0;
    int temp7=0;
    int i;
    PER *temp;
    int flag1=0;


    int n = 0;



    Initmouse(0,1024,0,768);

    Putbmp64k(0,0,"bmp\\chongz.bmp");
    temp6=Getpixel64k(1000,10);
    temp7=Getpixel64k(400,200);

    data->name[0]='\0';




    while(1)
    {
        if(Mouse_above(305,190,772,288))//ÓÃ»§Ãû¿ò
        {
            Newxy6();
            bicycle(722,239);
        }
        if(Mouse_press(305,190,772,288))//ÔÚ¿òÄÚ°´ÏÂ×ó¼ü
        {
            inputs(data->name,305,190,temp7);
            Initmouse(0,1024,0,768);
            fp=fopen("num.txt","r+");
            fscanf(fp,"%d",&n);
            fclose(fp);
            if(search3_cz(*data)!=n)
            {
                flag1=search3_cz(*data);  //flag1 是输入的用户的位置
            }
            else
            {
                Putbmp64k(305,190,"bmp\\kong.bmp");
                Putbmp64k(305,361,"bmp\\kong.bmp");
                Putbmp64k(300,300,"bmp\\tishi8.bmp");
                delay(2000);
                for(i=0;i<10;i++)
                 {
                    data->name[i]='\0';
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
            inputs3(data->yu_e,280,363,temp7);            //ÊäÈëÃÜÂë
            Initmouse(0,1024,0,768);
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
                    data->name[i]='\0';
                    data->yu_e[i]='\0';
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
                    data->name[i]='\0';
                    data->yu_e[i]='\0';
                 }
                Putbmp64k(0,0,"bmp\\chongz.bmp");
            }
            else if(search(*data)==0)//¼ìÑéÓÃ»§Ãû
            {
                Putbmp64k(305,190,"bmp\\kong.bmp");
                Putbmp64k(305,361,"bmp\\kong.bmp");
                Putbmp64k(300,300,"bmp\\tishi8.bmp");
                delay(2000);
                for(i=0;i<10;i++)
                 {
                    data->name[i]='\0';
                    data->yu_e[i]='\0';
                 }
                Putbmp64k(0,0,"bmp\\chongz.bmp");
            }
            else if(strlen(data->yu_e)==0)
            {
                Putbmp64k(305,190,"bmp\\kong.bmp");
                Putbmp64k(305,361,"bmp\\kong.bmp");
                Putbmp64k(300,300,"bmp\\tishi26.bmp");
                delay(2000);
                for(i=0;i<10;i++)
                 {
                    data->name[i]='\0';
                    data->yu_e[i]='\0';
                 }
                Putbmp64k(0,0,"bmp\\chongz.bmp");
            }
            else
            {
               //strcpy(data->password,check_newword);
                    // fp=fopen("num.txt","r+");    /// remain to be corrected
                    // fscanf(fp,"%d",&n);
                    // n++;
                    // fclose(fp);

                    // fp=fopen("num.txt","r+");
                    // fprintf(fp,"%d",n);
                    // fclose(fp);
                    save2(*data,flag1);
                    Putbmp64k(300,300,"bmp\\tishi25.bmp");
                    //break;
                }
                for(i=0;i<10;i++)
                 {
                    data->name[0]='\0';
                    data->yu_e[0]='\0';
                 }

                delay(1000);
                Initmouse(0,1024,0,768);
                Putbmp64k(0,0,"bmp\\chongz.bmp");
            }

        }
        if(Mouse_above(126,532,328,578))         //·µ»ØÖ÷Ò³Ãæ
        {
            a4();

        }
        if(Mouse_press(126,532,328,578))         //°´ÏÂ×ó¼ü
        {
            //Newxy2();
            Initmouse(0,1024,0,768);
            Putbmp64k(0,0,"bmp\\denglu2.bmp");
            for(i=0;i<10;i++)
                 {
                    data->name[i]='\0';
                    data->yu_e[i]='\0';
                 }
            return 0;
        }
        if(!Mouse_above(305,190,772,288)&&!Mouse_above(305,363,772,461)&&!Mouse_above(452,529,540,581)
            &&!Mouse_above(723,525,815,578)&&!Mouse_above(126,532,328,578))
        {
            Newxy();
            Linex(570,671,732,671,temp6);
            Liney(570,671,570,712,temp6);
            Linex(570,712,732,712,temp6);
            Liney(732,671,732,712,temp6);

            Linex(452,529,540,529,temp6);
            Liney(452,529,452,581,temp6);
            Linex(452,581,540,581,temp6);
            Liney(540,529,540,581,temp6);

            Linex(723,525,815,525,temp6);
            Liney(723,525,723,578,temp6);
            Linex(723,578,815,578,temp6);
            Liney(815,525,815,578,temp6);

            Linex(126,532,328,532,temp6);
            Liney(126,532,126,578,temp6);
            Linex(126,578,328,578,temp6);
            Liney(328,532,328,578,temp6);
            bicycle2(722,239,temp7);
            bicycle2(722,412,temp7);
        }
        // if(Mouse_press(0,0,100,100))
        // {
        //     del(temp);

        // }
    }
    //return 0;
}

int search3_cz(PER data)
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
        read_g(&temp,i);
        if(strcmp(data.name,temp.name)==0)
        {
            return i;
        }
    }
    return 0;
}

void read_cz(PER *info,int n)          //  read(&info[2],2);                //¶ÁÎÄ¼þº¯Êý£¬¶¯Ì¬Éú³ÉÁ´±í£¬·µ»ØÁ´±íÍ·Ö¸Õë
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
    info->yu_e[i]=0;

}

    for(i=0;i<=n;i++)
    {

        fscanf(fp,"%s", info->name);
        fscanf(fp,"%s", info->password);
        fscanf(fp,"%s", info->yu_e);
      //OutASC(info[*n].password,48,65500,500,300,1000,600);
        // fscanf(fp,"%s", p );

    }
  fclose(fp);
}

void inputs3(char *p,int x,int y,int color)
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

            if('0'<=key&&key<='9')//ÓÃ»§ÃûÊäÈë¼°ÏÔÊ¾
            {

                    input[n]=key;
                    n++;
                    OutChar(input[n-1],size,x+n*size,y+22,0);
                    if(n>3)
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
    strcpy(p,input);
    free(input);
}


