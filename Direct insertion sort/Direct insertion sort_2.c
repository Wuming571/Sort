#include<stdio.h>
#include<stdlib.h>
#define maxx 100
int n;//Ԫ�ظ���
int a[maxx];

int main()
{
	scanf_s("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf_s("%d", &a[i]);
	}
	//�������ֱ�Ӳ������� 

	for (int i = 2; i <= n; i++)
	{
		int t = a[i];
		int j;
		for (j = i; j > 1; j--)
		{
			if (t < a[j - 1])
			{
				a[j] = a[j - 1];
			}
			else {
				break;
			}

		}
		a[j] = t;
	}
	for (int i = 1; i <= n; i++)
	{
		printf("%d ", a[i]);
	}

	return 0;
}
