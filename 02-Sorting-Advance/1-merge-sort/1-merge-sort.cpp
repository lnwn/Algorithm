// 1-merge-sort.cpp : 归并排序。
// 2020/02/24
// O(nlogn) 由来：通过二分法达到 logn 的层级，每一层级通过O(n)级别的算法实现
// 归并排序需要开辟同样大小的临时空间辅助进行排序，相对来说占用了更多的存储空间
// 基本思想：三个索引。一个指向结果数组待放置的位置，另外两个指向待排序的数组当前待比较的两元素（划分后）。
// 依次比较两数，小的放至结果数组中，同时小数对应的数组和结果数组的指针后移，直至完全有序

#include <iostream>
#include "SortTestHelper.h"
#include "InsertionSort.h"

using namespace std;

// 将arr[l..mid]和arr[mid+1,...r]两部分进行归并
template<typename T>
void __merge(T arr[], int l, int mid, int r) {

	T aux[r - l + 1];// 临时辅助空间，大小与待排序数组空间一样大（设闭区间）

	for (int i = l; i <= r; i++) {

		aux[i - l] = arr[i];// 两者存在l的偏移量

		int i = l, j = mid + 1;// 设置两个索引
		for (int k = l; k <= r; k++) {
			// 考虑数组越界，判断索引合法性
			if (i > mid) {
				arr[k] = aux[j - l];
				j++;
			}
			else if (j > r) {
				arr[k] = aux[i - l];// 即aux起始元素（有l的偏移）
				i++;
			}
			// 确认索引合法再进行比较赋值
			else if (aux[i - l] < aux[j - l]) {
				arr[k] = aux[i - l];
				i++;
			}
			else {
				arr[k] = aux[j - l];
				j++;
			}
		}
	}
}
template<typename T>
void __mergeSort(T arr[], int l, int r) {
	// 当前处理数据集为空
	if (l >= r)
		return;
	int mid = (l + r) / 2;// 这里有个问题，当l和r非常大时相加可能会发生溢出
	// 一种解决方法是 将上式展开，l/2+r/2 
	__mergeSort(arr, l, mid);
	__mergeSort(arr, mid, r);
	__merge(arr, l, mid, r);
}
template<typename T>
void mergeSort(T arr[], int n) {
	// 借鉴了python的命名习惯，__XXXXX为私有函数，即 用户 不应该调用该函数（但是可以调用）
	__mergeSort(arr, 0, n - 1);
}

int main()
{
	int n = 50000;
	cout << "Test for Random Array,size = " << n << ", random range [0, " << n << "]" << endl;
	int *arr1 = SortTestHelper::generateRandomArray(n, 0, n);
	int *arr2 = SortTestHelper::copyIntArray(arr1, n);

	return 0;
}
