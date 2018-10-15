using namespace std;

#include <iostream>
#include "LinearList/LinkedList.h"
#include "LinearList/DuLinkList.h"
#include "LinearList/LinkStack.h"


int main() {

    LinkStack s;
    LinkStack_Init(s);
    int len = LinkStack_Length(s);
    cout << len << endl;
    LinkStack_Push(s, 1);
    len = LinkStack_Length(s);
    cout << len << endl;
    LinkStack_Push(s, 19);
    len = LinkStack_Length(s);
    cout << len << endl;
    int top;
    LinkStack_GetTop(s, top);
    cout << top << endl;
    bool b = LinkStack_Empty(s);
    cout << "empty:" << b << endl;
    int pop;
    LinkStack_Pop(s, pop);
    cout << "pop:" << pop << endl;
    LinkStack_GetTop(s, top);
    cout << "top:" << top << endl;
    LinkStack_Pop(s, pop);
    b = LinkStack_Empty(s);
    cout << "empty:" << b << endl;
    LinkStack_Destroy(s);

    return 0;
}