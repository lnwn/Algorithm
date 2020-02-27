#pragma once
#include <iostream>
#include <algorithm>
#include <ctime>

using namespace std;

namespace TestHelper {

	// ����һ����ȫ���������
	int *generateOrderedArray(int n) {

		int *arr = new int[n];
		for (int i = 0; i < n; i++)
			arr[i] = i;

		return arr;
	}

	// ������arr�����
	void shuffleArray(int arr[], int n) {

		srand(time(NULL));
		for (int i = 0; i < n; i++) {
			int j = rand() % (n - i) + i;
			swap(arr[i], arr[j]);
		}
	}
}