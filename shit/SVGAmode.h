/**********************************************************
Copyright (C) 2015 ���� ������.
File name:		SVGAmode.H
Author:			����
Version��		2.0
Date��			2015/8/12
Description��	SVGA��ʾģʽͷ�ļ���������ģʽ�»����ĳ�ʼ��������������������ͼ��������ͼ�����ȵ�ʵ�֡�
				�괦����SVGAmode.h�С�

				��Ϊ�궨���Ե�ʣ��Ͻ��������ļ��ж�������ΪR��G��B��r��g��b�ı�����
				Ϊ����graphics.h�еĺ�������������д����������ĸ��д��
				������д����������Ļ�ο�ϵΪ׼��

				����Line��Circle��CirclefillΪ���ϴ��룬�����빤������

				�Ա��ļ����޸��뼰ʱ�����¸�ʽ��¼�����棨ÿ���޸ĵ����г�����

Function List��
	1.void SetSVGA256(void);
		SVGA��ʾģʽ���ú�������Ϊ0x105

	2.void SetSVGA64k(void);
		SVGA��ʾģʽ���ú�������Ϊ0x117

	3.unsigned int GetSVGA(void);
		��ȡSVGA��ʾģʽ��bx

	4.void Selectpage(register char page);
		���жϹ��ܵĻ�ҳ�����������д�Դ�ʱ���Ѱַ����

	5.void Putpixel256(int x, int y, unsigned char color);
		���㺯����������ͼ�����Ļ�������������0x105ģʽ��

	6.void Putpixel64k(int x, int y, unsigned int color);
		���㺯����������ͼ�����Ļ�������������0x117ģʽ��

	7.int Putbmp256(int x, int y, const char * path);
		8λ��ѹ��bmpͼ��λ��ʾ����

	8.int Putbmp64k(int x, int y, const char * path);
		24λ��ѹ��bmpͼ��λ��ʾ����

	9.void Xorpixel(int x, int y, unsigned char color);
		��λ��򻭵㺯��

	10.void Horizline(int x, int y, int width, unsigned char color);
		��ˮƽ�ߺ���

	11.void Line(int x1, int y1, int x2, int y2, unsigned char color);
		��һ��ֱ�ߺ���

	12.void Bar(int x1, int y1, int x2, int y2, unsigned char color);
		�����ο麯��

	13.void Circle(int xc, int yc, int radius, unsigned char color);
		��ԲȦ����

	14.void Circlefill(int xc, int yc, int radius, unsigned char color);
		��ʵ��Բ����

History��		�Ա��ļ����޸��뼰ʱ�����¸�ʽ��¼�����棨ÿ���޸ĵ����г�����
	Example��	Date��
				Author��
				Version��
				Modification��

	1.	Date��2015/8/14
		Author������
		Version��2.0
		Modification���ļ��ദ�ش��޸ģ��汾����Ϊ2.0���ļ�����ΪSVGAmode.h

	2.	Date��2015/8/14
		Author������
		Version��2.0
		Modification������ʵ�ֲ��ֳַ�Ϊ���ļ�SVGAmode.c�����ļ�ֻ���й�����

	3.	Date��2015/8/14
		Author������
		Version��2.0
		Modification���������к�����
						int Putbmp(int x, int y, const char * path)

	4.	Date��2015/8/14
		Author������
		Version��2.0
		Modification���������½ṹ����
						��ͼ������ɫ����ɫ�ṹCOLORS
						bmpλͼ��ɫ����ɫ�ṹRGBQUAD
						bmpλͼ��Ϣͷ�ṹBITMAPINFOHEADER�����飩

	5.	Date��2015/9/2
		Author������
		Version��2.1
		Modification���ļ��ദ�޸ģ���SVGAmode.c�Ѱ汾����Ϊ2.1

	6.	Date��2015/9/2
		Author������
		Version��2.1
		Modification�����Ӷ���24λbmpͼ��ɫ�ṹCOLORS24

	7.	Date��2015/9/3
		Author������
		Version��2.1
		Modification�����ֺ��������¸�������Ӧע���޸�
					  SetSVGA��ΪSetSVGA256
					  Putbmp��ΪPutbmp256
					  Putpixel��ΪPutpixel256

	8.	Date��2015/9/3
		Author������
		Version��2.1
		Modification���������º�����
					  SetSVGA64k
					  Putpixel64k
					  Putbmp64k
					  ����SVGAģʽ������256ɫ��64kɫ����ѡ��
					  ���߽�����24λbmpת16λ��ͼ�����ͻ��㺯��������������ͼ����һ�ɲ����ã�

	9.	Date��2015/9/12
		Author������
		Version��2.1
		Modification���ѹ��õ�ͷ�ļ�������γ�head.h

	10.	Date��2015/11/5
		Author������
		Version��2.1
		Modification��ɾȥ14�����ú����;���ע�ͣ����ļ���������
**********************************************************/

