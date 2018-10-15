//
// Created by aSUSS on 2018/10/15.
//

#ifndef DATASTRUCTURE_SEQSTACK_H
#define DATASTRUCTURE_SEQSTACK_H
# define STACK_INIT_SIZE 100
# define STACKINCREMENT 10//满栈时增加存储存储空间，每次增加10个单元
typedef struct{
    int *stack;
    int top;
    int stackSize;
    int increment;
}SeqStack;

bool SeqStack_Init(SeqStack &S,int maxsize=STACK_INIT_SIZE,int increment=STACKINCREMENT);

bool SeqStack_Push(SeqStack &S,int elem);

#endif
