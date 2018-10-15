//
// Created by aSUSS on 2018/10/15.
//
#include "SeqStack.h"
#include "LinkedList.h"
#include "iostream"

bool SeqStack_Init(SeqStack &S, int maxsize = STACK_INIT_SIZE, int increment = STACKINCREMENT) {
    S.stack = (int *) malloc(maxsize * sizeof(int));
    if (!S.stack) { return false; }
    S.top = -1;
    S.stackSize = maxsize;
    S.increment = STACKINCREMENT;
}

bool SeqStack_Push(SeqStack &S, int elem) {
    if (S.top == S.stackSize - 1) {
        S.stack=(int *)realloc(S.stack,(S.stackSize+S.increment)* sizeof(LNode));//

    }
}


