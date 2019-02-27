
#include "fee.h"


int timesave()
{
	int sec,min,hour;
	long int sum;
	time_t nowtime;
	struct tm *timeinfo;
	time(&nowtime);
	timeinfo=localtime(&nowtime);
	 sec=timeinfo->tm_sec;
	 min=timeinfo->tm_min;
	 hour=timeinfo->tm_hour;
	 sum=3600*hour+60*min+sec;
	 return(sum);

}

int total_time(int x,int y)
{
	 int temp;
	 temp=y-x;
	 return(temp);
}

int total_mile(int x)
{
	int real_mile;
	real_mile=6*x;
	return(real_mile);
}

int total_fee(int x,int y)
{
	int total,temp1,temp2;
	{
		if(x<=10)
			temp1=N*x;
		if(x>10)
			temp1=N*10+M*(x-10);
	  //	printf("%f\n",temp);
	}

	{
		if(y<=2)
			temp2=P*y;
		if(y>=2)
			temp2=2*P+Q*(y-2);
	}
		total=temp1+temp2;
		return(total);
}

// float change_num(float x)
// {
//      int temp1;
// 	 int temp2;
// 	 temp1=100*x+0.5;
//      temp2=0.01*temp1;
// 	 return(temp2);
// }

int itoflo(char *str1,char *str2)
{
  int i,k;

  k=strlen(str2);
  if(k==1)
    {
    str1[0]='0';
    str1[1]='.';
    str1[2]='0';
    str1[3]=str2[0];
    str1[4]='\0';
    return 0;
    }
  if(k==2)
    {
    str1[0]='0';
    str1[1]='.';
    str1[2]=str2[0];
    str1[3]=str2[1];
    str1[4]='\0';
    return 0;
    }
  if(k>=3&&k<8)
    {
        for(i=0;i<k-2;i++)
        {
        str1[i]=str2[i];
        }
        str1[k-2]='.';
        str1[k-1]=str2[k-2];
        str1[k]=str2[k-1];
        str1[k+1]='\0';
        return 0;
    }
    return 0;
}