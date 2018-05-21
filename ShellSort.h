#pragma once
#include<stdio.h>
#include<stdlib.h>

//Ï£¶ûÅÅÐò
void ShellSort(int* arr, size_t size)
{
	int gap = 3;
	while (gap > 1)
	{
		gap = gap / 3 + 1;
		for (size_t i = 0; i < size - gap; ++i)
		{
			size_t end = i;
			int tmp = arr[end + gap];
			while (end >= 0)
			{
				if (arr[end]>tmp)
				{
					arr[end + gap] = arr[end];
					arr[end] = tmp;
					end -= gap;
				}
				else
				{
					break;
				}
			}
		}
	}
}
void TestShellSort()
{
	int arr[] = { 2, 5, 3, 1, 4, 8, 7, 6, 9, 0 };
	size_t size = sizeof(arr) / sizeof(arr[0]);
	ShellSort(arr, size);
	for (int i = 0; i < (int)size; ++i)
	{
		printf("%d ", arr[i]);
	}
}
