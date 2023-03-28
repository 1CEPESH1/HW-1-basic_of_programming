#include "List.h"

listnode* CreateNode(void (*Sort)(int *, int)){
    listnode* l = new listnode;
    l->Sort = Sort;
    return l;
}

void append(List& lst, void(*Sort)(int *, int)){
    listnode* l = CreateNode(Sort);
    listnode* p = lst.head;
    if(lst.length == 1)
        lst.head->next = l;
    else{
        for (int i = 0; i < lst.length - 1; ++i) {
            p = p->next;
        }
        p->next = l;
    }
    lst.length++;
}

bool StopSorting(List& lst){
    if(lst.head->time > 20)
        return true;
    return false;
}

void CreateList(List& lst){
    append(lst, quicksort_1);
    append(lst, mergeSort_1);
    append(lst, selection);
    append(lst, insertion);
    append(lst, bubble);
}