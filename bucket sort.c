#define _CRT_SECURE_NO_WARNINGS 1

//桶排序的案例
//时间复杂度太大了，占用的空间过多
//#include <stdio.h>
//int main()
//{
//	int arr[11];
//	int i = 0;
//	int t = 0;
//	for (i = 0; i <= 10; i++)
//	{
//		arr[i] = 0;
//	}
//	for (i = 0; i <= 10; i++)
//	{
//		scanf("%d", &t);
//		arr[t]++;
//    }
//	int j = 0;
//	for (i = 0; i <= 10; i++)
//	{
//		for (j = 1; j <= arr[i]; j++)
//		{
//			printf("%d ", i);
//		}
//	}
//	return 0;
//}

//冒泡排序
//时间复杂度高
#include <stdio.h>
int main()
{
	int arr[10];
	int i = 0;
	int j = 0;
	for (i = 0; i < 10; i++)
	{
		scanf("%d", &arr[i]);
	}
	for (i = 0; i < 9; i++)
	{
		for (j = 0; j < 9 - i; j++)
		{
			if (arr[j]>arr[j + 1])
			{
				int tmp = arr[j+1];
				arr[j+1] = arr[j];
				arr[j] = tmp;
			}
		}
	}
	for (i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}

//快速排序
#include <stdio.h>
int a[101], n;//定义全局变量，这两个变量需要在子函数中使用
void quicksort(int left, int right)
{
	int i, j, t, temp;
	if (left>right)
		return;
	temp = a[left]; //temp中存的就是基准数
	i = left;
	j = right;
	while (i != j)
	{
		//顺序很重要，要先从右往左找
		while (a[j] >= temp && i<j)
			j--;
		//再从左往右找
		while (a[i] <= temp && i<j)
			i++;
		//交换两个数在数组中的位置
		if (i<j)//当哨兵i和哨兵j没有相遇时
		{
			t = a[i];
			a[i] = a[j];
			a[j] = t;
		}
	}
	//最终将基准数归位 
		a[left] = a[i];
	a[i] = temp;

	quicksort(left, i - 1);//继续处理左边的，这里是一个递归的过程
	quicksort(i + 1, right);//继续处理右边的，这里是一个递归的过程
}
int main()
{
	int i, j, t;
	//读入数据
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	quicksort(1, n); //快速排序调用

	//输出排序后的结果
	for (i = 1; i <= n; i++)
		printf("%d ", a[i]);
	getchar(); getchar();
	return 0;
}