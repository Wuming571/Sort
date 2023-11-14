#include <stdio.h>
#define maxx 100
int a[maxx], n;

void Init() {
	scanf_s("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf_s("%d", &a[i]);
}

void Show() {
	for (int i = 1; i <= n; i++)
		printf("%d ", a[i]);
}

void Quick_sort(int a[], int l, int r) {
	if (l < r) {
		int i = l;
		int j = r;
		int x = a[i];//从左边开始
		while (i < j) {
			while (i < j && x < a[j])
				j--;
			if (i < j) {
				a[i] = a[j];
				++i;
			}
			while (i < j && x > a[i])
				i++;
			if (i < j) {
				a[j] = a[i];
				--j;
			}
			while (i < j && x < a[j])
				j--;
			if (i < j) {
				a[i] = a[j];
				++i;
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

/*本次书写依旧存在问题，在while循环判断时，将i<j写成l<r这样将无法跳出循环*/