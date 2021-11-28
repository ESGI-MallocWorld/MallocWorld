#include<stdio.h>
#include<stdlib.h>
#include"inventory.h"
#include"../Units/Player.h"

inventory* newItemAddToPlayer(int value1, int value2, int value3){ // create a new inventory entry
    inventory* newInv=malloc(sizeof(inventory));
    invInfo* invInfo=malloc(sizeof(invInfo));
    invInfo->item=initItem(value2);
    invInfo->item->durability=value3;
    invInfo->stock=value1;
    newInv->inv=invInfo;
    newInv->next=NULL;

    return newInv;
}

inventory* newItemAddToNPC(int value1, int value2){ // create a new inventory entry
    inventory* newInv=malloc(sizeof(inventory));
    invInfo* invInfo=malloc(sizeof(invInfo));
    invInfo->item=initItem(value2);
    invInfo->stock=value1;
    newInv->inv=invInfo;
    newInv->next=NULL;

    return newInv;
}

void loadGame(Player* player, inventory* invNPC){
   

    char test[100];
    int t1,t2,t3;

    FILE *f = fopen("save.txt","r");
    if (f!=NULL)
    {   
        
        while(fgetc(f)!='{'){ //advance until we find '{'
            }
        fscanf(f,"%d}\n",&t1); // CURRENT LEVEL
        if (t1!=0)
            {
                 player->level->levelID=t1;
            }    

        while(fgetc(f)!='{'){ //advance until we find '{'
            }
        fscanf(f,"%d}/{%d}\n",&t1,&t2); //CURRENT & MAX EXP
        if (t1!=0)
            {
                 player->exp=t1;
                 player->level->maxExp=t2;
            } 

        while(fgetc(f)!='{'){ //advance until we find '{'
            }
        fscanf(f,"%d}/{%d}\n",&t1,&t2); //CURRENT & MAX HP
        if (t1!=0)
            {
                 player->currentHp=t1;
                 player->maxHp=t2;
            } 

        for (int i = 0; i < 10; i++) // INVENTORY
        {
            while(fgetc(f)!='{'){ //advance until we find '{'
                }
            fscanf(f,"%d}@{%d}@{%d}\n",&t1,&t2,&t3);
            if (i==0)
            {
                if (t1!=0)
                {
                    player->inventory=newItemAddToPlayer(t1,t2,t3);
                }

            } else {

                if (t1!=0)
                {
                    player->inventory->next=newItemAddToPlayer(t1,t2,t3);
                    player->inventory=player->inventory->next;
                }

            }
            
            
        }
        int size=0;
        while (!feof(f))
        {   
            while(fgetc(f)!='{'){ //STORAGE
                
                }
            fscanf(f,"%d}@{%d}\n",&t1,&t2);
            
            invNPC->next=newItemAddToNPC(t1,t2);
            invNPC=invNPC->next;

            if (size==0)
            {
                invNPC=newItemAddToNPC(t1,t2);
            } else {
                invNPC->next=newItemAddToNPC(t1,t2);
                invNPC=invNPC->next;
            }

            size=size+1; 
        }
        fclose(f);
    } else{
        printf("erreur");
    } 
}

void saveGame(Player* player, inventory* invNPC){

   
    FILE *f = fopen("save.txt","w+");
    if (f!=NULL)
    {
        fprintf(f,"=== PLAYER ===\n");
        fprintf(f,"{%d}",player->level->levelID);
        fprintf(f,"{%d}/{%d}",player->exp,player->level->maxExp);
        fprintf(f,"{%d}/{%d}",player->currentHp,player->maxHp);
        fprintf(f,"-- INVENTORY --\n");
        int size=0;
        while(player->inventory!=NULL){
            size=size+1;
            fprintf(f,"{%d}@{%d}@{%d}\n",player->inventory->inv->stock,player->inventory->inv->item->id,player->inventory->inv->item->durability);
            player->inventory=player->inventory->next;
        }
        for (int i = 0; i < 10-size; i++)
        {
            fprintf(f,"{0}@{0}@{0}\n");
        }
        fprintf(f,"-- STORAGE --\n");
        while(invNPC!=NULL){
            size=size+1;
            fprintf(f,"{%d}@{%d}\n",invNPC->inv->stock,invNPC->inv->item->id);
            invNPC=invNPC->next;
        }
        
        fclose(f);
    } else{
        printf("Erreur lors de la sauvegarde");
    }
};