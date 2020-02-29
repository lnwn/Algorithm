// 01-max-heap-class-basic.cpp : 构建一个最大堆类
// 2020/02/28

#include <iostream>
#include <cmath>
#include <string>
#include <cassert>

using namespace std;

template <typename Item>
class MaxHeap
{
public:
	// 用户自定义存储空间
	MaxHeap(int capacity) {
		data = new Item[capacity + 1];// 数组存储堆的数据是从 1开始的
		count = 0;
	}
	~MaxHeap() {
		delete[] data;
	}
	int size() {
		return count;
	}
	bool isEmpty() {
		return count == 0;
	}

private:
	Item* data;
	int count;
};

int main()
{
	MaxHeap<int> maxheap = MaxHeap<int>(100);
	cout << maxheap.size() << endl;
	return 0;
}
