#ifndef llToTable_tableToLl.h
#define llToTable_tableToLl.h

#include <stdlib.h>
#include <stdio.h>

typedef struct linkedlist{
    int data;
    struct linkedlist* next;
} linkedlist;

int* linkedListToTable(linkedlist*);
linkedlist* tableToLinkedlist(int*,int);

linkedlist* newElement(int);

void printTable(int*,int);
void printLinkedlist(linkedlist*);

void freeLl(linkedlist*);


#endif

