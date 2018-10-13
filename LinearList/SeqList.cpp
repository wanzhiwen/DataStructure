//
// Created by aSUSS on 2018/10/4.
//

#include "SeqList.h"
#include <iostream>


Status List_Init(ListPtr L) {
    Status status = fatal;
    int maxsize = L->listsize;
    L->elem = (int *) malloc((maxsize) * sizeof(int));//存储空间分配
    if (L->elem) {
        L->length = 0;
        status = success;
        return status;
    }
}

void List_Destroy(ListPtr L) {
    if (L->elem) {
        free(L->elem);
        L->elem = NULL;
    }
    L->length = 0;
}

void List_Clear(ListPtr L) {
    L->length = 0;
}

bool List_Empty(ListPtr L) {
    return L->length == 0;
}

Status List_Prior(ListPtr L, int pos, int *elem) {
    Status status = fail;
    int len = L->length;
    if (pos >= 1 && pos < len - 1) {
        *elem = L->elem[pos - 1];
        status = success;
    }
    return status;
}

Status List_Next(ListPtr L, int pos, int *elem) {
    Status status = fail;
    int len = L->length;
    if (pos >= 0 && pos < len - 2) {
        *elem = L->elem[pos + 1];
        status = success;
    }
    return status;
}

Status List_Retrieve(ListPtr L, int pos, int *elem) {
    Status status = range_error;
    int len = L->length;
    if (1 <= pos && pos <= len) {//检查合法性
        *elem = L->elem[pos];
        status = success;
    }
    return status;
}

Status List_Locate(ListPtr L, int elem, int *pos) {
    Status status = range_error;
    int len = L->length;
    int i = 1;
    while (i <= len && L->elem[i] != elem) {
        i++;
    }
    if (i < len) {
        *pos = i;
        status = success;
    }
    return status;
}

Status List_Insert(ListPtr L, int pos, int elem) {
    Status status = range_error;
    int len = L->length;
    int maxsize = L->listsize;
    if (len >= maxsize) {
        status = fatal;//overflow
        return status;
    } else if (pos >= 0 && pos < len) {
        for (int i = len - 1; i >= pos; i--) {
            L->elem[i + 1] = L->elem[i];
        }
        L->elem[pos] = elem;
        L->length++;
        status = success;
    }
    return status;
}

Status List_Remove(ListPtr L, int pos) {
    Status status = range_error;
    int len = L->length;
    if (pos >= 0 && pos <= len - 1) {
        for (int i = pos; i < len - 1; ++i) {
            L->elem[i] = L->elem[i + 1];
        }
        L->length--;
        status = success;
    }
    return status;
}



