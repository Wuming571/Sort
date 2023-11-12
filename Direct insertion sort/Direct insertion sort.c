#include <stdio.h>
//#include <stdlib.h>
#define maxx 100
int a[maxx], n;
int main()
{

    scanf_s("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf_s("%d", &a[i]);
    }

    for (int i = 1; i < n; i++) // 从第2个数开始，取出当前数作为待排序数
    {
        int k, temp = a[i];
        for (k = i; k >= 0; k--)
        {
            if (a[i] > a[k]) // 找到小的数代表结束
                break;
        }
        for (int c = i; c > k + 1; c--) // 大的数都往后面移动一位ie
        {
            a[c] = a[c - 1];
        }
        a[k + 1] = temp; // 将a[i]放入正确的位置
    }

    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    return 0;
}