#ifndef	SVGA_H
#define	SVGA_H

#include"head.h"

/*��ͼ������ɫ����ɫ�ṹ*/
typedef struct
{
	unsigned char R;	/*��ɫ������RED��д*/
	unsigned char G;	/*��ɫ������GREEN��д*/
	unsigned char B;	/*��ɫ������BLUE��д*/
} COLORS;

/*24λbmpͼ��ɫ�ṹ*/
typedef struct
{
	unsigned char B;	/*��ɫ������BLUE��д*/
	unsigned char G;	/*��ɫ������GREEN��д*/
	unsigned char R;	/*��ɫ������RED��д*/
} COLORS24;

/*bmpλͼ��ɫ����ɫ�ṹ*/
typedef struct tagRGBQUAD
{
    unsigned char b;	/*��ɫ������RED��д*/
	unsigned char g;	/*��ɫ������GREEN��д*/
	unsigned char r;	/*��ɫ������BLUE��д*/
	unsigned char reserved;		/*������*/
} RGBQUAD;

/*bmpλͼ��Ϣͷ��������˵��λͼ�ĳߴ����Ϣ*/
typedef struct tagBITMAPINFOHEADER
{
	unsigned long int biSize;	/*���ṹ��ռ���ֽ�����15-18�ֽڣ�*/
	long int biWidth;			/*λͼ�Ŀ��ȣ�������Ϊ��λ��19-22�ֽڣ�*/
	long int biHeight;			/*λͼ�ĸ߶ȣ�������Ϊ��λ��23-26�ֽڣ�*/
	unsigned int biPlanes;		/*Ŀ���豸�ļ��𣬱���Ϊ1(27-28�ֽڣ�*/
	unsigned int biBitCount;	/*ÿ�����������λ����������1��˫ɫ����4(16ɫ����8(256ɫ��16(�߲�ɫ)��24�����ɫ��֮һ��29-30�ֽڣ�*/
	unsigned long int biCompression;	/*λͼѹ�����ͣ�������0����ѹ������1(BI_RLE8ѹ�����ͣ���2(BI_RLE4ѹ�����ͣ�֮һ��31-34�ֽڣ�*/
	unsigned long int biSizeImage;		/*λͼ�Ĵ�С(���а�����Ϊ�˲���������4�ı��������ӵĿ��ֽ�)�����ֽ�Ϊ��λ��35-38�ֽڣ�*/
	long int biXPelsPerMeter;			/*λͼˮƽ�ֱ��ʣ�ÿ����������39-42�ֽڣ�*/
	long int biYPelsPerMeter;			/*λͼ��ֱ�ֱ��ʣ�ÿ����������43-46�ֽ�)*/
	unsigned long int biClrUsed;		/*λͼʵ��ʹ�õ���ɫ���е���ɫ����47-50�ֽڣ�*/
	unsigned long int biClrImportant;	/*λͼ��ʾ��������Ҫ����ɫ����51-54�ֽڣ�*/
} BITMAPINFOHEADER;

