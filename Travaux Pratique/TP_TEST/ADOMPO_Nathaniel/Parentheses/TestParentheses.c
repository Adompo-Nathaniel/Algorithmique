#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Element.h"
#include "Pile_.h"
#include "Pile_ch.h"

int okPar(char* ch);

int main(){
    char ch[100];
    printf("Entrez une chaine de caractere(100) :\n");
    scanf("%s", ch);
    int resultat = okPar(ch);
    if(resultat){
        printf("Parentheses bien équilibrées.\n");
    }else{
        printf("Parentheses mal équilibrées.\n");
    }
    return 0;
}


int okPar(char *ch){
    Pile p;
    Element e;
    creerPile(&p);

    int res=1;
    int size_ch = strlen(ch);
    for(int i=0;i<size_ch;i++){
        char valChar = ch[i];
        switch (valChar){
            //cas d'une parenthèse ouvrante
            case '[':
                e.a=1;
                empiler(&p,e);
                break;
                
            case '(':
                e.a=2;
                empiler(&p,e);
                break;

            case '{':
                e.a=3;
                empiler(&p,e);
                break;
            //cas d'une paraenthèse fermante
            case ']':
                if( sommet(p).a != 1 ){
                    res=0;
                }else{
                    depiler(&p);
                }
                break;

            case ')':
                if( sommet(p).a != 2 ){
                    res=0;
                }else{
                    depiler(&p);
                }
                break;
            case '}':
                if( sommet(p).a != 3 ){
                    res=0;
                }else{
                    depiler(&p);
                }
                break;
        }
        if(res == 0)
            break;
    }
    if(!pileVide(p))
        res = 0;
    return res;
}