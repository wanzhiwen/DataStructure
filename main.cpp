using namespace std;

#include <iostream>
#include "LinearList/LinkedList.h"
#include "LinearList/DuLinkList.h"
#include "LinearList/LinkStack.h"
#include "LinearList/SeqStack.h"
#include "LinearList/SeqQueue.h"
#include "Tree/BiTree.h"
#include "Tree/HuffmanTree.h"


int main() {

//    BiTree bt1, bt2, bt3, bt4, bt5, bt6, bt7;
//    BiTree_Init(bt1, 1);
//    BiTree_Init(bt2, 2);
//    BiTree_Init(bt3, 3);
//    BiTree_Init(bt4, 4);
//    BiTree_Init(bt5, 5);
//    BiTree_Init(bt6, 6);
//    BiTree_Init(bt7, 7);
//    bt1->lchild = bt2;
//    bt1->rchild = bt3;
//    bt2->lchild = bt4;
//    bt2->rchild = bt5;
//    bt3->lchild = bt6;
//    bt3->rchild = bt7;
//    PrintBiTree(bt1,2);


    HuffmanTree huffmanTree;
    HuffmanCode hc;
    int w[10]={0,1,2,3,4,5,6,7,8,9};
    CreateHuffmanTree(&huffmanTree, w, 9);
    OutputHuffman(huffmanTree,17);//m=2n-1
    CreateHuffmanCode(huffmanTree,&hc,9);

    return 0;
}