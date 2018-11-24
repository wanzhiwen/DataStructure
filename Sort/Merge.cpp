//
// Created by aSUSS on 2018/11/24.
//
#include "Merge.h"
#include "iostream"

void Merge(int r1[], int low, int mid, int high, int r2[]) {
    int i, j, k;
    i = low;
    j = mid + 1;
    k = low;
    while (i <= mid && j <= high) {
        if (r1[i] < r1[j]) {
            r2[k] = r1[i];
            i++;
        } else {
            r2[k] = r1[j];
            j++;
        }
        k++;
    }
    while (i <= mid) {
        r2[k] = r1[i];
        i++;
        k++;
    }
    while (j <= high) {
        r2[k] = r1[j];
        k++;
        j++;
    }
}

void MSort(int r1[], int low, int high, int r3[]) {
    int mid;
    int r2[20];
    if (low == high) {
        r3[low] = r1[low];
    } else{
        mid=(low+high)/2;
        MSort(r1,low,mid,r2);
        MSort(r1,mid+1,high,r2);
        Merge(r2,low,mid,high,r3);
    }
}

void MergeSort(int r[], int n) {
    MSort ( r,  1,  n,  r );
}

//int main(){
//    int data[11]={0, 65, 15, 57, 34, 55, 23, 98, 67, 87, 89};
//    MergeSort(data,10);
//    for (int i = 1; i <= 10; ++i) {
//        printf("%d ", data[i]);
//    }
//}
