//
// Created by aSUSS on 2018/10/26.
//
#include <cstring>
#include "HuffmanTree.h"

using namespace std;

void Select(HuffmanTree *ht, int n, int *s1, int *s2) {
    int min = 0;
    for (int i = 1; i <= n; ++i) {
        if ((*ht)[i].parent == 0) {
            min = i;
            break;
        }
    }//随机选取一个没有双亲节点的节点
    for (int j = 1; j <= n; ++j) {
        if ((*ht)[j].parent == 0) {
            if ((*ht)[j].weight < (*ht)[min].weight) {
                min = j;
            }
        }
    }//比较没有双亲节点的所有节点中权重最小的节点
    *s1 = min;//选取到的权重最小的节点
    for (int i = 1; i <= n; ++i) {
        if ((*ht)[i].parent == 0 && i != (*s1)) {
            min = i;
            break;
        }
    }//随机选取一个除第一次选取的节点外没有双亲节点的节点
    for (int j = 1; j <= n; ++j) {
        if ((*ht)[j].parent == 0 && j != (*s1)) {
            if ((*ht)[j].weight < (*ht)[min].weight) {
                min = j;
            }
        }
    }//比较除第一次选取的节点外没有双亲节点的所有节点中权重最小的节点
    *s2 = min;
}

void CreateHuffmanTree(HuffmanTree *ht, int *w, int n) {
    int s1, s2, m;
    m = 2 * n - 1;//总节点数
    *ht = (HuffmanTree) malloc((m + 1) * sizeof(HTNode));
    Select(ht, n, &s1, &s2);
    for (int i = 1; i <= n; ++i) {
        (*ht)[i].weight = w[i];
        (*ht)[i].parent = 0;
        (*ht)[i].LChild = 0;
        (*ht)[i].RChild = 0;
    }//叶子节点初始化
    for (int j = n + 1; j <= m; ++j) {
        (*ht)[j].weight = 0;
        (*ht)[j].parent = 0;
        (*ht)[j].LChild = 0;
        (*ht)[j].RChild = 0;
    }//非叶子节点初始化
    for (int k = n + 1; k <= m; ++k) {
        Select(ht, k-1 , &s1, &s2);
        (*ht)[s1].parent = k;
        (*ht)[s2].parent = k;
        (*ht)[k].LChild = s1;
        (*ht)[k].RChild = s2;
        (*ht)[k].weight=(*ht)[s1].weight+(*ht)[s2].weight;
    }
}

void OutputHuffman(HuffmanTree HT, int m) {
    if (m) {
        cout << HT[m].weight <<endl;
        OutputHuffman(HT, HT[m].LChild);
        OutputHuffman(HT, HT[m].RChild);
    }
}

void CreateHuffmanCode(HuffmanTree ht, HuffmanCode *hc, int n) {
    hc = (HuffmanCode *) malloc((n + 1) * sizeof(char *));
    int p, c;
    HuffmanCode temp = (HuffmanCode) malloc(n * sizeof(char));
    temp[n - 1] = '\0';
    for (int i = 1; i <= n; ++i) {
        int start = n - 1;
        for (c = i, p = ht[i].parent; p != 0; c = p, p = ht[p].parent) {
            if (ht[p].LChild == c) {
                temp[--start] = '0';
            }
            if (ht[p].RChild == c) {
                temp[--start] = '1';
            }
        }
        hc[i] = (HuffmanCode) malloc((n - start) * sizeof(char));
        strcpy(hc[i], &temp[start]);
    }
    free(temp);
    for (int j = 1; j <= n; ++j) {
        cout << ht[j].weight << "的编码是：" << hc[j] << endl;
    }
}