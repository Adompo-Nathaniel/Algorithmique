#include <stdio.h>
#include <stdlib.h>

#include "Cellule.h"

Cellule* creerCell(Element e,Cellule* ptr){
    Cellule *newCell=(Cellule*)malloc(sizeof(Cellule));
    newCell->svt=ptr;
    newCell->val=e;
    return newCell;
}