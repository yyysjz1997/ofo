/**********************************************************
Copyright (C) 2015 ���� ������.
File name:		head.h
Author:			����
Version��		1.0
Date��			2015/9/13
Description��	����ͷ�ļ�

Function List��
	1.int Rand(int a, int b);
		������ɲ�����һ���ڱ�����[a,b]��������
		
	2.void ClearKey(void);
		������̻���

History��		�Ա��ļ����޸��뼰ʱ�����¸�ʽ��¼�����棨ÿ���޸ĵ����г�����
	Example��	Date��
				Author��
				Version��
				Modification��
				
	1.	Date��2015/10/26
		Author������
		Version��1.0
		Modification����Ӻ���Rand�ⲿ����
		
	2.	Date��2015/11/3
		Author������
		Version��1.0
		Modification����Ӻ���ClearKey
		
	3.	Date��2015/11/5
		Author������
		Version��1.0
		Modification�����ͷ�ļ�bios.h
**********************************************************/
#ifndef	HEAD_H
#define	HEAD_H

#define	SCR_WIDTH	1024	/*SCREEN_WIDTH����д����Ļ������� */
#define	SCR_HEIGHT	768		/*SCREEN_HEIGHT����д����Ļ�߶����� */

#include<dos.h>			/*int86��outportb����ͷ�ļ���union REGS�Ķ����ļ�*/
#include<stdio.h>		/*�ļ���������ͷ�ļ�*/
#include<time.h>		/*time����ͷ�ļ���clock_t�Ķ���ͷ�ļ�*/
#include<math.h>		/*abs��fabs��sin��cos����ͷ�ļ�*/
#include<stdlib.h>		/*rand��srand��exit����ͷ�ļ�*/
#include<graphics.h>	/*�Դ���ͼ����ͷ�ļ�*/
#include<conio.h>		/*getch����ͷ�ļ�*/
#include<string.h>		/*memmove����ͷ�ļ�*/
#include<bios.h>		/*bioskey����ͷ�ļ�*/



/**********************************************************
Function��		Rand

Description��	������ɲ�����һ���ڱ�����[a,b]��������
				��a > b��ύ��a��b��С
				���ݲ��ԣ������ڲ�������time��ʼ�����������Ϊ�ˣ�
				��Ϊ�����������õ�ʱ�������̣�
				������ʼ�����ӻ���ִ���������

Calls��			rand
				
Called By��		CarAimA
				CarAimB
				CarAimC
				CarAimD
				CarNewCreate
				
Input��			int a	��������
				int b	��������
				
Output��		None

Return��		int		�ڱ�����[a,b]�������
				
Others��		None
**********************************************************/
extern int Rand(int a, int b);

/**********************************************************
Function��		ClearKey

Description��	������̻���

Calls��			int86
				
Called By��		AutoSimulate
				HandOperate
				
Input��			None
				
Output��		������̻���

Return��		None
Others��		None
**********************************************************/
extern void ClearKey(void);

#endif