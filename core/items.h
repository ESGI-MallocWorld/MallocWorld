#ifndef MALLOCWORLD_ITEMS_H
#define MALLOCWORLD_ITEMS_H

typedef struct Tools{
    int id;
    char* name;
    int durability;
    int craftResources[2][2]; //2 rows and 2 columns; First column = resource id, second column=quantity
} Tools;

Tools* createTool(int);

#endif