#ifndef MY_MOUSE_H
#define MY_MOUSE_H

#include"draw.h"
#include"SVGAmode.h"

void cursor(int x,int y);     //画鼠标的函数
int init(int xmi,int xma,int ymi,int yma);    //鼠标器初始化函数
int read(int *mx,int *my,int *mbutt);     //读鼠标的位置和按钮状态函数
void newxy(int *mx,int *my,int *mbutt);     //是否有按钮按下，若按下，在新位置画鼠标
void MousePutBk(int x, int y);
void MouseStoreBk(int x, int y);

#endif