/**********************************************************
Function��		SetSVGA256

Description��	SVGA��ʾģʽ���ú�������Ϊ0x105

Calls��			int86
				delay
				printf
				exit

Called By��		AutoSimulate
				HandOperate

Input��			None

Output��		������Ϣ

Return��		None
Others��		None
**********************************************************/
extern void SetSVGA256(void);

/**********************************************************
Function��		SetSVGA64k

Description��	SVGA��ʾģʽ���ú�������Ϊ0x117

Calls��			int86
				delay
				printf
				exit

Called By��		AutoSimulate
				HandOperate

Input��			None

Output��		������Ϣ

Return��		None
Others��		None
**********************************************************/
extern void SetSVGA64k(void);

/**********************************************************
Function��		GetSVGA

Description��	��ȡSVGA��ʾģʽ��bx��ժ¼���õ�ģʽ�����£�
				ģʽ��		�ֱ���		��ɫ��		��ɫλ����
				0x101		640*480		256				-
				0x103		800*600		256				-
				0x104		1024*768	16				-
				0x105		1024*768	256				-
				0x110		640*480		32K			1:5:5:5
				0x111		640*480		64K			5:6:5
				0x112		640*480		16.8M		8:8:8
				0x113		800*600		32K			1:5:5:5
				0x114		800*600		64K			5:6:5
				0x115		800*600		16.8M		8:8:8
				0x116		1024*768	32K			1:5:5:5
				0x117		1024*768	64K			5:6:5
				0x118		1024*768	16.8M		8:8:8

Calls��			int86
				delay
				printf
				exit

Called By��		Unknown
Input��			None

Output��		��ʼ��ʧ��ʱ����Ļ�������š�

Return��		unsigned int graph_regs.x.bx	��ʾģʽ��

Others��		None
**********************************************************/
extern unsigned int GetSVGA(void);

/**********************************************************
Function��		Selectpage

Description��	���жϹ��ܵĻ�ҳ�����������д�Դ�ʱ���Ѱַ����

Calls��			int86

Called By��		Putpixel256
				Putpixel64k
				Xorpixel
				Horizline
				Getpixel64k

Input��			register char page		��Ҫ������ҳ���

Output��		None

Return��		None
Others��		None
**********************************************************/
extern void Selectpage(register char page);

/**********************************************************
Function��		Putpixel256

Description��	���㺯����������ͼ�����Ļ�������������0x105ģʽ��

Calls��			Selectpage

Called By��		Putbmp256
				Line
				Circle

Input��			int x					���غ����꣬���������ӣ�0Ϊ��Сֵ����Ļ�ο�ϵ��
				int y					���������꣬���ϵ������ӣ�0Ϊ��Сֵ����Ļ�ο�ϵ��
				unsigned char color		��ɫ��������256��

Output��		����Ļ�ϻ�ָ����ɫ�ĵ�

Return��		None
Others��		None
**********************************************************/
extern void Putpixel256(int x, int y, unsigned char color);

/**********************************************************
Function��		Putpixel64k

Description��	���㺯����������ͼ�����Ļ�������������0x117ģʽ��

Calls��			Selectpage

Called By��		Putbmp64k
				MousePutBk
				MouseDraw

Input��			int x					���غ����꣬���������ӣ�0Ϊ��Сֵ����Ļ�ο�ϵ��
				int y					���������꣬���ϵ������ӣ�0Ϊ��Сֵ����Ļ�ο�ϵ��
				unsigned int color		��ɫ��������64k��

Output��		����Ļ�ϻ�ָ����ɫ�ĵ�

Return��		None
Others��		None
**********************************************************/
extern void Putpixel64k(int x, int y, unsigned int color);

