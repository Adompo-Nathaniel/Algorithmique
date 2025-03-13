#include <stdio.h>
#include <stdlib.h>

#include "cellule2.h"

cellule2* creerCellule2(Element e, cellule2* succ, cellule2* pred){
    printf("Création de la cellule\n");
    cellule2 *newCell = (cellule2*)malloc(sizeof(cellule2));
    newCell->succ = succ; 
    newCell->pred = pred;
    newCell->val= e;
    return newCell;
}