#ifndef _REGIST3_H_
#define _REGIST3_H_

#include "svgamode.h"
#include "mouse2.h"
#include "draw.h"
//#include "music.h"
//#include "bike.h"
#include "explain.h"
#include "login.h"
#include "struct.h"
#include "asc.h"
#define size 48
#define size2  64

int regist(PER *data);
int login(PER *data);
void inputs(char *p,int x,int y,int color);
void inputs2(char *p,int x,int y,int color);
int search(PER data);
int search2(PER data);
void  read(PER *info,int n);
void save(PER info);
int a1(void);
int a2(void);
int a3(void);
int a4(void);
int a5(void);
int a6(void);
int a7(void);





#endif