//
// Created by aSUSS on 2018/10/16.
//
#include "BiTree.h"
#include "iostream"
#include "../LinearList/SeqQueue.h"

using namespace std;

bool BiTree_Init(BiTree &BT, int data) {
    BT = (BiTree) malloc(sizeof(BiTNode));
    if (!BT) { return false; }
    BT->data = data;
    BT->rchild = NULL;
    BT->lchild = NULL;
    return true;
}

void PreOrder(BiTree BT) {
    if (BT) {
        cout << BT->data << " " << endl;
        PreOrder(BT->lchild);
        PreOrder(BT->rchild);
    }
}

void InOrder(BiTree BT) {
    if (BT) {
        InOrder(BT->lchild);
        cout << BT->data << " " << endl;
        InOrder(BT->rchild);
    }
}

void PostOrder(BiTree BT) {
    if (BT) {
        PostOrder(BT->lchild);
        PostOrder(BT->rchild);
        cout << BT->data << " " << endl;
    }
}

int BiTreeDepth(BiTree BT) {
    if (BT) {
        int lDepth = BiTreeDepth(BT->lchild);
        int rDepth = BiTreeDepth(BT->rchild);
        return lDepth > rDepth ? lDepth + 1 : rDepth + 1;
    } else {
        return 0;
    }
}

void LevelOrder(BiTree BT) {
    SeqQueue s;
    int p;
    BiTree bt;
    if (BT) {
        SeqQueue_Init(s, MAXNODES, INCREMENT);
        SeqQueue_EnQueue(s, (int) BT);
        while (!SeqQueue_Empty(s)) {
            SeqQueue_DeQueue(s, p);
            BiTree out = (BiTree) p;
            cout << out->data << endl;
            bt = (BiTree) p;
            if (bt->lchild) {
                SeqQueue_EnQueue(s, (int) (bt->lchild));
            }
            if (bt->rchild) {
                SeqQueue_EnQueue(s, (int) (bt->rchild));
            }
        }
    }
}

void PrintBiTree(BiTree BT, int n) {
    int i;
    if (!BT)return;
    PrintBiTree(BT->rchild, n + 1);
    for (i = 2; i < n; ++i)
        cout << "      ";
    if (n > 1)cout << "  - - -";
    cout << BT->data << endl;
    PrintBiTree(BT->lchild, n + 1);
}

void DestroyBiTree(BiTree &BT) {
    if (BT) {
        DestroyBiTree(BT->lchild);
        DestroyBiTree(BT->rchild);
        free(BT);
        BT = NULL;
    }
}