// 8-shell-sort.cpp : 希尔排序。
// 2020/02/22
// 插入排序对于较小数据量或者基本有序的数据性能高，希尔排序则是利用了这一优势，将较大数据集分成较小数据集分组进行插入排序
// 这时插入排序作用的数据量小，效率高
// 时间复杂度与增量序列有关

#include "SortTestHelper.h"
#include "BubbleSort.h"
#include "InsertionSort.h"
#include "SelectionSort.h"

using namespace std;

template<typename T>
void shellSort(T arr[], int n) {
	// 计算增量序列：1，4，13，40，121，364，1093...
	int h = 1;
	while (h < n / 3)
		h = 3 * h + 1;
	while (h >= 1) {
		// h-sort the array
		for (int i = h; i < n; i++) {
			// 对arr[i],arr[i-h],arr[i-2h],arr[i-3h]...使用插入排序
			T e = arr[i];
			int j;
			for (j = i; j >= h && e < arr[j - h]; j -= h)
				arr[j] = arr[j - h];
			arr[j] = e;
		}
		h /= 3;
	}

}

// 比较SelectionSort，InsertionSort和BubbleSort和ShellSort四种排序算法的性能
// ShellSort是这四种中性能最优的算法
int main()
{
	int n = 20000;
	// 测试1 一般测试
	cout << "Test for random array, size = " << n << ", random range [0, " << n << "]" << endl;

	int *arr1 = SortTestHelper::generateRandomArray(n, 0, n);
	int *arr2 = SortTestHelper::copyIntArray(arr1, n);
	int *arr3 = SortTestHelper::copyIntArray(arr1, n);
	int *arr4 = SortTestHelper::copyIntArray(arr1, n);

	SortTestHelper::testSort("Selection Sort", selectionSort, arr1, n);
	SortTestHelper::testSort("Insertion Sort", insertionSort, arr2, n);
	SortTestHelper::testSort("Bubble Sort", bubbleSort, arr3, n);
	SortTestHelper::testSort("Shell Sort", shellSort, arr4, n);

	delete[] arr1;
	delete[] arr2;
	delete[] arr3;
	delete[] arr4;
	cout << endl;

	// 测试2 测试近乎有序的数组
	int swapTimes = 100;

	cout << "Test for nearly ordered array, size = " << n << ", swap time = " << swapTimes << endl;

	arr1 = SortTestHelper::generateNearlyOrderedArray(n, swapTimes);
	arr2 = SortTestHelper::copyIntArray(arr1, n);
	arr3 = SortTestHelper::copyIntArray(arr1, n);
	arr4 = SortTestHelper::copyIntArray(arr1, n);

	SortTestHelper::testSort("Selection Sort", selectionSort, arr1, n);
	SortTestHelper::testSort("Insertion Sort", insertionSort, arr2, n);
	SortTestHelper::testSort("Bubble Sort", bubbleSort, arr3, n);
	SortTestHelper::testSort("Shell Sort", shellSort, arr4, n);

	delete[] arr1;
	delete[] arr2;
	delete[] arr3;
	delete[] arr4;

	cin.get();
	return 0;
}
//Test for random array, size = 20000, random range[0, 20000]
//Selection Sort : 0.658 s
//Insertion Sort : 0.334 s
//Bubble Sort : 17.755 s
//Shell Sort : 0.006 s
//
//Test for nearly ordered array, size = 20000, swap time = 100
//Selection Sort : 0.734 s
//Insertion Sort : 0.005 s
//Bubble Sort : 1.092 s
//Shell Sort : 0.003 s