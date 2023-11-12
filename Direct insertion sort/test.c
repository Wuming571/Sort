#include <stdio.h>
#define maxx 100
int a[maxx], n;

int main() {
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++)
		scanf_s("%d", &a[i]);
	for (int i = 1; i < n; i++) {
		int k, temp = a[i];
		//从待排区取出
		for (k = i; k >= 0; k--) {
			//找到比temp小的数代表结束
			if (a[i] > a[k])
				break;
		}
		//大的数都往后面移动一位
		for (int c = i; c > k + 1; c--)
			a[c] = a[c - 1];
		//将a[i]放到正确的位置
		a[k + 1] = temp;
	}
	for (int i = 0; i < n; i++)
		printf("%d ", a[i]);

	return 0;
}