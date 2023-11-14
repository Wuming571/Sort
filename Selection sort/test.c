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
//简单选择排序：进行n-1趟排序，每次都在乱序区选择一个最小的元素
//放在乱序区的第一个位置，此时有序区+1，乱序区-1
void Simple_selection(int a[]) {
	for (int i = 1; i <= n - 1; i++) {//控制循环的趟数
		int minn = i;
		for (int j = i + 1; j <= n; j++) {//控制乱序区进行选择，找到最小元素位置
			if (a[j] < a[minn])
				minn = j;
		}
		//把minn位置的元素放在乱序区的第一个位置，即i位置，用t来存储防止值丢失
		if (minn != i) {
			int t = a[i];
			a[i] = a[minn];
			a[minn] = t;
		}
	}
}

int main() {
	Init();

	Simple_selection(a);

	Show();
}