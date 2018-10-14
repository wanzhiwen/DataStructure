//
// Created by aSUSS on 2018/10/14.
//
using namespace std;

#include <iostream>
#include "DuLinkList.h"

bool DuList_Init(DuLinkList &L) {
    L = (DuLinkList) malloc(sizeof(DuNode));
    if (!L) { return false; }
    L->next = NULL;
    L->prior = NULL;
}

bool DuList_Insert(DuLinkList &L, int loc, int elem) {
    DuLinkList p, s, q;
    int count = 0;
    p = L;
    while (p->next && count < loc - 1) {
        p = p->next;
        count++;
    }
    if (count != loc - 1) { return false; }
    s = (DuLinkList) malloc(sizeof(DuNode));
    if (!s) { return false; }
    s->data = elem;
    if (p->next) {
        q = p->next;
        s->prior = p;
        q->prior = s;
        s->next = q;
        p->next = s;
    }else{
        p->next=s;
        s->prior=p;
        s->next=NULL;
    }
    return true;
}

bool DuList_Delete(DuLinkList &L,int loc,int &elem){
    DuLinkList p,q,s;
    int count=0;
    p=L;
    while(p->next && count<loc){
        p=p->next;
        count++;
    }
    if (count!=loc){ return false;}
    if(p->next){
        p->next->prior=p->prior;
        p->prior->next=p->next;
        elem=p->data;
        free(p);
    } else{
        p->prior->next=NULL;
        elem=p->data;
        free(p);
    }
    return true;
}
