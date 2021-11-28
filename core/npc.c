#include<stdio.h>
#include<stdlib.h>
#include"inventory.h"

int getSize(inventory* inv1){//get the size of an inventory
    int size=1;
    while (inv1->next != NULL){
        size=size+1;
        inv1 = inv1->next;
    }
    return size;
}

void printInventory(inventory* inv1){ // print each item in the inventory 
    int size=0;
    while (inv1 != 0){
        size=size+1;
        char* itemName=inv1->inv->item->name;
        printf("%d-%s \n",size,itemName);
        inv1 = inv1->next;
    }
}

inventory* browseItem(inventory* inv1,int number){ // browse an item with an index in the inventory
    for (int i = 0; i < number-1; i++)
    {
        inv1 = inv1->next;
    }
    return inv1;
}

inventory* newItem(inventory* inv1){ // create a new inventory entry
    inventory* newItem=malloc(sizeof(inventory));
    invInfo* invInfo=malloc(sizeof(invInfo));
    invInfo->item=inv1->inv->item;
    invInfo->stock=inv1->inv->stock;
    newItem->inv=invInfo;
    newItem->next=NULL;

    return newItem;
}

void addItem(inventory* itemAdded, inventory* inv1){ // add an item in the inventory
    while (inv1->next != NULL){
        inv1 = inv1->next;
    }
    if (inv1->inv->item!=NULL)
    {
        inv1->next=newItem(itemAdded);
    } else {
        *inv1=*newItem(itemAdded);
    }
    
    
}

void deleteItem(inventory* inv1, int number){ //delete an item with an index in the inventory
    
    inventory* tempInv = malloc(sizeof(inventory));
    tempInv=inv1;

    if (number==1)
    {
       *inv1=*tempInv->next;  
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
    

    addItem(choosedItem,inv2);
    
    deleteItem(inv1,itemChoice); 
    printf("You deposited %d %s in the NPC's inventory\n",choosedItem->inv->stock,choosedItem->inv->item->name); 
    } else {
        printf("Cannot deposit items from your inventory car you have only one\n");
    }
    

    
}

void takeItems(inventory* inv2, inventory* inv1){ //take items from the NPC's inventory to the player's one
    
    if (inv2->inv->item!=NULL)
    {
        printInventory(inv2);

        int itemChoice;
        printf("Choose the item you want to take:");
        scanf("%d",&itemChoice);

        inventory* choosedItem = browseItem(inv2,itemChoice);

        int size=getSize(inv1); // get size from the player inventory

        if (size<10) //if size < 10 then we add the choosedItem to the inventory
        {
        /* Item* newItem=malloc(sizeof(Item));
            newItem=initItem(choosedItem->inv->item->id);
            choosedItem->inv->item=newItem;*/
            
            addItem(choosedItem,inv1);

            deleteItem(inv2,itemChoice);

            printf("You took %d %s in the NPC's inventory\n",choosedItem->inv->stock,choosedItem->inv->item->name); 

        }

    } else {
        printf("There is no items in the NPC's inventory\n");
    }
    
    
}

void verifyNotTypeResource(int val){ //verify if item are ressources and print if not to choose the one to craft

Item* newItem=malloc(sizeof(Item));
newItem=initItem(val);

    if (newItem->itemType!=1 && val!=34)
    {
        printf("%d-%s, ",newItem->id,newItem->name);
    }
    if (newItem->itemType!=1 && val==34)
    {
        printf("%d-%s \n",newItem->id,newItem->name);
    }
    
}

inventory* deleteNode(inventory* inv1){ //move from one node to the next one if not null

    inv1=inv1->next;
    return inv1;
    
}

int deleteItemFromCraft(inventory* inv1, int id, int amount){ //delete resources used
inventory * tempInv= malloc(sizeof(inventory));
tempInv=inv1;
int nb=1;
    while (tempInv != NULL){
        if (tempInv->inv->item->id==id)
        {
            if (tempInv->inv->stock>=amount)
            {
                tempInv->inv->stock=tempInv->inv->stock-amount;

                if (tempInv->inv->stock==0)
                {   if (nb==1)
                {
                    *inv1=*tempInv->next;  
                    return 1;
                } else {
                
                    if (tempInv->next!=NULL)
                    {   
                        while (inv1->next!=tempInv)
                        {
                            inv1=inv1->next;
                        }
                        inv1->next=deleteNode(tempInv);
                    } else {
                        inv1=inv1->next;
                        inv1->next=NULL;  
                    }
                    }
                    free(tempInv);
                    return 1;
                }
            } 
        }
        tempInv = tempInv->next;
        nb=nb+1;
    }

return 0;
}

