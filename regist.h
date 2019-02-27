#ifndef _REGIST_H_
#define _REGIST_H_

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

int regist(PER *info,PER *data);
int search(PER *info,PER *data);
void free_link(PER **head);                          //释放链表
void save(PER *head);                          //保存链表到文件
void read(PER *head);                            //读文件函数，动态生成链表，返回链表头指针
int log_in(PER *data);
void inputs(char *p,int x,int y);
int a1(void);
int a2(void);
int a3(void);
int a4(void);
int a5(void);
int a6(void);
int a7(void);





#endif