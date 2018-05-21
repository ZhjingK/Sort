#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<stack>
using namespace std;

//以挖坑法为例进行非递归
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

void QuickSortNoR(int* arr, int begin, int end)
{
	stack<int> s;
	//保证在数据有效的时候才将begin，end压入栈中
	if (begin < end)
	{
		s.push(end);	
		s.push(begin);
	}

	int left = s.top();
	s.pop();
	int right = s.top();
	s.pop();

	int div = DigSort(arr, left, right);
	if (left < div-1)
	{
		s.push(div - 1);
		s.push(left);
	}
	if (right>div + 1)
	{
		s.push(div + 1);
		s.push(right);
	}
}
void TestQuickSortNoR()
{
	int arr[] = { 8, 1, 4, 11, 2, 9, 6 };
	size_t size = sizeof(arr) / sizeof(arr[0]);
	QuickSortNoR(arr, 0, size - 1);
	for (int i = 0; i < size; ++i)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}