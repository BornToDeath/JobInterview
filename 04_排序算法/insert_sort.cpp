#include <iostream>
using namespace std;

void InsertSort(int arr[], int len);

int main(){
    int arr[] = {8,7,7,6,5,4,34,32,1};
    int len = sizeof(arr)/sizeof(int);
    InsertSort(arr, len);
    for(int i=0;i<len;i++){
        cout<<arr[i]<<"\t";
    }
    cout<<endl;
    return 0;
}

//插入排序
void InsertSort(int arr[], int len){
    if(len<=1){
        return;
    }
    for(int i=1;i<len;i++){
       int j=i-1;
       int temp = arr[i];
       while(temp<arr[j] && j>=0){
            arr[j+1] = arr[j];
            j--;
       }
       arr[j+1] = temp;
    }
}

