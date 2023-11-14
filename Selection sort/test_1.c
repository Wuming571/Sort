#include <stdio.h>
#define maxx 100

/*升序排列
1.初始化成一个小顶堆：
（1）找到最后一个内部结点（n/2），依次调整每颗子树
	调整过程：依次向下比较调整downAdjust()
	若该节点比左右孩子结点最小值大，进行交换,直到不满足该条件位置
2.在小顶堆的基础上进行堆排序
	循环n-1次：
	(1)输出(删除)根节点；
	(2)最后一个位置的结点代替根节点，
	(3)向下调整
	——最后一个元素时直接输出
*/

//对以下标i的元素为根节点的子树进行向下调整
void downAdjust(int a[], int i, int m) {
	//now是当前调整结点，next是now的孩子，也是如果有问题下次调整结点
	int now = i;
	int next=now*2;
	int t;
	//循环需要看看孩子的子树是否也应进行调整
	while (now * 2 <= m) {//少加一个等号，让我找半天
		//让最小的孩子和父亲结点比较
		 /*if(next+1<=m)
			next = (a[now * 2] < a[now * 2 + 1]) ? a[now * 2] : a[now * 2 + 1];*/
		
		next = now * 2;
		if (next + 1 <= m && a[next + 1] < a[next])
			next = next + 1;
		
		if (a[now] <= a[next]) {
			break;
		}//如果大于孩子，进行值交换
		else {
			t = a[now];
			a[now] = a[next];
			a[next] = t;
			now = next;//进行调整后，需要看看孩子子树是否需要调整
		}
	}
}

void upAdjust(int a[], int n) {
	//now是当前调整的结点，next是now的父亲，也是下一次要调整的结点
	int now = n;
	int next;
	int t;
	while (now > 1) {
		next = now / 2;//now的父亲
		if (a[next] <= a[now]) {//父亲结点比当前结点大
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

	int n;//元素个数
	int a[maxx];// 
	scanf_s("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf_s("%d", &a[i]);
	}
	//把a数组初始化成小顶堆,从最后一个内部结点向下优化(n/2)，有子树的结点都需要调整
	for (int i = n / 2; i >= 1; i--)
		downAdjust(a, i, n);
	//堆排序
	int m = n;
	int t;
	for (int i = 1; i <= n; i++) {
		printf("%d ", a[1]);
		//将最后一个结点的值交换过来，进行逻辑上的删除
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

	//在堆中插入一个元素；
	n++;
	scanf_s("%d", &a[n]);
	upAdjust(a, n);

	for (int i = n; i > 0; i--)
		printf("%d ", a[i]);

	return 0;
}