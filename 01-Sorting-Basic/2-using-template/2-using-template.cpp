// 2-using-template.cpp : 选择排序，模板类实现方式，使排序对象不再局限于单一类型。
// 2020/02/21

#include "TemplateSort.h"

using namespace std;

template<typename T>
void selectionSort(T arr[], int n) {
	for (int i = 0; i < n; i++) {
		int minIndex = i;
		for (int j = i + 1; j < n; j++)
			if (arr[j] < arr[minIndex])
				minIndex = j;
		swap(arr[i], arr[minIndex]);
	}
}

int main()
{
	int a[10] = { 10,9,8,7,6,5,4,3,2,1 };
	selectionSort(a, 10);
	for (int i = 0; i < 10; i++)
		cout << a[i] << " ";
	cout << endl;

	float b[4] = { 4.4,3.3,2.3,1.2 };
	selectionSort(b, 4);
	for (int i = 0; i < 4; i++)
		cout << b[i] << " ";
	cout << endl;

	string c[4] = { "D","B","C","A" };
	selectionSort(c, 4);
	for (int i = 0; i < 4; i++)
		cout << c[i] << " ";
	cout << endl;

	Student d[4] = { {"D",90},{"C",100},{"B",95},{"A",95} };
	selectionSort(d, 4);
	for (int i = 0; i < 4; i++)
		cout << d[i];
	cout << endl;

	cin.get();
	return 0;
}
