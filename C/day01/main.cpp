#include <stdio.h>

/*
将数列循环左移p个位置. 如: 1,2,3,4,5,6,7 循环左移3个位置为: 4,5,6,7,  1,2,3
核心: 数组逆序, 离散数学中的取逆
AB 转成 BA
*/

//用于打印数组
void print(int a[], int n){
    for(int i = 0 ;i<n; i++){
        printf("a[%d]=%d  ", i, a[i]);
    }
    printf(" \n\n");
}


//=======================================算法实现部分========================================

//将数组a[] 从 from到to的位置倒转排列; 
//@param from 逆序起始点
//@param to 逆序终止点
//数组逆序的思想: 以中间元素为中点, 两头一一交换,交换完了数组就逆序了
void reverse(int a[], int from, int to){
    //此处注意(to-from+1),如果不+1的话, 偶数个元素时逆序就会少交换一个. 
    //因为 /2 其实会把余数去掉的, 所以如果想完全遍历, 就要多+1, 宁多不少.
    for(int i = 0; i<(to-from+1)/2; i++){
        int temp;                          //定义一个临时变量, 用于交换from 和 to 的值
        temp = a[from+i];
        a[from+i] = a[to-i];
        a[to-i] = temp;
    }
}
//AB 转换成 BA
void converse(int a[], int n, int p){
    reverse(a, 0, p-1); //将0-p逆序 
    reverse(a, p, n-1); //将p至(n-1) 逆序
    reverse(a, 0, n-1); //整体逆序
}

//=======================================算法实现部分========================================


int main(){
    int b[6] = {0,1,2,3,4,5};
    reverse(b, 0, 5); //测试reverse函数
    print(b,6);

    int a[10] = {0,1,2,3,4,5,6,7,8,9};
    converse(a, 10, 3); //将a[]循环左移3个位置
    print(a, 10);
}






