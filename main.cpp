using namespace std;

#include <iostream>
#include "LinearList/LinkedList.h"
#include "LinearList/DuLinkList.h"
#include "LinearList/LinkStack.h"
#include "LinearList/SeqStack.h"


int main() {

    SeqStack s;
    int top,pop;
    SeqStack_Init(s,100,10);
    SeqStack_Push(s, 10);
    SeqStack_GetTop(s, top);
    cout << "top1:" << top << endl;
    SeqStack_Push(s, 20);
    SeqStack_GetTop(s, top);
    cout << "top2:" << top << endl;
    SeqStack_Push(s, 30);
    SeqStack_GetTop(s, top);
    cout << "top3:" << top << endl;
    cout << "len1:" << SeqStack_Length(s) << endl;
    SeqStack_Pop(s,pop);
    cout << "pop1:" << pop << endl;
    cout << "len2::" << SeqStack_Length(s) << endl;
    SeqStack_Pop(s,pop);
    cout << "pop2:" << pop << endl;
    cout << "len3::" << SeqStack_Length(s) << endl;
    cout<<"empty:"<<SeqStack_Empty(s)<<endl;
    SeqStack_Pop(s,pop);
    cout << "pop3:" << pop << endl;
    cout << "len4::" << SeqStack_Length(s) << endl;
    cout<<"empty:"<<SeqStack_Empty(s)<<endl;
    SeqStack_Destroy(s);

    return 0;
}