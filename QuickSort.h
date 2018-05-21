#pragma once
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include"MidNum.h"
#include"InsertSort.h"
using namespace std;

//快速排序
//左右指针法
int LRSort(int* arr, int begin, int end)
{
	MidNum(arr, begin, end);
	int key = arr[end];
	int left = begin;
	int right =end;
	while (left < right)
	{
		while (left<right&&arr[left] <= key)
		{
			++left;
		}
		while (left < right&&arr[right] >= key)
		{
			--right;
		}
		swap(arr[left], arr[right]);
	}
	swap(arr[left], arr[end]);

	return left;
}
void QuickSortLR(int* arr, int begin, int end)
{
	if (begin > end)
	{
		return;
	}
	//小区间优化
	if (end - begin + 1 < 5)
	{
		InsertSort(arr + begin, end - begin + 1);
	}
	else
	{
		int pos = LRSort(arr, begin, end);
		QuickSortLR(arr, begin, pos - 1);
		QuickSortLR(arr, pos + 1, end);
	}
}
	
void TestLRSort()
{
	int arr[] = { 8, 1, 4, 11, 2, 9, 6 };
	size_t size = sizeof(arr) / sizeof(arr[0]);
	QuickSortLR(arr, 0, size - 1);
	for (int i = 0; i < size; ++i)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

//挖坑法
int DigSort(int* arr, int begin, int end)
{
	int tmp = arr[end];
	int left = begin;
	int right = end;
	while (left < right)
	{
		while (left < right&&arr[left] <= tmp)
		{
			++left;
		}
		arr[right] = arr[left];
		while (left < right&&arr[right] >= tmp)
		{
			--right;
		}
		arr[left] = arr[right];
	}
	arr[left] = tmp;
	return left;
}
void QuickSortDig(int* arr, int begin, int end)
{
	if (begin > end)
	{
		return;
	}
	int pos = DigSort(arr, begin, end);
	QuickSortDig(arr, 0, pos - 1);
	QuickSortDig(arr, pos + 1, end);
}
void TestDigSort()
{
	int arr[] = { 8, 1, 4, 11, 2, 9, 6 };
	size_t size = sizeof(arr) / sizeof(arr[0]);
	QuickSortDig(arr, 0, size - 1);
	for (int i = 0; i < size; ++i)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

//前后指针法
int ABSort(int* arr, int begin, int end)
{
	int cur = begin;
	int prev = begin - 1;
	int key = arr[end];
	while (cur < end)
	{
		if (arr[cur] < key&&++prev != cur)
		{
			swap(arr[cur], arr[prev]);
		}
		++cur;
	}
	swap(arr[++prev], arr[end]);
	return prev;
}
void QuickSortAB(int* arr, int begin, int end)
{
	if (begin>end)
	{
		return;
	}
	int pos = ABSort(arr, begin, end);
	QuickSortAB(arr, begin, pos - 1);
	QuickSortAB(arr, pos + 1, end);
}
void TestABSort()
{
	int arr[] = { 8, 1, 4, 11, 2, 9, 6 };
	size_t size = sizeof(arr) / sizeof(arr[0]);
	QuickSortAB(arr, 0, size-1);
	for (int i = 0; i < size; ++i)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}
