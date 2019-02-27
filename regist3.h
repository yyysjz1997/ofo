#ifndef _REGIST3_H_
#define _REGIST3_H_

#include "svgamode.h"
#include "mouse2.h"
#include "draw.h"
#include "struct.h"
#include "asc.h"
#include "above.h"
#include "bike.h"
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
int change_pass(PER *data);
int search3(PER data);
int search4(PER data,int flag);
void save2(PER info,int flag);

void read2(PER *info,int n);





#endif