// 2-advanced-merge-sort.cpp : 自底向上的归并排序。
// 2020/02/25
// 重要意义：没有涉及到数组的重要特性——通过索引获取元素，因此可以很好的使用nlogn的时间对链表进行排序

#include <iostream>
#include "SortTestHelper.h"
#include "MergeSort.h"

using namespace std;

// BU 自底向上
template <typename T>
void mergeSortBU(T arr[], int n){

//    for( int sz = 1; sz <= n ; sz += sz )
//        for( int i = 0 ; i < n ; i += sz+sz )
//            // 对 arr[i...i+sz-1] 和 arr[i+sz...i+2*sz-1] 进行归并
//            __merge(arr, i, i+sz-1, min(i+sz+sz-1,n-1) );

    // Merge Sort Bottom Up 优化
    for( int i = 0 ; i < n ; i += 16 )
        insertionSort(arr,i,min(i+15,n-1));

    for( int sz = 16; sz <= n ; sz += sz )
        for( int i = 0 ; i < n - sz ; i += sz+sz )
            if( arr[i+sz-1] > arr[i+sz] )
                __merge(arr, i, i+sz-1, min(i+sz+sz-1,n-1) );
}


int main() {

    int n = 1000000;

    cout<<"Test for Random Array, size = "<<n<<", random range [0, "<<n<<"]"<<endl;
    int* arr1 = SortTestHelper::generateRandomArray(n,0,n);
    int* arr2 = SortTestHelper::copyIntArray(arr1, n);

    SortTestHelper::testSort("Merge Sort", mergeSort, arr1, n);
    SortTestHelper::testSort("Merge Sort Bottom Up", mergeSortBU, arr2, n);

    delete(arr1);
    delete(arr2);

    cout<<endl;

    // 测试2 测试近乎有序的数组
    int swapTimes = 100;
    cout<<"Test for Random Nearly Ordered Array, size = "<<n<<", swap time = "<<swapTimes<<endl;
    arr1 = SortTestHelper::generateNearlyOrderedArray(n,swapTimes);
    arr2 = SortTestHelper::copyIntArray(arr1, n);

    SortTestHelper::testSort("Merge Sort", mergeSort, arr1, n);
    SortTestHelper::testSort("Merge Sort Bottom Up", mergeSortBU, arr2, n);

    delete(arr1);
    delete(arr2);

    return 0;
}