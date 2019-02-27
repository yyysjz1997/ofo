#include "bikegav.h"


int bikegar(BIK *data2)
{
        int temp=0;
        int flag;
        PER *temp2;
        temp=Getpixel64k(10,10);
        gavmenu(data2);

        while(1)
        {
            if(Mouse_above(308,216,710,312))
            {
                bikegav_new();
            }
            if(Mouse_press(308,216,710,312))
            {
                newbike(data2);
                Initmouse(0,1024,0,768);
                gavmenu(data2);
            }
             if(Mouse_above(308,351,710,446))
            {
                bikegav_ming();
            }
            if(Mouse_press(308,351,710,446))
            {
                mingxi(data2);
                Initmouse(0,1024,0,768);
                gavmenu(data2);
            }
            if(Mouse_above(308,485,710,581))
            {
                bikegav_ditu();
            }
            if(Mouse_press(308,485,710,581))
            {
               bikeditu(data2);
               Initmouse(0,1024,0,768);
               gavmenu(data2);
            }
            if(Mouse_above(308,619,710,714))
            {

                bikegav_back();
            }
            if(Mouse_press(308,619,710,714))
            {
                del(temp2);
                Initmouse(0,1024,0,768);
                gavmenu(data2);
            }

            if(Mouse_above(811,641,964,714))
            {
                Newxy2();

            }

            if(Mouse_press(811,641,964,714))
            {
                Initmouse(0,1024,0,768);
                Putbmp64k(0,0,"bmp\\zhu.bmp");
                return 1;

            }
            else if(!Mouse_above(308,216,710,312)&&!Mouse_above(308,351,710,446)&&!Mouse_above(308,485,710,581)&&
              !Mouse_above(308,619,710,714)&&!Mouse_above(811,641,964,714))
            {
                Newxy();
                Bar_em(308,216,710,312,temp);
                Bar_em(308,351,710,446,temp);
                Bar_em(308,485,710,581,temp);
                Bar_em(308,619,710,714,temp);
            }


        }

}

int bikeditu(BIK *data2)
{
     FILE *fp;
     int n=0,i=0;
     int x=0,y=0;

     fp=fopen("numedit4.txt","r+");
     fscanf(fp,"%d",&n);
     fclose(fp);
     Initmouse(0,1024,0,768);
     Putbmp64k(0,0,"bmp\\ditu.bmp");
     Putbmp64k_TMW(824,609,"bmp\\fh2.bmp");
     Putbmp64k_TMW(100,609,"bmp\\qbwx2.bmp");
     for(i=0;i<n;i++)
     {
          read_BIK(data2,i+1);
          x=atoi(data2->bike_x);
          y=atoi(data2->bike_y);
          // if(data2->bike_repair[0]=='0')
          // {
          //    Putbmp64k_TMB(x,y,"bmp\\che6.bmp");
          // }
          if(data2->bike_repair[0]=='1')
          {
             Putbmp64k_TMB(x,y,"bmp\\che9.bmp");
          }
     }
     while(1)
     {
      if(Mouse_above(824,609,924,709))
        {
            Newxy6();
            Putbmp64k_TMW(824,609,"bmp\\fh.bmp");

            if(!Mouse_above(824,609,924,709))
            {
                Putbmp64k_TMW(824,609,"bmp\\fh2.bmp");
            }
            else if(Mouse_press(824,609,924,709))
            {
               return(5);

            }
        }

          else    if(Mouse_above(100,609,200,709))
        {
            Newxy6();
            Putbmp64k_TMW(100,609,"bmp\\qbwx.bmp");

            if(!Mouse_above(100,609,200,709))
            {
                Putbmp64k_TMW(100,609,"bmp\\qbwx2.bmp");
            }
            else if(Mouse_press(100,609,200,709))
            {
                for(i=0;i<n;i++)
                {
                      read_BIK(data2,i+1);
                      x=atoi(data2->bike_x);
                      y=atoi(data2->bike_y);
                      if(data2->bike_repair[0]=='1')
                     {
                            Putbmp64k_TMB(x,y,"bmp\\che6.bmp");
                            data2->bike_repair[0]='0';
                            data2->bike_repair[1]='\0';
                            save_BIK3(*data2,i+1);
                     }
                }

            }
        }


        else
        {
             Newxy();
             Putbmp64k_TMW(100,609,"bmp\\qbwx2.bmp");
             Putbmp64k_TMW(824,609,"bmp\\fh2.bmp");
        }

     }
}

