//
// Created by aSUSS on 2018/11/7.
//

#ifndef DATASTRUCTURE_AVL_H
#define DATASTRUCTURE_AVL_H

#include "iostream"

using namespace std;

typedef int keyType;
#define ENDKEY 0//创建avlt时作为结束条件

typedef struct node {
    keyType key;
    int bf;//balance factor
    struct node *lchild;
    struct node *rchild;
} AVLNode, *AVLTree;

//往平衡二叉树中插入节点
bool insert_AVLTree(AVLTree *avlt, keyType key);

//创建平衡二叉树
void CreateAVL(AVLTree *avlt);

//访问某个节点
void visit(AVLTree avlTree);

//中序遍历平衡二叉树
void AVL_InOrder(AVLTree avlTree);



#endif
