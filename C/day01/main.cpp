#include <stdio.h>

//将数组初始化为0 1 2 3 4 5 6 7 8 9
void init(int a[], int n){
    for(int i = 0 ; i<n; i++){
        a[i] = i;
        printf("a[%d]=%d  ",i, a[i]);
    }
    printf("数组初始化完成  \n\n");
}

//用于打印数组
void print(int a[], int n){
    for(int i = 0 ;i<n; i++){
        printf("a[%d]=%d  ", i, a[i]);
    }
    printf(" \n\n");
}


//=======================================算法实现部分========================================

//将数组a[] 从 from到to的位置倒转排列; from : 逆序起始点, to : 逆序终止点
void reverse(int a[], int from, int to){
    for(int i = 0; i<(to-from)/2; i++){
        //定义一个临时变量, 用于交换from 和 to 的值
        int temp; 
        temp = a[from+i];
        a[from+i] = a[to-i];
        a[to-i] = temp;
    }
}

void converse(int a[], int n, int p){
    reverse(a, 0, p-1); //将0-p逆序 
    reverse(a, p, n-1); //将p- n-1 逆序
    reverse(a, 0, n-1); //整体逆序
}

//=======================================算法实现部分========================================


int main(){
    int array[10];
    int n = 10;
    init(array, 10);
    //reverse(array, 0, 9); //测试reverse函数
    //print(array, 10);
    converse(array, 10, 3); //实际调用
    print(array, 10);
}
