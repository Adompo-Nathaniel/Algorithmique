#include "Exo2.h"
#define MAX 100

int main(){
    Point tableau[MAX];
    int taille;

    // Demande à l'utilisateur de saisir la taille du tableau
    do {
        printf("Entrez la taille du tableau : \n");
        scanf("%d", &taille);
    } while (taille <= 0 || taille > MAX);

    // Test de la fonction remplissage
    remplissage(tableau, taille);

    // Test de la fonction affichage
    printf("Tableau de points après remplissage :\n");
    affichage(tableau, taille);

    // Test de la fonction plusPetiteDistanceOrigine
    printf("Plus petite distance à l'origine : %.2f\n", plusPetiteDistanceOrigine(tableau, taille));

    // Test de la fonction deuxPointsPlusEloignes
    int indice1, indice2;
    deuxPointsPlusEloignes(tableau, taille, &indice1, &indice2);
    printf("Indices des deux points les plus éloignés : %d et %d\n", indice1, indice2);

    // Test de la fonction triParDistanceOrigine
    triParDistanceOrigine(tableau, taille);
    printf("Tableau trié par distance à l'origine :\n");
    affichage(tableau, taille);

    return 0;
}