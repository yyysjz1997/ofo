//|---------------------------------------------------------|
//|����ƷΪҵ��֮���������ο� �����и���ʵ�ַ�����ӭ��������|
//|���ߣ�Blue_Sky���ٶ�id��qq��947818238                    |
//|---------------------------------------------------------|
#include <stdio.h>

#include <windows.h>
#include <conio.h>
#include <time.h>
#include <malloc.h>
void gotoxy(int x, int y);
void drd(int x,int y);//����
void drl(int x1,int y1,int x2,int y2);//����
void drawmap(struct snk *p);//��������������������ͼʳ�����
int keydown(int z);//��ȡ����
struct snk * mvsnk(struct snk *p,int z);//�����ߵ�����
void  mkfood(struct snk *p);//����ʳ��
int food[2]={20,15};
struct snk{//������
	int x;
	int y;
	int life;
	struct snk *link;
};
int speed=100;
int fen=0;//����
int jilu;//��߷ּ�¼
char jiluzhe[20];
int main()
{

		//��ʼ����
		FILE *fp;//���ļ�������߼�¼
		//if((fp=fopen("jiulu.txt","r"))==NULL)jilu=0;
		//else {fgets(jiluzhe,20,fp);
		//fscanf(fp,"%d",&jilu);}
		//fclose (fp);
		system("title ̰����");
		system("mode con cols=64 lines=30");
		int z=4;
		struct snk *snake;//ָ��������ͷ�Ľṹ��ָ��
		struct snk *snakelink;//������Ϸ�������ͷ��ڴ�ʱ����ʱ�洢
		struct food *fd;//ָ��ʳ��Ľṹ��ָ��
		//�����ĸ�����ڵ�Ϊ��ʼ���Ľ�������
		snake=(struct snk *)malloc(sizeof(struct snk));
		snake->x=10;snake->y=10;snake->life=1;

		snake->link=(struct snk *)malloc(sizeof(struct snk));
		snake->link->x=10;snake->link->y=9;

		snake->link->link=(struct snk *)malloc(sizeof(struct snk));
		snake->link->link->x=10;snake->link->link->y=8;

		snake->link->link->link=(struct snk *)malloc(sizeof(struct snk));
		snake->link->link->link->x=10;snake->link->link->link->y=7;
		snake->link->link->link->link=NULL;

		gotoxy(2,15);
		printf("W:��  S:��  A:��  D:��  Esc:������Ϸ�˳�");
		Sleep(2300);
	//��Ϸ��ѭ�� -----------------------------------------|
		while(1){
			int temp_z;temp_z=z;
			z=keydown(z);
			if(z==27)break;
			if(z==5){
			gotoxy(30,15);
			printf("��ͣ");
			getch();z=temp_z;}/*|*/
			snake=mvsnk(snake,z);
			if (snake->life==0)break;
			drawmap(snake);
			Sleep(300-speed);
		}

			gotoxy(30,15);
			printf("Game Over!!!");

		Sleep(1500);
		if (fen>jilu){

		gotoxy(30,15);
			printf("����������߼�¼!\n\t\t\t�������Ĵ����ɣ�\n\t\t\t");
			gets(jiluzhe);
			fp=fopen("jiulu.txt","w");
		 	fprintf(fp,"%s\n%d",jiluzhe,fen);
			fclose (fp);
			Sleep(1500);
		}


	return 0;
}
	//----------------------------------------------------|
int keydown(int z)//��ȡ����
{
	char ch;
	if(kbhit()){
			ch=getch();
			switch(ch){
				case 'A':
				case 'a':if(z!=2)z=1;break;
				case 'D':
				case 'd':if(z!=1)z=2;break;
				case 'W':
				case 'w':if(z!=4)z=3;break;
				case 'S':
				case 's':if(z!=3)z=4;break;
				case 'E':
				case 'e':z=5;break;
				default :break;
				}
			if(ch==27)z=27;
		}
	return z;
}





struct snk * mvsnk(struct snk *p,int z)//�����ߵ�����
{
	struct snk *p2;
	struct snk *p3;
	int x,y;
	x=p->x;
	y=p->y;
	switch(z){
		case 1:x-=2;break;
		case 2:x+=2;break;
		case 3:y--;break;
		case 4:y++;break;
	}
	//���ߵ�ͷ�����һ���ڵ�
	p2=(struct snk *)malloc(sizeof(struct snk));
	p2->x=x;p2->y=y;
	p2->link=p;
	p2->life=1;
	//�ж���ͷ�Ƿ���������
	p3=p;

while(p3!=NULL){
		if (p2->x==p3->x&&p2->y==p3->y)p2->life=0;
		p3=p3->link;
	}
	//�ж���ͷ�Ƿ�����ǽ��
	if (p2->x>58||p2->y>28||p2->x<1||p2->y<3)p2->life=0;

	if (p2->x==food[0]&&p2->y==food[1]){
		p2->life=2;fen++;speed<250?speed+=2:speed=250;
		mkfood(p2);/*����Ե�ʳ����ɾ�����һ���ڵ㣬����֮ǰ��ͷ��������һ���ڵ㣬�����ߵĳ�������һ�� */
	}else {while(p->link->link!=NULL)p=p->link;
		p3=p->link;
		p->link=NULL;
		free(p3);}//���û�гԵ�ʳ����ɾ�����һ���ڵ�

	return p2;
}

void mkfood(struct snk *p)
{
	struct snk *p2;
	p2=p;
	srand((unsigned)clock());//�趨���������
		food[1]=rand()%26+3;//�������ʳ������
		food[0]=(rand()%27)*2+2;
	//���ʳ��������Ƿ����������ظ�������ǣ�����������ʳ��
	do{
		if (food[0]==p->x&&food[1]==p->y){mkfood(p2);}
		p=p->link;
	} while(p!=NULL);
}


void drd(int x,int y)//����
{
	gotoxy(x,y);
	printf("��");

}

void drl(int x1,int y1,int x2,int y2)//����
{


	do{
	gotoxy(x1,y1);
	printf("��");
	x1<x2?x1+=2:x2;
	y1<y2?y1++:y2;
	}while(x1!=x2||y1!=y2);

}


void drawmap(struct snk *p)//����ͼʳ�����
{
	system("cls");

	drl(0,0,60,0);
	drl(0,2,60,2);
	gotoxy(2,1);
	printf("����:%d  �ٶ�:%d  ��߼�¼:%d  ������:%s",fen,speed,jilu,jiluzhe);
	drl(0,1,0,30);
	drl(0,29,60,29);
	drl(60,0,60,30);
	drd(p->x,p->y);

	drd(food[0],food[1]);
	p=p->link;
	while(p!=NULL){
		drd(p->x,p->y);
		p=p->link;
	}

}
void gotoxy(int x, int y)
{
COORD pos = {x,y};
HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
SetConsoleCursorPosition(hOut, pos);
}
