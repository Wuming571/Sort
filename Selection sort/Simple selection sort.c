#include<stdio.h>
#include<stdlib.h>
#define maxx 100

int a[maxx], n, t;
int minn;


int main()
{
	int minn;//最小元素的下标 
	scanf_s("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf_s("%d", &a[i]);
	}
	//简单选择排序:就地排序， 时间复杂度O(n^2) ,不稳定的排序 
	//简单选择排序:进行n-1趟排序，每次都在乱序区中选择一个最小的元素，放在乱序的第一个位置，此时有序区+1，乱序区-1 
	for (int i = 1; i <= n - 1; i++)//控制循环趟数
	{
		minn = i;
		for (int j = i + 1; j <= n; j++)//控制乱序区，去找最小的元素的位置
		{
			if (a[j] < a[minn])
			{
				minn = j;
			}
		}
		//把minn位置的元素放在乱序区的第一个位置，即i位置
		if (minn != i)
		{
			int t = a[i];
			a[i] = a[minn];
			a[minn] = t;
		}

	}


	for (int i = 1; i <= n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
	return 0;
}
