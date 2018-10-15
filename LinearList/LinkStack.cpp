//
// Created by aSUSS on 2018/10/15.
//
#include <iostream>
#include "LinkStack.h"
#include "LinkedList.h"

void LinkStack_Init(LinkStack &S) {
    S = NULL;
}

int LinkStack_Length(LinkStack &S) {
    int count = 0;
    LinkStack p = S;
    while (p) {
        count++;
        p = p->next;
    }
    return count;
}

bool LinkStack_Push(LinkStack &S, int elem) {
    LinkStack p;
    p = (LinkStack) malloc(sizeof(LNode));
    if (!p) { return false; }
    p->data = elem;
    p->next = S;
    S = p;
    return true;
}

bool LinkStack_Pop(LinkStack &S, int &elem) {
    LinkStack p;
    if (S) {
        p = S;
        elem = p->data;
        S = S->next;
        free(p);
        return true;
    } else {
        return false;
    }
}

bool LinkStack_Empty(LinkStack &S) {
    if (!S) { return true; }
    else { return false; }
}

bool LinkStack_GetTop(LinkStack &S, int &elem) {
    if (S) {
        elem = S->data;
        return true;
    } else {
        return false;
    }
}

void LinkStack_Destroy(LinkStack &S) {
    LinkStack q, p = S;
    while (p) {
        q = p;
        p = p->next;
        free(q);
    }
    S = NULL;
}