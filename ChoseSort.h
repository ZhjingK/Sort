#pragma once
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

//一元选择排序
void ChoseSort(int* arr, size_t size)
{	
	int min = 0;
	for (int i = 0; i < size; ++i)
	{
		min = i;
		for (int j = i; j < size; ++j)
		{
			if (arr[j]<arr[min])
			{
				min = j;
			}
		}
		swap(arr[min],arr[i]);
	}
}
void TestChoseSort()
{
	int arr[] = { 2, 5, 3, 1, 4, 8, 7, 6, 9, 0 };
	size_t size = sizeof(arr) / sizeof(arr[0]);
	ChoseSort(arr, size);
	for (int i = 0; i < size; ++i)
	{
		printf("%d  ", arr[i]);
	}
	cout << endl;
}

//二元选择排序
