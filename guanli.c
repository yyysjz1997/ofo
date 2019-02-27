#include "guanli.h"


int govern(GOV *gov)
{
    FILE *fp;
    int temp6=0;
    int temp7=0;
	int i;
    PER *temp;
    int flag1=0;


    int n = 0;



    Initmouse(0,1024,0,768);

    Putbmp64k(0,0,"bmp\\guanli.bmp");
    temp6=Getpixel64k(1000,10);
    temp7=Getpixel64k(400,200);

    gov->g_name[0]='\0';
    gov->g_password[0]='\0';



    while(1)
    {
        if(Mouse_above(305,190,772,288))//ÓÃ»§Ãû¿ò
        {
            Newxy6();
            bicycle(722,239);
        }
        if(Mouse_press(305,190,772,288))//ÔÚ¿òÄÚ°´ÏÂ×ó¼ü
        {
            inputs(gov->g_name,305,190,temp7);
            Initmouse(0,1024,0,768);
            fp=fopen("num2.txt","r+");
            fscanf(fp,"%d",&n);
            fclose(fp);
            if(search3_g(*gov)!=n)
            {
                flag1=search3_g(*gov);  //flag1 是输入的用户的位置
            }
            else
            {
                Putbmp64k(305,190,"bmp\\kong.bmp");
                Putbmp64k(305,361,"bmp\\kong.bmp");
                Putbmp64k(300,300,"bmp\\tishi8.bmp");
                delay(2000);
                for(i=0;i<10;i++)
                 {
                    gov->g_name[i]='\0';
                    gov->g_password[i]='\0';
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
            inputs2(gov->g_password,280,363,temp7);            //ÊäÈëÃÜÂë
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
                    gov->g_name[i]='\0';
                    gov->g_password[i]='\0';
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
            if(strlen(gov->g_name)==0)
            {
                Putbmp64k(305,190,"bmp\\kong.bmp");
                Putbmp64k(305,361,"bmp\\kong.bmp");
                Putbmp64k(300,300,"bmp\\tishi6.bmp");
                delay(2000);
                for(i=0;i<10;i++)
                 {
                    gov->g_name[i]='\0';
                    gov->g_password[i]='\0';
                 }
                Putbmp64k(0,0,"bmp\\guanli.bmp");
            }
            else if(search_g(*gov)==0)//¼ìÑéÓÃ»§Ãû
            {
                Putbmp64k(305,190,"bmp\\kong.bmp");
                Putbmp64k(305,361,"bmp\\kong.bmp");
                Putbmp64k(300,300,"bmp\\tishi8.bmp");
                delay(2000);
                for(i=0;i<10;i++)
                 {
                    gov->g_name[i]='\0';
                    gov->g_password[i]='\0';
                 }
                Putbmp64k(0,0,"bmp\\guanli.bmp");
            }
            else if(strlen(gov->g_password)==0)
            {
                Putbmp64k(305,190,"bmp\\kong.bmp");
                Putbmp64k(305,361,"bmp\\kong.bmp");
                Putbmp64k(300,300,"bmp\\tishi5.bmp");
                delay(2000);
                for(i=0;i<10;i++)
                 {
                    gov->g_name[i]='\0';
                    gov->g_password[i]='\0';
                 }
                Putbmp64k(0,0,"bmp\\guanli.bmp");
            }
            else if(search4_g(*gov,flag1)==0)//¼ìÑéÃÜÂë
            {
                Putbmp64k(305,190,"bmp\\kong.bmp");
                Putbmp64k(305,361,"bmp\\kong.bmp");
                Putbmp64k(300,300,"bmp\\tishi1.bmp");
                delay(2000);
                for(i=0;i<10;i++)
                 {
                    gov->g_name[i]='\0';
                    gov->g_password[i]='\0';
                 }
                Putbmp64k(0,0,"bmp\\guanli.bmp");
            }
            else
            {
               Putbmp64k(300,300,"bmp\\success2.bmp");
               delay(2000);
               for(i=0;i<10;i++)
                 {
                    gov->g_name[i]='\0';
                    gov->g_password[i]='\0';
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
            Initmouse(0,1024,0,768);
            Putbmp64k(0,0,"bmp\\zhu.bmp");
            for(i=0;i<10;i++)
                 {
                    gov->g_name[i]='\0';
                    gov->g_password[i]='\0';
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

int search_g(GOV gov)
{
    int i;
    int n;
    FILE *fp;
    GOV temp;
    fp=fopen("num2.txt","r+");
    fscanf(fp,"%d",&n);
    fclose(fp);
    for(i=0;i<=n;i++)
    {
        read_g(&temp,i);
        if(!strcmp(gov.g_name,temp.g_name))
        {
            return 1;
        }
    }
    return 0;
}

int search2_g(GOV gov)
{
    int i;
    int n;
    FILE *fp;
    GOV temp;
    fp=fopen("num2.txt","r+");
    fscanf(fp,"%d",&n);
    fclose(fp);
    for(i=0;i<=n;i++)
    {
        read_g(&temp,i);
        if(!strcmp(gov.g_password,temp.g_password))
        {
            return 1;
        }
    }
    return 0;
}

void read_g(GOV *info,int n)          //  read(&info[2],2);                //¶ÁÎÄ¼þº¯Êý£¬¶¯Ì¬Éú³ÉÁ´±í£¬·µ»ØÁ´±íÍ·Ö¸Õë
{
    FILE *fp;
   // char flag[2];
    //char p[2];
    int i;
    if((fp=fopen(".\\gly.txt","r+"))==NULL)
        exit(1);
for(i=0;i<10;i++)
{
    info->g_password[i]=0;
    info->g_name[i]=0;

}

    for(i=0;i<=n;i++)
    {

        fscanf(fp,"%s", info->g_name);
        fscanf(fp,"%s", info->g_password);
      //OutASC(info[*n].password,48,65500,500,300,1000,600);
        // fscanf(fp,"%s", p );

    }
  fclose(fp);
}


int search3_g(GOV gov)
{
    int i;
    int n;
    FILE *fp;
    GOV temp;
    fp=fopen("num2.txt","r+");
    fscanf(fp,"%d",&n);
    fclose(fp);
    for(i=0;i<=n-1;i++)
    {
        read_g(&temp,i);
        if(strcmp(gov.g_name,temp.g_name)==0)
        {
            return i;
        }
    }
    return 0;
}

// search4_g(*gov,flag)
int search4_g(GOV gov,int flag)
{
    int i;
    int n;
    FILE *fp;
    GOV temp[20];
    fp=fopen("num2.txt","r+");
    fscanf(fp,"%d",&n);
    fclose(fp);

    read_g(&temp[flag],flag);
    if(strcmp(gov.g_password,temp[flag].g_password)==0)
    {
        return 1;
    }

    return 0;
}

int del(PER *data)
{
    FILE *fp;
    int temp16=0;
    int temp17=0;
    int flag=0;
    int flag1=0;
    int n;
    int i=0;
    Initmouse(0,1024,0,768);
    Putbmp64k(0,0,"bmp\\zhuxiao.bmp");

    temp16=Getpixel64k(1000,10);
    temp17=Getpixel64k(400,350);

    data->name[0]='\0';

    while(1)
    {
        if(flag==1)
        {
            Initmouse(0,1024,0,768);
            Putbmp64k(0,0,"bmp\\zhuxiao.bmp");
            flag=0;
        }
        if(Mouse_above(306,299,772,397))  //用户名
        {
            Newxy6();
            bicycle(728,348);
        }
        if(Mouse_press(306,299,772,397))  //用户名
        {

            inputs(data->name,306,299,temp17);    //ÊäÈëÕËºÅ
            Initmouse(0,1024,0,768);
            fp=fopen("num.txt","r+");
            fscanf(fp,"%d",&n);
            fclose(fp);
            if((search3(*data)<n)&&(search3(*data))>=0)
            {
                flag1=search3(*data);  //flag1 是输入的用户的位置
            }
            else
            {
                Putbmp64k(306,299,"bmp\\kong.bmp");
                for(i=0;i<10;i++)
                 {
                    data->name[i]='\0';

                 }

                Putbmp64k(300,300,"bmp\\tishi10.bmp");
                delay(2000);
                Putbmp64k(0,0,"bmp\\zhuxiao.bmp");
            }
        }
        if(Mouse_above(420,544,511,595))   //清除
        {
            a9();
        }
        if(Mouse_press(420,544,511,595))
        {
            //Newxy2();
            for(i=0;i<10;i++)
                 {
                    data->name[i]='\0';

                 }
            Putbmp64k(306,299,"bmp\\kong.bmp");

        }
        if(Mouse_above(674,544,848,594))      //确定
        {
            a10();
        }
        if(Mouse_press(674,544,848,594))
        {
            if(strlen(data->name)==0)
            {
                Putbmp64k(306,299,"bmp\\kong.bmp");
                for(i=0;i<10;i++)
                 {
                    data->name[i]='\0';

                 }

                Putbmp64k(300,300,"bmp\\tishi6.bmp");
                delay(2000);
                Putbmp64k(0,0,"bmp\\zhuxiao.bmp");
                flag=1;
                continue;
            }
            else
            {
                if(!(data->name[0]=='\0'))
                {
                    // fp=fopen("num.txt","r+");    /// remain to be corrected
                    // fscanf(fp,"%d",&n);
                    // n--;
                    // fclose(fp);

                    // fp=fopen("num.txt","r+");
                    // fprintf(fp,"%d",n);
                    // fclose(fp);
                    fp=fopen("num66.txt","r+");    /// remain to be corrected
                    fscanf(fp,"%d",&n);
                    n--;
                    fclose(fp);

                    fp=fopen("num66.txt","r+");
                    fprintf(fp,"%d",n);
                    fclose(fp);
                    save3(flag1);
                    Putbmp64k(300,300,"bmp\\tishi15.bmp");
                    //break;
                }

				delay(1000);
				Initmouse(0,1024,0,768);
				Putbmp64k(0,0,"bmp\\zhuxiao.bmp");
                continue;
            }
        }
       if(Mouse_above(148,545,235,593))         //ÍË³ö
        {
             a11();
        }
        if(Mouse_press(148,545,235,593))         //°´ÏÂ×ó¼ü
        {
            for(i=0;i<10;i++)
                 {
                    data->name[i]='\0';
                 }
            return 0;
        }
        if(!Mouse_above(420,544,511,595)&&!Mouse_above(674,544,848,594)&&!Mouse_above(148,545,235,593)&&!Mouse_above(306,299,772,397))
        {
            Newxy();

            Linex(148,545,235,545,temp16);
            Liney(148,545,148,593,temp16);
            Linex(148,593,235,593,temp16);
            Liney(235,545,235,593,temp16);

            Linex(674,544,848,544,temp16);
            Liney(674,544,674,594,temp16);
            Linex(674,594,848,594,temp16);
            Liney(848,544,848,594,temp16);

            Linex(420,544,511,544,temp16);
            Liney(420,544,420,595,temp16);
            Linex(420,595,511,595,temp16);
            Liney(511,544,511,595,temp16);

            bicycle2(728,348,temp17);

        }
    }
    //return (-1);
}

void save3(int flag)                          //±£´æÁ´±íµ½ÎÄ¼þ
{
    FILE *fp;
    int i;
    PER temp;
    //char flag[2];
    if((fp=fopen(".\\yh.txt","r+"))==NULL)
        exit(1);
    if(flag==0)
    {
        fprintf(fp,"%10s   ",";;;;;;");
        fprintf(fp,"%10s\n",";;;;;;");
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
        fprintf(fp,"%10s   ",";;;;;;");
        fprintf(fp,"%10s\n",";;;;;;");
     //   fprintf(fp,"%s   ","zxcvbn");
    //  fprintf(fp,"%s\r\n","yuiopo");
    // fprintf(fp,"%1s",";");
    }
    fclose(fp);
}