/**********************************************************
Function��		Putbmp256

Description��	8λ��ѹ��bmpͼ��λ��ʾ������
				ֻ֧��8λ��ѹ��bmpͼ�����������������Ϊ1024��
				����bmp���;���֧�֣�
				����0x105ģʽ��ʹ�ã�
				Ϊ�˼򻯣�û�������ļ����ͼ�⹦�ܼ�⹦�ܣ�������벻��Ҫ����ļ���
				�˺����ʺ��ڲ���λ�������¶�ȡ����ͼƬ��
				��Ȼ�������˶�ȡ��ɫ�����ܣ����ܼ���ʵ��ʹ����ɫ���������������ͼƬ��
				��ͳһҪ��ʹ��WindowsĬ����ɫ��������Ӱ������ͼƬ��ʾ��

Calls��			Putpixel256

				fseek
				fread
				fclose
				outportb
				malloc
				free

Called By��		AutoSimulate
				HandOperate

Input��			int x		ͼƬ���Ͻǵĺ����꣨��Ļ�ο�ϵ��
				int y		ͼƬ���Ͻǵ������꣨��Ļ�ο�ϵ��
				const char * path	bmpͼƬ·��

Output��		��Ļ����ʾͼƬ

Return��		0	��ʾ�ɹ�
				-1	��ʾʧ��

Others��		None
**********************************************************/
extern int Putbmp256(int x, int y, const char * path);

/**********************************************************
Function��		Putbmp64k

Description��	24λ��ѹ��bmpͼ��λ��ʾ������
				ֻ֧��24λ��ѹ��bmpͼ�����������������Ϊ1024��
				����bmp���;���֧�֣�
				����0x117ģʽ��ʹ�ã�
				Ϊ�˼򻯣�û�������ļ����ͼ�⹦�ܼ�⹦�ܣ�������벻��Ҫ����ļ���

Calls��			Putpixel64k

				fseek
				fread
				fclose
				outportb
				malloc
				free

Called By��		AutoSimulate
				HandOperate
				Menu

Input��			int x		ͼƬ���Ͻǵĺ����꣨��Ļ�ο�ϵ��
				int y		ͼƬ���Ͻǵ������꣨��Ļ�ο�ϵ��
				const char * path	bmpͼƬ·��

Output��		��Ļ����ʾͼƬ

Return��		0	��ʾ�ɹ�
				-1	��ʾʧ��

Others��		None
**********************************************************/
extern int Putbmp64k(int x, int y, const char * path);

/**********************************************************
Function��		Xorpixel

Description��	��λ��򻭵㺯��

Calls��			Selectpage

Called By��		XorCarBmp

Input��			int x					���غ����꣬���������ӣ�0Ϊ��Сֵ����Ļ�ο�ϵ��
				int y					���������꣬���ϵ������ӣ�0Ϊ��Сֵ����Ļ�ο�ϵ��
				unsigned char color		��ɫ��������256��

Output��		����Ļ�ϻ�����

Return��		None
Others��		None
**********************************************************/
extern void Xorpixel(int x, int y, unsigned char color);

/**********************************************************
Function��		Horizline

Description��	��ˮƽ�ߺ���
				���Խ��ճ�����Ļ��Χ�����ݣ�ֻ��������Ļ�ڲ���
				��Ϊû�з�ֹ���ͱ���������жϣ���������Ļ����ʱӦ��ֹ�����ش�����

Calls��			Selectpage

Called By��		Line
				Bar
				Circlefill

Input��			int x					��ʼ������꣬���������ӣ�0Ϊ��Сֵ����Ļ�ο�ϵ��
				int y					��ʼ�������꣬���ϵ������ӣ�0Ϊ��Сֵ����Ļ�ο�ϵ��
				int width				ˮƽ���ȣ�Ϊ���������죬Ϊ����������
				unsigned char color		��ɫ��������256��

Output��		��Ļ�ϻ���ˮƽ��

Return��		None
Others��		None
**********************************************************/
extern void Horizline(int x, int y, int width, unsigned char color);

