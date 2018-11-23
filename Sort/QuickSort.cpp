//
// Created by aSUSS on 2018/11/23.
//

#include "QuickSort.h"
#include "iostream"
int QKPass(KeyType r[], int left, int right){
    KeyType x;
    int high;
    int low;
    x=r[left];
    low=left;
    high=right;
    while (low<high){
        while (low<high && r[high]>x){
            high--;
        }
        if(low<high){
            r[low]=r[high];
            low++;
        }
        while (low<high && r[low]<x){
            low++;
        }
        if(low<high){
            r[high]=r[low];
            high--;
        }
    }
    r[low]=x;
    return low;
}

void QKSort(KeyType r[], int low, int high){
    int pos;
    if(low<high){
        pos=QKPass(r,low,high);
        QKSort(r,low,pos-1);
        QKSort(r,pos+1,high);
    }
}

int main(){
    KeyType data[11]={0, 65, 15, 57, 34, 55, 23, 98, 67, 87, 89};
    QKSort(data,1,10);
    for (int i = 1; i < 10; ++i) {
        printf("%d ", data[i]);
    }
}