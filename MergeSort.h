#pragma once
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

//����������һ���������飬�����ں������ڶ������ÿһ�εݹ鶼�ᴴ��һ�����飬��ɲ���Ҫ�Ŀ���
void Merge(int* arr, int begin,int mid, int end, int tmp[])
{
	//��һ�������Ϊbegin mid | mid+1 end
	int begin1 = begin;
	int end1 = mid;
	int begin2 = mid + 1;
	int end2 = end;

	int left = 0;
	while (begin1 <= end1&&begin2 <= end2)
	{
		//������бȽ�
		while (begin1 <= end1&&arr[begin1] < arr[begin2])
		{
			tmp[left++] = arr[begin1++];
		}
		while (begin2<=end2&&arr[begin1]>arr[begin2])
		{
			tmp[left++] = arr[begin2++];
		}
	}
	//����һ�������Ƚ���������������������
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
	//�������������������÷���һ��һ��ݹ���ȥ��ֱ�������ٽ��й鲢
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