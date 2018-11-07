//
// Created by aSUSS on 2018/11/7.
//

#ifndef DATASTRUCTURE_TOP_K_H
#define DATASTRUCTURE_TOP_K_H

#include "iostream"

//堆用数组进行存储
// 该函数根据输入的节点的对应序号自上而下对堆进行维护
//data[]堆中数据 loc需要调整的节点的位置，从1开始 datalen数据长度
void HeapAdjust(int data[], int loc, int dataLen);

//data[]未初始化的数据 datalen堆大小
void HeapInit(int data[],int dataLen);

#endif
