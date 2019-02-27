#ifndef _GUANLI_H_
#define _GUANLI_H_

#include "svgamode.h"
#include "mouse2.h"
#include "draw.h"
#include "struct.h"
#include "asc.h"
#include "regist3.h"
#include "above.h"
#include "bike.h"

#define size 48
#define size2  64

int govern(GOV *gov);
int search_g(GOV data);
int search2_g(GOV data);
void read_g(GOV *info,int n);
void save3(int flag);
int del(PER *data);
int search3_g(GOV gov);
int search4_g(GOV gov,int flag);



#endif