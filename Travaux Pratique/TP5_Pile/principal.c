#include <stdio.h>
#include <stdlib.h>
#include "Element.h"
#include "Pile_.h"
#include "Pile_tab.h"

int main(void){
    Element e1;
    Pile p1;
    int taille,res;

    Pile *p=&p1;
    creerPile(p);
    printf("Entrez une taille :\n");
    scanf("%d",&taille);
    res=0;

    while(taille>res){
        printf("L'élément n° %d : ",res);
        saisieElement(&e1);
        res=res+1;
        empiler(p,e1);
    }
    afficherElement(sommet(*p));
    return 0;
}