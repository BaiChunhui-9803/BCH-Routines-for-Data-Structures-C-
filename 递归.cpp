/*白春辉*/
/*递归*/
/*2018.06.07*/

#include<stdio.h>  

int F(int n, int x)
{
	int result;
	if (n == 0)
	{
		result = 1;
	}
	else if (n == 1)
	{
		result = 2 * x;
	}
	else if (n >= 2)
	{
		result = 2 * x*F(n - 1, x) - 2 * (n - 1)*F(n - 2, x);
	}
	return result;
}
int main()
{
	int n, x;
	printf("请输入n的值：");
	scanf("%d", &n);

	printf("请输入x的值：");
	scanf("%d", &x);
	printf("%d\n", F(n, x));
	return 0;
}
