#ifndef NOEUD_H
#define NOEUD_H

//Définition de la structure d'un noeud dans un arbre binaire
typedef struct sNoeud{
    struct sNoeud* filsG;//ptr vers le sous arbre gauche
    struct sNoeud* filsD;//ptr vers le sous arbre droit
    struct sNoeud* pere;//ptr vers le père
    int* cle;
}Noeud;

#endif