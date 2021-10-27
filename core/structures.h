//
//  Created by brqan on 16/10/2021.
//

#ifndef MALLOCWORLD_STRUTURES_H
#define MALLOCWORLD_STRUTURES_H


typedef struct Ressource {
    
    int value;
    char* name;
    int quantity; // MAX QUANTITY
    
} Ressource;

typedef struct Weapon {
    
    
    int value;
    char* name;
    int zone; // 1=ZONE 1/2/3 2=ZONE 2/3 3=ZONE 3
    int damage;
    int durability;
    int** ressource; // ARRAY[9][2]
    
} Weapon;

typedef struct Tool {
    
    
    int value;
    char* name;
    int zone;
    int durability;
    int** ressource;
    
} Tool ;

typedef struct Armor {
    
    
    int value;
    char* name;
    int zone;
    int resistance;
    int** ressource;
    
} Armor ;

typedef struct Potion {
    
    
    int value;
    char* name;
    int zone;
    int hp_restored;
    int** ressource;
    
} Potion ;


#endif /* MALLOCWORLD_STRUTURES_H */
