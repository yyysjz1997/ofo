#ifndef _NEWB_H_
#define _NEWB_H_

#include "svgamode.h"
#include "mouse2.h"
#include "draw.h"
#include "struct2.h"
#include "asc.h"
#include "bikemove.h"
#include "above.h"
#include "bike.h"
#define size 48
#define size2  64

int newbike(BIK *data2);
int unlock(BIK *data2);
void input_BIK(char *p,int x,int y,int color);
int search_BIK(BIK data2);
int search_BIK2(BIK data2);
void read_BIK(BIK *info,int n);
void read_BIK2(BIK *info2,int flag);
void save_BIK(BIK info);
void save_BIK2(BIK info2,int flag);
void save_BIK3(BIK info2,int flag);
int bike_sq1(void);
int bike_sq2(void);
int bike_sq3(void);

#endif