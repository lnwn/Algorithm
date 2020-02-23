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
				// ��¼���һ�εĽ���λ�ã��ڴ˺��Ԫ����һ�ֲ�����
				newn = i;
			}
		n = newn;
	} while (newn > 0);
}