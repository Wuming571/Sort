#include "Merge sort.h"

int main()
{
	int n;//元素个数
	int a[maxx];// 
	scanf_s("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf_s("%d", &a[i]);
	}

	merge_sort(a, 1, n);

	for (int i = 1; i <= n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");


	return 0;
}

