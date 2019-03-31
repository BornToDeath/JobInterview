#include <iostream>
using namespace std;

void SelectSort(int arr[], int len);

int main(){

    int arr[] = {9,8,7,6,5,4,3,2,1};
    int len = sizeof(arr)/sizeof(int);
    SelectSort(arr, len);
    for(int i =0;i<len;i++){
        cout<<arr[i]<<"\t";
    }
    cout<<endl;

    return 0;
}

//选择排序
void SelectSort(int arr[], int len){
    for(int i=0;i<len;i++){
        int index = i;
        for(int j = i+1;j<len;j++){
            if(arr[j]<arr[index]){
                index = j;
            }
        }
        if(index != i){
            int temp = arr[i];
            arr[i] = arr[index];
            arr[index] = temp;
        }
    }
}
