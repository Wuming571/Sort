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

//物理上进行合并，中间用到临时数组来暂存
void merge(int a[], int l, int mid, int r) {
	//l~mid
	//mid+1~r
	int t[maxx];//临时数组
	int k = 0;//t数组的下标
	int i = l;
	int j = mid + 1;
	//循环进行对比，重新排列进行合并，但凡有一个排完，则推出循环
	while (i <= mid && j <= r) {
		if (a[i] < a[j]) {
			t[k] = a[i];
			k++;
			i++;
		}
		else {
			t[k] = a[j];
			k++;
			j++;
		}
	}
	//如果，前半部分i还没输完就直接全部入集合
	while (i <= mid) {
		t[k] = a[i];
		k++;
		i++;
	}
	//
	while (j <= r) {
		t[k] = a[j];
		k++;
		j++;
	}
	//将临时数组中的元素存入数组中
	for (int i = 0; i < k; i++)
		a[l + i] = t[i];
}

//从逻辑上不断进行二分，直到划分到1
void merge_sort(int a[], int l, int r) {
	int mid;
	if (l < r) {
		mid = (1 + r) / 2;
		//l~mid
		merge_sort(a, l, mid);
		//mid+1~r
		merge_sort(a, mid + 1, r);
		merge(a, l, mid, r);
	}
}

int main() {
	Init();

	merge_sort(a, 1, n);

	Show();
}