#include<stdio.h>

int get_max(a, b)
{
	if (a > b)
		return a;
	else
		return b;
}

int main()
{
	int num1 = 0, num2 = 0;
	scanf_s("%d%d", &num1, &num2);
	int max = get_max(num1, num2);
	printf("%d", max);
	return 0;

}
//int main()
//{
//	int a = 0, b = 0;
//	scanf_s("%d%d", &a, &b);
//	if (a>b)
//	{
//		printf("%d", a);
//	}
//	else
//	{
//		printf("%d", b);
//	}
//	return 0;
//}
