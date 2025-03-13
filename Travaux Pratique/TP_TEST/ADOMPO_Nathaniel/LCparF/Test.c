#include <stdio.h>
#include "cellule2.h"
#include "ListeC_F.h"
#include "File_.h"

int main() {
    ListeC maListe;
    File avant, apres;
    Element e1 = {1, 1}; // Exemple de données à insérer
    Element e2 = {2, 2}; // Exemple de données à insérer
    Element e3 = {3, 3}; // Exemple de données à insérer

    // Initialisation des files avant et après
    creerFile(&avant);
    creerFile(&apres);

    // Création de la liste
    creerListeC(&maListe, &avant, &apres);

    // Insertion d'éléments dans la liste
    inserer(&maListe, e1, &avant, &apres);
    inserer(&maListe, e2, &avant, &apres);
    inserer(&maListe, e3, &avant, &apres);

    // Affichage de la valeur courante après l'insertion
    printf("Valeur courante : %d, %d\n", valeurCourante(maListe).a, valeurCourante(maListe).b);

    // Déplacement du curseur au début de la liste
    allerDebut(&maListe);

    // Suppression d'un élément de la liste
    supprimer(&maListe, &avant, &apres);

    // Affichage de la valeur courante après la suppression
    printf("Valeur courante après suppression : %d, %d\n", valeurCourante(maListe).a, valeurCourante(maListe).b);

    return 0;
}
