#include <stdio.h>
#include <stdlib.h>
#include "LR.h"
#include "Element2P.h"


Element2p* LR_rechercher(ListR* listR,int cle){
    Element2p *tmp= (Element2p*)malloc(sizeof(Element2p));
    tmp = listR;
    while(tmp!=NULL && tmp->cle != cle){
        tmp =tmp->succ;
    }
    return tmp;
}
void LR_inserer(ListR* listR,int cle){
    Element2p *tmp= (Element2p*)malloc(sizeof(Element2p));
    if(listR == NULL){
        tmp= listR;
    }else{
        tmp->pred = NULL;
        tmp->succ = listR;
        tmp->cle = cle;
    }
}

void LR_supprimer(ListR* listR,Element2p *elem){
    if(listR != NULL){
        elem->pred->succ = elem->succ;
        elem->succ->pred = elem->pred;
        free(elem);
    }
}