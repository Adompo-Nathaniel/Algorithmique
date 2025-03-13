#ifndef LR_H
#define LR_H
#include "Element2P.h"

typedef Element2p *ListR;
Element2p* LR_rechercher(ListR,int);
void LR_inserer(ListR*,int);
void LR_supprimer(ListR*,Element2p*);

#endif