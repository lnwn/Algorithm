// 4-quick-sort-3ways.cpp : 三路快速排序，适合于处理大量相同元素的数组。
// 2020/02/26
// 将数组分为三部分：<v,=v,>v，只需递归的快排<v和>v的部分
// 对快速排序的思考：
// 优化1：对于底层可以考虑通过插入排序进行优化
// 即对于递归只剩很少的元素（16个）时采用插入排序能稍微提升算法性能
// 优化2：【针对近乎有序的数组】
// 这是由于快排也是不断将数组一分为二，与归并等分不同的是
// 快排是确定标定点（最左边）然后将数组分为小于和大于标定点两部分，
// 对于近乎有序的数组，这种标定点选取会导致分类效率很低
// 因此，优化即使标定点的选取方式变为随机选取
// 优化3：【针对含有大量相同元素】
// 将小于和大于标定点的两部分放在数组两端（以前都在一端），
// 两边索引同时向中心移动直至两索引重合
// 这样的好处是是等于标定点的大量元素分散在了小于和大于标定点的两部分
// 优化4：【三路快排，针对含有大量相同元素的数组】
// 小于，大于和等于标定点三部分 

#include <iostream>
#include "SortTestHelper.h"
#include "MergeSort.h"
#include "InsertionSort.h"
#include "QuickSort.h"

using namespace std;

// 三路快排处理 arr[l..r]
// 将arr[l...r]分为<v,=v,>v三部分
// 之后递归对<v,>v两部分继续进行三路快排
template<typename T>
void __quickSort3Ways(T arr[], int l, int r) {
	if (r - l <= 15) {
		insertionSort(arr, l, r);
		return;
	}
	// partition
	swap(arr[l], arr[rand() % (r - l + 1) + l]);
	T v = arr[l];
	int lt = l;// arr[l+1...lt]<v
	int gt = r + 1;// arr[gt...r]>v
	int i = l + 1;// arr[lt+1...i]==v
	while (i < gt) {
		if (arr[i] < v) {
			swap(arr[i], arr[lt + 1]);
			lt++;
			i++;
		}
		else if (arr[i] > v) {
			swap(arr[i], arr[gt - 1]);
			gt--;
		}
		else
			i++;// arr[i]==v
	}
	swap(arr[l], arr[lt]);
	__quickSort3Ways(arr, l, lt - 1);
	__quickSort3Ways(arr, gt, r);
}

template<typename T>
void quickSort3Ways(T arr[], int n) {
	srand(time(NULL));// 随即方式确立快排的标定点
	__quickSort3Ways(arr, 0, n - 1);
}

int main()
{

	int n = 1000000;

	// 测试1 一般性测试
	cout << "Test for Random Array, size = " << n << ", random range [0, " << n << "]" << endl;
	int* arr1 = SortTestHelper::generateRandomArray(n, 0, n);
	int* arr2 = SortTestHelper::copyIntArray(arr1, n);
	int* arr3 = SortTestHelper::copyIntArray(arr1, n);

	//SortTestHelper::testSort("Merge Sort", mergeSort, arr1, n);
	SortTestHelper::testSort("Quick Sort", quickSort, arr2, n);
	SortTestHelper::testSort("Quick Sort 3 Ways", quickSort3Ways, arr3, n);

	delete[] arr1;
	delete[] arr2;
	delete[] arr3;

	cout << endl;


	// 测试2 测试近乎有序的数组
	int swapTimes = 100;
	cout << "Test for Random Nearly Ordered Array, size = " << n << ", swap time = " << swapTimes << endl;
	arr1 = SortTestHelper::generateNearlyOrderedArray(n, swapTimes);
	arr2 = SortTestHelper::copyIntArray(arr1, n);
	arr3 = SortTestHelper::copyIntArray(arr1, n);

	//SortTestHelper::testSort("Merge Sort", mergeSort, arr1, n);
	SortTestHelper::testSort("Quick Sort", quickSort, arr2, n);
	SortTestHelper::testSort("Quick Sort 3 Ways", quickSort3Ways, arr3, n);

	delete[] arr1;
	delete[] arr2;
	delete[] arr3;

	cout << endl;


	// 测试3 测试存在包含大量相同元素的数组
	cout << "Test for Random Array, size = " << n << ", random range [0,10]" << endl;
	arr1 = SortTestHelper::generateRandomArray(n, 0, 10);
	arr2 = SortTestHelper::copyIntArray(arr1, n);
	arr3 = SortTestHelper::copyIntArray(arr1, n);

	//SortTestHelper::testSort("Merge Sort", mergeSort, arr1, n);
	SortTestHelper::testSort("Quick Sort", quickSort, arr2, n);
	SortTestHelper::testSort("Quick Sort 3 Ways", quickSort3Ways, arr3, n);

	delete[] arr1;
	delete[] arr2;
	delete[] arr3;

	cin.get();
	return 0;
}
