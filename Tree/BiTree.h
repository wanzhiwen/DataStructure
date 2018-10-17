//
// Created by aSUSS on 2018/10/16.
//
#ifndef DATASTRUCTURE_BITREE_H
#define DATASTRUCTURE_BITREE_H
#define MAXNODES 100
#define INCREMENT 10
typedef struct BiTNode{
    int data;
    struct BiTNode *lchild;
    struct BiTNode *rchild;
}BiTNode,*BiTree;

//二叉树初始化
bool BiTree_Init(BiTree &BT, int data);

//先序遍历二叉树
void PreOrder(BiTree BT);

//中序遍历二叉树
void InOrder(BiTree BT);

//后序遍历二叉树
void PostOrder(BiTree BT);

//层次遍历二叉树
void LevelOrder(BiTree BT);

//求二叉树深度
int BiTreeDepth(BiTree BT);

#endif
