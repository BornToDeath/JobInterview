#include <stdio.h>
#include <stdlib.h>

/*****合并两个有序数组
* nums1：升序数组1，其保存合并后的所有元素，即其实际大小应>=(m+n)
* m：nums1中的有效元素个数
* nums2：升序数组2
* n：nums2数组元素个数
*****/
void Merge(int* nums1, int m, int* nums2, int n){
    //解决思路：从后向前比较两个数组中的最后一个元素

    int i = m-1; //指向nums1待比较元素
    int j = n-1; //指向nums2待比较元素
    while(j>=0){
        // 如果nums1为空，直接把nums2的元素复制到nums1
        if(i<0){
            nums1[i+j+1] = nums2[j];
            j--;
            continue;
        }
        //如果nums1尾部元素大于等于nums2尾部元素，将nums1尾部
        //元素放置于排序后其所在的位置，因为两个数组均是有序的
        if(nums1[i]>=nums2[j]){
            nums1[i+j+1] = nums1[i];
            i--;
        }else{  //如果nums1尾部元素小于nums2尾部元素，将nums2中的元素添加到nums1排序后理应在的位置
            nums1[i+j+1] = nums2[j];
            j--;
        }
        //PrintArray(nums1,m+n);
    }

}

/********打印数组元素
* arr：数组
* len：数组长度
********/
void PrintArray(int* arr, int len){
    int i=0;
    for(;i<len;i++){
        printf("%d\t", *(arr+i));
    }
    printf("\n");
}
