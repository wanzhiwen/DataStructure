//
// Created by aSUSS on 2018/10/5.
//
#include <iostream>
#include "LinkedList.h"

bool List_Init(LinkList &L) {
    L = (LinkList) malloc(sizeof(LNode));
    if (!L) { return false; }
    L->next = NULL;
    return true;
}

bool List_Insert(LinkList &L, int loc, int elem) {
    LinkList p = L;
    int count = 0;
    LinkList newNode = (LinkList) malloc(sizeof(LNode));
    if (!newNode) { return false; }
    newNode->data = elem;
    while (p->next && count < loc - 1) {
        p = p->next;
        count++;
    }
    if (count != loc - 1) { return false; }
    newNode->next = p->next;
    p->next = newNode;
    return true;
}
