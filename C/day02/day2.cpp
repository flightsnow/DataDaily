#include <stdio.h>

/**
求两个有序数列的中位数
核心思想: 归并排序
*/


//========================================算法实现部分======================================
//通过归并排序的方式来找到中位数
//数组a , b 的长度分别是为 m, n
void getMidBySort(int a[], int b[], int m , int n){
    //p, q分别是指向a, b的第一个元素, 并逐渐向前移动
    int p = 0, q = 0 ;
    int R[m+n];
    for(int i = 0; i<(m+n)/2; i++){
        if(a[p]<b[q]){
            R[i] = a[p];
            p++;
        }else{
            R[i] = b[q];
            q++;
        }
        printf("%d ", R[i]);
    }
    printf("\n");
}


//使用归并排序的思想, 但是并不排序.
//同上一个方法相比, 省去了用于排序的空间复杂度o(n), 空间复杂度为o(1)
//一层从0到(m+n)/2的循环, 时间复杂度为o(n)
int getMid(int a[], int b[], int m , int n){
    int p = 0 , q = 0 ;
    int result; //用于存储最后的中位数
    for(int i = 0 ; i < (m+n)/2; i++){
        if(a[p] < b[q]){
            result = a[p];
            p++;
        }else{
            result = b[q];
            q++;
        }
    }
    printf("mid num is = %d \n", result);
    return result;
}


//========================================算法实现部分======================================


int main()
{
    int a[5] = {1,3,5,7,9};
    int b[15] = {2,4,6,8,10,11,12,13,14,15,16,17,18,19,20};
    getMidBySort(a, b, 5, 15);
    getMid(a, b, 5, 15);
    return 0;
}
