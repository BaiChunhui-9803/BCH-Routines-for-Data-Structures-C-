/*2018/06/02*/
/*白春辉*/
/*单链表的基本操作*/


#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>


typedef int ElemType;


typedef struct Lnode												//结构定义
{
	int data;
	struct Lnode *next;
}Lnode, *LinkList;


Lnode *Get_LinkList(LinkList L, int i)								//查找第i个数据元素，找到返回其指针，否则返回空
{
	Lnode *p = L;
	int j = 0;
	while (p != NULL && j<i) { p = p->next; j++; }
	return p;
}


void Init_LinkList(LinkList &L)										//1、创建单链表
{
	L = (LinkList)malloc(sizeof(Lnode));							//动态分配空间
	L->next = NULL;
}


void Destroy_LinkList(LinkList &L)									//2、销毁线性表L，若L不存在，则出错
{
	LinkList q;
	while (L)
	{
		q = (L)->next;
		free(L);
		L = q;
	}
}

void Clear_LinkList(LinkList &L)									//3、将L重置为空表 
{
	LinkList p, q;
	p = L->next;													//p指向第一个结点 
	while (p)
	{
		q = p->next;
		free(p);
		p = q;
	}
	L->next = NULL;													//头结点指针域为空
}

void Emply_LinkList(LinkList &L)									//4、判断是否为空表，若为空
{
	LinkList q;
	q = L->next;
	if (q == NULL) printf("\n是否为空表：TRUE\n");
	else printf("\n是否为空表：FALSE\n");
}




int Length_LinkList(LinkList &L)									//5、返回表长
{
	int j = 0;
	Lnode *p;
	p = L->next;
	while (p != NULL)
	{
		p = p->next;
		j++;
	}
	return j;
}




int GetElem_LinkList(LinkList &L, int i, int &e)					//6、用e返回L中第i个数据元素的值
{
	Lnode *p = L;
	int j = 0, Length;
	Length = Length_LinkList(L);

	if (i <= 0 || i > Length)
	{
		printf("\n输入i值错误\n");
		e = -99999999;
		return e;
	}

	else
	{
		while (p != NULL && j < i) { p = p->next; j++; }
		e = p->data;
		return e;
	}
}

void LocateElem_LinkList(LinkList &L, ElemType x)					//7、定位L中数值等于x的数据元素
{
	Lnode *p = L;
	int ipos = 0, j = 0;
	while (p)
	{
		if (p->data == x)
		{
			printf("\n数值为%d的元素在链表中的位置为：%d\n", x, ipos);
			j++;
		}

		p = p->next;
		ipos++;


	}

	if (j == 0)
	{
		printf("\n数值为%d的元素不在该链表里\n", x);
	}
}


void GetPriorElem_LinkList(LinkList &L, ElemType x)					//8、查找某数据元素的前驱，找到返回其指针和数据，否则返回空
{
	Lnode *p = L;
	int ipos = 0, e, j = 0;

	while (p)
	{
		if (p->data == x)
		{
			if (ipos == 1) printf("\n表首元素无前驱\n");
			else
			{
				e = GetElem_LinkList(L, ipos - 1, e);
				printf("\n%d号元素%d的前驱为：%d\n", ipos, x, e);
			}
			j++;
		}

		p = p->next;
		ipos++;
	}

	if (j == 0)
	{
		printf("\n数值为%d的元素不在该链表里\n", x);
	}
}


void GetNextElem_LinkList(LinkList &L, ElemType x)					//9、查找某数据元素的后继，找到返回其指针和数据，否则返回空
{
	Lnode *p = L;
	int ipos = 0, e, Length;

	Length = Length_LinkList(L);
	while (p)
	{
		if (p->data == x)
			if (ipos == Length) printf("\n表尾元素无后继\n");
			else
			{
				e = GetElem_LinkList(L, ipos + 1, e);
				printf("\n%d号元素%d的后继为：%d\n", ipos, x, e);
			}

		p = p->next;
		ipos++;
	}

	if (ipos == 0)
	{
		printf("\n数值为%d的元素不在该链表里\n", x);
	}

}












