//
// Created by aSUSS on 2018/10/15.
//
#include "SeqStack.h"
#include "LinkedList.h"
#include "iostream"

bool SeqStack_Init(SeqStack &S, int maxsize, int increment) {
    S.stack = (int *) malloc(maxsize * sizeof(int));
    if (!S.stack) { return false; }
    S.top = -1;
    S.stackSize = maxsize;
    S.increment = increment;
}

int SeqStack_Length(SeqStack &S) {
    return S.top + 1;
}

bool SeqStack_Push(SeqStack &S, int elem) {
    if (S.top == S.stackSize - 1) {
        S.stack = (int *) realloc(S.stack, (S.stackSize + S.increment) * sizeof(LNode));//满栈操作
        if (!S.stack) { return false; }
        S.stackSize += S.increment;
    }
    S.stack[++S.top] = elem;
    return true;
}

bool SeqStack_Pop(SeqStack &S, int &elem) {
    if (S.top == -1) { return false; }
    elem = S.stack[S.top--];
    return true;
}

bool SeqStack_GetTop(SeqStack &S, int &elem) {
    if (S.top != -1) {
        elem = S.stack[S.top];
        return true;
    } else {
        return false;
    }
}

bool SeqStack_Empty(SeqStack &S) {
    return S.top == -1;
}

void SeqStack_Destroy(SeqStack &S) {
    free(S.stack);
    S.stack = NULL;
    S.stackSize = 0;
    S.top = -1;
}