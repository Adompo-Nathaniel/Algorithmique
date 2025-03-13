#ifndef __CELLULE2_H__
#define __CELLULE2_H__

#include "Element2P.h"

typedef struct scell2
{   Element val;
    struct scell2 * pred, * succ;
} cellule2;

cellule2* creerCellule2(Element e, cellule2* succ, cellule2* pred);

#endif
