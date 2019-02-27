/**********************************************************
Copyright (C) 2015 姜君 王鹏晖.
File name:		head.h
Author:			姜君
Version：		1.0
Date：			2015/9/13
Description：	公用头文件

Function List：
	1.int Rand(int a, int b);
		随机生成并返回一个在闭区间[a,b]的正整数
		
	2.void ClearKey(void);
		清除键盘缓存

History：		对本文件的修改请及时按如下格式记录在下面（每个修改单独列出）！
	Example：	Date：
				Author：
				Version：
				Modification：
				
	1.	Date：2015/10/26
		Author：姜君
		Version：1.0
		Modification：添加函数Rand外部声明
		
	2.	Date：2015/11/3
		Author：姜君
		Version：1.0
		Modification：添加函数ClearKey
		
	3.	Date：2015/11/5
		Author：姜君
		Version：1.0
		Modification：添加头文件bios.h
**********************************************************/
#ifndef	HEAD_H
#define	HEAD_H

#define	SCR_WIDTH	1024	/*SCREEN_WIDTH的缩写，屏幕宽度像素 */
#define	SCR_HEIGHT	768		/*SCREEN_HEIGHT的缩写，屏幕高度像素 */

#include<dos.h>			/*int86、outportb函数头文件，union REGS的定义文件*/
#include<stdio.h>		/*文件操作函数头文件*/
#include<time.h>		/*time函数头文件，clock_t的定义头文件*/
#include<math.h>		/*abs，fabs，sin，cos函数头文件*/
#include<stdlib.h>		/*rand、srand、exit函数头文件*/
#include<graphics.h>	/*自带画图函数头文件*/
#include<conio.h>		/*getch函数头文件*/
#include<string.h>		/*memmove函数头文件*/
#include<bios.h>		/*bioskey函数头文件*/



/**********************************************************
Function：		Rand

Description：	随机生成并返回一个在闭区间[a,b]的正整数
				若a > b则会交换a，b大小
				根据测试，函数内部不放入time初始化随机数种子为宜，
				因为本函数被调用的时间间隔极短，
				反复初始化种子会出现大量连号数

Calls：			rand
				
Called By：		CarAimA
				CarAimB
				CarAimC
				CarAimD
				CarNewCreate
				
Input：			int a	区间下限
				int b	区间上限
				
Output：		None

Return：		int		在闭区间[a,b]的随机数
				
Others：		None
**********************************************************/
extern int Rand(int a, int b);

/**********************************************************
Function：		ClearKey

Description：	清除键盘缓存

Calls：			int86
				
Called By：		AutoSimulate
				HandOperate
				
Input：			None
				
Output：		清除键盘缓存

Return：		None
Others：		None
**********************************************************/
extern void ClearKey(void);

#endif