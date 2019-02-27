#ifndef _ASC_H_
#define _ASC_H_

#include "svgamode.h"

int OutASC(char *string,int size,int color,int x0,int y0,int x1,int y1);
int GetBit(int num,char ch);
int OutChar(char out,int size,int x,int y,int color);

#endif