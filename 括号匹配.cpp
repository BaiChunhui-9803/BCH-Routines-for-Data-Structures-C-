/*白春辉*/
/*括号匹配*/
/*2018.06.07*/


#include <stdio.h>  
#include <malloc.h>   
#include <math.h>     
#include <process.h> 

#define S_SIZE 100     
#define STACKINCREAMENT 10//增加空间  


struct SqStack {
	int *base;  
	int *top;    
	int stacksize;     
};


int main()
{  
	void InitStack(SqStack &S);  
	int StackEmpty(SqStack S);  
	void push(SqStack &S, int e);  
	void pop(SqStack &S, int &e);  
								 
	SqStack S;
	InitStack(S);

	char ch[100], *p; int e;
	p = ch;


	printf("\n输一个含义有()[]{}的括号表达式:\n");
	scanf("%s",ch);

	while (*p)
	{
		switch (*p)
		{
		case '{':
		case '[':
		case '(': push(S, *p++); break;  
		case '}':
		case ']':
		case ')':pop(S, e);


			if ((e == '{' && *p == '}') || (e == '[' && *p == ']') || (e == '(' && *p == ')'))
				p++;
			else
			{
				printf("\n括号不匹配!\n"); exit(OVERFLOW);
			}
			break;
		default:p++;  
		}
	}
	if (StackEmpty(S))
		printf("\n括号匹配成功\n");
	else
		printf("\n缺少右括号！\n");
	printf("\n");
}


void InitStack(SqStack &S)
{
	S.base = (int *)malloc(S_SIZE * sizeof(int));
	S.stacksize = S_SIZE;
	S.top = S.base; 
}


int StackEmpty(SqStack S)
{
	if (S.base == S.top)
		return 1;
	else
		return 0;
}


void push(SqStack &S, int e)
{  
	if (S.top - S.base >= S.stacksize)
	{
		S.base = (int *)realloc(S.base, (S.stacksize + STACKINCREAMENT) * sizeof(int));
		S.top = S.base + S.stacksize;
		S.stacksize += STACKINCREAMENT;
	}
	*(S.top) = e;
	S.top++;
}


void pop(SqStack &S, int &e)
{  
	if (S.base != S.top)
	{
		S.top--;
		e = *S.top;
	}
}