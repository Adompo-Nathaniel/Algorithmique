#include <stdio.h>
#include <stdlib.h>

#include "Pile_.h"
#include "Pile_tab.h"
#include "Element.h"

void creerPileTab(Pile *p){
    p->tab = (Element*)malloc(sizeof(Element)*MAX_PILE);
    p->nb = -1 ;
    //printf("Pile créer\n");
}

int pileVideTab(Pile p){
    //printf("Pile vide\n");
    return p.nb <= -1;
}

void empilerTab(Pile *p,Element e){
    p->nb += 1;
    p->tab[p->nb] = e;
    //printf("Empillage\n");
}

void depilerTab(Pile *p){
    if(!pileVide(*p)){
        p->nb--;
    }
    //printf("Dépillage\n");
}

Element sommetTab(Pile p){
    printf("Le sommet de la pile est :");
    return p.tab[p.nb];
    printf("\n");
}

void libererPileTab(Pile *p){
    //printf("libérations de la pile");
    free(p->tab);
}
