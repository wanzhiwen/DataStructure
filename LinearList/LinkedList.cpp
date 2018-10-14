//
// Created by aSUSS on 2018/10/5.
//
using namespace std;

#include <iostream>
#include "LinkedList.h"

bool List_Init(LinkList &L) {
    L = (LinkList) malloc(sizeof(LNode));
    if (!L) { return false; }
    L->next = NULL;
    return true;
}

int List_Size(LinkList &L) {
    LinkList p = L->next;
    int count = 0;
    while (p) {
        p = p->next;
        count++;
    }
    return count;
}

void List_Traverse(LinkList &L) {
    LinkList p = L->next;
    while (p) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
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

bool List_Delete(LinkList &L, int loc) {
    LinkList q, p = L;
    int count = 0;
    while (p->next && count < loc - 1) {
        p = p->next;
        count++;
    }
    if (count != loc - 1) { return false; }
    q = p->next;
    p->next = q->next;
    free(q);
    return true;
}

bool List_Retrieve(LinkList &L, int loc, int &elem) {
    LinkList p = L;
    int count = 0;
    while (p->next && count < loc) {
        p = p->next;
        count++;
    }
    if (count != loc) { return false; }
    elem = p->data;
    return true;
}

bool List_Locate(LinkList &L, int elem, int &loc) {
    int loc1 = 1;
    LinkList p = L->next;
    while (p && p->data != elem) {
        loc1++;
        p = p->next;
    }
    if (!p) { return false; }
    loc = loc1;
    return true;
}

void List_Destroy(LinkList &L){
    LinkList q,p=L;
    while (p){
        q=p;
        p=p->next;
        free(q);
    }
    L=NULL;
}
