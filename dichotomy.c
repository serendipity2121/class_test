#include<stdio.h>
#include<stdlib.h>

int main()
{
	//��д������һ���������������в��Ҿ����ĳ����,�ҵ��˾ʹ�ӡ�������ڵ��±꣬�Ҳ�����������Ҳ�����
	int num = 0;
	printf("��������ҵ����֣�");
	scanf_s("%d", &num);
	int arr[] = { 0,1,2,3,4,5,6,7,8 };
	int left = 0, right = 8;
	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (num < arr[mid])//��벿��
		{
			right = mid - 1;
		}
		else if (num > arr[mid])//�Ұ벿��
		{
			left = mid + 1;
		}
		else//�ҵ�
		{
			printf("��ѯ���ֵ��±�Ϊ��%d\n", mid);
			break;
		}
	}
	if (left > right)
	{
		printf("�Ҳ�����\n");
	}

	system("pause");
	return 0;
}