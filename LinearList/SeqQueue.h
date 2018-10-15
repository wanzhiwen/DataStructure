//
// Created by aSUSS on 2018/10/16.
//
#ifndef DATASTRUCTURE_SEQQUEUE_H
#define DATASTRUCTURE_SEQQUEUE_H

typedef struct{
    int *queue;
    int front;
    int rear;
    int queueSize;
    int increment;
}SeqQueue;

//队列初始化
bool SeqQueue_Init(SeqQueue &Q,int maxSize,int increment);

//求队列长度
int SeqQueue_Length(SeqQueue &Q);

//进队列操作
bool SeqQueue_EnQueue(SeqQueue &Q,int elem);

//出队操作
bool SeqQueue_DeQueue(SeqQueue &Q,int &elem);

//取队首元素
bool SeqQueue_GetHead(SeqQueue &Q, int &elem);

//队是否空
bool SeqQueue_Empty(SeqQueue &Q);

//队列销毁
bool SeqQueue_Destroy(SeqQueue &Q);


#endif
