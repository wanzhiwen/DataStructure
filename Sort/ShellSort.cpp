//
// Created by aSUSS on 2018/11/23.
//
#include "ShellSort.h"
#include "iostream"

void ShellInsert(KeyType r[], int length, int delta) {
    int i, j;
    for (i = 1 + delta; i <= length; i++)      /* 1+delta为第一个子序列的第二个元素的下标 */
    {//插入排序
        if (r[i] < r[i - delta]) {//数据搬家
            r[0] = r[i];
            for (j = i - delta; j > 0 && r[0] < r[j]; j -= delta) {
                r[j + delta] = r[j];
            }
            r[j + delta] = r[0];
        }
    }
}

void ShellSort(KeyType r[], int length, int delta[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        ShellInsert(r, length, delta[i]);
    }
}

//int main() {
//    KeyType data[11] = {0, 65, 15, 57, 34, 55, 23, 98, 67, 87, 89};//a[0]是一个存临时数据的位置
//    int delta[2] = {1, 3};
//    ShellSort(data, 10, delta, 2);
//    for (int i = 1; i < 10; ++i) {
//        printf("%d ", data[i]);
//    }
//}