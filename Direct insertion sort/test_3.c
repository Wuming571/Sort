#include <stdio.h>
#define maxx 10
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

int main() {
	Init();
	int k=0;//Ñ­»·´ÎÊý
	int d = n / 2;
	for (d; d > 0; d /= 2) {
		k++;
		for (int i = d + 1; i <= n; i++) {
			int t = a[i];
			int j;
			for (j = i; j >= d; j -= d) {
				if (a[j-d] > t)
					a[j] = a[j - d];
				else
					break;
			}
			a[j] = t;
		}
		printf("%d,%d:", k, d);
		Show();
		printf("\n");
	}
	return 0;
}