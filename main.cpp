using namespace std;

#include <iostream>
#include "LinearList/LinkedList.h"
#include "LinearList/DuLinkList.h"


int main() {

    DuLinkList l;
    DuList_Init(l);
    DuList_Insert(l,1,1);
    DuList_Insert(l,1,2);
    DuList_Insert(l,1,3);
    cout<<l->next->data<<l->next->next->data<<l->next->next->next->data<<endl;
    int elem;
    bool b=DuList_Delete(l,4,elem);
    cout<<b<<endl;
    cout<<l->next->data<<l->next->next->data<<endl;
    return 0;
}