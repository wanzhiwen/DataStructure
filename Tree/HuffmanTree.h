//
// Created by aSUSS on 2018/10/26.
//

#ifndef DATASTRUCTURE_HUFFMANTREE_H
#define DATASTRUCTURE_HUFFMANTREE_H

#include <iostream>

typedef char *HuffmanCode;

typedef struct {
    int weight;
    int parent;
    int LChild;
    int RChild;
} HTNode, *HuffmanTree;

//选择两个权值最小的节点
void Select(HuffmanTree ht, int n, int *s1, int *s2);

//构建哈夫曼二叉树，注意w的的长度要比n大一
void CreateHuffmanTree(HuffmanTree *ht, int *w, int n);

//先序输出构建出来的哈夫曼二叉树
void OutputHuffman(HuffmanTree HT, int m);

//构建哈夫曼编码
void CreateHuffmanCode(HuffmanTree ht, HuffmanCode *hc, int n);

#endif
