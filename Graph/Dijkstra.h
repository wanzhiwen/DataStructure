//
// Created by aSUSS on 2018/11/7.
//

#ifndef DATASTRUCTURE_DIJKSTRA_H
#define DATASTRUCTURE_DIJKSTRA_H

#include <limits.h>
#include "iostream"

using namespace std;

typedef struct node {
    int **matrix;   //存储图的邻接矩阵
    int n;          //顶点数
    int e;          //边数
} Graph;
//source源节点，从0开始 dist源节点到各个节点的最短距离 path各个节点到该节点的前一个节点
void Dijkstra(Graph g, int *dist, int *path, int source);


#endif
