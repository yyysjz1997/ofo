#ifndef _BIKEMOVE_H_
#define _BIKEMOVE_H_

#include "svgamode.h"
#include "draw.h"
#include "mouse2.h"
#include "remenu.h"
#include "asc.h"
#include "fee.h"
#define H 120

int bikemove(void);
int bike_savebk(int x,int y);
int bike_putbk(int x,int y);
int bikeuse(void);

// int bike_limit(int x,int y);


#endif