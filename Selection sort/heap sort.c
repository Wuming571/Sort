#include<stdio.h>
#define maxx 100

/*��������
ѡ�����򣺻���ѡ������� ---ÿ�δ�������ѡ��һ����С�����У������
   ������:�͵����򣬲��ȶ� ��ʱ�临�Ӷ�O(nlogn)
   n��Ԫ�أ�������a�����У�ֱ����a������
1.��ʼ����һ��С���ѣ�
  �±������ڲ��ڵ���±��Ǽ������һ���ڲ��ڵ���±��Ǽ���
		n/2
��1���ҵ����һ���ڲ��ڵ㣨n/2��,���ε���ÿ������
		�������̣��������±Ƚϵ��������ýڵ�����Һ��ӽڵ��е���Сֵ�󣬽��н�����ֱ�������������λ��
2.��С���ѵĻ����ϣ����ж�����
   ѭ��n-1�Σ�
  ��1�������ɾ�������ڵ㣻
   ��2�����һ��λ�õĽڵ������ڵ�
��3�����µ���
---�������һ��Ԫ��
3.���в���һ��Ԫ�أ�
��1����Ԫ�طŵ��������
��2�����Ϻ͸��׽ڵ�ȽϽ��е���

 */
void downAdjust(int a[], int i, int m)//���� �±�i��Ԫ�� Ϊ���ڵ�������������µ��� 
{//now�ǵ�ǰ�����Ľڵ㣬next��now�ĺ��ӣ�Ҳ����һ��Ҫ�����Ľڵ� 
	int now = i;
	int next;
	int t;
	while (now * 2 <= m)
	{
		next = now * 2;//now������
		if (next + 1 <= m && a[next + 1] < a[next])
		{
			next = next + 1;//now���Һ��� 
		}
		if (a[now] <= a[next])
		{
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
void upAdjust(int a[], int n)
{//now�ǵ�ǰ�����Ľڵ㣬next��now�ĸ��ף�Ҳ����һ��Ҫ�����Ľڵ�
	int now = n;
	int next;
	int t;
	while (now > 1)
	{
		next = now / 2;// now�ĸ���
		if (a[next] <= a[now])//���׽ڵ�ȵ�ǰ�ڵ�� 
		{
			break;
		}
		else
		{
			t = a[now];
			a[now] = a[next];
			a[next] = t;
			now = next;
		}
	}

}

int main()
{
	int n;//Ԫ�ظ���
	int a[maxx];// 
	scanf_s("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf_s("%d", &a[i]);
	}
	//��a�����ʼ����С����
	for (int i = n / 2; i >= 1; i--)
	{
		downAdjust(a, i, n);
	}
	//������
	int m = n;
	int t;
	for (int i = 1; i <= n; i++)
	{
		printf("%d ", a[1]);
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
	//�ڶ��в���һ��Ԫ�أ�
	n++;
	scanf_s("%d", &a[n]);
	upAdjust(a, n);

	for (int i = 1; i <= n; i++)
	{
		printf("%d ", a[i]);
	}
	return 0;
}

//�ѵ�Ӧ��--���ȶ��� 




