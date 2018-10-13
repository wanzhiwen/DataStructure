//
// Created by aSUSS on 2018/10/4.
//

#ifndef DATASTRUCTURE_SEQLIST_H
#define DATASTRUCTURE_SEQLIST_H

//操作状态的枚举类型
typedef enum Status {
    success, fail, fatal, range_error
} Status;

//定义顺序表结构
typedef struct Sqlist {
    int *elem;      //存储空间基址
    int length;     //当前长度
    int listsize;   //当前分配的存储容量
} Sqlist, *ListPtr;


//顺序表创建算法
Status List_Init(ListPtr L);

//顺序表销毁算法
void List_Destroy(ListPtr L);

//顺序表清空算法
void List_Clear(ListPtr L);

//顺序表判空算法
bool List_Empty(ListPtr L);

//求顺序表前趋算法
Status List_Prior(ListPtr L, int pos, int *elem);

//求顺序表后继算法
Status List_Next(ListPtr L, int pos, int *elem);

//顺序表按位置查找
Status List_Retrieve(ListPtr L, int pos, int *elem);

//顺序表按值查找
Status List_Locate(ListPtr L, int elem, int *pos);

//顺序表插入算法
Status List_Insert(ListPtr L, int pos, int elem);

//顺序表删除算法
Status List_Remove(ListPtr L, int pos);



#endif