/**********************************************************
Function��		Line

Description��	��һ��ֱ�ߺ���
				���Խ��ճ�����Ļ��Χ�����ݣ�ֻ��������Ļ�ڲ���
				��Ϊû�з�ֹ���ͱ���������жϣ���������Ļ����ʱӦ��ֹ�����ش�����

Calls��			Putpixel256

				abs

Called By��		LightSW
				LightNE
				LightNW
				LightSE

Input��			int x1					��ʼ������꣬���������ӣ�0Ϊ��Сֵ����Ļ�ο�ϵ��
				int y1					��ʼ�������꣬���ϵ������ӣ�0Ϊ��Сֵ����Ļ�ο�ϵ��
				int x2					��ֹ������꣨��Ļ�ο�ϵ��
				int y2					��ֹ�������꣨��Ļ�ο�ϵ��
				unsigned char color		��ɫ��������256��

Output��		��Ļ�ϻ���ֱ��

Return��		None
Others��		None
**********************************************************/
extern void Line(int x1, int y1, int x2, int y2, unsigned char color);

/**********************************************************
Function��		Bar
Description��	�����ο麯��
				���Խ��ճ�����Ļ��Χ�����ݣ�ֻ��������Ļ�ڲ���
				��Ϊû�з�ֹ���ͱ���������жϣ���������Ļ�Ĳ���ʱӦ��ֹ�����ش�����

Calls��			Horizline

Called By��		LightSW
				LightNE
				LightNW
				LightSE

Input��			int x1					�Խǵ�1�ĺ����꣬���������ӣ�0Ϊ��Сֵ����Ļ�ο�ϵ��
				int y1					�Խǵ�1�������꣬���ϵ������ӣ�0Ϊ��Сֵ����Ļ�ο�ϵ��
				int x2					�Խǵ�2�ĺ����꣬���������ӣ�0Ϊ��Сֵ����Ļ�ο�ϵ��
				int y2					�Խǵ�2�������꣬���ϵ������ӣ�0Ϊ��Сֵ����Ļ�ο�ϵ��
				unsigned char color		��ɫ��������256��

Output��		��Ļ�ϻ������ο�

Return��		None
Others��		None
**********************************************************/
extern void Bar(int x1, int y1, int x2, int y2, unsigned char color);

/**********************************************************
Function��		Circle
Description��	��ԲȦ����
				���Խ��ճ�����Ļ��Χ�����ݣ�ֻ��������Ļ�ڲ���
				��Ϊû�з�ֹ���ͱ���������жϣ���������Ļ�Ĳ���ʱӦ��ֹ�����ش�����

Calls��			Putpixel256

Called By��		LightSW
				LightNE
				LightNW
				LightSE

Input��			int xc					x_center����д��Բ�ĺ����꣨��Ļ�ο�ϵ��
				int yc					y_center����д��Բ�������꣨��Ļ�ο�ϵ��
				int radius				�뾶������Ϊ��
				unsigned char color		��ɫ��������256��

Output��		��Ļ�ϻ���ԲȦ

Return��		None
Others��		None
**********************************************************/
extern void Circle(int xc, int yc, int radius, unsigned char color);

/**********************************************************
Function��		Circlefill
Description��	��ʵ��Բ����
				���Խ��ճ�����Ļ��Χ�����ݣ�ֻ��������Ļ�ڲ���
				��Ϊû�з�ֹ���ͱ���������жϣ���������Ļ�Ĳ���ʱӦ��ֹ�����ش�����

Calls��			Horizline

Called By��		LightColorR
				LightColorY
				LightColorG
				LightColor1
				LightColor2
				LightColor3
				LightColor4
				LightColorD1
				LightColorD2
				LightColorD3
				TrafficLight

Input��			int xc					x_center����д��Բ�ĺ����꣨��Ļ�ο�ϵ��
				int yc					y_center����д��Բ�������꣨��Ļ�ο�ϵ��
				int radius				�뾶������Ϊ��
				unsigned char color		��ɫ��������256��

Output��		��Ļ�ϻ���ԲȦ

Return��		None
Others��		None
**********************************************************/
extern void Circlefill(int xc, int yc, int radius, unsigned char color);
int Getpixel64k(int x, int y);
int Putbmp64k_TMB(int x, int y, const char * path);   //�Ѻ�ɫ��Ϊ͸������ͼ����
int Putbmp64k_TMW(int x, int y, const char * path);   //�Ѱ�ɫ��Ϊ͸������ͼ����


#endif