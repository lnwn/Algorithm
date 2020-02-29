// 03-Shift-Down.cpp : 从最大堆中取出元素（出队）。
// 2020/02/29
// 从堆中取出一个元素，只能从根节点取出，
// 然后为了保持堆是完全二叉树的性质，将最后一个元素补到第一个
// 最后为了保持最大堆的性质，将根节点的元素向下转换直到大小合适（大于它的子节点小于它的父节点）
// 左右两子节点分别比较，和更大的交换

#include <iostream>
#include <cmath>
#include <string>
#include <cassert>
#include <ctime>

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
	void insert(Item item) {
		assert(count + 1 <= capacity);
		data[count + 1] = item;
		count++;
		shiftUp(count);
	}
	Item extractMax() {
		assert(count > 0);
		Item ret = data[1];
		swap(data[1], data[count]);
		count--;
		shiftDown(1);
		return ret;
	}

private:
	Item* data;
	int count;
	void shiftUp(int k) {
		while (k > 1 && data[k / 2] < data[k]) {
			swap(data[k / 2], data[k]);
			k /= 2;
		}
	}
	void shiftDown(int k) {
		// k处有左孩就认为有孩子（完全二叉树）
		while (2 * k <= count) {
			int j = 2 * k;// 在此轮循环中，data[k]和data[j]交换位置
			// 如果有右孩且右孩子大于左孩子
			if (j + 1 <= count && data[j + 1] > data[j])
				j += 1;
			if (data[k] >= data[j])
				break;
			swap(data[k], data[j]);
			k = j;
		}
	}
};

int main()
{
	MaxHeap<int> maxheap = MaxHeap<int>(100);
	// cout << maxheap.size() << endl;
	srand(time(NULL));
	for (int i = 0; i < 15; i++)
		maxheap.insert(rand() % 100);
	while (!maxheap.isEmpty())
		cout << maxheap.extractMax() << " ";
	cout << endl;

	cin.get();
	return 0;
}

