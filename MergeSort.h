#pragma once
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

//参数传入了一个辅助数组，避免在函数体内定义造成每一次递归都会创建一次数组，造成不必要的开销
void Merge(int* arr, int begin,int mid, int end, int tmp[])
{
	//见一个区间分为begin mid | mid+1 end
	int begin1 = begin;
	int end1 = mid;
	int begin2 = mid + 1;
	int end2 = end;

	int left = 0;
	while (begin1 <= end1&&begin2 <= end2)
	{
		//区间进行比较
		while (begin1 <= end1&&arr[begin1] < arr[begin2])
		{
			tmp[left++] = arr[begin1++];
		}
		while (begin2<=end2&&arr[begin1]>arr[begin2])
		{
			tmp[left++] = arr[begin2++];
		}
	}
	//避免一个区间先结束，这里分情况进行讨论
	while (begin1<=end1&&begin2>end2)
	{
		tmp[left] = arr[begin1];
		left++;
		begin1++;
	}
	while (begin2 <= end2&&begin1>end1)
	{
		tmp[left] = arr[begin2];
		left++;
		begin2++;
	}

	left = begin;
	for (int i = 0; i < end - begin + 1; ++i)
	{
		arr[begin + i] = tmp[i];
	}
}

void MergeSort(int* arr, int begin, int end, int* tmp)
{
	
	int mid = begin + ((end - begin) >> 1);
	//先让左右区间有序，利用分治一层一层递归下去，直到有序，再进行归并
	if (begin < end)
	{
		MergeSort(arr, begin, mid, tmp);
		MergeSort(arr, mid + 1, end, tmp);
		Merge(arr, begin, mid, end, tmp);
	}	
}

void TestMergeSort()
{
	int arr[] = { 8, 1, 4, 11, 2, 9, 6 };
	size_t size = sizeof(arr) / sizeof(arr[0]);
	int* tmp = new int[size];
	if (tmp == NULL)
	{
		return;
	}
	MergeSort(arr, 0, size - 1,tmp);
	for (int i = 0; i < size; ++i)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	delete[] tmp;
}