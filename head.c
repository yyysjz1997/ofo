/**********************************************************
Copyright (C) 2015 姜君 王鹏晖.
File name:		head.c
Author:			姜君
Version：		1.0
Date：			2015/10/25
Description：	公用文件

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
				
	1.	Date：2015/11/3
		Author：姜君
		Version：1.0
		Modification：添加函数ClearKey
**********************************************************/

#include"head.h"

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
int Rand(int a, int b)
{
	/*下限不大于上限，否则互换*/
	if (a > b)
	{
		a = a ^ b;
		b = a ^ b;
		a = a ^ b;
	}
	
	return (a + rand() % (b - a + 1));
}

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
void ClearKey(void)
{
	union REGS key;
	
	key.h.ah = 0x0c;
	key.h.al = 0x00;
	int86(0x21, &key, &key);
}