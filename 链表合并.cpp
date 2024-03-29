/*2018/06/02*/
/*白春辉*/
/*两个单链表L1、L2的合并链接*/

#include<stdio.h>  
#include<stdlib.h>  

typedef struct LNode  //定义
{
	int data;
	struct LNode *next;
}LNode, *LinkList;

LinkList link(LinkList L1, LinkList L2)                             //将L1,L2链接成新的链表并返回新链表指针
{
	LinkList p, q, r;
	p = q = (LinkList)malloc(sizeof(LNode));                        //带头节点  
	while (L1->next != NULL)                                          
	{
		r = (LinkList)malloc(sizeof(LNode));
		r->data = L1->next->data;
		q->next = r;
		q = r;
		L1 = L1->next;
	}


	while (L2->next != NULL)  
	{
		r = (LinkList)malloc(sizeof(LNode));
		r->data = L2->next->data;
		q->next = r;
		q = r;
		L2 = L2->next;
	}
	q->next = NULL;
	return p;  
}

void main()
{
	LinkList L1, L2, P, q, r;
	int l1, l2;
	L1 = q = (LinkList)malloc(sizeof(LNode));                 //L1带头节点  


	printf("\n请输入L1的表长：");
	scanf("%d", &l1);
	printf("\n请输入L2的表长：");
	scanf("%d", &l2);
	printf("\n");


	while (l1)    
	{
		r = (LinkList)malloc(sizeof(LNode));
		r->data = rand()%100;
		q->next = r;
		q = r;
		l1--;
	}
	q->next = NULL;   
	
	L2 = q = (LinkList)malloc(sizeof(LNode));              //L2带头节点  


	while (l2)    
	{
		r = (LinkList)malloc(sizeof(LNode));
		r->data = rand() % 100;
		q->next = r;
		q = r;
		l2--;
	}
	q->next = NULL;         

	P = link(L1, L2);   

	printf("L1:\n\n"); 
	while (L1->next != NULL)
	{
		printf("%d ->", L1->next->data);
		L1 = L1->next;
	}
	
	printf("NULL\n\n");

	printf("\nL2:\n\n");
	while (L2->next != NULL)
	{
		printf("%d ->", L2->next->data);
		L2 = L2->next;
	}
	
	printf("NULL\n\n");

	printf("\nP:\n\n");
	while (P->next != NULL)
	{
		printf("%d ->", P->next->data);
		P = P->next;
	}
	printf("NULL\n\n");

}

/*2018/06/02*/
/*白春辉*/
/*两个单链表L1、L2的合并链接*/