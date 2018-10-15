//
// Created by aSUSS on 2018/10/15.
//

#ifndef DATASTRUCTURE_SEQSTACK_H
#define DATASTRUCTURE_SEQSTACK_H
# define STACK_INIT_SIZE 100
# define STACKINCREMENT 10//满栈时增加存储存储空间，每次增加10个单元
typedef struct {
    int *stack;
    int top;
    int stackSize;
    int increment;
} SeqStack;

//顺序栈初始化
bool SeqStack_Init(SeqStack &S, int maxsize, int increment);

//顺序栈长度
int SeqStack_Length(SeqStack &S);

//顺序栈push操作
bool SeqStack_Push(SeqStack &S, int elem);

//顺序栈pop操作
bool SeqStack_Pop(SeqStack &S, int &elem);

//顺序栈获取栈顶元素
bool SeqStack_GetTop(SeqStack &S, int &elem);

//顺序表是否为空
bool SeqStack_Empty(SeqStack &S);

//顺序表的销毁
void SeqStack_Destroy(SeqStack &S);

#endif
