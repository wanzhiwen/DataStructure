//
// Created by aSUSS on 2018/11/7.
//

#include "BST.h"

bool InsertTree(BSTree *bst, keyType key) {
    if ((*bst) == nullptr) {
        *bst = (BSTree) malloc(sizeof(BSTNode));
        (*bst)->key = key;
        (*bst)->lchild = nullptr;
        (*bst)->rchild = nullptr;
    } else {
        if (key < (*bst)->key) {
            InsertTree(&(*bst)->lchild, key);
        }
        if (key > (*bst)->key) {
            InsertTree(&(*bst)->rchild, key);
        }
        if (key == (*bst)->key) {
            return false;//插入二叉排序树已经有的数据
        }
    }
    return true;
}

void CreateBST(BSTree *bst) {
    keyType key;
    *bst = nullptr;
    scanf("%d", &key);
    while (key != ENDKEY) {
        InsertTree(bst, key);
        scanf("%d", &key);
    }

}

void visit(BSTNode bsn) {
    printf("%d ", bsn.key);
}

void InOrder(BSTree bst) {
    if (bst != nullptr) {
        InOrder(bst->lchild);
        visit(*bst);
        InOrder(bst->rchild);
    }
}

BSTree SearchBST(BSTree bst, keyType key) {
    if (bst != nullptr) {
        if (bst->key > key) {
            return SearchBST(bst->lchild, key);
        }
        if (bst->key < key) {
            return SearchBST(bst->rchild, key);
        }
        if (bst->key == key) {
            return bst;
        }
    } else {
        return nullptr;
    }
}

BSTNode *DelBSTNode(BSTree t, keyType k) {
    BSTNode *p;
    BSTNode *f;
    BSTNode *s;
    BSTNode *q;
    p = t;
    f = nullptr;
    while (p) {
        if (p->key == k) break;
        f = p;
        if (p->key > k) {
            p = p->lchild;
        } else {
            p = p->rchild;
        }
    }
    if (p == nullptr) {
        return t;//找不到返回原来的二叉排序树
    }
    if (p->lchild == nullptr) {
        if (f == nullptr) {
            t = p->rchild;
        } else {
            if (f->lchild == p)  /*p是f的左孩子*/
            {
                f->lchild = p->rchild;  /*将p的右子树链到f的左链上*/
            } else  /*p是f的右孩子*/
            {
                f->rchild = p->rchild;  /*将p的右子树链到f的右链上*/
            }
        }
        free(p);
    } else {
        q = p;
        s = p->lchild;
        while (s->rchild)  /*在p的左子树中查找最右下结点*/
        {
            q = s;
            s = s->rchild;
        }
        if (q == p) {
            q->lchild = s->lchild;  /*将s的左子树链到q上*/
        } else {
            q->rchild = s->lchild;
        }
        p->key = s->key;  /*将s的值赋给p*/
        free(s);
    }
    return t;
}

//int main(int argc, char *argv[]) {
//    BSTree bsTree;
//    CreateBST(&bsTree);
//    InOrder(bsTree);
//    DelBSTNode(bsTree,32);
//    InOrder(bsTree);
//}