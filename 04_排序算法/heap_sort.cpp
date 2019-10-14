#include <iostream>
using namespace std;


void HeapSort(int arr[], int);
void HeapAdjust(int arr[], int, int);



int main(){
    
    int arr[] = {7,6,4,5,6342,5,56,4,74,5,324,7};
    int len = sizeof(arr)/sizeof(int);
    //堆排序，从小到大排序 
    HeapSort(arr, len);
    for(int i=0;i<len;i++){
        cout<<arr[i]<<", ";
    }
    cout<<endl;

    return 0;
}

/**
 * 堆排序。升序排序
 * arr: 待排序的整数数组
 * len: 数组长度
 */
void HeapSort(int arr[], int len){
    //调整堆的结构，从最后一个非叶子节点开始调整。
    //如果是升序的话则调整为大顶堆
    for(int i=len/2-1;i>=0;i--){
        HeapAdjust(arr, i, len);
    }
    int temp;
    for(int i=len-1;i>0;i--){
        //将第一个元素（大顶堆的根）和最后一个元素交换
        temp = arr[i];
        arr[i] = arr[0];
        arr[0] = temp;
        //重新调整当前堆的结构
        HeapAdjust(arr, 0, i);
    }

}

/**
 * 堆顺序调整，调整为大顶堆
 * arr: 待调整的整数数组
 * index: 待调整的数组元素的下标
 * len: 数组长度
 */
void HeapAdjust(int arr[], int index, int len){
    int child;
    while(index*2+1 < len){
        child = index * 2 + 1; //右孩子
        if(child+1 < len && arr[child] < arr[child+1]){  //左孩子小于右孩子
            child++;
        }
        if(arr[index] < arr[child]){  //父节点小于孩子节点，交换两者的值
            int temp = arr[child];
            arr[child] = arr[index];
            arr[index] = temp;
        }else{
            break;
        }
        index = child;         
    }
}
