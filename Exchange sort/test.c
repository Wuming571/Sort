#include <stdio.h>
#define maxx 100
//���������������ؼ��ֱȽϵĽ�������������ؼ�����������λ��
int a[maxx], n, t;
int v;//���ͨ��������жϣ��Ƿ��������

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

	//ð������
	//���ѭ�������������� n��Ԫ������Ҫn-1��
	for (int i = 1; i <= n - 1; i++) {
		v = 0;
		//�ڲ�ѭ�����ƱȽϵĴ���
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