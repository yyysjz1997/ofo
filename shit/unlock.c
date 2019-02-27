#include "unlock.h"


int  num_sq[120][120]={0};


int unlock()
{
	  char str_num[7]={0};
	  char *str1="111111";
	  char *str4="000000";
	  int a,i;
	  int k;

	  num_write();

	  SetSVGA64k();
	  Putbmp64k(0,0,"bmp\\yongche.bmp");
	  num_savebk(186,339);
	  for(i=0;i<6;i++)
	  {
		   while(1)
		   {
				  a=i;
				  while(!kbhit())
				  {
						  int direct=getch();
						  if((direct>='0')&&(direct<='9'))
						  {
								 str_num[i]=(char)direct;
								 OutASC(&str_num[i],64,0,190+109*i,349,1024,768);
								 i++;
								 break;
						  }
						  if((direct=='\b')&&(i>=1))
						  {
								str_num[i-1]='\0';
								num_putbk(184+109*(i-1),339);
							   //	OutASC(str_num,64,65000,190+109*i,349,1024,768);
								i=i-1;
								break;
						  }

				  }
				  if(i!=a)
				  {
					  i--;
				  }
					 break;
		   }


}
	  str1=str_num;
	  k=num_read(str1);
	  itoa(k,str4,10);

	SetSVGA64k();
	Putbmp64k(0,0,"bmp\\kaisuo.bmp");
	  OutASC(str4,180,65000,350,210,1024,768);

	Putbmp64k(192,487,"bmp\\daoshu5.bmp");
	delay(1000);
	Putbmp64k(192,487,"bmp\\daoshu4.bmp");
	delay(1000);
	Putbmp64k(192,487,"bmp\\daoshu3.bmp");
	delay(1000);
	Putbmp64k(192,487,"bmp\\daoshu2.bmp");
	delay(1000);
	Putbmp64k(192,487,"bmp\\daoshu1.bmp");


	//Putbmp64k(0,0,"bmp\\kaisuo.bmp");
	return 0;

}

void num_savebk(int x,int y)
 {
   int i,j;
   for(i=0;i<=111;i++)
   for(j=0;j<=111;j++)
   num_sq[i][j]=Getpixel64k(x+i,y+j);
 }

 void num_putbk(int x,int y)
 {
   int i,j;
   for(i=0;i<=111;i++)
   for(j=0;j<=111;j++)
   Putpixel64k(x+i,y+j,num_sq[i][j]);

 }





int num_write(void)
{
	int i=0;
	char num[Y][7]={0};
	char unlock[Y][5]={0};

	FILE *fp=fopen("numedit1.txt","w");
	for(i=0;i<Y;i++)
	{
		gets(num[i]);
		gets(unlock[i]);

		fputs(num[i],fp);
		fputs(unlock[i],fp);

	}
	 fclose(fp);/*¹Ø±ÕÎÄ¼þ*/
	 return 0;
}

int num_read(char *str)
{
	   int i=0;
	   int p=0;
	   char *str2="0000";
	   char num[Y][7]={0};
	   char unlock[Y][5]={0};

		FILE *fp=fopen("numedit1.txt","r");
		for(i=0;i<Y;i++)
		{
			 fread(num[i],6,1,fp);
			 fread(unlock[i],4,1,fp);
			 if(strcmp(num[i],str)==0)
			 {
				  str2=unlock[i];
				  printf("%s\n",str2);
				  p=atoi(str2);
				  fclose(fp);
				  return p;
			 }
		}
	   return 0;
}