#include <stdio.h>
#define maxx 100
int a[maxx], n;

int main() {
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++)
		scanf_s("%d", &a[i]);
	for (int i = 1; i < n; i++) {
		int k, temp = a[i];
		//�Ӵ�����ȡ��
		for (k = i; k >= 0; k--) {
			//�ҵ���tempС�����������
			if (a[i] > a[k])
				break;
		}
		//��������������ƶ�һλ
		for (int c = i; c > k + 1; c--)
			a[c] = a[c - 1];
		//��a[i]�ŵ���ȷ��λ��
		a[k + 1] = temp;
	}
	for (int i = 0; i < n; i++)
		printf("%d ", a[i]);

	return 0;
}