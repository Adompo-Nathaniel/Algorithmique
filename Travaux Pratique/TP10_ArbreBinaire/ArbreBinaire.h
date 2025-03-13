#ifndef ARBREBINAIRE_H
#define ARBREBINAIRE_H
#include "Noeud.h"

//On a dit qu'un arbre binaire de recherche étais un pointeur de noeud
typedef Noeud* ABR;

//On doit mettre en place les fonctions suivantes
Noeud* ABR_Minimum(ABR abr);
Noeud* ABR_Maximum(ABR abr);
Noeud* ABR_recherche(ABR a,int cle);

Noeud* ABR_predececeur(ABR abr,Noeud* noeud);
Noeud* ABR_succeseur(ABR abr,Noeud* noeud);


void Ajouter(ABR* abr,int*val);
void Supprimer(ABR* abr,Noeud* noeud);



//Fonction d'affichage
void AffichagePrefixe(ABR* abr);
void AffichageInfixe(ABR* abr);
void AffichagePostfixe(ABR* abr);

#endif