//
// Created by wuchi on 2021/10/12.
//

#ifndef MALLOCWORLD_GENEARTORMAP_H
#define MALLOCWORLD_GENEARTORMAP_H

/**
 *
 * @return maps
 */

int*** genere_map(int zone_number){
    int zone1_row_size = 10;
    int zone1_col_size = 10;
    /**
    int zone2_row_size = 10;
    int zone2_col_size = 10;
    int zone3_row_size = 10;
    int zone3_col_size = 10;
    */
    int** zone_map ;

    switch (zone_number) {
        case 1:
        default:
            zone_map = genere_zone1(zone1_row_size , zone1_col_size);
            break;
        case 2:
            zone_map = genere_zone2(zone1_row_size , zone1_col_size);
            break;
        case 3:
            zone_map = genere_zone3(zone1_row_size , zone1_col_size);
            break;
    }


    return zone_map;
}

int** genere_zone1(int row , int col){

}

int** genere_zone2(int row , int col){

}

int** genere_zone3(int row , int col){

}

#endif //MALLOCWORLD_GENEARTORMAP_H
