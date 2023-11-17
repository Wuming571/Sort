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

//�����Ͻ��кϲ����м��õ���ʱ�������ݴ�
void merge(int a[], int l, int mid, int r) {
	//l~mid
	//mid+1~r
	int i = l;
	int j = mid + 1;
	//��ʱ����
	int t[maxx];
	//t������±�
	int k = 0;
	//ѭ�����жԱȣ��������н��кϲ���������һ�����꣬���Ƴ�ѭ��
	while (j<=r && i<=mid) {
		if (a[i] < a[j]) {
			t[k] = a[i];
			k++;
			i++;
		}
		else {
			t[k] = a[j];
			k++;
			j++;
		}
	}
	//�����ǰ�벿��i��û�����ֱ��ȫ���뼯��
	while (i <= mid) {
		t[k] = a[i];
		k++;
		i++;
	}
	while (j <= r) {
		t[k] = a[j];
		k++;
		j++;
	}
	//����ʱ�����е�Ԫ�ش���������
	for (int i = 0; i < k; i++)
		a[l+i] = t[i];
}

void merge_sort(int a[], int l, int r) {
	//��ôȥ�ݹ飿
	int mid=(l+r)/2;
	if (l < r) {
		merge_sort(a, l, mid);
		merge_sort(a, mid + 1, r);
		merge(a, l, mid, r);
	}
}

int main() {
	Init();

	merge_sort(a, 1, n);

	Show();
}