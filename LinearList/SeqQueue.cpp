//
// Created by aSUSS on 2018/10/16.
//
#include "SeqQueue.h"
#include "iostream"

bool SeqQueue_Init(SeqQueue &Q, int maxSize, int increment) {
    Q.queue = (int *) malloc(maxSize * sizeof(int));
    if (!Q.queue) { return false; }
    Q.front = Q.rear = 0;//循环队列初值
    Q.queueSize = maxSize;
    Q.increment = increment;
}

bool SeqQueue_EnQueue(SeqQueue &Q, int elem) {
    if ((Q.rear + 1) % Q.queueSize == Q.front) {
        Q.queue = (int *) realloc(Q.queue, (Q.queueSize + Q.increment) * sizeof(int));
        if (Q.queue) { return false; }
        if (Q.front>Q.rear){
            for (int i = Q.queueSize; i>Q.front ; i--) {
                Q.queue[i+Q.increment]=Q.queue[i];
            }
            Q.front=Q.front+Q.increment;
        }
        Q.queueSize+=Q.increment;
    }
    Q.rear=(Q.rear+1)%Q.queueSize;
    Q.queue[Q.rear]=elem;
    return true;
}