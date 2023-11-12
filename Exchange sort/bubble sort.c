#include<stdio.h>
#include<stdlib.h>
#define maxx 100
/*所谓交换,是指根据序列中两个关键字比较的结果来对换这两个关键字在序列中的位置。*/
int a[maxx], n, t;
int v;//标记 
int main()
{

	scanf_s("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf_s("%d", &a[i]);
	}

	//冒泡排序
	//外层循环控制 排序的趟数 n个元素排序需要循环n-1次 【1】
	for (int i = 1; i <= n - 1; i++)
	{
		v = 0;
		//内层循环控制比较的次数 n个元素第i趟比较n-i次 【2】
		for (int j = 1; j < n - i + 1; j++)
		{
			//比较相邻的元素大小 目的：将最大的元素选出到移动到最后 
			if (a[j] > a[j + 1])
			{
				v = 1;
				t = a[j];
				a[j] = a[j + 1];
				a[j + 1] = t;
			}
		}
		if (v == 0)//v仍然等0，说明没交换，说明完全有序 
		{
			break;
		}
	}



	for (int i = 1; i <= n; i++)
	{
		printf("%d ", a[i]);
	}
	return 0;
}


