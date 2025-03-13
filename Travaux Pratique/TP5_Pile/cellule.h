#ifndef CELLULE_H

#define CELLULE_H
#include "Element.h"

typedef struct Cellule{
    Element element;
    struct Cellule *c;
}Cellule;

#endif