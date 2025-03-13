#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int somme1(int a, int b);
int somme2(int a, int b);

int main() {
    int a, b;
    int choix;
    clock_t debut, fin;

    printf("Entrez la valeur de a :\n");
    scanf("%d", &a);
    printf("Entrez la valeur de b :\n");
    scanf("%d", &b);
    printf("Que voulez-vous faire ?\n");
    printf("-1) Faire somme1\n");
    printf("-2) Faire somme2\n");
    printf("-3) Ne rien faire\n");
    scanf("%d", &choix);

    switch (choix) {
        case 1:
            debut = clock();
            choix = somme1(a, b);
            fin = clock();
            printf("Le resultat est %d\n", choix);
            printf("Temps d'execution pour somme1: %f secondes\n", ((double) (fin - debut)) / CLOCKS_PER_SEC);
            break;
        case 2:
            debut = clock();
            choix = somme2(a, b);
            fin = clock();
            printf("Le resultat est %d\n", choix);
            printf("Temps d'execution pour somme2: %f secondes\n", ((double) (fin - debut)) / CLOCKS_PER_SEC);
            break;
        case 3:
            printf("Je ne fais rien\n");
            break;
        default:
            printf("Erreur\n");
            break;
    }

    return 0;
}

int somme1(int a, int b) {
    if (b == 0) {
        return a;
    } else {
        return 1 + somme1(a, b - 1);
    }
}

int somme2(int a, int b) {
    if (b == 0) {
        return a;
    } else {
        return somme2(a + 1, b - 1);
    }
}
