

#include <stdio.h>  
#include <malloc.h>   
#include <math.h>     
#include <process.h> 

#define S_SIZE 100     
#define STACKINCREAMENT 10//增加空间  

int i=0;
void hanoi(int n, char a, char b, char c)

{
	
	if (n == 1)

		printf("\n%d  将盘%d从%c移到%c\n", ++i, n, a, c);

	else

	{

		hanoi(n - 1, a, c, b);

		printf("\n%d  将盘%d从%c移动到%c\n",++i, n, a, c);

		hanoi(n - 1, b, a, c);

	}

}

void main()

{

	int n;

	printf("\n请输入盘子的个数\n");

	scanf("%d", &n);

	printf("----------------------------------------\n");

	hanoi(n, 'x', 'y', 'z');

	printf("----------------------------------------\n");

}