// QS-nearly-ordered-array.cpp : 测试近乎有序的数组。
// 2020/02/26
// 快速排序最差情况：完全有序，时间复杂度将退化为O(n2)。
// 当数组完全有序，其他元素都要比找的标定点大（每次都使用最左边的元素为标定点），
// 则生成的树左边没有东西，只有右边（除去标定点）。
// 最后生成的树有n层，每层时间复杂度O(n)，共O(n2)。

#include "SortTestHelper.h"
#include "MergeSort.h"
#include "InsertionSort.h"

using namespace std;

template <typename T>
int __partition(T arr[], int l, int r) {

	swap(arr[l], arr[rand() % (r - l + 1) + l]);

	T v = arr[l];
	int j = l;
	for (int i = l + 1; i <= r; i++)
		if (arr[i] < v) {
			j++;
			swap(arr[j], arr[i]);
		}

	swap(arr[l], arr[j]);

	return j;
}

template <typename T>
void __quickSort(T arr[], int l, int r) {

	//    if( l >= r )
	//        return;
	if (r - l <= 15) {
		insertionSort(arr, l, r);
		return;
	}

	int p = __partition(arr, l, r);
	__quickSort(arr, l, p - 1);
	__quickSort(arr, p + 1, r);
}

template <typename T>
void quickSort(T arr[], int n) {

	srand(time(NULL));
	__quickSort(arr, 0, n - 1);
}

int main() {

	int n = 1000000;

	//// 测试1 一般性测试
	//cout << "Test for Random Array, size = " << n << ", random range [0, " << n << "]" << endl;
	//int* arr1 = SortTestHelper::generateRandomArray(n, 0, n);
	//int* arr2 = SortTestHelper::copyIntArray(arr1, n);

	////SortTestHelper::testSort("Merge Sort", mergeSort, arr1, n);
	//SortTestHelper::testSort("Quick Sort", quickSort, arr2, n);

	//delete[] arr1;
	//delete[] arr2;

	//cout << endl;

	//// 测试2 测试近乎有序的数组
	//int swapTimes = 100;
	//cout << "Test for Random Nearly Ordered Array, size = " << n << ", swap time = " << swapTimes << endl;
	//arr1 = SortTestHelper::generateNearlyOrderedArray(n, swapTimes);
	//arr2 = SortTestHelper::copyIntArray(arr1, n);

	////SortTestHelper::testSort("Merge Sort", mergeSort, arr1, n);
	//SortTestHelper::testSort("Quick Sort", quickSort, arr2, n);

	//delete[] arr1;
	//delete[] arr2;

	//cout << endl;

	// 测试3 测试存在包含大量相同元素的数组
	cout << "Test for Random Array, size = " << n << ", random range [0,10]" << endl;
	int *arr1 = SortTestHelper::generateRandomArray(n, 0, 10);
	int *arr2 = SortTestHelper::copyIntArray(arr1, n);

	//SortTestHelper::testSort("Merge Sort", mergeSort, arr1, n);
	SortTestHelper::testSort("Quick Sort", quickSort, arr2, n);

	delete[] arr1;
	delete[] arr2;

	cin.get();
	return 0;
}