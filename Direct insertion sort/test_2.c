#include <stdio.h>
#define maxx 10
int a[maxx], n;

void Init() {
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++)
		scanf_s("%d", &a[i]);
}

void Show() {
	for (int i = 0; i < n; i++)
		printf("%d ", a[i]);
}

int main() {
	Init();

	for (int i = 1; i < n; i++) {
		int j, k = a[i];
		for (j = i; j > 0; j--) {
			if (k < a[j-1]) {
				a[j] = a[j - 1];
			}
			else {
				break;
			}
		}
		a[j] = k;//将待排区的点放入要插入的位置
	}

	Show();
}
