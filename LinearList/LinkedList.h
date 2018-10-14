//
// Created by aSUSS on 2018/10/5.
//

#ifndef DATASTRUCTURE_LINKEDLIST_H
#define DATASTRUCTURE_LINKEDLIST_H

#include "SeqList.h"

//链表结构定义
typedef struct node {
    int data;
    struct node *next;
} LNode, *LinkList;

//链表初始化
bool List_Init(LinkList &L);

//链表长度
int List_Size(LinkList &L);

//链表节点遍历
void List_Traverse(LinkList &L);

//带头节点链表L第loc个节点插入elem
bool List_Insert(LinkList &L, int loc, int elem);

//带头节点链表L第loc个节点删除
bool List_Delete(LinkList &L, int loc);

//单链表按位置查找算法
bool List_Retrieve(LinkList &L,int loc,int &elem);

//单链表按值查找算法,返回元素所在位置
bool List_Locate(LinkList &L, int elem, int &loc);

//链表销毁
void List_Destroy(LinkList &L);

#endif