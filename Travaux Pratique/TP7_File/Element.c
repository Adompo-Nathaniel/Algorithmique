#include <stdio.h>
#include <stdlib.h>

#include "Element.h"


void saisieElement(Element *ph){
    printf("Entrez une valeur pour a :\n");
    scanf("%d",&(ph->a));
    printf("Entrez une valeur pour b :\n");
    scanf("%lf",&(ph->b));
}

void afficherElement(Element h){
    printf("{%d + %.1lf}",h.a,h.b);
}

int egaliteElement(Element h1,Element h2){
    int res;
    if((h1.a==h2.a) && (h1.b==h2.b)){
        res=1;
    }else{
        res=0;
    }
    return res;
}

int valeurEntiere(Element h){
    return h.a;
}

double valeurRellee(Element h){
    return h.b;
}

