#include <iostream>
using namespace std;


void MergeSort(int[], int, int);
void Merge(int[], int, int, int);

int main(){

    int arr[] = {2,3,4,6,5,3,4,45,6,475,45,2,42,4};
    int len = sizeof(arr)/sizeof(int);
    MergeSort(arr, 0, len-1);
    for(int i=0;i<len;i++){
        cout<<arr[i]<<", ";
    }
    cout<<endl;
    return 0;
}

//归并排序
void MergeSort(int arr[], int start, int end){
    if(start < end){
        int mid = (end-start)/2 + start;
        //分
        MergeSort(arr, start, mid);
        MergeSort(arr, mid+1, end);
        //治
        Merge(arr, start, mid, end);
    }
}

//合并两个有序数组
void Merge(int arr[], int start, int mid, int end){
    int *temp = new int[end-start+1];
    int i = mid;
    int j = end;
    int k = end-start;
    while(i>=start && j>=mid+1){
        if(arr[i] < arr[j]){
            temp[k--] = arr[j--];
        }else{
            temp[k--] = arr[i--];
        }
    }
    while(i>=start){
        temp[k--] = arr[i--];
    }
    while(j>=mid+1){
        temp[k--] = arr[j--];
    }
    for(int i=0,j=start;j<=end;i++,j++){
        arr[j] = temp[i];
    }

}
