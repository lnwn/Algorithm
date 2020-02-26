#pragma once
#include <iostream>
#include <ctime>
#include <string>// 不包含会报一些奇怪的错误
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
	// 测试sort正确性
	template<typename T>
	bool isSorted(T arr[], int n) {
		for (int i = 0; i < n - 1; i++)
			if (arr[i] > arr[i + 1])
				return false;
		return true;
	}
	// 计算执行时间
	template<typename T>
	void testSort(const string &sortName, void(*sort)(T[], int), T arr[], int n) {
		clock_t startTime = clock();
		sort(arr, n);
		clock_t endTime = clock();
		assert(isSorted(arr, n));
		cout << sortName << " : " << double(endTime - startTime) / CLOCKS_PER_SEC << " s" << endl;
		// CLOCKS_PER_SEC 每秒钟运行的时钟周期个数
		return;
	}
	// 拷贝数组
	int* copyIntArray(int a[], int n) {
		int* arr = new int[n];
		copy(a, a + n, arr);
		return arr;
	}
	int *generateNearlyOrderedArray(int n, int swapTimes) {
		// 先生成一个完全有序的数组
		int *arr = new int[n];
		for (int i = 0; i < n; i++)
			arr[i] = i;
		// 随机交换位置，得到近似有序的数组
		srand(time(NULL));
		for (int i = 0; i < swapTimes; i++) {
			int posx = rand() % n;
			int posy = rand() % n;
			swap(arr[posx], arr[posy]);
		}
		return arr;
	}
};