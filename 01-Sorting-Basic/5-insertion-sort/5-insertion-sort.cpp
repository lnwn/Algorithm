// 5-insertion-sort.cpp : 插入排序。
// 2020/02/21

#include "SortTestHelper.h"
#include "SelectionSort.h"

using namespace std;

template<typename T>
void insertionSort(T arr[], int n) {
	for (int i = 1; i < n; i++) {
		// 寻找元素arr[i]合适的位置
		// 写法1
		for (int j = i; j > 0; j--) {
			// 插入排序与选择排序最大的不同：插排第二层循环可以提前结束
			if (arr[j] < arr[j - 1])
				swap(arr[j], arr[j - 1]);
			else
				break;
			//// 写法2
			//for (int j = i; j > 0 && arr[j] < arr[j - 1]; j--)
			//	swap(arr[j], arr[j - 1]);
		}
	}
	return;
}

int main()
{
	int n = 10000;
	int *arr1 = SortTestHelper::generateRandomArray(n, 0, n);
	int *arr2 = SortTestHelper::copyIntArray(arr1, n);

	SortTestHelper::testSort("Insertion Sort", insertionSort, arr1, n);
	SortTestHelper::testSort("Selection Sort", selectionSort, arr2, n);

	delete[] arr1;
	delete[] arr2;

	cin.get();
	return 0;
}

