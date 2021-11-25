//
// Created by wuchi on 2021/11/25.
//

#ifndef MALLOCWORLD_RESSOURCESACTION_H
#define MALLOCWORLD_RESSOURCESACTION_H

#endif //MALLOCWORLD_RESSOURCESACTION_H



int deleteItemFromInv(Item* item, inventory* inv, int quantity){
    int stockInInv = getStockItem(item->id, inv);
    int amount = quantity;

    if(stockInInv == 0){
        printf("There is no %s present in the inventory\n", item->name);
    }else if( stockInInv  < amount ){
        printf("You only have %d pieces of %s in the inventory \n", stockInInv, item->name);
    }else{

        *inventory temp;
        int difference = amount - inv->inv->stock;
        if(inv->inv->item->id == item->id){ // if item is stocked in the first case of the inventory
            if(difference==0){//if the demanded quantity is equal to the stock present in the first item's case
                temp = inv;
                inv = inv->next;
                free(temp);
                printf("%d piece(s) of %s were withdrawn from the inventory.\n", amount, item->name )
                return 1;
            }if else (difference>0){ //if the demanded amount is higher than the stock present in the first item's case
                amount -= inv->inv->stock;
                temp = inv;
                inv = inv->next;
                free(temp);

            }else{//if the stock in the inventory of the first item's case is higher than the demanded amount
                inv->inv->stock -= amount;
                printf("%d piece(s) of %s were withdrawn from the inventory.\n", amount, item->name )
                return 1;
            }
        }
        //if item is not stocked in the first case or if the demanded amount is higher than what has already been withdrawn and the item is stocked in multiple cases
        while(inv->next != NULL){
            difference = amount - inv->next->inv->stock;
            if(inv->next->inv->item->id == item->id){//checks if the item can be found in the next case
                if(difference==0){//if the demanded quantity is equal to the stock present in the next item's case
                    temp = inv->next;
                    inv->next = inv->next->next;
                    free(temp);
                    printf("%d piece(s) of %s were withdrawn from the inventory.\n", amount, item->name )
                    return 1;
                }
                if else (difference>0){//if the demanded amount is higher than the stock present in the next item's case
                    amount -= inv->next->inv->stock;
                    temp = inv->next;
                    inv->next = inv->next->next;
                    free(temp);
                }
                else{//if the stock in the inventory of the next item's case is higher than the demanded amount
                    inv->next->inv->stock -= amount;
                    return 1;
                    printf("%d piece(s) of %s were withdrawn from the inventory.\n", amount, item->name )
                }
            }
            inv = inv->next;
        }

    }

}
