#include<stdio.h>
#include<stdlib.h>
#include"inventory.h"
#include"../Units/Player.h"


void loadGame(Player** player, inventory** invNPC){
   /* 

    char test[100];
    int t1,t2,t3;

    FILE *f = fopen("text.txt","r");
    if (f!=NULL)
    {   
        for (int i = 0; i < 10; i++)
        {
            while(fgetc(f)!='{'){
                
                }
            fscanf(f,"%d}@{%d}@{%d}\n",&t1,&t2,&t3);
            if (t1!=0)
            {
                printf("%d %d %d\n",t1,t2,t3);
            }
        }
        
        while (!feof(f))
        {
            while(fgetc(f)!='{'){
                
                }
            fscanf(f,"%d}@{%d}\n",&t1,&t2);
            
            printf("%d %d\n",t1,t2);
            
        }
        fclose(f);
    } else{
        printf("erreur");
    } */
}

void saveGame(Player* player, inventory* invNPC){

   
    FILE *f = fopen("save.txt","w+");
    if (f!=NULL)
    {
        fprintf(f,"=== PLAYER ===\n");
        fprintf(f,"{%d}",player->level);
        fprintf(f,"{%d}/{%d}",player->exp,player->getMaxExp);
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
