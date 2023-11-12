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
		int i, j, x;
		//��ʼ�������ȷ�
		i = l;
		j = r;
		//��һ��Ԫ������׼��
		x = a[i];
		//�ж��Ƿ�����
		while (i < j) {
			while (i < j && a[j]>x)
				j--;//�Ҵ��ҵ����һ��С��x����
			if (i < j)
				a[i++] = a[j];//��С��x��ֵ�������
			while (i < j && a[i] < x)
				i++;//�������ҵ�һ������x����
			if (i < j)
				a[j--] = a[i];//������x��ֵ�����ұ�
		}
	a[i] = x;
	//�ֱ�Ի�׼�����ߺ��ұ߽�������
	Quick_Sort1(a, l, i - 1);
	Quick_Sort1(a, i + 1, r);
	}
}

int main() {
	Init();
	Quick_Sort1(a, 1, n);

	Show();
}