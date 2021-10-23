struct linkedlist{
    int data;
    struct linkedlist* next;
};

typedef struct linkedlist linkedlist;


int* linkedListToTable(linkedlist* ll){
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
