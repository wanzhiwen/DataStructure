//
// Created by aSUSS on 2018/11/24.
//

#ifndef DATASTRUCTURE_HASHSEARCH_H
#define DATASTRUCTURE_HASHSEARCH_H
#define  m   13
#define  NULLKEY  0
typedef int HashTable[m];

//哈希函数
int hash(int k);

//哈希搜索
int HashSearch(HashTable ht, int K);

#endif
