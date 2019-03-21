#include <iostream>
using namespace std;

/*******
* 给定一个整数n，打印从1至n的所有数字组成的全排列
********/

void dfs(int);
void dfs(int,int,int*,int*);


int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        dfs(i);
    }
    return 0;
}

void dfs(int n){
    int *arr = new int[n];
    int *flag = new int[n];
    dfs(0,n,arr,flag);
}

void dfs(int step, int len, int* arr, int* flag){
    if(step==len){
        for(int i=0;i<len;i++){
            cout<<arr[i];
        }
        cout<<endl;
        return;
    }
    //核心代码
    for(int i=0;i<len;i++){
        if(flag[i]==0){
            flag[i]=1;
            arr[step]=i+1;
            dfs(step+1,len,arr,flag);
            flag[i]=0;
        }
    }
}