int mingxi(BIK *data2)
{
    FILE *fp;
    int n=0,i=0;
    int temp=0;
    int k=0;
    int page_max=0;
    int page_now=0;

    char str2[2]={'\0','\0'};
    char *str4= (char*)malloc(sizeof(char)*10);
    char *str5= (char*)malloc(sizeof(char)*2);
    char *str_pagemax= (char*)malloc(sizeof(char)*5);
    char *str_pagenow= (char*)malloc(sizeof(char)*5);

    fp=fopen("numedit4.txt","r+");
    fscanf(fp,"%d",&n);
    fclose(fp);
     Initmouse(0,1024,0,768);

    temp=Getpixel64k(1000,10);
    page_max=(n/7)+1;
    page_now=1;
    str5[0]='/';
    str5[1]='\0';
    Putbmp64k(0,0,"bmp\\mingxi1.bmp");

    itoa(page_max,str_pagemax,10);
    itoa(page_now,str_pagenow,10);
                    OutASC(str_pagenow,48,65000,486,700,1024,768);
                    OutASC(str5,48,65000,514,700,1024,768);
                    OutASC(str_pagemax,48,65000,542,700,1024,768);
    if(page_max==1)
    {
        k=n;
    }
    else if(page_max>1)
    {
        k=7;
    }
    for(i=0;i<k;i++)
    {
          read_BIK(data2,i+1);
          itoa(i+1,str2,10);
          itoflo(str4,data2->bike_fee);
          OutASC(str2,60,65000,2,220+i*66,1024,768);
          OutASC(data2->bike_name,60,65530,133,220+i*66,1024,768);
          OutASC(data2->bike_password,60,65530,332,220+i*66,1024,768);
          OutASC(str4,60,65530,538,220+i*66,1024,768);
          if(data2->bike_repair[0]=='0')
          {
              Putbmp64k(818,223+i*66,"bmp\\zc.bmp");
              // OutChinese(str_zhengchang,65000,812,220+i*66,1024,768,48);
          }
          if(data2->bike_repair[0]=='1')
          {
              Putbmp64k(818,223+i*66,"bmp\\dwx.bmp");
              // OutChinese(str_weixiu,65000,812,220+i*66,1024,768,48);
          }
    }
    while(1)
    {
         if(Mouse_above(356,699,473,750))
         {
               Newxy2();
               Bar_em(356,699,473,750,60000);
         }
         if(Mouse_press(356,699,473,750))
         {
            if(page_now>1&&page_max>1&&page_now<=page_max)
            {
                Initmouse(0,1024,0,768);
                Putbmp64k(0,0,"bmp\\mingxi1.bmp");
                for(i=page_now*7-14;i<page_now*7-7;i++)
                {
                 read_BIK(data2,i+1);
                 itoa(i+1,str2,10);
                 itoflo(str4,data2->bike_fee);

                 OutASC(str2,60,65000,2,220+(i-page_now*7+14)*66,1024,768);
                 OutASC(data2->bike_name,60,65530,133,220+(i-page_now*7+14)*66,1024,768);
                 OutASC(data2->bike_password,60,65530,332,220+(i-page_now*7+14)*66,1024,768);
                 OutASC(str4,60,65530,538,220+(i-page_now*7+14)*66,1024,768);
                  if(data2->bike_repair[0]=='0')
                   {
                      Putbmp64k(818,223+(i-page_now*7+14)*66,"bmp\\zc.bmp");
                   }
                  if(data2->bike_repair[0]=='1')
                   {
                      Putbmp64k(818,223+(i-page_now*7+14)*66,"bmp\\dwx.bmp");
                      // OutChinese(str_weixiu,65000,812,220+(i-page_now*7+14)*66,1024,768,48);
                   }
                }
                    page_now--;
                    page_max=(n/7)+1;
                    itoa(page_max,str_pagemax,10);
                    itoa(page_now,str_pagenow,10);
                    OutASC(str_pagenow,48,65000,486,700,1024,768);
                    OutASC(str5,48,65000,514,700,1024,768);
                    OutASC(str_pagemax,48,65000,542,700,1024,768);

            }
         }
          if(Mouse_above(575,699,687,750))
         {
               Newxy2();
               Bar_em(575,699,687,750,60000);
         }
         if(Mouse_press(575,699,687,750))
         {
            if(page_now>=1&&page_max>1&&page_now<page_max-1)
            {
                Initmouse(0,1024,0,768);
                Putbmp64k(0,0,"bmp\\mingxi1.bmp");
                for(i=page_now*7;i<page_now*7+7;i++)
                {
                 read_BIK(data2,i+1);
                 itoa(i+1,str2,10);
                  itoflo(str4,data2->bike_fee);

                 OutASC(str2,60,65000,2,220+(i-page_now*7)*66,1024,768);
                 OutASC(data2->bike_name,60,65530,133,220+(i-page_now*7)*66,1024,768);
                 OutASC(data2->bike_password,60,65530,332,220+(i-page_now*7)*66,1024,768);
                 OutASC(str4,60,65530,538,220+(i-page_now*7)*66,1024,768);
                  if(data2->bike_repair[0]=='0')
                   {
                      Putbmp64k(818,223+(i-page_now*7)*66,"bmp\\zc.bmp");
                      // OutChinese(str_zhengchang,65000,812,220+(i-page_now*7)*66,1024,768,48);
                   }
                  if(data2->bike_repair[0]=='1')
                   {
                       Putbmp64k(818,223+(i-page_now*7)*66,"bmp\\dwx.bmp");
                      // OutChinese(str_weixiu,65000,812,220+(i-page_now*7)*66,1024,768,48);
                   }
                  }
                    page_now++;
                    page_max=(n/7)+1;
                    itoa(page_max,str_pagemax,10);
                    itoa(page_now,str_pagenow,10);
                    OutASC(str_pagenow,48,65000,486,700,1024,768);
                    OutASC(str5,48,65000,514,700,1024,768);
                    OutASC(str_pagemax,48,65000,542,700,1024,768);
            }
               else if(page_now>=1&&page_max>1&&page_now==page_max-1)
              {
                Initmouse(0,1024,0,768);
                Putbmp64k(0,0,"bmp\\mingxi1.bmp");
                for(i=page_now*7;i<n;i++)
                {
                 read_BIK(data2,i+1);
                 itoa(i+1,str2,10);
                  itoflo(str4,data2->bike_fee);

                 OutASC(str2,60,65000,2,220+(i-page_now*7)*66,1024,768);
                 OutASC(data2->bike_name,60,65530,133,220+(i-page_now*7)*66,1024,768);
                 OutASC(data2->bike_password,60,65530,332,220+(i-page_now*7)*66,1024,768);
                 OutASC(str4,60,65530,538,220+(i-page_now*7)*66,1024,768);
                  if(data2->bike_repair[0]=='0')
                   {
                       Putbmp64k(818,223+(i-page_now*7)*66,"bmp\\zc.bmp");
                      // OutChinese(str_zhengchang,65000,812,220+(i-page_now*7)*66,1024,768,48);
                   }
                  if(data2->bike_repair[0]=='1')
                   {
                     Putbmp64k(818,223+(i-page_now*7)*66,"bmp\\dwx.bmp");
                      // OutChinese(str_weixiu,65000,812,220+(i-page_now*7)*66,1024,768,48);
                   }
                  }
                    page_now++;
                    page_max=(n/7)+1;
                   itoa(page_max,str_pagemax,10);
                   itoa(page_now,str_pagenow,10);
                    OutASC(str_pagenow,48,65000,486,700,1024,768);
                    OutASC(str5,48,65000,514,700,1024,768);
                    OutASC(str_pagemax,48,65000,542,700,1024,768);
                  }
         }




         if(Mouse_above(820,698,897,748))
         {
            mingxi_back();
         }

         if(Mouse_press(820,698,897,748))
         {
            //  Initmouse(0,1024,0,768);
            // Putbmp64k(0,0,"bmp\\ghlogin.bmp");
                  free(str4);
                  free(str5);
                  free(str_pagemax);
                  free(str_pagenow);
            return(2);
         }
         if(!Mouse_above(820,698,897,748)&!Mouse_above(575,699,687,750)&&!Mouse_above(356,699,473,750))
         {
            Newxy();
            Bar_em(820,698,897,748,temp);
            Bar_em(575,699,687,750,temp);
            Bar_em(356,699,473,750,temp);
         }
    }
}

