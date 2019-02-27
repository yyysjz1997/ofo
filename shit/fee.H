#ifndef _FEE_H_
#define _FEE_H_

#include <time.h>
#include <stdio.h>
#define N 0.01 // time<10's fee
#define M 0.02 //time>10's fee
#define P 0.04 //distance<=2mile
#define Q 0.08 //distance>2mile

int timesave(void);
//float timefee(int x,int y);
int total_time(int x,int y);
float total_mile(int x);
float total_fee(int x,float y);
float change_num(float x);

#endif