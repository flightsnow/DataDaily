#include <stdio.h>

/**
有序数组中查找数值为x的元素, 如果找到了, 就把它与它后面一个元素交换位置
如果没有找到, 就把它插入到数组中, 使数组仍然有序
核心: 二分查找
*/


void print(int a[] ,int n){
    for(int i = 0 ; i <n ; i++){
        printf("a[%d]=%d   ", i, a[i]);
    }
    printf("\n");
}


//======================================算法内容=================================


//二分查找, a[]是要查找的数组
//@param n 数组长度
//@param x 要查找的数字
int binarySearch(int a[], int n, int x){
    int low = 0 , high = n-1, mid;
    while(low<=high){
        mid = (low + high)/2;
        //找中间位置, 找到就退出
        if(x == a[mid]){
            return mid; //返回的mid是查找的值在数组中的下标
        }
        if(x < a[mid]){
            high = mid -1; //如果查找的值比中间值小, 就到左半边找
        }else{
            low = mid+1; //如果查找的值比中间值大, 就到右半边找
        }
    }
    return -1;
}



//找到就将其与后继元素相交换, 找不到就将其插入表中, 使元素仍递增有序
//@param n 数组长度
//@param x 要查找的数字
void searchExchangeInsert(int a[], int n, int x){
    int mid = binarySearch(a, n, x);
    //如果找到了mid, 且mid不处于最后一个位置(最后位置就没有后继元素, 没法交换)
    if(mid != -1 && mid != n-1){
        //交换
        int temp = a[mid];
        a[mid] = a[mid+1];
        a[mid+1] = temp;
    }

    //如果没有找到, 则插入x
    if(mid == -1){
        int i;
        for(i = n-1; a[i] > x; i--){  //a[i] > x; 是循环下去要满足的条件 错写成了 a[i] < x
            printf("操作前 i = %d \n", i);
            a[i+1] = a[i];
            printf("操作后 i = %d \n", i);
        }
        a[i+1] = x;  //是a[i+1], 我写成了 a[i]. 如果写在循环里面, 就是a[i], 但是写在了循环外面, i 已经被-1了
    }
}


//===================================算法内容====================================




int main()
{
    int a[11] = {1,3,5,7,9,11,13,15,17,19};
    //这是测试二分查找代码, 在a[]中找到数字9, 此处应该返回9的下标: 4
    int mid  = binarySearch(a, 10, 9);
    printf("mid  = %d \n", mid);

    print(a, 11);
    //这是测试找到后就交换, 找不到就插入的代码
    searchExchangeInsert(a, 10, 10);  //目标结果: 数组中插入元素 10
    // searchExchangeInsert(a, 10, 9);  //目标结果: 9和11的位置互换
    print(a, 11);
    return 0;
}