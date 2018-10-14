//
// Created by aSUSS on 2018/10/14.
//

#ifndef DATASTRUCTURE_DULINKLIST_H
#define DATASTRUCTURE_DULINKLIST_H

typedef struct DuNode{
    int data;
    struct DuNode *prior;
    struct DuNode *next;
}DuNode,*DuLinkList;

//带头节点双向链表初始化
bool DuList_Init(DuLinkList &L);

//带头节点双向链表节点插入
bool DuList_Insert(DuLinkList &L,int loc,int elem);

//带头节点双向链表删除,返回被删除节点的值
bool DuList_Delete(DuLinkList &L,int loc,int &elem);

#endif
