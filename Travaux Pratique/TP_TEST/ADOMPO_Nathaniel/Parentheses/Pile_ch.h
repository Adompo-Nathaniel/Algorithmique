#ifndef PILE_CH_H
#define PILE_CH_H

#include "Element.h"
#include "cellule.h"
#include "Pile_.h"

#define MAX_PILE 100

typedef struct sPile{
    Cellule* haut;
} Pile;

void libererPile(Pile *p);
void afficherPile(Pile p);

#endif
