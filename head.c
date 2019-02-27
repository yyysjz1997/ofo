/**********************************************************
Copyright (C) 2015 ���� ������.
File name:		head.c
Author:			����
Version��		1.0
Date��			2015/10/25
Description��	�����ļ�

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
				
	1.	Date��2015/11/3
		Author������
		Version��1.0
		Modification����Ӻ���ClearKey
**********************************************************/

#include"head.h"

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
int Rand(int a, int b)
{
	/*���޲��������ޣ����򻥻�*/
	if (a > b)
	{
		a = a ^ b;
		b = a ^ b;
		a = a ^ b;
	}
	
	return (a + rand() % (b - a + 1));
}

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
void ClearKey(void)
{
	union REGS key;
	
	key.h.ah = 0x0c;
	key.h.al = 0x00;
	int86(0x21, &key, &key);
}