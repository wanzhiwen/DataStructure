//
// Created by aSUSS on 2018/11/7.
//
#include "AVL.h"

bool insert_AVLTree(AVLTree *avlt, keyType key) {
/*
 * 过程：先插入节点--->更新平衡因子-->判断类型-->调整
*/
    AVLNode *newNode;   //要插入的新节点
    AVLNode *A;         //指向离插入点最近的平衡因子不为0的一个节点
    AVLNode *fa;        //指向离插入点次最近的平衡因子不为0的点
    AVLNode *fp;        //指向插入点的前一个节点
    AVLNode *p;         //移动指针
    AVLNode *B;         //指向A的下一个节点
    AVLNode *C;         //B的右孩子
    newNode = (AVLNode *) malloc(sizeof(AVLNode));
    newNode->key = key;
    newNode->lchild = nullptr;
    newNode->rchild = nullptr;
    newNode->bf = 0;
    if (*avlt == nullptr) {
        *avlt = newNode;
        return true;
    } else {
        p = *avlt;
        A = *avlt;
        fa = nullptr;
        fp = nullptr;

        while (p != nullptr) {
            if (p->bf != 0) {
                A = p;
                fa = fp;
            }
            fp = p;
            if (key < p->key) {
                p = p->lchild;
            } else if (key > p->key) {
                p = p->rchild;
            } else {
                return false;
            }

        }


        if (key > fp->key) {
            fp->rchild = newNode;
        }
        if (key < fp->key) {
            fp->lchild = newNode;
        }

        if (key > A->key) {
            B = A->rchild;
            A->bf = A->bf - 1;
        }
        if (key < A->key) {
            B = A->lchild;
            A->bf = A->bf + 1;
        }
        p = B;
        while (p != newNode) {
            if (key < p->key) {
                p->bf = 1;
                p = p->lchild;
            }
            if (key > p->key) {
                p->bf = -1;
                p = p->rchild;
            }
        }

        if (A->bf == -2 && B->bf == -1) {
            A->rchild = B->lchild;
            B->lchild = A;
            A->bf = 0;
            B->bf = 0;
            if (fa == nullptr) {
                *avlt = B;
            } else if (A == fa->lchild) {
                fa->lchild = B;
            } else {
                fa->rchild = B;
            }
        } else if (A->bf == 2 && B->bf == 1) {
            A->lchild = B->rchild;
            B->rchild = A;
            A->bf = 0;
            B->bf = 0;
            if (fa == nullptr) {
                *avlt = B;
            } else if (A == fa->lchild) {
                fa->lchild = B;
            } else {
                fa->rchild = B;
            }
        } else if (A->bf == 2 && B->bf == -1) {
            C = B->rchild;
            B->rchild = C->lchild;
            A->lchild = C->rchild;
            C->lchild = B;
            C->rchild = A;
            if (key < C->key) {
                A->bf = -1;
                B->bf = 0;
                C->bf = 0;
            } else if (key > C->key) {
                A->bf = 0;
                B->bf = 1;
                C->bf = 0;
            } else {
                A->bf = 0;
                B->bf = 0;
            }
            if (fa == nullptr) {
                *avlt = C;
            } else if (A == fa->lchild) {
                fa->lchild = C;
            } else {
                fa->rchild = C;
            }
        } else if (A->bf == -2 && B->bf == 1) {
            C = B->lchild;
            B->lchild = C->rchild;
            A->rchild = C->lchild;
            C->lchild = A;
            C->rchild = B;
            if (key < C->key) {
                A->bf = 0;
                B->bf = -1;
                C->bf = 0;
            } else if (key > C->key) {
                A->bf = 1;
                B->bf = 0;
                C->bf = 0;
            } else {
                A->bf = 0;
                B->bf = 0;
            }
            if (fa == nullptr) {
                *avlt = C;
            } else if (A == fa->lchild) {
                fa->lchild = C;
            } else {
                fa->rchild = C;
            }
        }
        return true;
    }
}

void CreateAVL(AVLTree *avlt){
    *avlt= nullptr;
    keyType key;
    scanf("%d",&key);
    while (key!=ENDKEY){
        insert_AVLTree(avlt,key);
        scanf("%d",&key);
    }
}

void visit(AVLTree avlTree) {
    printf("%d ", avlTree->key);
}

void AVL_InOrder(AVLTree avlTree) {
    if (avlTree != nullptr) {
        AVL_InOrder(avlTree->lchild);
        visit(avlTree);
        AVL_InOrder(avlTree->rchild);
    }
}



//int main() {
//    AVLTree avlTree;
//    CreateAVL(&avlTree);
//    AVL_InOrder(avlTree);
//}
