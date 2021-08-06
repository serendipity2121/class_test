#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

	//给定两个数，求这两个数的最大公约数
	//暴力穷举
	//int s, b,t;
	//printf("请输入两个整数：\n");
	//scanf("%d%d", &s, &b);
	//if (s>b)
	//{
	//	t = s;
	//	s = b;
	//	b = t;
	//}
	//for (int i = s; i > 0; i--)
	//{
	//	if (s%i==0 && b%i==0)
	//	{
	//		printf("两个数的最大公约数是：%d\n", i);
	//	}
	//	break;
	//}
	//辗转相除
int main()
{
	int a = 0;
	int b = 0;
	int c = 0;
	printf("请输入两个整数：");
	scanf("%d%d",&a,&b);

	while (c = a % b)
		{
			a = b;
			b = c;
		}

	printf("%d\n", b);
	system("pause");
	return 0;
}
