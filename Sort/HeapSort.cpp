//
// Created by aSUSS on 2018/11/23.
//
#include "HeapSort.h"
#include "iostream"
void sift(int r[], int k, int m) {
    int t, i, j, x;
    bool finished;
    t = r[k];
    x = r[k];
    i = k;
    j = 2 * i;
    finished = false;
    while (j <= m && !finished) {
        if (j < m && r[j] < r[j + 1]) {
            j = j + 1;
        }
        if (x >= r[j]) {
            finished = true;
        } else {
            r[i] = r[j];
            i = j;
            j = 2 * i;
        }
    }
    r[i] = t;
}

void createHeap(int r[], int length) {
    int i;
    for (i = length / 2; i >= 1; --i)         /* 自第[n/2]个记录开始进行筛选建堆 */
    {
        sift(r, i, length);
    }
}

void HeapSort(int r[],int length){
    int b;
    for (int i = length; i >=2 ; --i) {
        b=r[1];
        r[1]=r[i];
        r[i]=b;
        sift(r,1,i-1);
    }
}
int main(){
    int data[11]={0, 65, 15, 57, 34, 55, 23, 98, 67, 87, 89};
    createHeap(data,10);
    HeapSort(data,10);
    for (int i = 1; i <= 10; ++i) {
        printf("%d ", data[i]);
    }
}
