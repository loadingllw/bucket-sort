#define _CRT_SECURE_NO_WARNINGS 1

//Ͱ����İ���
//ʱ�临�Ӷ�̫���ˣ�ռ�õĿռ����
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

//ð������
//ʱ�临�Ӷȸ�
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

//��������
#include <stdio.h>
int a[101], n;//����ȫ�ֱ�����������������Ҫ���Ӻ�����ʹ��
void quicksort(int left, int right)
{
	int i, j, t, temp;
	if (left>right)
		return;
	temp = a[left]; //temp�д�ľ��ǻ�׼��
	i = left;
	j = right;
	while (i != j)
	{
		//˳�����Ҫ��Ҫ�ȴ���������
		while (a[j] >= temp && i<j)
			j--;
		//�ٴ���������
		while (a[i] <= temp && i<j)
			i++;
		//�����������������е�λ��
		if (i<j)//���ڱ�i���ڱ�jû������ʱ
		{
			t = a[i];
			a[i] = a[j];
			a[j] = t;
		}
	}
	//���ս���׼����λ 
		a[left] = a[i];
	a[i] = temp;

	quicksort(left, i - 1);//����������ߵģ�������һ���ݹ�Ĺ���
	quicksort(i + 1, right);//���������ұߵģ�������һ���ݹ�Ĺ���
}
int main()
{
	int i, j, t;
	//��������
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	quicksort(1, n); //�����������

	//��������Ľ��
	for (i = 1; i <= n; i++)
		printf("%d ", a[i]);
	getchar(); getchar();
	return 0;
}