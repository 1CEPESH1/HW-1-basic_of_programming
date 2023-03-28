
#include "Sorts.h"
#ifndef PESTOV_RL6_11_LIST_H
#define PESTOV_RL6_11_LIST_H

struct listnode{
    void (*Sort)(int *, int);
    float time;
    listnode* next;
    listnode(){
        time = 0;
        next = nullptr;
    }
};

listnode* CreateNode(void (*Sort)(int *, int));

struct List{
    listnode* head;
    int length;
    List(void (*Sort)(int *, int)) {
        head = CreateNode(Sort);
        length = 1;
    }
};

void append(List& lst, void(*Sort)(int *, int));
void CreateList(List& lst);
bool StopSorting(List& lst);
#endif //PESTOV_RL6_11_LIST_H