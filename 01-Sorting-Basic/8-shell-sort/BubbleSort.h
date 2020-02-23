#pragma once
#include <iostream>
//#include <algorithm>

using namespace std;

template<typename T>
void bubbleSort(T arr[], int n) {

	int newn;

	do {
		newn = 0;
		for (int i = 1; i < n; i++)
			if (arr[i - 1] > arr[i]) {
				swap(arr[i - 1], arr[i]);
				// 记录最后一次的交换位置，在此后的元素下一轮不考虑
				newn = i;
			}
		n = newn;
	} while (newn > 0);
}