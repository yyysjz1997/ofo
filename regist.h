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
void free_link(PER **head);                          //�ͷ�����
void save(PER *head);                          //���������ļ�
void read(PER *head);                            //���ļ���������̬����������������ͷָ��
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