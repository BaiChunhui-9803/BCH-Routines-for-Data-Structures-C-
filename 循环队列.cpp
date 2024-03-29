/*白春辉*/
/*循环队列*/
/*2018.06.05*/

#include<iostream>  
#include<cstdio>  
#include<cstdlib>  
#define MAXQSIZE 20

typedef int QElemType;
typedef int Status;


typedef struct
{
	QElemType *base;
	int front;
	int  rear;
}SqQueue;

int Init_Queue(SqQueue &Q)                          //1、构造一个空队列 
{
	 
	Q.base = (QElemType*)malloc(MAXQSIZE * sizeof(QElemType));
	if (!Q.base)//存储空间分配失败
	{
		printf("\n队列创建失败！\n");   
		return 0;
	}    
	Q.front = Q.rear = 0;
	printf("\n队列创建成功！\n");

	return 1;
}


void Destroy_Queue(SqQueue &Q)                         //2、销毁
{
	Q.front = Q.rear = 0;
	while (Q.front != Q.rear)
	{
		free(&Q.base[Q.front]);
		Q.front = (Q.front + 1) % MAXQSIZE;
	}
	printf("\n队列销毁成功！\n");
}


void  Clear_Queue(SqQueue &Q)                           //3、清空
{
	Q.front = Q.rear = 0;
	printf("\n队列清空成功！\n");
}




Status Queue_Empty(SqQueue &Q)                               //4、判空
{
	if (Q.front == Q.rear)
	{
		printf("\n当前队列是否为空：TRUE\n");
		return 1;
	}
		
	printf("\n当前队列是否为空：FALSE\n");
	return 0;
}




Status Queue_Length(SqQueue Q)                               //5、求队长
{
	int length = 0;
	length = (Q.rear - Q.front + MAXQSIZE) % MAXQSIZE;
	printf("\n当前队列队长为：%d\n",length);
	return length;
}




Status Get_Head(SqQueue &Q)                              //6、取首元素
{
	QElemType e;
	if (Q.front == Q.rear)
	{
		printf("\n当前队列为空队列\n");
		return 0;
	}
		
	e = Q.base[Q.front];
	printf("\n队头元素为：%d\n",e );
	return e;
}




Status En_Queue(SqQueue &Q, QElemType e)                    //7、入队
{
	if ((Q.rear + 1) % MAXQSIZE == Q.front)
	{
		printf("\n当前队列已满\n");
		return 0;
	}
		
	Q.base[Q.rear] = e;
	Q.rear = (Q.rear + 1) % MAXQSIZE;
	printf("\n元素%d入队成功！\n",e);
	return 1;
}




Status De_Queue(SqQueue &Q)                                //8、出队
{
	QElemType e;
	if (Q.front == Q.rear)
	{
		printf("\n当前队列为空队列\n");
		return 0;
	}
	e = Q.base[Q.front];
	Q.front = (Q.front + 1) % MAXQSIZE;
	printf("\n元素%d出队成功！\n",e);
	return e;
}




void Queue_Traver(SqQueue &Q)                             //9、遍历队
{
	int i = Q.front;
	printf("\n遍历结果为：\n\n← …… ");
	while (i != Q.rear)
	{
		printf(" %d ", Q.base[i]);
		i++;
	}
	printf(" …… ←\n\n");
}

void Rand_Queue(SqQueue &Q)                             //10、生成一段随机队列
{
	int n,r;
	printf("\n请输入循环队列的长度：");
	scanf("%d", &n);
	Init_Queue(Q);
	if (n>=MAXQSIZE||n<1)
	{
		printf("\n参数n输入有误\n");
	}
	else
		for (int i = 1; i <= n; i++)
		{
			r = rand() % 100;
			Q.base[Q.rear] = r;
			printf("\n元素%d入队成功！", r);
			Q.rear = (Q.rear + 1) % MAXQSIZE;
		}
}



int main()
{
	printf("初始化\n");
	SqQueue Q;

	int  x, cord, e, m;


	do {
		printf("\n**********************************************************\n");
		printf("\n				\n");
		printf("1---构造空队列			");
		printf("2---销毁队列			");
		printf("3---清空队列	\n\n");
		printf("4---空队列检验			");						  //若S为空栈，则返回TUSE；否则返回FALSE
		printf("5---队列长			");
		printf("6---队头	\n\n");
		printf("7---入队			");
		printf("8---出队			");
		printf("9--显示当前队列\n\n");
		printf("10--生成一段随机队列		");
		printf("0---结束程序			\n");


		printf("\n\n请输入您选的的菜单号<1,2,3,4,5,6,7,8,9,10,0>:");
		scanf("%d", &cord);
		switch (cord)
		{

		case 1:
			SqQueue S;
			Init_Queue(S);

			printf("\n是否继续操作?(1/是；0/否)");
			scanf("%d", &m);
			if (m)
				break;
			else
			{
				exit(0);
				break;
			}

		case 2:
			Destroy_Queue(Q);

			printf("\n是否继续操作?(1/是；0/否)");
			scanf("%d", &m);
			if (m)
				break;
			else
			{
				exit(0);
				break;
			}

		case 3:
			Clear_Queue(Q);

			printf("\n是否继续操作?(1/是；0/否)");
			scanf("%d", &m);
			if (m)
				break;
			else
			{
				exit(0);
				break;
			}

		case 4:

			Queue_Empty(Q);


			printf("\n是否继续操作?(1/是；0/否)");
			scanf("%d", &m);
			if (m)
				break;
			else
			{
				exit(0);
				break;
			}

		case 5:
			Queue_Length(Q);

			printf("\n是否继续操作?(1/是；0/否)");
			scanf("%d", &m);
			if (m)
				break;
			else
			{
				exit(0);
				break;
			}

		case 6:
			Get_Head(Q);

			printf("\n是否继续操作?(1/是；0/否)");
			scanf("%d", &m);
			if (m)
				break;
			else
			{
				exit(0);
				break;
			}

		case 7:
			printf("请输入入队元素数值 x:");
			scanf("%d", &x);
			En_Queue(Q, x);
			Queue_Traver(Q);

			printf("\n是否继续操作?(1/是；0/否)");
			scanf("%d", &m);
			if (m)
				break;
			else
			{
				exit(0);
				break;
			}



		case 8:
			De_Queue(Q);
			Queue_Traver(Q);

			printf("\n是否继续操作?(1/是；0/否)");
			scanf("%d", &m);
			if (m)
				break;
			else
			{
				exit(0);
				break;
			}



		case 9:
			Queue_Traver(Q);

			printf("\n是否继续操作?(1/是；0/否)");
			scanf("%d", &m);
			if (m)
				break;
			else
			{
				exit(0);
				break;
			}

		case 10:
			Rand_Queue(Q);
			Queue_Traver(Q);

			printf("\n是否继续操作?(1/是；0/否)");
			scanf("%d", &m);
			if (m)
				break;
			else
			{
				exit(0);
				break;
			}


		case 0:
			exit(0);
			break;

		default:
			printf("\n输入有误！\n");
		}
	} while (cord <= 10 && cord >= 0);

}