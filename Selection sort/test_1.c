#include <stdio.h>
#define maxx 100

/*��������
1.��ʼ����һ��С���ѣ�
��1���ҵ����һ���ڲ���㣨n/2�������ε���ÿ������
	�������̣��������±Ƚϵ���downAdjust()
	���ýڵ�����Һ��ӽ����Сֵ�󣬽��н���,ֱ�������������λ��
2.��С���ѵĻ����Ͻ��ж�����
	ѭ��n-1�Σ�
	(1)���(ɾ��)���ڵ㣻
	(2)���һ��λ�õĽ�������ڵ㣬
	(3)���µ���
	�������һ��Ԫ��ʱֱ�����
*/

//�����±�i��Ԫ��Ϊ���ڵ�������������µ���
void downAdjust(int a[], int i, int m) {
	//now�ǵ�ǰ������㣬next��now�ĺ��ӣ�Ҳ������������´ε������
	int now = i;
	int next=now*2;
	int t;
	//ѭ����Ҫ�������ӵ������Ƿ�ҲӦ���е���
	while (now * 2 <= m) {//�ټ�һ���Ⱥţ������Ұ���
		//����С�ĺ��Ӻ͸��׽��Ƚ�
		 /*if(next+1<=m)
			next = (a[now * 2] < a[now * 2 + 1]) ? a[now * 2] : a[now * 2 + 1];*/
		
		next = now * 2;
		if (next + 1 <= m && a[next + 1] < a[next])
			next = next + 1;
		
		if (a[now] <= a[next]) {
			break;
		}//������ں��ӣ�����ֵ����
		else {
			t = a[now];
			a[now] = a[next];
			a[next] = t;
			now = next;//���е�������Ҫ�������������Ƿ���Ҫ����
		}
	}
}

void upAdjust(int a[], int n) {
	//now�ǵ�ǰ�����Ľ�㣬next��now�ĸ��ף�Ҳ����һ��Ҫ�����Ľ��
	int now = n;
	int next;
	int t;
	while (now > 1) {
		next = now / 2;//now�ĸ���
		if (a[next] <= a[now]) {//���׽��ȵ�ǰ����
			break;
		}
		else {
			t = a[now];
			a[now] = a[next];
			a[next] = t;
			now = next;
		}
	}
}

int main() {

	int n;//Ԫ�ظ���
	int a[maxx];// 
	scanf_s("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf_s("%d", &a[i]);
	}
	//��a�����ʼ����С����,�����һ���ڲ���������Ż�(n/2)���������Ľ�㶼��Ҫ����
	for (int i = n / 2; i >= 1; i--)
		downAdjust(a, i, n);
	//������
	int m = n;
	int t;
	for (int i = 1; i <= n; i++) {
		printf("%d ", a[1]);
		//�����һ������ֵ���������������߼��ϵ�ɾ��
		t = a[1];
		a[1] = a[m];
		a[m] = t;
		m--;
		downAdjust(a, 1, m);
	}
	printf("\n");
	for (int i = 1; i <= n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");

	for (int i = n; i > 0; i--)
		printf("%d ", a[i]);

	//�ڶ��в���һ��Ԫ�أ�
	n++;
	scanf_s("%d", &a[n]);
	upAdjust(a, n);

	for (int i = n; i > 0; i--)
		printf("%d ", a[i]);

	return 0;
}