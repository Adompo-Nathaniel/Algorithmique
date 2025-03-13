#include "Exo2.h"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 100

void remplissage(Point tab[], int taille) {
    printf("Remplissage du tableau avec des coordonnées aléatoires dans l'intervalle [-3.1, 5]:\n");
    for (int i = 0; i < taille; i++) {
        tab[i].x = ((float)rand() / RAND_MAX) * 8.1 - 3.1;  // Génère un nombre aléatoire dans [-3.1, 5]
        tab[i].y = ((float)rand() / RAND_MAX) * 8.1 - 3.1;
    }
}

void affichage(Point tab[], int taille) {
    printf("Affichage du tableau de points :\n");

    for (int i = 0; i < taille; i++) {
        printf("Point %d : (%.2f, %.2f)\n", i + 1, tab[i].x, tab[i].y);
    }
}

float distanceOrigine(Point p) {
    return sqrt(p.x * p.x + p.y * p.y);
}

float plusPetiteDistanceOrigine(Point tab[], int taille) {
    float minDistance = distanceOrigine(tab[0]);

    for (int i = 1; i < taille; i++) {
        float dist = distanceOrigine(tab[i]);
        if (dist < minDistance) {
            minDistance = dist;
        }
    }

    return minDistance;
}

void deuxPointsPlusEloignes(Point tab[], int taille, int *indice1, int *indice2) {
    float maxDistance = 0;

    for (int i = 0; i < taille - 1; i++) {
        for (int j = i + 1; j < taille; j++) {
            float dist = sqrt(pow(tab[j].x - tab[i].x, 2) + pow(tab[j].y - tab[i].y, 2));

            if (dist > maxDistance) {
                maxDistance = dist;
                *indice1 = i;
                *indice2 = j;
            }
        }
    }
}

void triParDistanceOrigine(Point tab[], int taille) {
    for (int i = 0; i < taille - 1; i++) {
        for (int j = 0; j < taille - i - 1; j++) {
            if (distanceOrigine(tab[j]) > distanceOrigine(tab[j + 1])) {
                Point temp = tab[j];
                tab[j] = tab[j + 1];
                tab[j + 1] = temp;
            }
        }
    }
}
