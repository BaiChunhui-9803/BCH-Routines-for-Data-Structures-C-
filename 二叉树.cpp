/*白春辉*/
/*二叉树*/
/*2018.06.12*/

#include <iostream>
using namespace std;

typedef struct Node
{//定义二叉树结构
	char data;
	struct Node *lchild, *rchild;
}*BiTree, BiTNode;



void CreateBiTree(BiTree &T)
{										//先序创建二叉树
	char ch;
	scanf("%c",&ch);
	if (ch == '#') T = NULL;
	else {
		T = new BiTNode;
		T->data = ch;
		CreateBiTree(T->lchild);
		CreateBiTree(T->rchild);
	}
}


void InOrderTraverse(BiTree T)
{										//中序遍历
	if (T)
	{
		InOrderTraverse(T->lchild);
		printf("%c",T->data);
		InOrderTraverse(T->rchild);
	}
}


void PreOrderTraverse(BiTree T)
{										//先序遍历
	if (T)
	{
		printf("%c", T->data);
		PreOrderTraverse(T->lchild);
		PreOrderTraverse(T->rchild);
	}
}


void PostOrderTraverse(BiTree T)
{										//后序遍历
	if (T)
	{
		PostOrderTraverse(T->lchild);
		PostOrderTraverse(T->rchild);
		printf("%c", T->data);
	}
}


int Depth(BiTree T)
{										//树的深度
	if (T == NULL)
		return 0;
	else
	{
		int m = Depth(T->lchild);
		int n = Depth(T->rchild);
		if (m>n) return (m + 1);
		else return (n + 1);
	}
}


int NodeCount(BiTree T)
{										//统计二叉树中结点的个数
	if (T == NULL) return 0;
	else return NodeCount(T->lchild) + NodeCount(T->rchild) + 1;
}


int LeafCount(BiTree T)
{										//统计二叉树中叶子结点的个数
	if (!T) return 0;
	if (!T->lchild && !T->rchild) {		//如果二叉树左子树和右子树皆为空,说明该二叉树根节点为叶子节点,加1.
		return 1;
	}
	else {
		return LeafCount(T->lchild) + LeafCount(T->rchild);
	}
}

char GetElemType(BiTree T, int &num, char &e) {
	if (T) 
	{
		if (num == 1) 
		{
			e = T->data;
			return 0;
		}
		else {
			if (T->lchild) 
			{
				--num;
				GetElemType(T->lchild, num, e);
			}
			if (T->rchild) 
			{
				--num;
				GetElemType(T->rchild, num, e);
			}
		}
	}
}
char PreOrder(BiTree T, int k)
{
	char e;
	e = '#';
	GetElemType(T, k, e);
	return e;
}


int main()
{
	int k,i = 0;
	BiTree T;
	printf("先序遍历输入(以#结束):");
	CreateBiTree(T);
	
	printf("\n\n先序遍历输出:");
	PreOrderTraverse(T);
	
	printf("\n\n中序遍历输出:");
	InOrderTraverse(T);
	
	printf("\n\n后序遍历输出:");
	PostOrderTraverse(T);

	printf("\n\n\n树的深度: %d\n", Depth(T));
	printf("\n结点的个数: %d\n", NodeCount(T));
	printf("\n叶结点的个数: %d\n\n", LeafCount(T));

	printf("\n请输入所查找的结点的先序序列位置k:");
	scanf("%d",&k);
	printf("\n先序序列中第%d个位置的结点为 %c \n\n",k, PreOrder(T, k));
	return 1;

}