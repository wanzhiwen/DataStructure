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

//带头节点链表L第loc个节点插入elem
bool List_Insert(LinkList &L,int loc,int elem);






#endif