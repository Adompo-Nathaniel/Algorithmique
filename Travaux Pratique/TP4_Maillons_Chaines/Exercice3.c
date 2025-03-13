#include <stdio.h>
#include <stdlib.h>

typedef struct Maillon {
    int val;
    struct Maillon* ath;
} Maillon;

void afficherListe(Maillon* maill) {
    while (maill != NULL) {
        printf("Adresse : %p ; Valeur : %d\n", maill, maill->val);
        maill = maill->ath;
    }
}
void supprimerMaillon(int *p,Maillon* maill){
    while(*p){
        
    }
}

int main() {
    Maillon *chaine = (Maillon*)malloc(sizeof(Maillon));
    chaine->val = 1;
    chaine->ath = (Maillon*)malloc(sizeof(Maillon));
    chaine->ath->val = 3;
    chaine->ath->ath = (Maillon*)malloc(sizeof(Maillon));
    chaine->ath->ath->val = 2;
    chaine->ath->ath->ath = (Maillon*)malloc(sizeof(Maillon));
    chaine->ath->ath->ath->val = 8;
    chaine->ath->ath->ath->ath = (Maillon*)malloc(sizeof(Maillon));
    chaine->ath->ath->ath->ath->val = 12;
    chaine->ath->ath->ath->ath->ath = (Maillon*)malloc(sizeof(Maillon));
    

    // Affichage avant la suppression
    printf("Avant la suppression :\n");
    afficherListe(chaine);

    // Suppression du maillon contenant la valeur 3
    Maillon* maill = chaine;
    while (maill != NULL && maill->ath != NULL && maill->ath->val != 1) {
        maill = maill->ath;
    }

    if (maill != NULL && maill->ath != NULL) {
        Maillon* temp = maill->ath;
        maill->ath = maill->ath->ath;
        free(temp);
    }

    // Affichage après la suppression
    printf("\nAprès la suppression :\n");
    afficherListe(chaine);

    // Libération de mémoire restante
    maill = chaine;
    while (maill != NULL) {
        Maillon* temp = maill;
        maill = maill->ath;
        free(temp);
    }

    return 0;
}
