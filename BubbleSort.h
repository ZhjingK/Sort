#pragma once
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

//√∞≈›≈≈–Ú
void Bubble1(int* arr, size_t size)
{
	for (int i = 0; i < size - 1; ++i)
	{
		for (int j = 0; j < size - i - 1; ++j)
		{
			if (arr[j] > arr[j + 1])
			{
				swap(arr[j], arr[j + 1]);
			}
		}
	}
}
void TestBubble1()
{
	int arr[] = { 2, 5, 3, 1, 4, 8, 7, 6, 9, 0 };
	size_t size = sizeof(arr) / sizeof(arr[0]);
	Bubble1(arr,size);
	for (int i = 0; i < (int)size; ++i)
	{
		printf("%d ", arr[i]);
	}
}

//√∞≈›≈≈–Úµƒ”≈ªØ
void Bubble2(int* arr, size_t size)
{
	int flag = 0;
	for (int i = 0; i < size - 1; ++i)
	{
		for (int j = 0; j < size - i - 1; ++j)
		{
			if (arr[j]>arr[j + 1])
			{
				flag = 1;
				swap(arr[j], arr[j + 1]);
			}
		}
		if (flag == 0)
		{
			break;
		}
	}
}
void TestBubble2()
{
	int arr[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	size_t size = sizeof(arr) / sizeof(arr[0]);
	Bubble2(arr,size);
	for (int i = 0; i < (int)size; ++i)
	{
		printf("%d ", arr[i]);
	}
}