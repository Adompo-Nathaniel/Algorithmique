#include <stdio.h>
#include <stdlib.h>

#include "LR.c"

int main(){
    ListR *r;
    Element2p *p;

    r=NULL;
    LR_inserer(&r,3);
    p= LR_rechercher(r,5); 

}