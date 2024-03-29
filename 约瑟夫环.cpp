/*2018/06/02*/
/*白春辉*/
/*约瑟夫环问题*/

#include<stdio.h>   
#include <stdlib.h>  

typedef struct node 
{
	int data;
	struct node* pnext;
} Node;

Node *link_create(int n)                //创建n个节点的循环链表  
{ 
	Node *p, *q, *head;
	int i;
	p = (Node *)malloc(sizeof(Node));

	head = p;                
	p->data = 1;

	for (i = 2; i <= n; i++)            
	{
		q = (Node *)malloc(sizeof(Node));
		q->data = i;
		p->pnext = q;
		p = q;
	}
	p->pnext = head;                    //最后一个节点指向头部，形成循环链表  
	return head;
}

void link_process(Node *head, int k, int m)         //从编号为k(1<=k<=n)的人开始报数，数到m的那个人出列；  
{
	int i;
	Node *p = head, *tmp1;
	tmp1 = NULL;
	while (p->data != k)  
		p = p->pnext;

	while (p->pnext != p)
	{
		for (i = 0; i<m; i++)
		{
			tmp1 = p;
			p = p->pnext;
		}
		printf("%d ", p->data);
		tmp1->pnext = p->pnext;
		free(p);
		p = tmp1->pnext;

	}
	printf("%d ", p->data);
	printf("\n\n");
	free(p);
}

int main()
{
	int a, b, c;

	printf("游戏规则：\n");
	printf("已知n个人（以编号1，2，3...n分别表示）围坐在一张圆桌周围\n");
	printf("从编号为k的人开始从0报数，数到m的人出列\n");
	printf("下一个人又从0开始报数，数到m的人又出列\n");
	printf("依此规律重复下去，直到圆桌周围的人全部出列\n\n");

	printf("\n请输入总人数n：");
	scanf("%d",&a);
	printf("\n请输入从几号玩家开始报数k：");
	scanf("%d", &b);
	printf("\n请输入出列数m：");
	scanf("%d", &c);
	printf("\n\n");

	Node *head = link_create(a);
	link_process(head, b, c);
	return 0;
}