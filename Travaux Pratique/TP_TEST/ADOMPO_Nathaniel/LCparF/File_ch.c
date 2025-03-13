#include <stdio.h>
#include <stdlib.h>

#include "File_.h"
#include "File_ch.h"
#include "Element.h"
#include "Cellule.h"

void creerFile(File *p) {
    printf("Création d'une file vide\n");
    p->deb = NULL;
    p->fin = NULL;
}

int fileVide(File p) {
    return ((p.deb == NULL) && (p.fin == NULL));
}

void emfiler(File *p, Element e) {
    Cellule *ptr = creerCell(e, NULL);
    if (fileVide(*p)) {
        printf("Votre file contient maintenant 1 seule cellule\n");
        p->deb = ptr;
        p->fin = ptr;
    } else {
        printf("Ajout de l'élément :\n");
        afficherElement(e);
        printf("\n");
        (p->fin)->svt = ptr;
        p->fin = ptr; // Met à jour la fin de la file pour pointer vers la nouvelle cellule
    }
}

void defiller(File *p) {
    if (!fileVide(*p)) {
        Cellule *tmpCell = (p->deb)->svt;
        free(p->deb);
        p->deb = tmpCell;
        printf("Suppression de la cellule en tête de votre file\n");
        if (fileVide(*p)) {
            printf("Votre file est vide dorénavant\n");
        }
    } else {
        printf("Erreur: il n'y a rien dans la file !\n");
    }
}

Element tete(File p) {
    if (!fileVide(p)) {
        return (p.deb)->val;
    } else {
        printf("Erreur: file vide, pas de tête !\n");
        exit(EXIT_FAILURE);
    }
}

void FileAfficher(File *p) {
    printf("[");
    if (fileVide(*p)) {
        printf("Rien");
    } else {
        Cellule *courant = p->deb;
        afficherElement(courant->val);
        while (courant->svt != NULL) {
            printf(", ");
            courant = courant->svt;
            afficherElement(courant->val);
        }
    }
    printf("]\n");
}
void viderFile(File *p) {
    while (fileVide(*p)==1) {
        defiller(p);
    }
    p->deb = NULL;
    p->fin = NULL;
}

