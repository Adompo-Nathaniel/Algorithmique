#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "Element.h"
#include "File_.h"
#include "File_ch.h"

void afficherMenu();
void testerFonctions();
void afficherLentement(const char *message);
int main() {
    printf("Bienvenue dans la gestion de la file !\n");
    testerFonctions();
    return 0;
}
void afficherLentement(const char *message) {
    while (*message != '\0') {
        putchar(*message);
        fflush(stdout);
        sleep(1);
        message++;
    }
}
void afficherMenu() {
    printf("\nMenu:\n");
    printf("1. Créer une file\n");
    printf("2. Vérifier si la file est vide\n");
    printf("3. Ajouter un élément\n");
    printf("4. Retirer un élément\n");
    printf("5. Afficher la file\n");
    printf("6. Supprimer la file\n");
    printf("7. Quitter\n");
}

void testerFonctions() {
    File maFile;
    Element nouvelElement;
    int continuer = 1;
    int choix;

    while (continuer) {
        afficherMenu();
        printf("Choix: ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                creerFile(&maFile);
                printf("Chargement");
                afficherLentement("...\n");
                printf("File créée avec succès.\n");
                break;
            case 2:
                if (fileVide(maFile)){
                    printf("Chargement");
                    afficherLentement("...\n");
                    printf("La file est vide.\n");
               }else{
                    printf("Chargement");
                    afficherLentement("...\n");
                    printf("La file n'est pas vide.\n");
               }
                break;
            case 3:
                printf("Voulez-vous ajouter un seul élément (1) ou plusieurs (2) ? \n");
                int nbElements;
                scanf("%d", &nbElements);
                if (nbElements == 1) {
                    saisieElement(&nouvelElement);
                    emfiler(&maFile, nouvelElement);
                } else if (nbElements == 2) {
                    printf("Combien d'éléments vous souhaitez ajoutez ? ");
                    scanf("%d", &nbElements);
                    for (int i = 0; i < nbElements; i++) {
                        printf("Entrez la valeur de l'élément %d: ", i + 1);
                        saisieElement(&nouvelElement);
                        emfiler(&maFile, nouvelElement);
                    }
                } else {
                    printf("Nombre invalide.\n");
                }
                break;
            case 4:
                if (!fileVide(maFile)) {
                    if (maFile.deb == maFile.fin) {
                        // S'il n'y a qu'un seul élément dans la file,
                        // vider entièrement la file
                        viderFile(&maFile);
                        printf("Chargement");
                        afficherLentement("...\n");
                        printf("File vidée.\n");
                    } else {
                        // Sinon, retirer un élément de la file
                        defiller(&maFile);
                        printf("Chargement");
                        afficherLentement("...\n");
                        printf("Element retiré.\n");
                    }
                } else {
                    printf("La file est vide, impossible de retirer un élément.\n");

                }
                break;
            case 5:
                printf("Chargement");
                afficherLentement("...\n");
                printf("Contenu de la file: ");
                FileAfficher(&maFile);
                break;
            case 6:
                printf("Suppression de la file au complet\n");
                viderFile(&maFile);
                printf("Chargement");
                afficherLentement("...\n");
                printf("file supprimer");
                break;
            case 7:
                continuer = 0;
                printf("Fin du programme.\n");
                break;
            default:
                printf("Choix invalide.\n");
                break;
        }
    }
}

    /*saisieElement(&e1); 
    saisieElement(&e2);

    afficherElement(e1);
    afficherElement(e2);

    if(egaliteElement(e1,e2)){
        printf("e1=e2\n");
    }else{
        printf("e1!=e2\n");
    }*/
    
    /*creerPile(p);
    int taille,res;
    printf("Entrez une taille :\n");
    scanf("%d",&taille);
    while(taille>res){
        printf("L'élément n° %d : ",res);
        saisieElement(&e1);
        res=res+1;
        empiler(p,e1);
    }
    pileVide(*p);
    printf("Le sommet est \n");
    afficherElement(sommet(*p));
    depiler(p);
    afficherElement(sommet(*p));
    */
    