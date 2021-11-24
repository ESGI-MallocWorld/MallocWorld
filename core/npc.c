#include<stdio.h>
#include<inventory.h>
#include<inventory.c>
#include<npc.h>


void printInventory(inventory* inv){ // print each item in the inventory 
    int size=0;
    while (inv != 0){
        size=size+1;
        char* itemName=inv->inv->item->name;
        printf("%d-%s \n",size,itemName);
        inv = inv->next;
    }
}

Item browseItem(inventory* inv1,int number){ // browse an item with an index in the inventory
    for (int i = 0; i < number-1; i++)
    {
        inv1 = inv1->next;
    }
    return inv1->inv->item;
}

void addItem(Item item, inventory* inv1){ // add an item in the inventory
    while (inv1 != 0){
        inv1 = inv1->next;
    }
    inv1->inv->item = item;
    inv1->inv->stock = 1;
    inv1->next = NULL;
}

void deleteItem(inventory* inv1, int number){ //delete an item with an index in the inventory
    if (number==1) //delete first item in linked list
    {
        
    } else {
        inventory* tempInv = malloc(sizeof(inventory));

        for (int i = 0; i < number-2; i++)
        {
            inv1=inv1->next
        }

        tmpInv=inv1->next;

        if(tmpInv->next==NULL){
            inv1->next=NULL;
        } else {
            inv1->next=tmpInv->next;
        }
        
    }

}

void depositItems(inventory* inv1, inventory* inv2){ //deposit items from the player's inventory to the NPC's one

    printInventory(inv1);

    int itemChoice;
    printf("Choose the item you want to deposit:");
    scanf("%d",&itemChoice);

    Item choosedItem = browseItem(inv1,itemChoice);

    addItem(choosedItem,inv2);

    deleteItem(inv1,itemChoice);

}

void takeItems(inventory* inv2, inventory* inv1){ //take items from the NPC's inventory to the player's one
    
    printInventory(inv2);

    int itemChoice;
    printf("Choose the item you want to deposit:");
    scanf("%d",&itemChoice);

    Item choosedItem = browseItem(inv2,itemChoice);

    int size=getSizeInv(inv1); // get size from the player inventory

    if (size<10) //if size < 10 then we add the choosedItem to the inventory
    {
        addItem(choosedItem,inv1);

        deleteItem(inv2,itemChoice);
    }

}

void craftItems(){

}

void main(int argc, char *argv[]){

    int choice;
    printf("Hello, what do you want to do? \n 1->Deposit Items, 2->Take Items, 3->Craft Items, 4->Nothing : ");
    scanf("%d", &choice);

    inventory* invPlayer = malloc(sizeof(inventory));
    inventory* invNPC = malloc(sizeof(inventory));
    

    switch (choice) {
    case 1:
        depositItems(invPlayer,invNPC);
    case 2:
        takeItems(invNPC,invPlayer);
    case 3:
        craftItems();
    case 4:
        break;
    default:
        break;
    }
}
