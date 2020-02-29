// 02-Shift-Up.cpp : 向最大堆中添加新元素。
// 2020/02/29
// 堆使用数组进行表示，所以添加新元素相当于在数组末尾添加新元素
// 以最大堆定义为标准与父节点比较，调整位置

#include "testPrint.h"

int main()
{
	MaxHeap<int> maxheap = MaxHeap<int>(100);
	cout << maxheap.size() << endl;
	srand(time(NULL));
	for (int i = 0; i < 15; i++)
		maxheap.insert(rand() % 100);

	maxheap.testPrint();

	cin.get();
	return 0;
}