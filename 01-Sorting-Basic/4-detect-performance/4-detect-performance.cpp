// 4-detect-performance.cpp : 测试性能
// 2020/02/21

#include "TemplateSort.h"
#include "SortTestHelper.h"

using namespace std;

template<typename T>
void selectionSort(T arr[], int n) {
	for (int i = 0; i < n; i++) {
		// 寻找[i,n)区间内最小值
		int minIndex = i;
		for (int j = i + 1; j < n; j++)
			if (arr[j] < arr[minIndex])
				minIndex = j;
		swap(arr[i], arr[minIndex]);
	}
}

int main()
{
	int n = 100000;// 10000-0.179s,100000-14.358s
	int *arr = SortTestHelper::generateRandomArray(n, 0, n);
	//selectionSort(arr, n);
	//SortTestHelper::printArray(arr, n);
	SortTestHelper::testSort("Selection Sort", selectionSort, arr, n);
	delete[] arr;// 对应于new开辟的一块数组空间

	cin.get();
	return 0;
}
