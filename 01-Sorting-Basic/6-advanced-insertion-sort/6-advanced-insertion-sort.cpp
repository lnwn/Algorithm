// 6-advanced-insertion-sort.cpp : 改进的插入排序。
// 改进思想：传统算法在比较后做交换（三次赋值），改进后在比较后做一次赋值
// 2020/02/22

// 选择排序两层循环，每层都需要完全执行，效率低
// 插入排序内层循环可以提前结束，近乎有序的方法效率高，甚至高于一些O(nlogn)的算法
// 冒泡排序法（Bubble Sort）
// 希尔排序（Shell Sort），整体思路是插入排序的延伸
// 对于排序算法，最优复杂度是O(nlogn)

#include "SortTestHelper.h"
#include "SelectionSort.h"

using namespace std;

template<typename T>
void insertionSort(T arr[], int n) {
	for (int i = 1; i < n; i++) {
		// 寻找元素arr[i]合适的插入位置
		T e = arr[i];
		int j;// j保存元素e应该插入的位置
		for (j = i; j > 0 && arr[j - 1] > e; j--)
			arr[j] = arr[j - 1];
		arr[j] = e;
	}
	return;
}
// O(n2)的算法并非一无是处，比如：
// 对于近乎有序的数组，插入排序性能要远优于选择排序，甚至由于O(nlogn)的算法
int main()
{
	int n = 10000;
	int *arr1 = SortTestHelper::generateNearlyOrderedArray(n, 100);// 0-3之间
	int *arr2 = SortTestHelper::copyIntArray(arr1, n);

	SortTestHelper::testSort("Insertion Sort", insertionSort, arr1, n);
	SortTestHelper::testSort("Selection Sort", selectionSort, arr2, n);

	delete[] arr1;
	delete[] arr2;

	cin.get();
	return 0;
}
