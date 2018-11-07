//
// Created by aSUSS on 2018/11/7.
//

#ifndef DATASTRUCTURE_BST_H
#define DATASTRUCTURE_BST_H

#include <iostream>

using namespace std;

#define ENDKEY 0//创建bst时作为结束条件
typedef int keyType;
typedef struct node {
    keyType key;
    struct node *lchild;
    struct node *rchild;
} BSTNode, *BSTree;

//往二叉树中插入节点
bool InsertTree(BSTree *bst, keyType key);

//构建二叉搜索树
void CreateBST(BSTree *bst);

//访问并打印某节点的值
void visit(BSTNode bsn);

//中序遍历二叉树
void InOrder(BSTree bst);

//根据键值查找相应的节点
BSTree SearchBST(BSTree bst, keyType key);

//在二叉排序树t中删去关键字为k的结点
BSTNode * DelBSTNode(BSTree t,keyType k);

#endif
