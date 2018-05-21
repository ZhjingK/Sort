#pragma once
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

void MidNum(int* arr, int begin, int end)
{
	int mid = begin + ((end - begin) >> 1);
	if (arr[mid] > arr[begin])
	{
		//arr[begin] arr[mid] arr[end]
		if (arr[mid] < arr[end])
		{
			swap(arr[mid], arr[end]);
		}//arr[end] arr[begin] arr[mid]
		else if (arr[begin]>arr[end])
		{
			swap(arr[begin], arr[end]);
		}
		//else之后的情况如下，arr[end]就是处于中间大的值，可以作为key
		//arr[begin] arr[end] arr[mid] 
	}
	else
	{
		//arr[end] arr[mid] arr[begin]
		if (arr[mid] > arr[end])
		{
			swap(arr[mid], arr[end]);
		}
		else
		{
			//arr[mid] arr[begin] arr[end] 
			if (arr[begin] < arr[end])
			{
				swap(arr[begin], arr[end]);
			}
			//arr[mid] arr[end] arr[begin]
		}
	}
}