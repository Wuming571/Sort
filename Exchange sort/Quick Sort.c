#include <stdio.h>
#define maxx 100
int a[maxx], n, t;

void Init() {
	scanf_s("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf_s("%d", &a[i]);
}

void Show() {
	for (int i = 1; i <= n; i++)
		printf("%d ", a[i]);
}
//快速排序：是就地排序，是不稳定排序 时间复杂度O(nlogn)
//选取第一个元素做基准数
void Quick_Sort1(int a[], int l, int r) {
	if (l < r) {
		int i, j, x;
		//初始化左右先锋
		i = l;
		j = r;
		//第一个元素做基准点
		x = a[i];
		//判断是否排完
		while (i < j) {
			while (i < j && a[j]>x)
				j--;//找从右到左第一个小于x的数
			if (i < j)
				a[i++] = a[j];//将小于x的值放在左边
			while (i < j && a[i] < x)
				i++;//从左向右第一个大于x的数
			if (i < j)
				a[j--] = a[i];//将大于x的值放在右边
		}
	a[i] = x;
	//分别对基准点的左边和右边进行排序
	Quick_Sort1(a, l, i - 1);
	Quick_Sort1(a, i + 1, r);
	}
}

int main() {
	Init();
	Quick_Sort1(a, 1, n);

	Show();
}