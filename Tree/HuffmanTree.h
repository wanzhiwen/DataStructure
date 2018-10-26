//
// Created by aSUSS on 2018/10/26.
//

#ifndef DATASTRUCTURE_HUFFMANTREE_H
#define DATASTRUCTURE_HUFFMANTREE_H

typedef char* HuffmanCode;

typedef struct {
    unsigned int weight;
    unsigned int parent;
    unsigned int LChild;
    unsigned int RChild;
}HTNode,* HuffmanTree;

void Select(HuffmanTree *ht,int n,int *s1,int *s2);

void CrtHuffmanTree(HuffmanTree *ht,int *w,int n);

void OutputHuffman(HuffmanTree HT,int m);

void CrtHuffmanCode(HuffmanTree *ht,HuffmanCode *hc,int n);

#endif