int verifyInInventory(inventory* inv1, int id, int amount){ //verify if the resources are in the inventory

    while (inv1!= NULL){
        if (inv1->inv->item->id==id)
        {
            if (inv1->inv->stock>=amount)
            {
                return 1;
            } 
        }
        inv1 = inv1->next;
    }
printf("You dont have the necessary ressources to craft this item \n");
return 0;
}

int verifyResources(inventory* inv1, int val,int ressourceNumber){ //get ressources id and amount then verify through verifyInInventory

Item* newItem=malloc(sizeof(Item));
newItem=initItem(val);


int id=newItem->craftResources[ressourceNumber][0];
int amount=newItem->craftResources[ressourceNumber][1];

if (id==0 && amount==0)
{
 return 1;
}
if (verifyInInventory(inv1,id,amount)==1)
{
    deleteItemFromCraft(inv1,id,amount);
    return 1;
}

return 0;
}

inventory* newItemFromCraft(int val){ //create a new crafted item
    inventory* newItem=malloc(sizeof(inventory));
    invInfo* invInfo=malloc(sizeof(invInfo));
    invInfo->item=initItem(val);
    invInfo->stock=1;
    newItem->inv=invInfo;
    newItem->next=NULL;

    return newItem;
}

void addItemFromCraft(inventory* newItem, inventory* inv1){ // add an item in the inventory from the craft
    while (inv1->next != NULL){
        inv1 = inv1->next;
    }
    inv1->next=newItem;
    printf("Congrats, you crafted 1 %s\n",newItem->inv->item->name);
}

void craft(inventory* inv1,int val){ //craft an item with it's id

for (int i = 0; i < 2; i++)
{
    int result=verifyResources(inv1,val,i);
    if (result==0)
    {
        return;
    }
}

inventory* newItem = newItemFromCraft(val);

addItemFromCraft(newItem,inv1);

}

void craftItem(inventory* invPlayer){ //print and choose the item to craft

    int size=getSize(invPlayer); 
    if (size<10) 
    {
       
    for (int i = 1; i < 35; i++)
    {
        verifyNotTypeResource(i);
    }

    int itemChoice;
    printf("Choose the item you want to craft:");
    scanf("%d",&itemChoice);

    craft(invPlayer,itemChoice);
    }

}

void startNPC(inventory* invPlayer, inventory* invNPC){

    int choice;
    printf("Hello, what do you want to do? \n 1->Deposit Items, 2->Take Items, 3->Craft Items, 4->Nothing : ");
    scanf("%d", &choice);
    
    while (choice!=4)
    {
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
                printf("Hello, what do you want to do? \n 1->Deposit Items, 2->Take Items, 3->Craft Items, 4->Nothing : ");
                scanf("%d", &choice);
            }
        
        case 3:
            while (choice==3)
            {
                craftItem(invPlayer);
                printf("Hello, what do you want to do? \n 1->Deposit Items, 2->Take Items, 3->Craft Items, 4->Nothing : ");
                scanf("%d", &choice);
            }
            
        case 4:
            break;
        default:
            break;
        }
    }


}

/* void test(){


    Item* item1= malloc(sizeof(Item));
    item1=initItem(5);
    Item* item2= malloc(sizeof(Item));
    item2=initItem(2);
    Item* item3= malloc(sizeof(Item));
    item3=initItem(1);

    invInfo* invInfo1 = malloc(sizeof(invInfo));
    invInfo* invInfo2 = malloc(sizeof(invInfo));
    invInfo* invInfo3 = malloc(sizeof(invInfo));
    invInfo* invInfo4 = malloc(sizeof(invInfo));
    invInfo* invInfo5 = malloc(sizeof(invInfo));

    inventory* invPlayer = malloc(sizeof(inventory));
    
    inventory* invPlayer2 = malloc(sizeof(inventory));

    inventory* invPlayer3 = malloc(sizeof(inventory));


    invInfo1->item=item1;
    invInfo1->stock=3;
    invPlayer->inv=invInfo1;
    invPlayer->next=invPlayer2; 
    

    invInfo2->item=item2;
    invInfo2->stock=25;
    invPlayer2->inv=invInfo2;  
    invPlayer2->next=invPlayer3;

   
    invInfo3->item=item3;
    invInfo3->stock=3;
    invPlayer3->inv=invInfo3;  
    invPlayer3->next=NULL;
    

    inventory* invNPC = malloc(sizeof(inventory));
    inventory* invNPC2 = malloc(sizeof(inventory));

    invInfo4->item=item2;
    invInfo4->stock=2;
    invNPC->inv=invInfo4; 
    invNPC->next=invNPC2;


    invInfo5->item=item2;
    invInfo5->stock=2;
    invNPC2->inv=invInfo5;  
    invNPC2->next=NULL;
        }*/