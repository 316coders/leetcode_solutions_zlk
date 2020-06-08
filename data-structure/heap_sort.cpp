//
// Created by zale on 2020/6/8.
//


#include <iostream>
#include <algorithm>
using namespace std;

// 在c++的函数里面，如果把一个数组作为参数传进去，那么这个数组就会退化为一个指针，因而就不知道这个数组的长度
// 使用模板定义一 个函数getArrayLen,该函数将返回数组array的长度
template<class T>
int getArrayLen(T& array){
    return sizeof(array)/ sizeof(array[0]);
}


/**
 * 堆类完全二叉树结构
 * 满足一定条件可分为大顶堆小顶堆
 * 关键性质：
 *      1. 若一个结点的下标为k，那么它的父结点为(k-1)/2，其子节点为2k+1和2k+2
 *      2. 最后一个父节点（非叶子结点）的索引为(len/2 - 1)
 *
 *
 */


// 不断建立大顶堆，当顶部的元素调整以后还要对调整的子树元素进行调整，这里通过while循环实现。
void max_heapify(int arr[], int start, int end){
    // 建立父节点指针和子节点指针
    int dad = start;
    int son = dad *2 +1;
    while(son <= end){ // 若子节点指针位置在范围内才做出比较
        if(son + 1 <= end && arr[son] < arr[son + 1]){  // 先比较两个子节点大小，选择最大的
            son ++;
        }
        if(arr[dad] > arr[son]){  //如果父节点大于子节点代表调整完毕，直接跳出函数
            return;
        }
        else{   // 否则交换父子内容再继续子节点和孙子结点的比较
            swap(arr[dad],arr[son]);
            dad = son; // 将dad设为son，继续比较字数进行调整
            son = dad * 2 + 1;  // 将son设置叶子结点，继续比较子树进行调整。
        }
    }
}

void heap_sort(int arr[],int len){
    //初始化，i从最后一个父节点（非叶子结点）开始调整，通过循环知道调整到i=0，这样就建立了一个大顶堆或者小顶堆
    for (int i = len/2 - 1;i >= 0;i--){
        max_heapify(arr,i,len-1);
    }
    //将堆顶第一个元素和已排好顺序的元素的前一位做交换，再重新调整，直到排序完毕，这样就能够将数组变为有序数组
    for(int i = len - 1; i > 0; i--){
        swap(arr[0],arr[i]);
        max_heapify(arr,0,i - 1);
    }
}


int main(){
    int arr[] =  { 3, 5, 3, 0, 8, 6, 1, 5, 8, 6, 2, 4, 9, 4, 7, 0, 1, 8, 9, 7, 3, 1, 2, 5, 9, 7, 4, 0, 2, 6 };
//    int len = (int)sizeof(arr) / sizeof(*arr);
    int len = getArrayLen(arr);
    heap_sort(arr, len);
    for (int i = 0; i < len; i++)
        cout << arr[i] << ' ';
    cout << endl;
    return 0;


}