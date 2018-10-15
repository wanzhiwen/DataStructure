cmake_minimum_required(VERSION 3.10)
project(DataStructure)

set(CMAKE_CXX_STANDARD 11)

add_executable(DataStructure main.cpp LinearList/SeqList.cpp LinearList/SeqList.h LinearList/LinkedList.cpp LinearList/LinkedList.h LinearList/DuLinkList.cpp LinearList/DuLinkList.h LinearList/LinkStack.cpp LinearList/LinkStack.h LinearList/SeqStack.cpp LinearList/SeqStack.h LinearList/SeqQueue.cpp LinearList/SeqQueue.h)