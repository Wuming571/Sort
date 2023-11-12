#include <stdio.h>
#define maxx 100
//根据序列中两个关键字比较的结果来交换两个关键字在序列中位置
int a[maxx], n, t;
int v;//标记通过标记来判断，是否排序完成

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

	//冒泡排序
	//外层循环控制排序趟数 n个元素排序要n-1次
	for (int i = 1; i <= n - 1; i++) {
		v = 0;
		//内层循环控制比较的次数
		for (int j = 1; j < n - i+1; j++) {
			t = a[j];
			if (a[j] > a[j + 1]) {
				
				v = 1;
				a[j] = a[j + 1];
				a[j + 1] = t;
			}
		}
		if (v==0)
			break;
	}

	Show();
}