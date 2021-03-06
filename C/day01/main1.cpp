#include<stdio.h>

/*
将数列循环左移p个位置. 如: 1,2,3,4,5,6,7 循环左移3个位置为: 4,5,6,7,  1,2,3
相比于上一个算法, 这个更容易想到.
保存前p个元素, 然后将剩下的元素逐个向前移动, 最后再把保存的元素加入最后即可
*/

void print(int a[],int n){
    for(int i = 0 ; i<n; i++){
        printf("a[%d]=%d ",i,a[i]);
    }
    printf("\n");
}


//=======================================算法实现部分========================================

//将数组a的序列循环左移p个位置, n为数组长度
void moveLeft(int a[], int n, int p){
    int temp[p];
    for(int i = 0; i<p; i++){
        temp[i] = a[i]; //将前p个元素拷到数组tmep中
    }
    //将数组a左移p个位置
    for(int i = 0 ; i<n-p; i++){  ///这里错将i<n-p 写成了 i<p
        a[i] = a[i+p];
    }
    //将temp数组放回到a中
    for(int i=0; i<p; i++ ){
        a[n-p+i] = temp[i];   //注意这里的逻辑
    }
}

//=======================================算法实现部分========================================


int main()
{
    int a[10] = {0,1,2,3,4,5,6,7,8,9};
    moveLeft(a, 10, 3);
    print(a, 10);
    return 0;
}