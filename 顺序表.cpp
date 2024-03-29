/*2018/06/02*/
/*白春辉*/
/*顺序表的基本操作*/


#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

#define LIST_INIT_SIZE 100     //顺序表存储空间的初始分配量
#define LISTINCREMENT  10      //顺序表存储空间的分配增量

#define ElemType int
#define Status int

typedef struct SqList												//结构定义
{
	ElemType *elem;      //存储空间基地址
	int length;          //当前长度
	int listsize;        //当前分配的存储容量
}SqList;


Status Init_SqList(SqList &L)
{
	L.elem = (ElemType*)malloc(LIST_INIT_SIZE * sizeof(ElemType)); //1、创建顺序表
	if (!L.elem) return 0;
	L.length = 0;
	L.listsize = LIST_INIT_SIZE;
	printf("\n顺序表L创建成功\n");
}

void Destroy_SqList(SqList &L)									//2、销毁顺序表L，若L不存在，则出错
{
	if (L.elem)
	{
		free(L.elem);
		L.elem = NULL;
		L.length = 0;
		L.listsize = 0;
	}
	printf("\n顺序表L销毁成功\n");
}

void Clear_SqList(SqList &L)                                     //3、清空顺序表
{
	L.length = 0;
	printf("\n顺序表L清空成功\n");
}


void Emply_SqList(SqList &L)									//4、判断是否为空表，若为空
{
	SqList q;
	if (!L.length) printf("\n是否为空表：TRUE\n");
	else printf("\n是否为空表：FALSE\n");
}


int Length_SqList(SqList &L)									//5、返回表长
{
	return L.length;
}

Status GetElem_SqList(SqList L, int i, ElemType &e)             //6、用e返回L中第i个数据元素的值
{
	if(i<1||i>L.length) 
	{
		printf("\n参数i输入有误！\n");
		e = -99999999;
		return e;
	}
	else
	{
		e = *(L.elem + i - 1);
		return e;
	}
}



void LocateElem_SqList(SqList &L, ElemType x)					//7、定位L中数值等于x的数据元素
{
	int i,ipos = 0, j = 0;

	for (i = 0; i < L.length; i++)
	{
		if (L.elem[i] == x)
		{
			printf("\n数值为%d的元素在顺序表中的位置为：%d\n", x, i+1);
			ipos++;
		}
	}

	if (ipos == 0)
	{
		printf("\n数值为%d的元素不在该顺序表里\n", x);
	}
}


void GetPriorElem_SqList(SqList &L, ElemType x)					//8、查找某数据元素的前驱，找到返回其数据，否则返回空
{
	int i, j = 0,e;

	for (i = 0; i < L.length; i++)
	{

		if (L.elem[i] == x)
		{
			if (i == 0) printf("\n表首元素无前驱\n");
			else
			{
				e = GetElem_SqList(L, i, e);
				printf("\n%d号元素%d的前驱为：%d\n", i+1, x, e);
			}
			j++;
		}
	}

	if (j == 0)
	{
		printf("\n数值为%d的元素不在该顺序表里\n", x);
	}

}


void GetNextElem_SqList(SqList &L, ElemType x)					//9、查找某数据元素的后继，找到返回其数据，否则返回空
{
	int i, j = 0, e;

	for (i = 0; i < L.length; i++)
	{

		if (L.elem[i] == x)
		{
			if (i == L.length-1) printf("\n表尾元素无后继\n");
			else
			{
				e = GetElem_SqList(L, i + 2, e);
				printf("\n%d号元素%d的后继为：%d\n", i+1, x, e);
			}
			j++;
		}
	}

	if (j == 0)
	{
		printf("\n数值为%d的元素不在该顺序表里\n", x);
	}
}


Status Insert_SqList(SqList &L, int i, ElemType e)                  //10、在第i个位置之前插入值为x的元素
{
	int *q, *p;
	if (i<1 || i>L.length + 1) 
	{
		printf("\n参数i输入有误！\n"); return 0;
	}
	if (L.length >= L.listsize)
	{
		ElemType*newbase = (ElemType*)realloc(L.elem, (L.listsize + LISTINCREMENT) * sizeof(ElemType));
		if (!newbase) printf("\n存储分配失败\n");
		L.elem = newbase;
		L.listsize += LISTINCREMENT;
	}

	q = &(L.elem[i - 1]);
	for (p = &(L.elem[L.length - 1]); p >= q; --p)
		*(p + 1) = *p;
	*q = e;
	++L.length;
	return 1;
}


