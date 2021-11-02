#include <stdlib.h>
#include <stdio.h>
#include "llToTable_tableToLl.h"

linkedlist* newElement(int el){ //function that creates a new element in a linked list
    linkedlist* ll = malloc(sizeof(linkedlist));
    ll->data = el;
    ll->next = NULL;
    return ll;
}

int* linkedListToTable(linkedlist* ll){ //function that transforms a linkedlist into a table
    linkedlist* head = ll;
    int size = 0;
    while(ll!=NULL){
        size+=1;
        ll = ll->next;
    }
    int* table = malloc(sizeof(int)*size);
    for(int i = 0; i<size;i+=1){
        table[i]=head->data;
        head = head->next;
    }
    return table;
}

void printTable(int* table, int size){ //function that prints a table
    for(int i=0; i<size;i+=1){
        printf("%d ", table[i]);
    }
    printf("\n");
}

linkedlist* tableToLinkedlist(int* table, int size){
    linkedlist* ll = newElement(*table);
    linkedlist* head = ll;
    for(int i = 1; i<size;i+=1){
        ll->next = newElement(*(table+i));
        ll = ll->next;
    }
    return head;
}



void printLinkedlist(linkedlist* ll){
    while(ll!=NULL){
        printf("%d ", ll->data);
        ll = ll->next;
    }
    printf("\n");
}

void freeLl(linkedlist* ll){
    linkedlist* saved;
    while(ll!=NULL){
        printf("ici %d \n", ll->data);
        saved = ll->next;
        free(ll);
        ll = saved;
    }

}