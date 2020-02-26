#pragma once

#include <iostream>
#include "InsertionSort.h"

using namespace std;

// ��arr[l..mid]��arr[mid+1,...r]�����ֽ��й鲢�������䣩
template<typename T>
void __merge(T arr[], int l, int mid, int r) {

	T *aux=new T [r - l + 1];// !ע������Ķ��巽ʽ��
	
	// ���Ƹ�������
	for (int i = l; i <= r; i++)
		aux[i - l] = arr[i];// ���ߴ���l��ƫ����

	int i = l, j = mid + 1;// ������������
	for (int k = l; k <= r; k++) {
		// ��������Խ�磬�ж������Ϸ���
		if (i > mid) {
			arr[k] = aux[j - l];
			j++;
		}
		else if (j > r) {
			arr[k] = aux[i - l];// ��aux��ʼԪ�أ���l��ƫ�ƣ�
			i++;
		}
		// ȷ�������Ϸ��ٽ��бȽϸ�ֵ
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
template<typename T>
void __mergeSort(T arr[], int l, int r) {

	//// ��ǰ�������ݼ�Ϊ��
	//if (l >= r)
	//	return;
	// �Ż�����������Сʱ�����ò����������鲢����
	if (r - l <= 15) {
		insertionSort(arr, l, r);
		return;
	}

	int mid = (l + r) / 2;// �����и����⣬��l��r�ǳ���ʱ��ӿ��ܻᷢ�����
	// һ�ֽ�������� ����ʽչ����l/2+r/2 
	__mergeSort(arr, l, mid);
	__mergeSort(arr, mid + 1, r);
	// �Ż�
	if (arr[mid] > arr[mid + 1])
		__merge(arr, l, mid, r);
}
template<typename T>
void mergeSort(T arr[], int n) {
	// �����python������ϰ�ߣ�__XXXXXΪ˽�к������� �û� ��Ӧ�õ��øú��������ǿ��Ե��ã�
	__mergeSort(arr, 0, n - 1);
}

