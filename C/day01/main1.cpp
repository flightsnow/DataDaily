#include<stdio.h>

//将数组初始化为0 1 2 3 4 5 6 7 8 9
void init(int a[], int n){
    for(int i = 0 ; i<n; i++){
        a[i] = i;
        printf("a[%d]=%d  ",i, a[i]);
    }
    printf("数组初始化完成  \n\n");
}

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
    for(int j=0; j<p; j++ ){
        a[n-p+j] = temp[j];
    }
    for(int i= 0; i<10; i++){
        printf("a[%d]=%d ",i,a[i]);
    }
}

//=======================================算法实现部分========================================


int main()
{
    int R[10];
    init(R, 10);
    moveLeft(R, 10, 3);
    return 0;
}