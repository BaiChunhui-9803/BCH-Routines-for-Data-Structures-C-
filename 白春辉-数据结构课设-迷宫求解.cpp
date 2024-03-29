/*白春辉*/
/*数据结构课设*/
/*2018.06.27*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define STACKINCREMENT 10
#define STACK_INIT_SIZE 100//初始长度 

typedef int Status;
struct PosType  // 坐标竖直为x，横为y 
{
	int x;
	int y;
};
struct SElemType
{
	int ord; //路径的序号 
	PosType seat;  //坐标      
	int di;   //移动方向：上下左右 
};
struct SqStack
{
	SElemType *base;
	SElemType *top;
	int stacksize;
};
SqStack S;
#define MAXLENGTH 100 
typedef int MazeType[MAXLENGTH][MAXLENGTH]; //将数组做成地图。 
MazeType m;  
MazeType b;
int curstep = 2; //代表足迹 

Status InitStack(SqStack &S)
{
	S.base = (SElemType *)malloc(STACK_INIT_SIZE * sizeof(SElemType));
	if (!S.base) exit(OVERFLOW);
	S.top = S.base;//设为空栈 
	S.stacksize = STACK_INIT_SIZE;//设置长度 
	return OK;
}
Status Pop(SqStack &S, SElemType &e)//得到栈顶元素 
{
	if (S.base == S.top) return ERROR;
	e = *--S.top;  
	return OK;
}
Status StackEmpty(SqStack &S)//判断是否为空 
{
	if (!S.base) return ERROR;
	if (S.base == S.top) return TRUE;
	else return FALSE;
}
Status Push(SqStack &S, SElemType e)//进栈 
{
	if (S.top - S.base >= S.stacksize) 
	{
		S.base = (SElemType *)realloc(S.base, (S.stacksize + STACKINCREMENT) * sizeof(SElemType));//开空间 
		if (!S.base) exit(OVERFLOW); 
		S.top = S.base + S.stacksize;
		S.stacksize += STACKINCREMENT;
	}
	*S.top++ = e;
	return OK;
}
Status Pass(PosType a)//传参当前位置的坐标 
{   
	if (m[a.x][a.y] == 0)
	{
		return OK;
	}
	else
	{
		return ERROR;
	}
}
void FootPrint(PosType a)//对已经走过的路做成标记 1，2，3，4...
{
	m[a.x][a.y] = curstep;
}
PosType NextPos(PosType c, int di)//0-4上下左右 
{
	//作用是移动一个位置，所以需要传进来位置，移动方向，毕竟位移量已经确定为1
	PosType direc[5] = { {0,0}, { -1,0 },{ 1,0 },{ 0,-1 },{ 0,1 } };//上下左右 
	c.x += direc[di].x;
	c.y += direc[di].y;
	return c;
}
void MarkPrint(PosType a)//走不通 
{
	m[a.x][a.y] = -1;//此路不通 
}
void Print(int x, int y)  //迷宫的输出 
{
	int i, j;
	

	printf("  ");
	for (i = 0; i<y; i++)
	{
		if(i<10)
			printf("0%d",i);
		else
			printf("%d", i);
	}
	printf("\n");
	
	for (i = 0; i<x; i++)
	{

		if (i<10)
			printf("0%d", i);
		else
			printf("%d", i);

		for (j = 0; j<y; j++)
		{
			if (m[i][j] == 1)
				printf("■");
			else
				printf("□");
		}
		printf("\n");
	}
}


Status MazePath(PosType start, PosType end)//找通路 
{
	InitStack(S);//保存可以走的路径 
	SElemType e;
	PosType curpos = start;
	do
	{
		if (Pass(curpos))//如果当前位置的序号为0，即此位置不是迷宫中的墙  即为能走的路。 
		{
			FootPrint(curpos);//留下标记
			e.ord = curstep;  
			e.seat.x = curpos.x;
			e.seat.y = curpos.y;
			e.di = 0;
			Push(S, e);
			curstep++; 
			if (curpos.x == end.x&&curpos.y == end.y) return TRUE; 
			curpos = NextPos(curpos, e.di); 
		}
		else
		{
			if (!StackEmpty(S)) 
			{
				Pop(S, e); 
				curstep--;

				if (e.seat.x < end.x&&e.seat.y <= end.y)
				{

					while (e.di == 3 && !StackEmpty(S)) 
					{
						MarkPrint(e.seat);
						Pop(S, e);
						curstep--;
					}
					if (e.di == 0)//0—4代表上下左右 
					{
						e.di = 2;
						Push(S, e);
						curstep++;
						curpos = NextPos(e.seat, e.di);//下一步怎么移动
						
					}
					else if (e.di == 2)//0—4代表上下左右 
					{
						e.di = 4;
						Push(S, e);
						curstep++;
						curpos = NextPos(e.seat, e.di);//下一步怎么移动
						
					}
					else if (e.di == 4)//0—4代表上下左右 
					{
						e.di = 1;
						Push(S, e);
						curstep++;
						curpos = NextPos(e.seat, e.di);//下一步怎么移动
						
					}
					else if (e.di == 1)//0—4代表上下左右 
					{
						e.di = 3;
						Push(S, e);
						curstep++;
						curpos = NextPos(e.seat, e.di);//下一步怎么移动
					}
					
				}

				else if (e.seat.x <= end.x&&e.seat.y > end.y)
				{
					while (e.di == 1 && !StackEmpty(S)) 
					{
						MarkPrint(e.seat);
						Pop(S, e);
						curstep--;
					}
					 if (e.di == 0)//0—4代表上下左右 
					{
						e.di = 3;
						Push(S, e);
						curstep++;
						curpos = NextPos(e.seat, e.di);//下一步怎么移动
					}
					else if (e.di == 3)//0—4代表上下左右 
					{
						e.di = 2;
						Push(S, e);
						curstep++;
						curpos = NextPos(e.seat, e.di);//下一步怎么移动
					}
					else if (e.di == 2)//0—4代表上下左右 
					{
						e.di = 4;
						Push(S, e);
						curstep++;
						curpos = NextPos(e.seat, e.di);//下一步怎么移动
					}
					else if (e.di == 4)//0—4代表上下左右 
					{
						e.di = 1;
						Push(S, e);
						curstep++;
						curpos = NextPos(e.seat, e.di);//下一步怎么移动
					}
				}

				else if (e.seat.x >= end.x&&e.seat.y < end.y)
				{
					while (e.di == 2 && !StackEmpty(S))
					{
						MarkPrint(e.seat);
						Pop(S, e);
						curstep--;
					}
					if (e.di == 0)//0—4代表上下左右 
					{
						e.di = 4;
						Push(S, e);
						curstep++;
						curpos = NextPos(e.seat, e.di);//下一步怎么移动
					}
					else if (e.di == 4)//0—4代表上下左右 
					{
						e.di = 1;
						Push(S, e);
						curstep++;
						curpos = NextPos(e.seat, e.di);//下一步怎么移动
					}
					else if (e.di == 1)//0—4代表上下左右 
					{
						e.di = 3;
						Push(S, e);
						curstep++;
						curpos = NextPos(e.seat, e.di);//下一步怎么移动
					}
					else if (e.di == 3)//0—4代表上下左右 
					{
						e.di = 2;
						Push(S, e);
						curstep++;
						curpos = NextPos(e.seat, e.di);//下一步怎么移动
					}
				}
				
				else if (e.seat.x > end.x&&e.seat.y >= end.y)
				{
					while (e.di == 4 && !StackEmpty(S))
					{
						MarkPrint(e.seat);
						Pop(S, e);
						curstep--;
					}
					if (e.di == 0)//0—4代表上下左右 
					{
						e.di = 1;
						Push(S, e);
						curstep++;
						curpos = NextPos(e.seat, e.di);//下一步怎么移动
					}
					else if (e.di == 1)//0—4代表上下左右 
					{
						e.di = 3;
						Push(S, e);
						curstep++;
						curpos = NextPos(e.seat, e.di);//下一步怎么移动
					}
					else if (e.di == 3)//0—4代表上下左右 
					{
						e.di = 2;
						Push(S, e);
						curstep++;
						curpos = NextPos(e.seat, e.di);//下一步怎么移动
					}
					else if (e.di == 2)//0—4代表上下左右 
					{
						e.di = 4;
						Push(S, e);
						curstep++;
						curpos = NextPos(e.seat, e.di);//下一步怎么移动
					}
				}
			}
		}
	} 
	while (!StackEmpty(S));
	return FALSE;
}



void Print1(int x, int y)//有通路的迷宫的输出  
{

	int i, j;


	printf("  ");
	for (i = 0; i<y; i++)
	{

		if (i<10)
			printf("0%d",i);
		else
			printf("%d", i);
	}
	printf("\n");



	for (i = 0; i<x; i++)
	{

		if (i<10)
			printf("0%d", i);
		else
			printf("%d", i);


		for (j = 0; j<y; j++)
		{
			

			if (m[i][j] == 1)
			{
				printf("■");
			}

			else if (m[i][j] == -1 || m[i][j] == 0)
			{
				printf("□");
			}
			else if (m[i][j] >= 2)
			{

					switch (b[i][j])
					{
					case 0:
						printf("○");
						break;

					case 1:
						printf("↑");
						break;

					case 2:
						printf("↓");
						break;

					case 3:
						printf("←");
						break;

					case 4:
						printf("→");
						break;
					
				}
			}
		}
		printf("\n");
	}
}




void Auto_maze(int x, int y)
{
	int i, j;
	printf("\n迷宫生成中……\n\n");
	system("pause");
	srand(time(0));
	for (i = 0; i < x; i++)
		for (j = 0; j < y; j++)
		{
			if (i == 1 && j == 1)  m[i][j] = 0;
			else
			{
				if (rand() % 3) m[i][j] = 0;
				else m[i][j] = 1;
			}  
		}
			
}
void GenerateMaze(int x, int y)//生成迷宫地图 
{
	int i, j;
	int x1, y1;//障碍物坐标 
	for (i = 0; i<y; i++)
	{
		m[0][i] = 1;
		m[x - 1][i] = 1;
	}
	for (j = 0; j<x; j++)
	{
		m[j][0] = 1;
		m[j][y - 1] = 1;
	}
	for (i = 1; i<x - 1; i++)
	{
		for (j = 1; j<y - 1; j++)
		{
			m[i][j] = 0;
		}
	}
	
	Print(x, y);
	for (i = 0; i<x*y; i++)
	{
		printf("\n请输入迷宫中障碍物坐标：\n");
		scanf("%d%d", &x1, &y1);
		m[x1][y1] = !m[x1][y1];

		Print(x, y);

		if (x1 == 0 && y1 == 0) 
		{
			m[0][0] = 1;
			break;
		}
			
	}
	system("cls");
	printf("-------------------------------------迷宫图-------------------------------------\n");
	Print(x, y);
	
}
void Movingdirection(SElemType a)//用来显示迷宫通路怎么走
{
	

	switch (a.di)
	{
	case 0:
		b[a.seat.x][a.seat.y] = 0;
		printf("(%2d,%2d)   ○\n", a.seat.x, a.seat.y);
		break;
	case 1:
		b[a.seat.x][a.seat.y] = 1;
		printf("(%2d,%2d)   ↑		", a.seat.x, a.seat.y);
		break;
	case 2:
		b[a.seat.x][a.seat.y] = 2;
		printf("(%2d,%2d)   ↓		", a.seat.x, a.seat.y);
		break;
	case 3:
		b[a.seat.x][a.seat.y] = 3;
		printf("(%2d,%2d)   ←		", a.seat.x, a.seat.y);
		break;
	case 4:
		b[a.seat.x][a.seat.y] = 4;
		printf("(%2d,%2d)   →		", a.seat.x, a.seat.y);
		break;
	}
}
void MazePathway(PosType begin, PosType end, int x, int y)//显示迷宫通路图 
{
	SElemType a;
	SqStack T;
	InitStack(T);
	
	if (MazePath(begin, end))
	{
		
		while (!StackEmpty(S))
		{
			Pop(S, a);
			Push(T, a);
		}

		printf("找到的路径用坐标表示如下:\n");
		while (!StackEmpty(T))
		{
			Pop(T, a);
			Movingdirection(a);
		}

		
		printf("迷宫通路如下图所示:\n");
		Print1(x, y);

	}
	else
		printf("迷宫中没有出路\n");
}
int main()
{
	PosType begin, end;
	int x, y;
	int n;
	int i, j,k;
	char ch;
	printf("\n欢迎使用《迷宫求解》系统！\n\n");
	printf("\n请输入密码:\n");
	ch = _getch();
	putchar('*');
	if (ch == 'b')
	{

		printf("密码正确\n");
		while (1)
		{

			printf("\n---------1.手    动---------\n");
			printf("\n---------2.自    动---------\n");
			printf("\n---------3.退    出---------\n");
			printf("\n请输入：");
			scanf("%d", &n);
			system("CLS");
			switch (n)
			{
			case 1:
				printf("请输入迷宫的宽和长：");
				scanf("%d%d", &x, &y);
				GenerateMaze(x, y);
				do
				{
				
					printf("请输入起点的坐标：");
					scanf("%d%d", &begin.x, &begin.y);				
					printf("请输入终点的坐标：");				
					scanf("%d%d", &end.x, &end.y);			
					MazePathway(begin, end, x, y);				
					printf("\n1.继续测试/2.返回菜单\n");				
					scanf("%d", &k);				
					for (i = 0; i < x; i++)				
					{					
						for (j = 0; j < y; j++)					
						{					
							if (m[i][j] == -1 || m[i][j] >= 2)					
							{					
								m[i][j] = 0;					
							}					
						}				
					}			
				} while (k == 1);
				break;
			case 2:
				printf("请输入迷宫的宽和长：");
				scanf("%d%d", &x, &y);
				Auto_maze(x, y);
				do 				
				{	
					for (i = 0; i < y; i++)			
					{					
						m[0][i] = 1;					
						m[x - 1][i] = 1;				
					}				
					for (j = 0; j < x; j++)				
					{					
						m[j][0] = 1;					
						m[j][y - 1] = 1;				
					}
					Print(x, y);
					printf("请输入起点的坐标：");				
					scanf("%d%d", &begin.x, &begin.y);				
					printf("请输入终点的坐标：");				
					scanf("%d%d", &end.x, &end.y);				
					MazePathway(begin, end, x, y);
					printf("\n1.继续测试/2.返回菜单\n");
					scanf("%d", &k);

					for (i = 0; i < x; i++)
					{
						for (j = 0; j < y; j++)
						{
							if (m[i][j] == -1 || m[i][j] >= 2)
							{
								m[i][j] = 0;
							}
						}
					}
				} while (k == 1);
				break;

			case 3: exit(-1);

			}
		}
		return 0;
	}
	else 
	{
		printf("密码错误\n");
		exit(-1);
	}
		
}