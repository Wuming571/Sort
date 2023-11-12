#include <stdio.h>
#define maxx 100
int a[maxx], n, t;

void Init() {
	scanf_s("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf_s("%d", &a[i]);
}

void Show() {
	for (int i = 1; i <= n; i++)
		printf("%d ", a[i]);
}
//���������Ǿ͵������ǲ��ȶ����� ʱ�临�Ӷ�O(nlogn)
//ѡȡ��һ��Ԫ������׼��
void Quick_Sort1(int a[], int l, int r) {
	if (l < r) {
		//��ʼ�������ȷ�
		int i = l;
		int j = r;
		//��һ��Ԫ������׼��
		int x = a[i];
		//�ж��Ƿ�����
		while (i < j) {
			//�Ҵ��ҵ����һ��С��x����
			while (i < j && a[j] > x)
				j--;
			//��С��x��ֵ�������
			if (i < j)
				a[i++] = a[j];
			//�������ҵ�һ������x����
			while (i<j && a[i] < x)
				i++;
			//������x��ֵ�����ұ�
			if (i < j)
				a[j--] = a[i];
		}
		//�ֱ�Ի�׼�����ߺ��ұ߽�������
		a[j] = x;
		Quick_Sort1(a, l, i - 1);
		Quick_Sort1(a, i + 1, r);
	}
}

int main() {
	Init();
	Quick_Sort1(a, 1, n);

	Show();
}