int gavmenu(BIK *data2)
{
        int zyle=0,dwx=0,zyh=0,zcls=0;
        int temp3=0;
        char *str_zcls= (char*)malloc(sizeof(char)*2);
        char *str_zyh= (char*)malloc(sizeof(char)*2);
        char *str_dwx= (char*)malloc(sizeof(char)*2);
        char *str_zyle= (char*)malloc(sizeof(char)*10);
        char *str_zyle1= (char*)malloc(sizeof(char)*10);
        int i=0;
        FILE *fp;

        Initmouse(0,1024,0,768);
        Putbmp64k(0,0,"bmp\\ghlogin.bmp");
        fp=fopen("numedit4.txt","r+");
        fscanf(fp,"%d",&zcls);
        fclose(fp);
        itoa(zcls,str_zcls,10);
        OutASC(str_zcls,48,65532,100,297,1024,768);

        fp=fopen("num66.txt","r+");
        fscanf(fp,"%d",&zyh);
        fclose(fp);
        itoa(zyh,str_zyh,10);
        OutASC(str_zyh,48,65532,858,556,1024,768);

        for(i=0;i<zcls;i++)
        {
          read_BIK(data2,i+1);
          if(data2->bike_repair[0]=='1')
          {
            dwx++;
          }
        }
        itoa(dwx,str_dwx,10);
        OutASC(str_dwx,48,65532,100,556,1024,768);

        for(i=0;i<zcls;i++)
        {
            read_BIK(data2,i+1);
            temp3=atoi(data2->bike_fee);
            zyle=zyle+temp3;
        }
            itoa(zyle,str_zyle,10);
            itoflo(str_zyle1,str_zyle);
            OutASC(str_zyle1,48,65532,838,297,1024,768);


        free(str_zcls);
        free(str_zyh);
        free(str_dwx);
        free(str_zyle);
        free(str_zyle1);
        return 3;
}

int mingxi_back()
{
  Newxy2();
  Bar_em(820,698,897,748,60000);
  return 4;
}

int bikegav_new()
{
     Newxy2();
     Bar_em(308,216,710,312,60000);
     return 6;
}

int bikegav_ming()
{
     Newxy2();
     Bar_em(308,351,710,446,60000);
     return 7;
}

int bikegav_ditu()
{
     Newxy2();
     Bar_em(308,485,710,581,60000);
     return 8;
}

int bikegav_back()
{
     Newxy2();
     Bar_em(308,619,710,714,60000);
     return 9;
}