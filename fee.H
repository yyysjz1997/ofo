#ifndef _FEE_H_
#define _FEE_H_

#include <time.h>
#include <stdio.h>
#include <string.h>
#define N 0.01*100 // time<10's fee
#define M 0.02*100 //time>10's fee
#define P 0.04 //distance<=2mile
#define Q 0.08 //distance>2mile

int timesave(void);
//float timefee(int x,int y);
int total_time(int x,int y);
int total_mile(int x);
int total_fee(int x,int y);
int itoflo(char *str1,char *str2);
// int change_num(int x);

#endif