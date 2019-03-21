#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

/******主程序*******/
int main(){
    int a[] = {5,7,9,0,0,0};
    //PrintArray(a,6);
    int b[] = {3,6,10};
    Merge(a,3,b,3);
    PrintArray(a,6);  //打印数组

    return 0;
}
