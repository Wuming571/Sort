#pragma once
#include <stdio.h>
#define maxx 100

void merge(int a[], int l, int mid, int r)
{
	//l~mid
	//mid+1~r
	int t[maxx];
	int k = 0;//t数组的下标 
	int i = l;
	int j = mid + 1;
	while (i <= mid && j <= r)
	{
		if (a[i] < a[j])
		{
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
	while (i <= mid)
	{
		t[k] = a[i];
		k++;
		i++;
	}
	while (j <= r)
	{
		t[k] = a[j];
		k++;
		j++;
	}
	for (int i = 0; i < k; i++)
	{
		a[l + i] = t[i];
	}

}

void merge_sort(int a[], int l, int r)
{
	int mid;
	if (l < r)
	{
		mid = (l + r) / 2;
		//l~mid
		merge_sort(a, l, mid);
		//mid+1~r
		merge_sort(a, mid + 1, r);
		merge(a, l, mid, r);
	}

}
