#ifndef PILE_TAB_H

#define PILE_TAB_H
#include "Element.h"
#include "Pile_.h"
#define MAX_PILE 100

typedef struct sPile{
    int nb;
    Element *tab;
}Pile;
void libererPile(Pile *p);

#endif