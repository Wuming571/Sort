#include<stdio.h>
#define maxx 100

/*升序排列
选择排序：基于选择的排序。 ---每次从乱序区选择一个最小的排列（输出）
   堆排序:就地排序，不稳定 ，时间复杂度O(nlogn)
   n个元素，保存在a数组中，直接在a数组中
1.初始化成一个小顶堆：
  下标最大的内部节点的下标是几？最后一个内部节点的下标是几？
		n/2
（1）找到最后一个内部节点（n/2）,依次调整每棵子树
		调整过程：依次向下比较调整：若该节点比左右孩子节点中的最小值大，进行交换，直到不满足该条件位置
2.在小顶堆的基础上，进行堆排序
   循环n-1次：
  （1）输出（删除）根节点；
   （2）最后一个位置的节点代替根节点
（3）向下调整
---输入最后一个元素
3.堆中插入一个元素：
（1）把元素放到数组最后
（2）向上和父亲节点比较进行调整

 */
void downAdjust(int a[], int i, int m)//对以 下标i的元素 为根节点的子树进行向下调整 
{//now是当前调整的节点，next是now的孩子，也是下一次要调整的节点 
	int now = i;
	int next;
	int t;
	while (now * 2 <= m)
	{
		next = now * 2;//now的左孩子
		if (next + 1 <= m && a[next + 1] < a[next])
		{
			next = next + 1;//now的右孩子 
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
{//now是当前调整的节点，next是now的父亲，也是下一次要调整的节点
	int now = n;
	int next;
	int t;
	while (now > 1)
	{
		next = now / 2;// now的父亲
		if (a[next] <= a[now])//父亲节点比当前节点大 
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
	int n;//元素个数
	int a[maxx];// 
	scanf_s("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf_s("%d", &a[i]);
	}
	//把a数组初始化成小顶堆
	for (int i = n / 2; i >= 1; i--)
	{
		downAdjust(a, i, n);
	}
	//堆排序
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
	//在堆中插入一个元素；
	n++;
	scanf_s("%d", &a[n]);
	upAdjust(a, n);

	for (int i = 1; i <= n; i++)
	{
		printf("%d ", a[i]);
	}
	return 0;
}

//堆的应用--优先队列 




