#pragma once
#include<stdio.h>
#include<stdlib.h>

//直接插入排序
void InsertSort(int* arr, size_t size)
{
	//这里i只能走到倒数第二个位置，end加一之后最后一个数也进行了比较
	for (size_t i = 0; i < size-1; ++i)
	{	
		size_t end = i;
		while (end >= 0)
		{
			int tmp = arr[end + 1];
			if (arr[end]>tmp)
			{
				arr[end + 1] = arr[end];
				arr[end] = tmp;
				--end;
			}
			else if (arr[end] < tmp)
			{
				break;
			}
		}
	}
}
void TestInsertSort()
{
	int arr[] = { 2, 5, 3, 1, 4, 8, 7, 6, 9, 0 };
	size_t size = sizeof(arr) / sizeof(arr[0]);
	InsertSort(arr, size);
	for (int i = 0; i < (int)size; ++i)
	{
		printf("%d ", arr[i]);
	}
}
