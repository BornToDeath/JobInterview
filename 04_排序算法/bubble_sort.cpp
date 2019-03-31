#include <iostream>
using namespace std;

void BubbleSort(int arr[], int len);

int main(){
    
    int arr[] = {9,8,7,6,5,4,3,2,1};
    int len = sizeof(arr)/sizeof(int);
    BubbleSort(arr, len);
    for(int i=0;i<len;i++){
        cout<<arr[i]<<"\t";
    }
    cout<<endl;

    return 0;
}


//冒泡排序，从小到大
void BubbleSort(int arr[], int len){
    for(int i=0;i<len-1;i++){
        for(int j=len-1;j>=i;j--){
            if(arr[j] < arr[j-1]){
                int temp = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = temp;
            }
        }
    }
}

