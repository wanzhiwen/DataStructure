cmake_minimum_required(VERSION 3.10)
project(DataStructure)

set(CMAKE_CXX_STANDARD 11)

add_executable(DataStructure main.cpp LinearList/SeqList.cpp LinearList/SeqList.h LinearList/LinkedList.cpp LinearList/LinkedList.h LinearList/DuLinkList.cpp LinearList/DuLinkList.h LinearList/LinkStack.cpp LinearList/LinkStack.h LinearList/SeqStack.cpp LinearList/SeqStack.h LinearList/SeqQueue.cpp LinearList/SeqQueue.h Tree/BiTree.cpp Tree/BiTree.h Tree/HuffmanTree.h Tree/HuffmanTree.cpp Tree/ThreadTree.h Tree/ThreadTree.cpp Search/BST.cpp Search/BST.h Search/AVL.cpp Search/AVL.h Sort/Heap_top_k.cpp Sort/Heap_top_k.h Graph/Dijkstra.cpp Graph/Dijkstra.h)