#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

	//���������������������������Լ��
	//�������
	//int s, b,t;
	//printf("����������������\n");
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
	//		printf("�����������Լ���ǣ�%d\n", i);
	//	}
	//	break;
	//}
	//շת���
int main()
{
	int a = 0;
	int b = 0;
	int c = 0;
	printf("����������������");
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