Status Delete_SqList(SqList &L, int i)                  //11、删除顺序表上的第i个数据结点
{
	int *q, *p,e;
	if (i<1 || i>L.length) printf("\n参数i输入有误！\n");

	p = &(L.elem[i - 1]);
	e = *p;
	q = L.elem + L.length - 1;
	for (++p; p <= q; ++p)
		*(p - 1) = *p;
	--L.length;
	return e;
}


void Display_SqList(SqList &L)								        //12、顺序表的显示
{
	int i;
	printf("\n\n当前顺序表L为：\n\n");
	for (i = 0; i < L.length; i++)
	{
		printf("%d  ", L.elem[i]);
	}
	printf("\n");
}


void Random_SqList(SqList &L)								 //13、创建单链表并随机生成单链表
{
	int i;
	Init_SqList(L);
	printf("\n请输入顺序表的长度\n");
	scanf("%d", &L.length);
	for (i = 0; i < L.length; i++)
	{
		L.elem[i] = rand() % 100;
	}
	Display_SqList(L);

}



int main()
{
	printf("初始化\n");
	SqList L;

	int x, y, m, e, cord, i, l, d;


	do {
		printf("\n**********************************************************\n");
		printf("\n				\n");
		printf("1---构造空顺序表		");
		printf("2---销毁顺序表			");
		printf("3---清空顺序表	\n\n");
		printf("4---空表检验			");						  //若L为空表，则返回TUSE；否则返回FALSE
		printf("5---表长			");
		printf("6---查询数据	\n\n");
		printf("7---定位下标			");
		printf("8---查找前驱			");
		printf("9---查找后继	\n\n");
		printf("10--插入结点			");
		printf("11--删除结点			");
		printf("12--显示当前顺序表\n\n");
		printf("13--生成一段随机顺序表		");
		printf("0---结束程序			\n");


		printf("\n\n请输入您选的的菜单号<1,2,3,4,5,6,7,8,9,10,11,12,13,0>:");
		scanf("%d", &cord);
		switch (cord)
		{

		case 1:
			SqList L;
			Init_SqList(L);

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
			Destroy_SqList(L);

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
			Clear_SqList(L);

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

			Emply_SqList(L);
			printf("\n顺序表L空表检验成功\n");


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
			l = Length_SqList(L);
			printf("\n顺序表L长为：%d\n", l);

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
			printf("请输入查询元素位置序号 i:");
			scanf("%d", &i);
			GetElem_SqList(L, i, e);

			if (e != -99999999) printf("\n第%d位元素的数值为：%d\n", i, e);

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
			printf("请输入查询元素数值 x:");
			scanf("%d", &x);
			LocateElem_SqList(L, x);

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
			printf("请输入查询元素数值 x:");
			scanf("%d", &x);
			GetPriorElem_SqList(L, x);

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
			printf("请输入查询元素数值 x:");
			scanf("%d", &x);
			GetNextElem_SqList(L, x);

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
			printf("请输入插入元素位置序号 i:");
			scanf("%d", &x);
			printf("请输入插入的数据y：");
			scanf("%d", &y);
			Insert_SqList(L, x, y);
			printf("\n顺序表输出如下：\n");
			Display_SqList(L);

			printf("\n是否继续操作?(1/是；0/否)");
			scanf("%d", &m);
			if (m)
			break;
			else
			{
			exit(0);
			break;
			}


			case 11:
			printf("请输入删除元素位置序号 i:");
			scanf("%d", &i);

			d = Delete_SqList(L, i);
			if (d != -99999999)
			{
			printf("\n删除第%d位元素：%d", i, d);
			
			Display_SqList(L);
			}
			
			printf("\n是否继续操作?(1/是；0/否)");
			scanf("%d", &m);
			if (m)
			break;
			else
			{
				exit(0);
				break;
			}

			
			case 12:

			Display_SqList(L);

			printf("\n是否继续操作?(1/是；0/否)");
			scanf("%d", &m);
			if (m)
			break;
			else
			{
			exit(0);
			break;
			}

			

		case 13:
			Random_SqList(L);

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
			printf("输入有误！\n");
		}
	} while (cord <= 13 && cord >= 0);

}
