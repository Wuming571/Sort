#include <stdio.h>
#define maxx 10
int a[maxx], n;

void Init() {
	scanf_s("%d", &n);
	for (int i = 1; i < n; i++)
		scanf_s("%d", &a[i]);
}

void Show() {
	for (int i = 1; i < n; i++)
		printf("%d ", a[i]);
}

int main() {
	Init();
	int k = 0;//通过缩小增量排序的趟数
	//希尔排序
	for (int d = n / 2; d > 0; d /= 2) {//减少增量，直到增量减到1
		k++;
		for (int i = 1 + d; i <= n; i++) {
			int t = a[i];
			int j;
			//对一个循环增量的数据进行排序
			for (j = i; j >= d; j -= d) {
				if (t < a[j - d])
					a[j] = a[j - d];
				else
					break;
			}
			a[j] = t;
		}
		printf("第%d趟，增量为%d:", k, d);
		Show();
		printf("\n");
	}

	return 0;
}