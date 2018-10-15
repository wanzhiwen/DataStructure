//
// Created by aSUSS on 2018/10/15.
//

#ifndef DATASTRUCTURE_LINKSTACK_H
#define DATASTRUCTURE_LINKSTACK_H

#include "LinkedList.h"

typedef LinkList LinkStack;

//初始化栈
void LinkStack_Init(LinkStack &S);

//获取链栈元素个数
int LinkStack_Length(LinkStack &S);

//链栈中插入元素
bool LinkStack_Push(LinkStack &S, int elem);

//链栈中删除栈顶元素
bool LinkStack_Pop(LinkStack &S, int &elem);

//检查链栈是否为空
bool LinkStack_Empty(LinkStack &S);

//遍历链栈
bool LinkStack_GetTop(LinkStack &S,int &elem);

//链栈销毁
void LinkStack_Destroy(LinkStack &S);

#endif
