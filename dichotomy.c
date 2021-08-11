#include<stdio.h>
#include<stdlib.h>

int main()
{
	//编写代码在一个整形有序数组中查找具体的某个数,找到了就打印数字所在的下标，找不到则输出：找不到。
	int num = 0;
	printf("请输入查找的数字：");
	scanf_s("%d", &num);
	int arr[] = { 0,1,2,3,4,5,6,7,8 };
	int left = 0, right = 8;
	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (num < arr[mid])//左半部分
		{
			right = mid - 1;
		}
		else if (num > arr[mid])//右半部分
		{
			left = mid + 1;
		}
		else//找到
		{
			printf("查询数字的下标为：%d\n", mid);
			break;
		}
	}
	if (left > right)
	{
		printf("找不到！\n");
	}

	system("pause");
	return 0;
}