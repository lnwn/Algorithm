// 1-selection-sort.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// 2020/02/20

#include <iostream>

using namespace std;

void selectionSort(int arr[], int n) {
	for (int i = 0; i < n; i++) {
		//寻找 [i,n] 区间里的最小值
		int minIndex = i;
		for (int j = i + 1; j < n; j++) {
			if (arr[j] < arr[minIndex])
				minIndex = j;
		}
		swap(arr[i], arr[minIndex]);
	}
}

int main()
{
	int a[10] = { 10,9,7,4,8,6,5,1,3,2 };
	selectionSort(a, 10);
	for (int i = 0; i < 10; i++)
		cout << a[i] << " ";
	cout << endl;
	cin.get();
	return 0;
}
