#include <stdio.h>
#define maxx 100
int a[maxx], n;
//快速排序

void Init() {
	scanf_s("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf_s("%d", &a[i]);
	}
}

void Show() {
	for (int i = 1; i <= n; i++) {
		printf("%d ", a[i]);
	}
}

void Quick_sort(int a[], int l, int r) {
	if (l < r) {
		int x, i, j;
		i = l;
		j = r;
		x = a[i];//等于左边元素的第一个
		while (i < j) {
			while (i<j && a[j]>x) {//从右边开始找，找到比x小的
				j--;
			}
			if (i < j) {
				a[i++] = a[j];
			}
			while (i < j && a[i] < x) {//从左边开始找，找到比x大的
				i++;
			}
			if (i < j) {
				a[j--] = a[i];
			}
		}
		a[i] = x;
		Quick_sort(a, l, i - 1);
		Quick_sort(a, i + 1, r);
	}
}

int main() {
	Init();
	int l = 1, r = n;
	Quick_sort(a, l, r);
	Show();
}