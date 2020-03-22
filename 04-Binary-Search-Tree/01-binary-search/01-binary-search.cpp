// 01-binary-search.cpp : 二分查找。
// 2020/03/07
// 二分查找法，数组必须是有序的

#include <iostream>

using namespace std;
// 在有序数组 arr 中，查找 target
// 如果找到 target，返回相应的索引 index
// 如果没有找到 target，返回 -1
template<typename T>
int binarySearch(T arr[], int n, T target) {
	int l = 0, r = n - 1;// 在 [l...r] 中查找 target
	while (l <= r) {
		//x int mid = (l + r) / 2;
		int mid = l + (r - l) / 2;// 避免 (l+r) 溢出
		if (arr[mid] == target)
			return mid;
		if (target < arr[mid])
			r = mid - 1;
		else
			l = mid + 1;
	}
	return -1;
}

int main()
{
	return 0;
}