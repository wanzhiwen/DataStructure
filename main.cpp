using namespace std;

#include <iostream>
#include "LinearList/LinkedList.h"
#include "LinearList/DuLinkList.h"
#include "LinearList/LinkStack.h"
#include "LinearList/SeqStack.h"
#include "LinearList/SeqQueue.h"


int main() {
    bool b;
    SeqQueue s;
    SeqQueue_Init(s, 3, 2);
    b = SeqQueue_EnQueue(s, 1);
    cout << b << endl;
    b = SeqQueue_EnQueue(s, 2);
    cout << b << endl;
    b = SeqQueue_EnQueue(s, 3);
    cout << b << endl;
    cout << "len:" << sizeof(s.queue) / sizeof(int) << endl;
    cout << s.queue[1] << s.queue[2] << s.queue[3] << endl;

    return 0;
}