using namespace std;

#include <iostream>
#include "LinearList/LinkedList.h"


int main() {

    LinkList l;
    List_Init(l);
    List_Insert(l, 1,2);
    List_Insert(l, 1,3);
    cout<<l->next->next->data<<endl;
    return 0;
}