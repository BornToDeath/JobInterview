#include <iostream>
using namespace std;

void QuickSort(int arr[], int, int);

int main(){

    int arr[] = {5,32,43,5,677,4,10,3,32,23};
    int len = sizeof(arr)/sizeof(len);
    QuickSort(arr, 0, len-1);
    for(int i=0;i<len;i++){
        cout<<arr[i]<<"\t";
    }
    cout<<endl;
    
    return 0; 
}

//快速排序
void QuickSort(int arr[], int start, int end){
    if(start < end){
        int s = start;
        int e = end;
        int target = arr[start];
        while(start < end){
            //从后往前
            while(arr[end] > target && start < end){
                end--;
            }
            if(start < end){
                arr[start++] = arr[end];
            }
            //从前往后
            while(arr[start] < target && start < end){
                start++;
            }
            if(start < end){
                arr[end--] = arr[start];
            }
        }
        arr[start] = target;
        QuickSort(arr, s, start-1);
        QuickSort(arr, start+1, e);
    }
}
