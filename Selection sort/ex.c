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
	//����ѭ��������
	for (int i = 1; i < n; i++) {
		//��������������ѡ���ҵ���СԪ��λ��
		int minn = i;
		int t = a[i];
		for (int j = i+1; j <= n; j++) {
			//��minnλ�õ�Ԫ�ط����������ĵ�һ��λ�ã���iλ�ã���t���洢��ֵֹ��ʧ
			if (a[j] < a[i]) {
				minn = j;
				
			}
		}
		a[i] = a[minn];
		a[minn] = t;
	}
}

int main() {
	Init();

	Simple_selection(a);

	Show();
}