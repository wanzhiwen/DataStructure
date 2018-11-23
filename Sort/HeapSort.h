//
// Created by aSUSS on 2018/11/23.
//

#ifndef DATASTRUCTURE_HEAPSORT_H
#define DATASTRUCTURE_HEAPSORT_H

//对r[k-m]进行堆调整
void sift(int r[],int k,int m);

//堆的创建
void createHeap(int r[],int length);

//堆排序
void HeapSort(int r[],int length);
#endif
