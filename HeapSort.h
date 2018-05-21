#pragma once
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

//∂—≈≈–Ú
void AdjustDown(int* arr, size_t size, int parent)
{
	int child = parent * 2 + 1;
	while (child < size)
	{
		if (child + 1 < size&&arr[child] < arr[child + 1])
		{
			child += 1;
		}
		if (arr[child]>arr[parent])
		{
			swap(arr[parent],arr[child]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}
void HeapSort(int* arr, size_t size)
{
	for (int i = (size - 2) / 2; i >=0 ; --i)
	{
		AdjustDown(arr, size, i);
	}
	int end = size - 1;
	while (end)
	{
		swap(arr[0], arr[end]);
		AdjustDown(arr, end, 0);
		end--;
	}
	for (int i = 0; i < size; ++i)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

void TestHeapSort()
{
	int arr[] = { 2, 5, 3, 1, 4, 8, 7, 6, 9, 0 };
	size_t size = sizeof(arr) / sizeof(arr[0]);
	HeapSort(arr, size);
	for (int i = 0; i < (int)size; ++i)
	{
		printf("%d ", arr[i]);
	}
}