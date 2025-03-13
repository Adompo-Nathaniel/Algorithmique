#ifndef CELLULE_H

#define CELLULE_H
#include "Element.h"

typedef struct sCellule{
    Element val;
    struct sCellule *svt;
}Cellule;

Cellule* creerCell(Element e,Cellule* ptr);

#endif