int Insert_LinkList(LinkList &L, int i, int x)						//10、在第i个位置之前插入值为x的元素
{
	Lnode *p, *s;
	p = Get_LinkList(L, i - 1);
	if (p == NULL)
	{
		printf("\n参数i输入有误！\n"); return 0;
	}
	else
	{
		s = (Lnode *)malloc(sizeof(Lnode));
		s->data = x; s->next = p->next;
		p->next = s; return 1;
	}
}




int Delete_LinkList(LinkList &L, int i)                           //11、删除单链表上的第i个数据结点
{
	Lnode *p, *s;
	int e, Length;
	p = Get_LinkList(L, i - 1);

	Length = Length_LinkList(L);

	if (i <= 0 || i>Length)
	{
		printf("结点不存在！\n"); return -99999999;
	}

	else
	{
		s = p->next;
		p->next = s->next;
		e = s->data;
		free(s);
	}

	return e;
}



void Display_LinkList(LinkList &L)								  //12、单链表的显示
{
	LinkList p; p = L;
	while (p->next)
	{
		printf("%d -> ", p->next->data); p = p->next;
	}
	printf("NULL\n");
}


void Random_LinkList(LinkList &L)								 //13、创建单链表并随机生成单链表
{
	L = (LinkList)malloc(sizeof(Lnode));
	L->next = NULL;
	Lnode *s;
	int i = 0, r, x;
	LinkList p; p = L;
	printf("\n请输入随机生成的链表的长度r：");
	scanf("%d", &r);
	while (i < r)
	{
		x = rand() % 100;
		s = (Lnode *)malloc(sizeof(Lnode));
		s->data = x; s->next = p->next;
		p->next = s;
		i++;
	}

	printf("\n当前链表L为：\n\n");

	Display_LinkList(L);

}













int main()
{
	printf("初始化\n");
	LinkList L;
	int x, y, m, e, cord, i, l, d;


	do {
		printf("\n**********************************************************\n");
		printf("\n				\n");
		printf("1---构造空链表			");
		printf("2---销毁链表			");
		printf("3---清空链表	\n\n");
		printf("4---空表检验			");						  //若L为空表，则返回TUSE；否则返回FALSE
		printf("5---表长			");
		printf("6---查询数据	\n\n");
		printf("7---定位下标			");
		printf("8---查找前驱			");
		printf("9---查找后继	\n\n");
		printf("10--插入结点			");
		printf("11--删除结点			");
		printf("12--显示当前链表\n\n");
		printf("13--生成一段随机单链表		");
		printf("0---结束程序			\n");


		printf("\n\n请输入您选的的菜单号<1,2,3,4,5,6,7,8,9,10,11,12,13,0>:");
		scanf("%d", &cord);
		switch (cord)
		{

		case 1:
			LinkList L;
			Init_LinkList(L);
			printf("\n链表L创建成功\n");

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
			Destroy_LinkList(L);
			printf("\n链表L销毁成功\n");

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
			Clear_LinkList(L);
			printf("\n链表L清空成功\n");

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

			Emply_LinkList(L);
			printf("\n链表L空表检验成功\n");


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
			l = Length_LinkList(L);
			printf("\n链表L长为：%d\n", l);

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
			GetElem_LinkList(L, i, e);

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
			LocateElem_LinkList(L, x);

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
			GetPriorElem_LinkList(L, x);

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
			GetNextElem_LinkList(L, x);

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
			Insert_LinkList(L, x, y);
			printf("\n单链表输出如下：\n");
			Display_LinkList(L);

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

			d = Delete_LinkList(L, i);
			if (d != -99999999)
			{
				printf("\n删除第%d位元素：%d", i, d);
				printf("\n\n单链表输出如下：\n");
				Display_LinkList(L);
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

			printf("\n当前链表L为：\n\n");
			Display_LinkList(L);

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
			Random_LinkList(L);


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
