#include<stdio.h>
#include"inventory.h"
#include<inventory.c>
#include"npc.h"


int getSize(inventory* inv){//get the size of an inventory
    int size=1;
    while (inv->next != NULL){
        size=size+1;
        inv = inv->next;
    }
    return size;
}

void printInventory(inventory* inv){ // print each item in the inventory 
    int size=0;
    while (inv != 0){
        size=size+1;
        char* itemName=inv->inv->item->name;
        printf("%d-%s \n",size,itemName);
        inv = inv->next;
    }
}

inventory* browseItem(inventory* inv1,int number){ // browse an item with an index in the inventory
    for (int i = 0; i < number-1; i++)
    {
        inv1 = inv1->next;
    }
    return inv1;
}

inventory* newItem(inventory* inv1){
    inventory* newItem=malloc(sizeof(inventory));
    newItem->inv->item=inv1->inv->item;
    newItem->inv->stock=inv1->inv->stock;
    newItem->next=NULL;

    return newItem;
}

void addItem(inventory* itemAdded, inventory* inv1){ // add an item in the inventory
    while (inv1->next != NULL){
        inv1 = inv1->next;
    }
    inv1->next=newItem(itemAdded);
}

void deleteItem(inventory* inv1, int number){ //delete an item with an index in the inventory
    
    inventory* tempInv = malloc(sizeof(inventory));
    tempInv=inv1;

    if (number==1)
    {
       *inv1=*tempInv->next;  
       free(tempInv);
       return;
    }
    

    for (int i = 0; inv1!=NULL && i < number-2; i++)
    {
        tempInv=tempInv->next;
    }

    if (tempInv == NULL || tempInv->next == NULL){
         return;
    }
    inventory* next = malloc(sizeof(inventory));
    next=tempInv->next->next;

    free(tempInv->next);

    tempInv->next=next;

}

void depositItems(inventory* inv1, inventory* inv2){ //deposit items from the player's inventory to the NPC's one

    int size=getSize(inv1);

    if (size>1)
    {
    printInventory(inv1);

    int itemChoice=1;
    printf("Choose the item you want to deposit:");
    scanf("%d",&itemChoice);

    inventory* choosedItem = browseItem(inv1,itemChoice);
    printf("ok");

    addItem(choosedItem,inv2);
    
    deleteItem(inv1,itemChoice);  
    } else {
        printf("Cannot deposit items from your inventory car you have only one\n");
    }
    

    
}

void takeItems(inventory* inv2, inventory* inv1){ //take items from the NPC's inventory to the player's one
    
    printInventory(inv2);

    int itemChoice;
    printf("Choose the item you want to deposit:");
    scanf("%d",&itemChoice);

    inventory* choosedItem = browseItem(inv2,itemChoice);

    int size=getSizeInv(inv1); // get size from the player inventory

    if (size<10) //if size < 10 then we add the choosedItem to the inventory
    {
        addItem(choosedItem,inv1);

        deleteItem(inv2,itemChoice);
    }

}

void craftItems(){

}

int main(int argc, char *argv[]){

    int choice;
    printf("Hello, what do you want to do? \n 1->Deposit Items, 2->Take Items, 3->Craft Items, 4->Nothing : ");
    scanf("%d", &choice);

    Item* item1= malloc(sizeof(Item));
    item1->itemType=3;
    item1->id=1;
    item1->name="Test1";
    item1->zone=1;
    item1->durability=1; 
    item1->craftResources=0;
    item1->toolUsuryByResource=1; 
   
    item1->damage=1; 
    item1->resistance=1; 
    item1->restoredHP=1;

    Item* item2= malloc(sizeof(Item));
    item2->itemType=3;
    item2->id=2;
    item2->name="Test2";
    item2->zone=1;
    item2->durability=1; 
    item2->craftResources=0;
    item2->toolUsuryByResource=1; 

    item2->damage=1; 
    item2->resistance=1; 
    item2->restoredHP=1;

    Item* item3= malloc(sizeof(Item));
    item3->itemType=3;
    item3->id=2;
    item3->name="Test3";
    item3->zone=1;
    item3->durability=1; 
    item3->craftResources=0;
    item3->toolUsuryByResource=1; 

    item3->damage=1; 
    item3->resistance=1; 
    item3->restoredHP=1;

    inventory* invPlayer = malloc(sizeof(inventory));
    inventory* invPlayer2 = malloc(sizeof(inventory));
    inventory* invPlayer3 = malloc(sizeof(inventory));
    invPlayer->inv->item=item1;
    invPlayer->inv->stock=2;
    invPlayer->next=invPlayer2;
    invPlayer2->inv->item=item2;
    invPlayer2->inv->stock=2;
    invPlayer2->next=invPlayer3;
    invPlayer3->inv->item=item3;
    invPlayer3->inv->stock=2;
    invPlayer3->next=NULL;
    
    inventory* invNPC = malloc(sizeof(inventory));
    inventory* invNPC2 = malloc(sizeof(inventory));
    invNPC->inv->item=item2;
    invNPC->inv->stock=3;
    invNPC->next=invNPC2;
    invNPC2->inv->item=item2;
    invNPC2->inv->stock=3;
    invNPC2->next=NULL;

    switch (choice) {
    case 1:
        while (choice==1)
        {
            depositItems(invPlayer,invNPC);
            printf("1:\n");
            printInventory(invPlayer);
            printf("2:\n");
            printInventory(invNPC);
            printf("Hello, what do you want to do? \n 1->Deposit Items, 2->Take Items, 3->Craft Items, 4->Nothing : ");
            scanf("%d", &choice);
        }
    case 2:
        while (choice==2)
        {
            takeItems(invNPC,invPlayer);  
            printf("1:\n");
            printInventory(invPlayer);
            printf("2:\n");
            printInventory(invNPC);
            printf("Hello, what do you want to do? \n 1->Deposit Items, 2->Take Items, 3->Craft Items, 4->Nothing : ");
            scanf("%d", &choice); 
        }
        
        
    case 3:
        craftItems();
    case 4:
        break;
    default:
        break;
    }


}