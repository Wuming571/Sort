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
//��ѡ�����򣺽���n-1������ÿ�ζ���������ѡ��һ����С��Ԫ��
//�����������ĵ�һ��λ�ã���ʱ������+1��������-1
void Simple_selection(int a[]) {
	for (int i = 1; i <= n - 1; i++) {//����ѭ��������
		int minn = i;
		for (int j = i + 1; j <= n; j++) {//��������������ѡ���ҵ���СԪ��λ��
			if (a[j] < a[minn])
				minn = j;
		}
		//��minnλ�õ�Ԫ�ط����������ĵ�һ��λ�ã���iλ�ã���t���洢��ֵֹ��ʧ
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