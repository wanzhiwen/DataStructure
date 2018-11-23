//
// Created by aSUSS on 2018/11/23.
//

#ifndef DATASTRUCTURE_QUICKSORT_H
#define DATASTRUCTURE_QUICKSORT_H

typedef int KeyType;

// 对记录数组r 中的r[left]至r[right]部分进行一趟排序，并得到基准的位置，使得排序后的结果满足其之后（前）的记录的关键字均不小于（大于）于基准记录*/
int QKPass(KeyType r[], int left, int right);

//对记录数组r[low..high]用快速排序算法进行排序
void QKSort(KeyType r[], int low, int high);

#endif
