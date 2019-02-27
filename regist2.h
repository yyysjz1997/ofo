#ifndef _REGIST2_H_
#define _REGIST2_H_

#include "svgamode.h"
#include "mouse2.h"
#include "draw.h"
#include "music.h"
#include "bike.h"
#include "explain.h"
#include "login.h"
#include "struct.h"
#include "asc.h"
#define size 16

void Register(void);
int InputInformation(int x1,int x2,int y1,int y2,int pan,char reg[][20]);
int Putfile(char reg[][20]);
void Login(void);
void Input(char *account,char *password);
int JudgePassword(char *password,char *path);
int a1(void);
int a2(void);
int a3(void);
int a4(void);
int a5(void);
int a6(void);
int a7(void);





#endif