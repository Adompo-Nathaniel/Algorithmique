#ifndef PILE_H
#define PILE_H

#include "Element.h"
#include "cellule.h"

typedef struct sPile Pile;

void empiler(Pile *p,Element e);
void creerPile(Pile *p);
Element sommet(Pile p);
void depiler(Pile *p);
int pileVide(Pile p);

#endif