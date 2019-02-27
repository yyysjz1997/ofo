#ifndef _BIKEMOVE_H_
#define _BIKEMOVE_H_

#include "svgamode.h"
#include "draw.h"
#include "mouse2.h"
#include "remenu.h"
#include "asc.h"
#include "fee.h"
#include "struct2.h"


int bikemove(BIK *data2);
int bikeuse(BIK *data2);
int bike_limit(int x,int y);

#endif