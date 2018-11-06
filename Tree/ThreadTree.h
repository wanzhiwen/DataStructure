//
// Created by aSUSS on 2018/11/6.
//

#ifndef DATASTRUCTURE_THREADTREE_H
#define DATASTRUCTURE_THREADTREE_H

typedef char DataType;

typedef struct Node {
    DataType data;
    int Ltag;
    int Rtag;
    struct Node *Lchild;
    struct Node *Rchild;
} BiTNode, *BiTree;

BiTree pre;

//创建二叉树（先序插入）
void CreateBiTree(BiTree *bt);

//将二叉树中序线索化
void InitThread(BiTree root);

//查找某个节点中序遍历的前继节点
BiTNode *InPre(BiTNode *p);

//查找某个节点中序遍历的后继节点
BiTNode *InNext(BiTNode *p);

//返回中序遍历时头节点
BiTNode *TinFirst(BiTree root);

//中序遍历所有节点
void TInOrder(BiTree root);

//在p节点后面插入r
void InsertNode(BiTNode *p, BiTNode *r);

#endif
