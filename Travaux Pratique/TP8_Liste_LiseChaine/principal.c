#include <stdio.h>
#include <stdlib.h>

#include "Element.h"
#include "ListeC_ch2.h"
#include "ListeC.h"


/*
void creerListeC(ListeC *);
void allerDebut(ListeC *);
void allerFin (ListeC *);
int estDebut(ListeC);
int estFin (ListeC);
void avancer(ListeC *);
int listeCVide(ListeC);
void inserer(ListeC *,Element);
void supprimer(ListeC *);
int  tailleL(ListeC *);
Element valeurCourante(ListeC);
*/
void afficherL(ListeC *);
void viderL(ListeC *);
int tailleL(ListeC *);

int  tailleL(ListeC *list){
    int nbTotal=0, nbFin=0;
	while(!estFin(*list)){
		nbFin=nbFin+1;
		avancer(list);
	}
    allerDebut(list);
    while(!(estFin(*list))){
        nbTotal=nbTotal+1;
        avancer(list);
    }
	allerDebut(list);
	for(int i=0;i<(nbTotal-nbFin);i++){
		avancer(list);
	}
    return nbTotal;
}
void afficherL(ListeC *list){
    printf("[");
    cellule2 *tmp = list->crt;
    if(!(listeCVide(*list))){
        allerDebut(list);
        while(!(estFin(*list))){
            afficherElement(list->crt->val);
            avancer(list);
        }
        allerDebut(list);
        while (list->crt != tmp){
            avancer(list);
        }
    }
    printf("]\n");
}
void viderL(ListeC *list){
    allerDebut(list);
    while(!(estFin(*list))){
        supprimer(list);
    }
}

int main(void)
{	ListeC lc; 
	Element e;

	creerListeC(&lc);

	for(int i=0 ; i<5 ; i++){
		saisieElement(&e);
		inserer(&lc,e);
		afficherL(&lc);
	}

	printf("contenu apres remplissage : ");
		afficherL(&lc);	// cette fois le contenu de la struct. ne change pas
		// mais on passe quand meme l'adresse
		// 		pour respecter la notation imposee pour les piles / files

	printf("\n\t => taille (2 fois) : %d %d\n", tailleL(&lc), tailleL(&lc));
	printf("contenu apres taille : "); 	afficherL(&lc);

	printf("\non va au debut et on supprime : "); 
	allerDebut(&lc); supprimer(&lc); 
	afficherL(&lc);
	printf("\n\t => taille : %d\n", tailleL(&lc));
	
	printf("on avance 2 fois, on en supprime 2 et on en ajoute 1 : "); 
	avancer(&lc); avancer(&lc); supprimer(&lc); supprimer(&lc); saisieElement(&e); inserer(&lc,e);
	afficherL(&lc);
	printf("\n\t => taille : %d\n", tailleL(&lc));

	viderL(&lc);
	printf("contenu apres vidage : "); 		afficherL(&lc);
	printf("\n\t => taille : %d\n", tailleL(&lc));
	return 0;
}
