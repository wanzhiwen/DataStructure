//
// Created by aSUSS on 2018/11/23.
//

#ifndef DATASTRUCTURE_SHELLSORT_H
#define DATASTRUCTURE_SHELLSORT_H

typedef int KeyType;

//对记录数组做一趟希尔插入排序，length是数组r长度，delta是增量
void ShellInsert(KeyType r[],int length,int delta);

//对记录数组r做希尔排序，length表示数组r的长度，delta表示增量数组，n表示delta的长度
void ShellSort(KeyType r[],int length,int delta[],int n);


#endif
