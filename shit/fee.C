
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
	 float temp;
	 temp=y-x;
	 return(temp);
}

float total_mile(int x)
{
	float real_mile;
	real_mile=0.057*x;
	return(real_mile);
}

float total_fee(int x,float y)
{
	float total,temp1,temp2;
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

float change_num(float x)
{
     int temp1;
	 float temp2;
	 temp1=100*x+0.5;
     temp2=0.01*temp1;
	 return(temp2);
}

