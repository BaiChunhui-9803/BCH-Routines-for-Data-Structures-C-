/*白春辉*/
/*顺序栈*/
/*2018.06.05*/

#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>

#define  STACK_INIT_SIZE  100
#define  STACKINCREMENT    10

typedef  int  ElemType;
typedef  int    Status;

typedef struct
{
	ElemType *base;
	ElemType  *top;
	int  stacksize;
}SqStack;


Status Init_Stack(SqStack &S)                                      //1、构造空栈
{
	S.base = (ElemType*)malloc(STACK_INIT_SIZE * sizeof(ElemType));
	if (!S.base)
		exit(0);								//存储分配失败
	S.top = S.base;
	S.stacksize = STACK_INIT_SIZE;
	printf("\n空栈构造成功！\n");
	return 1;
}

Status Destroy_Stack(SqStack &S)                                      //2、销毁栈
{
	S.top = NULL;
	S.stacksize = 0;
	free(S.base);
	printf("\n栈销毁成功！\n");
	return 1;
}

Status Clear_Stack(SqStack &S)                                      //3、清空栈
{
	S.top = S.base;
	printf("\n栈清空成功！\n");
	return 1;
}

Status Stack_Empty(SqStack S)                                      //4、空栈检验
{
	if (S.top == S.base)
	{
		printf("\n当前栈是否为空：TRUE\n");
		return 0;
	}
	else
	{
		printf("\n当前栈是否为空：FALSE\n");
		return 1;
	}
	printf("\n栈S空栈检验成功\n");

}

Status Stack_Length(SqStack S)                                      //5、栈长
{
	int l;
	if (S.top == S.base)
	{
		printf("\n当前栈为空\n");
		return 0;
	}
	else
	{
		l = S.top - S.base;
		printf("栈长为：%d",l);
		return (l);
	}	                                    //也可以直接返回S.top - S.base
}

Status Get_Top(SqStack S, ElemType &e)                                      //6、栈顶元素
{
	if (S.top == S.base)
	{
		printf("\n当前栈为空\n");
		return 0;
	}
	else
	{
		e = *(S.top - 1);
		printf("\n当前栈顶元素为：%d",e);
		printf("\n");
		return e;
	}
}


Status Push(SqStack &S, ElemType &e)                                      //7、入栈
{
	if (S.top - S.base >= STACK_INIT_SIZE)
	{
		S.base = (ElemType *)realloc(S.base, (S.stacksize + STACKINCREMENT) * sizeof(ElemType));
		if (!S.base)
		{
			return 0;
		}
		S.top = S.base + STACK_INIT_SIZE;
		S.stacksize = S.stacksize + STACKINCREMENT;
	}
	*S.top = e;
	S.top++;
	printf("\n元素%d入栈成功	↘", e);
	return 1;
}

 
Status Pop(SqStack &S, ElemType &e)                                       //8、出栈
{
	if (S.top == S.base)
	{
		printf("\n当前栈为空\n");
		return 0;
	}
	else
	{
		S.top--;
		e = *S.top;
		printf("\n栈顶元素%d已出栈\n", e);
		return e;
	}
}
 

Status Stack_Traverse(SqStack S)                                           //9、遍历栈
{
	int St[STACK_INIT_SIZE];
	int i=0,j=0;
	if (S.base == NULL)
	{
		printf("\n栈不存在\n");
		return 0;
	}
	if (S.top == S.base)
	{
		printf("\n当前栈为空\n");
		return 0;
	}
	ElemType *p;
	p = S.top;
	printf("\n\n显示当前栈\n\n");
	
	//0.
	
	/*while (p > S.base)
	{
		printf(" %d ]",*(--p));
	}
	*/


	//1.

	while (p > S.base)                                          //利用数组储存栈元素，反向输出数组，即可以正常顺序遍历栈
	{
		St[i] = *(--p);          
		i++;
		j++;
	}
	i = 0;
	while (i < j)
	{
		printf("[ %d ", St[--j]); 
	}
	

	return 1;
}




Status Rand_Stack(SqStack &S)                                       //10、随机生成
{
	int l,r;
	Init_Stack(S);
	printf("\n请输入指定栈长：");
	scanf("%d",&l);

	while (l) 
	{
		r = rand()%100;
		Push(S,r);
		l--;
	}
	return 1;
}






int main()
{
	printf("初始化\n");
	SqStack S;

	int  x,cord,e,m;


	do {
		printf("\n**********************************************************\n");
		printf("\n				\n");
		printf("1---构造空顺序栈		");
		printf("2---销毁顺序栈			");
		printf("3---清空顺序栈	\n\n");
		printf("4---空栈检验			");						  //若S为空栈，则返回TUSE；否则返回FALSE
		printf("5---栈长			");
		printf("6---栈顶	\n\n");
		printf("7---入栈			");
		printf("8---出栈			");
		printf("9--显示当前顺序栈\n\n");
		printf("10--生成一段随机顺序栈		");
		printf("0---结束程序			\n");


		printf("\n\n请输入您选的的菜单号<1,2,3,4,5,6,7,8,9,10,0>:");
		scanf("%d", &cord);
		switch (cord)
		{

		case 1:
			SqStack S;
			Init_Stack(S);

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
			Destroy_Stack(S);

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
			Clear_Stack(S);

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

			Stack_Empty(S);


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
			Stack_Length(S);

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
			Get_Top(S, e);

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
			printf("请输入入栈元素数值 x:");
			scanf("%d", &x);
			Push(S, x);
			Stack_Traverse(S);

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
			Pop(S, x);
			Stack_Traverse(S);

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
			Stack_Traverse(S);

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
			Rand_Stack(S);
			Stack_Traverse(S);

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