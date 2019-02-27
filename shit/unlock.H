#ifndef _UNLOCK_H_
#define _UNLOCK_H_


#include "svgamode.h"
#include "asc.h"
#define Y 3

int unlock(void);
void num_savebk(int x,int y);
void num_putbk(int x,int y);
int num_write(void);
int num_read(char *str);


#endif