#ifndef LISTE_H
#define LISTE_H

#include "Element.h"
#include "cellule2.h"

typedef struct sListe {
    cellule2 *deb,*fin;
    cellule2 *crt;
}Liste;

Element valeurCourante(Liste);
void inserer(Liste *,Element);
void creerListeC(Liste *);
void allerDebut(Liste *);
void allerFin (Liste *);
void supprimer(Liste *);
int listeCVide(Liste*);
void avancer(Liste *);
int estDebut(Liste);
int estFin (Liste);

#endif