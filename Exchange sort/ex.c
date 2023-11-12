#include <stdio.h>
#define maxx 100
int a[maxx], n;
//��������

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
		x = a[i];//�������Ԫ�صĵ�һ��
		while (i < j) {
			while (i<j && a[j]>x) {//���ұ߿�ʼ�ң��ҵ���xС��
				j--;
			}
			if (i < j) {
				a[i++] = a[j];
			}
			while (i < j && a[i] < x) {//����߿�ʼ�ң��ҵ���x���
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