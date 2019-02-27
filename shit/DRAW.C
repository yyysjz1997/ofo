#include"draw.h"

/**********************************************************
Function��   Linex

Description��  ��SVGAģʽ�»���ˮƽ�ߵĺ���

Input��     x1   ��ʼ��ĺ�����
            y1   ��ʼ���������
            x2   ��ֹ��ĺ�����
            y2   ��ֹ���������
            color   �ߵ���ɫֵ

Output��   �����õ����������Ļ��

Return��   ��

Others��   ��
**********************************************************/

int Linex(int x1,int y1,int x2, int y2,int color)   //��ˮƽ�ߵĺ���
{
  int i;
  if(x1>=1024||x2>=1024||y1>=768||y2>=768)
  return(0);

  if(x1<=0||x2<=0||y1<=0||y2<=0)
  return(0);

  if(y1!=y2||x1>x2)
  return(0);
  for(i=x1;i<=x2;i++)
  Putpixel64k(i,y1,color);
  return 0;
}

/**********************************************************
Function��   Liney

Description��  ��SVGAģʽ�»�����ֱ�ߵĺ���

Input��     x1   ��ʼ��ĺ�����
            y1   ��ʼ���������
            x2   ��ֹ��ĺ�����
            y2   ��ֹ���������
            color   �ߵ���ɫֵ

Output��   �����õ����������Ļ��

Return��   ��

Others��   ��
**********************************************************/

int Liney(int x1,int y1,int x2, int y2,int color)    //����ֱ�ߵĺ���
{
  int i;
  if(x1>=1024||x2>=1024||y1>=768||y2>=768)
  return(0);

  if(x1<=0||x2<=0||y1<=0||y2<=0)
  return(0);

  if(x1!=x2||y1>y2)
  return(0);
  for(i=y1;i<=y2;i++)
  Putpixel64k(x1,i,color);
  return 0;
}

/**********************************************************
Function��   Bar64k

Description��  ��SVGAģʽ��,��Liney����Ϊ��������ʵ�ĵľ��εĺ���

Input��     x1   �������Ͻǵ�ĺ�����
            y1   �������Ͻǵ��������
            x2   �������½ǵ�ĺ�����
            y2   �������½ǵ��������
            color   ���ε���ɫֵ

Output��   �����õľ����������Ļ��

Return��   ��

Others��   ��
**********************************************************/

int Bar64k(int x1,int y1,int x2,int y2,int color)   //��ǰLiney����Ϊ��������ʵ�ĵľ��εĺ���
{
  int i;
  if(x1>=1024||x2>=1024||y1>=768||y2>=768)
  return(0);

  if(x1<=0||x2<=0||y1<=0||y2<=0)
  return(0);

  if(x1>=x2||y1>=y2)
  return(0);

  for(i=x1;i<=x2;i++)
  {
	Liney(i,y1,i,y2,color);
  }
  return 0;
}

/**********************************************************
Function��   Tri_L

Description��  ��SVGAģʽ��,��Liney����Ϊ���������������εĺ���

Input��     x   �����ζ���ĺ�����
            y   �����ζ����������
            color   ���ε���ɫֵ

Output��   �����õ����������������Ļ��

Return��   ��

Others��   ��
**********************************************************/

void Tri_L(int x,int y,int color)      //��Liney����Ϊ���������������εĺ���
{
  int i;
  for(i=0;i<=39;i++)
  {
	Liney(x-i,y+(i+1)/2,x-i,y+40-(i+1)/2,color);
  }

}

/**********************************************************
Function��   Tri_R

Description��  ��SVGAģʽ��,��Liney����Ϊ���������������εĺ���

Input��     x   �����ζ���ĺ�����
            y   �����ζ����������
            color   ���ε���ɫֵ

Output��   �����õ����������������Ļ��

Return��   ��

Others��   ��
**********************************************************/

void Tri_R(int x,int y,int color)     //��ǰLiney����Ϊ���������������εĺ���
{
  int i;
  for(i=0;i<=39;i++)
  {
	Liney(x+i,y+(i+1)/2,x+i,y+40-(i+1)/2,color);
  }
}

/**********************************************************
Function��   circley

Description��  ��SVGAģʽ��,��Liney����Ϊ��������Բ�ĺ���

Input��     x   Բ�ĵĺ�����
            y   Բ�ĵ�������
            r   Բ�İ뾶
            color   Բ������ɫֵ

Output��   �����õ�Բ�������Ļ��

Return��   ��

Others��   ��
**********************************************************/

void circley(int x,int y,int r,int color)  //��ǰLiney����Ϊ��������Բ�ĺ���
{
    int x0=0,y0=r;
    int d=1-r;

    while(y0>x0)
    {
        Liney(x0+x,y0+y,x0+x,y0+y,color);
        Liney(y0+x,x0+y,y0+x,x0+y,color);
        Liney(-x0+x,y0+y,-x0+x,y0+y,color);
        Liney(-y0+x,x0+y,-y0+x,x0+y,color);
        Liney(-x0+x,-y0+y,-x0+x,-y0+y,color);
        Liney(-y0+x,-x0+y,-y0+x,-x0+y,color);
        Liney(x0+x,-y0+y,x0+x,-y0+y,color);
        Liney(y0+x,-x0+y,y0+x,-x0+y,color);
        if(d<0)
            d=d+2*x0+3;
        else
        {
            d=d+2*(x0-y0)+5;
            y0--;
        }
        x0++;
    }
}

/**********************************************************
Function��   circle_fill

Description��  ��SVGAģʽ��,��Liney�Լ�circley����Ϊ��������ʵ��Բ�ĺ���

Input��     x   Բ�ĵĺ�����
            y   Բ�ĵ�������
            r   Բ�İ뾶
            color   Բ������ɫֵ

Output��   �����õ�ʵ��Բ�������Ļ��

Return��   ��

Others��   ��
**********************************************************/

void circle_fill(int x,int y,int r,int color)   //��ǰLiney�����Լ�circley����Ϊ��������ʵ��Բ�ĺ���
{
   int i;
   for(i=1;i<=r;i++)
   {
      circley(x,y,i,color);
   }
}