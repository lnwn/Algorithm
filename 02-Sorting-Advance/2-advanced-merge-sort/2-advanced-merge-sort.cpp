// 2-advanced-merge-sort.cpp : 自底向上的归并排序。
// 2020/02/25
// 重要意义：没有涉及到数组的重要特性——通过索引获取元素，因此可以很好的使用nlogn的时间对链表进行排序

#include <iostream>
#include "SortTestHelper.h"
#include "MergeSort.h"

using namespace std;
// BU 自底向上
template <typename T>
void mergeSortBU(T arr[], int n) {
	for (int sz = 1; sz <= n; sz += sz)
		for (int i = 0; i +sz < n; i += sz + sz)
			// 对arr[i...i+sz-1]和arr[i+sz...i+2*sz-1]进行归并
			__merge(arr, i, i + sz - 1, min(i + sz + sz - 1, n-1));
}

int main()
{
	return 0;
}
