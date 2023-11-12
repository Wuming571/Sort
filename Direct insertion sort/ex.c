#include <stdio.h>
#define maxx 100
int a[maxx], n;
int main() {
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++)
		scanf_s("%d", &a[i]);
	for (int i = 1; i < n; i++) {
		int k, temp = a[i];
		for (k=i; k >= 0; k--) {
			if (a[i] > a[k])
				break;
		}
		////这个在移动时会前面数据将后面的数据覆盖掉
		//for (int c = k+1; c < i; c++) {
		//	a[c] = a[c + 1];
		//}

		for (int c = i; c > k + 1; c--) // 大的数都往后面移动一位ie
		{
			a[c] = a[c - 1];
		}

		a[k+1] = temp;
	}

	for (int i = 0; i < n+3; i++)
		printf("%d ",a[i]);

	return 0;
}