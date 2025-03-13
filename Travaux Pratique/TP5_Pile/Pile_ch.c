#include <stdio.h>
#include <stdlib.h>
#include "Pile_.h"
#include "Pile_ch.h"

void creerPile(Pile *p) {
    p->haut = NULL;
}

int pileVide (Pile p) {
    return p.haut == NULL;
    }

void empiler (Pile *p, Element e) {
    Cellule* tmp = (Cellule*)malloc(sizeof(Cellule));
    tmp->element = e;
    tmp->c = p->haut;
    p->haut = tmp;
}

void depiler (Pile *p) {
    Cellule* tmp;
    if(!(pileVide(*p))) {
        tmp = p->haut;
        p->haut = p->haut->c;
        free(tmp);
    }
}

Element sommet(Pile p) {
    return p.haut->element;
}

void libererPile(Pile *p) {
    while(!(pileVide(*p))) {
        free(p->haut);
    }
}