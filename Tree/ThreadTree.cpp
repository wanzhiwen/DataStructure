//
// Created by aSUSS on 2018/11/6.
//
#include <cstdio>
#include "ThreadTree.h"
#include "iostream"

void CreateBiTree(BiTree *bt) {

    char ch;
    ch = getchar();
    if (ch == '.') {
        *bt = NULL;
    } else {
        *bt = (BiTree) malloc(sizeof(BiTNode)); //生成一个新结点
        (*bt)->data = ch;
        (*bt)->Ltag = 0;
        (*bt)->Rtag = 0;
        CreateBiTree(&((*bt)->Lchild)); //生成左子树
        CreateBiTree(&((*bt)->Rchild)); //生成右子树
    }
}

void InitThread(BiTree root) {
    if (root != NULL) {
        InitThread(root->Lchild);
        if (root->Lchild == NULL) {
            root->Ltag = 1;
            root->Lchild = pre;
        }
        if (pre != NULL && pre->Rchild == NULL) {
            pre->Rtag = 1;
            pre->Rchild = root;
        }
        pre = root;
        InitThread(root->Rchild);
    }
}

BiTNode *InPre(BiTNode *p) {
    BiTNode *q;
    if (p->Ltag == 1) {
        pre = p->Lchild;
    } else {
        for (q = p->Lchild; q->Rtag == 0; q = q->Rchild);
        pre = q;
    }
    return pre;
}

BiTNode *InNext(BiTNode *p) {
    BiTNode *Next;
    BiTNode *q;
    if (p->Rtag == 1) {
        Next = p->Rchild;
    } else {
        if (p->Rchild != NULL) {
            for (q = p->Rchild; q->Ltag == 0; q = q->Lchild);
            Next = q;
        } else {
            Next = NULL;
        }
    }
    return Next;
}

BiTNode *TinFirst(BiTree root) {
    BiTNode *p;
    p = root;
    if (p) {
        while (p->Lchild != NULL) {
            p = p->Lchild;
        }
    }
    return p;
}

void TInOrder(BiTree root) {
    BiTNode *p;
    p = TinFirst(root);
    while (p != NULL) {
        printf("%c  ", p->data);
        p = InNext(p);
    }
}

void InsertNode(BiTNode *p, BiTNode *r) {
    BiTNode *s;
    if (p->Rtag == 1)    /* p无右孩子 */
    {
        r->Rchild = p->Rchild;  /* p的后继变为r的后继 */
        r->Rtag = 1;
        p->Rchild = r;  /* r成为p的右孩子 */
        r->Lchild = p;  /* p变为r的前驱 */
        r->Ltag = 1;
    } else              /* p有右孩子 */
    {
        s = p->Rchild;
        while (s->Ltag == 0)
            s = s->Lchild;  /* 查找p结点的右子树的"最左下端"结点 */
        r->Rchild = p->Rchild;  /* p的右孩子变为r的右孩子 */
        r->Rtag = 0;
        r->Lchild = p;  /* p变为r的前驱 */
        r->Ltag = 1;
        p->Rchild = r;  /* r变为p的右孩子 */
        s->Lchild = r;  /* r变为p原来右子树的"最左下端"结点的前驱 */
    }
}

//int main() {
//    //abd..e..cf..g..
//    BiTree bt;
//    CreateBiTree(&bt);
//    InitThread(bt);
//    TInOrder(bt);
//    BiTNode *btNew = (BiTree) malloc(sizeof(BiTNode));
//    btNew->data='x';
//    InsertNode(bt, btNew);
//    printf("\n");
//    TInOrder(bt);
//    BiTNode * btPre=InPre(bt);
//    printf("\n%c",btPre->data);
//
//}


