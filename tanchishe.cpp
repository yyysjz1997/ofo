//|---------------------------------------------------------|
//|本作品为业余之作，仅供参考 ，如有更好实现方法欢迎交流！！|
//|作者：Blue_Sky，百度id及qq：947818238                    |
//|---------------------------------------------------------|
#include <stdio.h>

#include <windows.h>
#include <conio.h>
#include <time.h>
#include <malloc.h>
void gotoxy(int x, int y);
void drd(int x,int y);//画点
void drl(int x1,int y1,int x2,int y2);//画线
void drawmap(struct snk *p);//里用上面两个函数画地图食物和蛇
int keydown(int z);//获取输入
struct snk * mvsnk(struct snk *p,int z);//更新蛇的坐标
void  mkfood(struct snk *p);//产生食物
int food[2]={20,15};
struct snk{//蛇身体
	int x;
	int y;
	int life;
	struct snk *link;
};
int speed=100;
int fen=0;//积分
int jilu;//最高分记录
char jiluzhe[20];
int main()
{

		//初始化，
		FILE *fp;//从文件载入最高记录
		//if((fp=fopen("jiulu.txt","r"))==NULL)jilu=0;
		//else {fgets(jiluzhe,20,fp);
		//fscanf(fp,"%d",&jilu);}
		//fclose (fp);
		system("title 贪吃蛇");
		system("mode con cols=64 lines=30");
		int z=4;
		struct snk *snake;//指向蛇链表头的结构体指针
		struct snk *snakelink;//用于游戏结束后释放内存时的临时存储
		struct food *fd;//指向食物的结构体指针
		//声明四个链表节点为初始的四节蛇身体
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
		printf("W:上  S:下  A:左  D:右  Esc:结束游戏退出");
		Sleep(2300);
	//游戏主循环 -----------------------------------------|
		while(1){
			int temp_z;temp_z=z;
			z=keydown(z);
			if(z==27)break;
			if(z==5){
			gotoxy(30,15);
			printf("暂停");
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
			printf("您打破了最高记录!\n\t\t\t留下您的大名吧！\n\t\t\t");
			gets(jiluzhe);
			fp=fopen("jiulu.txt","w");
		 	fprintf(fp,"%s\n%d",jiluzhe,fen);
			fclose (fp);
			Sleep(1500);
		}


	return 0;
}
	//----------------------------------------------------|
int keydown(int z)//获取输入
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





struct snk * mvsnk(struct snk *p,int z)//更新蛇的坐标
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
	//在蛇的头部添加一个节点
	p2=(struct snk *)malloc(sizeof(struct snk));
	p2->x=x;p2->y=y;
	p2->link=p;
	p2->life=1;
	//判断蛇头是否碰到身体
	p3=p;

while(p3!=NULL){
		if (p2->x==p3->x&&p2->y==p3->y)p2->life=0;
		p3=p3->link;
	}
	//判断蛇头是否碰到墙壁
	if (p2->x>58||p2->y>28||p2->x<1||p2->y<3)p2->life=0;

	if (p2->x==food[0]&&p2->y==food[1]){
		p2->life=2;fen++;speed<250?speed+=2:speed=250;
		mkfood(p2);/*如果吃到食物则不删除最后一个节点，由于之前在头部增加了一个节点，所以蛇的长度增加一节 */
	}else {while(p->link->link!=NULL)p=p->link;
		p3=p->link;
		p->link=NULL;
		free(p3);}//如果没有吃到食物则删除最后一个节点

	return p2;
}

void mkfood(struct snk *p)
{
	struct snk *p2;
	p2=p;
	srand((unsigned)clock());//设定随机数种子
		food[1]=rand()%26+3;//随机产生食物坐标
		food[0]=(rand()%27)*2+2;
	//检测食物的坐标是否与蛇身体重复，如果是，则重新生成食物
	do{
		if (food[0]==p->x&&food[1]==p->y){mkfood(p2);}
		p=p->link;
	} while(p!=NULL);
}


void drd(int x,int y)//画点
{
	gotoxy(x,y);
	printf("口");

}

void drl(int x1,int y1,int x2,int y2)//画线
{


	do{
	gotoxy(x1,y1);
	printf("口");
	x1<x2?x1+=2:x2;
	y1<y2?y1++:y2;
	}while(x1!=x2||y1!=y2);

}


void drawmap(struct snk *p)//画地图食物和蛇
{
	system("cls");

	drl(0,0,60,0);
	drl(0,2,60,2);
	gotoxy(2,1);
	printf("分数:%d  速度:%d  最高记录:%d  保持者:%s",fen,speed,jilu,jiluzhe);
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
