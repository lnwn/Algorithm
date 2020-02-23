#pragma once
#include <iostream>
#include <ctime>
#include <cassert>

using namespace std;

namespace SortTestHelper {
	// 生成n个元素的随机数组，每个元素的随即范围[rangeL,rangeR]
	int* generateRandomArray(int n, int rangeL, int rangeR) {
		assert(rangeL <= rangeR);
		int *arr = new int[n];
		srand(time(NULL));
		for (int i = 0; i < n; i++)
			arr[i] = rand() % (rangeR - rangeL + 1) + rangeL;// 控制随机数生成范围

		return arr;
	}
	// 打印数组
	template<typename T>
	void printArray(T arr[], int n) {
		for (int i = 0; i < n; i++)
			cout << arr[i] << " ";
		cout << endl;
		return;
	}
};