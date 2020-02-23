// 7-bubble-sort.cpp : 冒泡排序：双层循环，一遍遍两两比较（三次交换）。
// 2020/02/22
// 冒泡排序效率很低（测试结果见末尾） O(n2)
// 只有对近乎有序的数组排序时，改进的冒泡排序较冒泡排序稍有改善

#include "SortTestHelper.h"
#include "SelectionSort.h"
#include "InsertionSort.h"

using namespace std;

template<typename T>
void bubbleSort(T arr[], int n) {

	bool swapped;

	do {
		swapped = false;
		for (int i = 1; i < n; i++)
			if (arr[i - 1] > arr[i]) {
				swap(arr[i - 1], arr[i]);
				swapped = true;
			}

		n--;// 每一次的排序都将最大的元素放在了最后，所以下一次排序最后的元素不考虑（一个不考虑）

	} while (swapped);
}

// 改进的冒泡排序
template<typename T>
void bubbleSort2(T arr[], int n) {

	int newn;

	do {
		newn = 0;
		for (int i = 1; i < n; i++)
			if (arr[i - 1] > arr[i]) {
				swap(arr[i - 1], arr[i]);
				newn = i;// 记录最后一次交换位置，在此之后的元素都不考虑（多个不考虑）
			}
		n = newn;
	} while (newn > 0);
}

int main()
{
	int n = 20000;
	// 测试1 一般测试
	cout << "Test for random array,size=" << n << ", random range [0," << n << "]" << endl;

	int *arr1 = SortTestHelper::generateRandomArray(n, 0, n);
	int *arr2 = SortTestHelper::copyIntArray(arr1, n);
	int *arr3 = SortTestHelper::copyIntArray(arr1, n);
	int *arr4 = SortTestHelper::copyIntArray(arr1, n);

	SortTestHelper::testSort("Selection Sort", selectionSort, arr1, n);
	SortTestHelper::testSort("Insertion Sort", insertionSort, arr2, n);
	SortTestHelper::testSort("Bubble Sort", bubbleSort, arr3, n);
	SortTestHelper::testSort("Bubble Sort 2", bubbleSort, arr4, n);

	delete[] arr1;
	delete[] arr2;
	delete[] arr3;
	delete[] arr4;

	cout << endl;

	// 测试2 测试近乎有序的数组
	int swapTimes = 100;

	cout << "Test for nNearly ordered array, size = " << n << ", swap time = " << swapTimes << endl;

	arr1 = SortTestHelper::generateNearlyOrderedArray(n, swapTimes);
	arr2 = SortTestHelper::copyIntArray(arr1, n);
	arr3 = SortTestHelper::copyIntArray(arr1, n);
	arr4 = SortTestHelper::copyIntArray(arr1, n);

	SortTestHelper::testSort("Selection Sort", selectionSort, arr1, n);
	SortTestHelper::testSort("Insertion Sort", insertionSort, arr2, n);
	SortTestHelper::testSort("Bubble Sort", bubbleSort, arr3, n);
	SortTestHelper::testSort("Bubble Sort 2", bubbleSort, arr4, n);

	delete[] arr1;
	delete[] arr2;
	delete[] arr3;
	delete[] arr4;

	cout << endl;

	// 测试3 测试完全有序的数组
	// 对于完全有序的数组，冒泡排序法也将成为O(n)级别的算法
	swapTimes = 0;
	n = 10000000;    // 由于插入排序法和冒泡排序法在完全有序的情况下都将成为O(n)算法
					 // 所以我们的测试数据规模变大，为1000,0000
	cout << "Test for ordered array, size = " << n << endl;

	arr1 = SortTestHelper::generateNearlyOrderedArray(n, swapTimes);
	arr2 = SortTestHelper::copyIntArray(arr1, n);
	arr3 = SortTestHelper::copyIntArray(arr1, n);
	arr4 = SortTestHelper::copyIntArray(arr1, n);

	// 在这种情况下，不再测试选择排序算法
	//SortTestHelper::testSort("Selection Sort", selectionSort, arr1, n);
	SortTestHelper::testSort("Insertion Sort", insertionSort, arr2, n);
	SortTestHelper::testSort("Bubble Sort", bubbleSort, arr3, n);
	SortTestHelper::testSort("Bubble Sort 2", bubbleSort, arr4, n);

	delete[] arr1;
	delete[] arr2;
	delete[] arr3;
	delete[] arr4;

	cin.get();
	return 0;
}
//Test for random array, size = 20000, random range[0, 20000]
//Selection Sort : 0.557 s
//Insertion Sort : 0.266 s
//Bubble Sort : 13.589 s
//Bubble Sort 2 : 14.962 s
//
//Test for nNearly ordered array, size = 20000, swap time = 100
//Selection Sort : 0.817 s
//Insertion Sort : 0.006 s
//Bubble Sort : 1.409 s
//Bubble Sort 2 : 1.319 s
//
//Test for ordered array, size = 10000000
//Insertion Sort : 0.09 s
//Bubble Sort : 0.049 s
//Bubble Sort 2 : 0.066 s

