#include<stdio.h>
#include<stdlib.h>
#include"inventory.h"

void importInv(inventory* invPlayer, inventory* invNPC){
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

void exportInv(inventory* invPlayer, inventory* invNPC){
   
    FILE *f = fopen("text.txt","w+");
    if (f!=NULL)
    {
        fprintf(f,"=== MAP ===\n");
        fprintf(f,"-- ZONE 1 --\n");



        fprintf(f,"-- ZONE 3 --\n");




        fprintf(f,"-- ZONE 3 --\n");




    
        fprintf(f,"=== PLAYER ===\n");
        fprintf(f,"{%d}",playerLevel);
        fprintf(f,"{%d}/{%d}",xpCurrent,xpNext);
        fprintf(f,"{%d}/{%d}",hpCurrent,hpMax);
        fprintf(f,"-- INVENTORY --\n");
        int size=0;
        while(invPlayer!=NULL){
            size=size+1;
            fprintf(f,"{%d}@{%d}@{%d}\n",invPlayer->inv->stock,invPlayer->inv->item->id,invPlayer->inv->item->durability);
            invPlayer=invPlayer->next;
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
        printf("erreur");
    }
};

void loadGame(inventory* invPlayer, inventory* invNPC){
    
    exportInv(invPlayer,invNPC);
    
   /* importInv(invPlayer,invNPC); */

}
