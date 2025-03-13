#include <stdio.h>
#define MAX 100 
void remplissage(float tab[],int taille);
void afficherTab(float tab[],int taille);
float somme(float a, float b);
float produit(float a, float b);
int indiceMin(float tab[],int taille);
int indiceMax(float tab[],int taille);
void TrieSequentielle(float tab[],int taille);
void TrieDichotomique(float tab[],int taille);
void TrieParSelection(float tab[],int taille);
void TrieParInsertion(float tab[],int taille);
int rechercheDichotomique(float tab[], int debut, int fin, float element);
void echanger(float *a, float *b);
void TrieBulles(float tab[],int taille);

int main(){
    float tableau[MAX];

    int taille;
    do{
        printf("Entrez la taille du tableau : \n");
        scanf("%d",&taille);
    }while ((taille > MAX)||(taille < 1));
    
    remplissage(tableau,taille);
    afficherTab(tableau,taille);

    printf("Tableau avant le tri :\n");
    for (int i = 0; i < taille; ++i) {
        printf("%.2f ", tableau[i]);
    }
    printf("\n");
    TrieBulles(tableau, taille);    
    printf("Tableau après le tri :\n");
    for (int i = 0; i < taille; ++i) {
        printf("%.2f ", tableau[i]);
    }
    printf("\n");
    return 0;
}
void remplissage(float tab[],int taille){
    printf("Entrez les valeurs \n");

    for(int i=0;i<taille;i++){
        printf("Entrez la %i valeur :\n",i+1);
        scanf("%fl",&tab[i]);
    }
}
void afficherTab(float tab[],int taille){
    printf("Votre de tableau de %d valeur :\n",taille);
    for(int i=0;i<taille;i++){
        printf("La %d valeur est : %.1f\n",i+1,tab[i]);
    }
}
float somme(float a,float b){
    float c;
    return c=a+b;
}
float produit(float a, float b){
    float c;
    return c=a*b;
}
int indiceMin(float tab[],int taille){
    float val=tab[0];
    int indice=0;
    for(int i=1;i<taille;i++){
        if(tab[i] < val){
            indice=i;
        }
    }
    return indice;
}
int indiceMax(float tab[],int taille){
    float val=tab[0];
    int indice=0;
    for(int i=1;i<taille;i++){
        if(tab[i] > val){
            indice=i;
        }
    }
    return indice;
}

void echanger(float *a, float *b) {
    float temp = *a;
    *a = *b;
    *b = temp;
}
int rechercheDichotomique(float tab[], int debut, int fin, float element) {
    while (debut <= fin) {
        int milieu = debut + (fin - debut) / 2;

        if (tab[milieu] == element) {
            return milieu;
        } else if (tab[milieu] < element) {
            debut = milieu + 1;
        } else {
            fin = milieu - 1;
        }
    }
    return -1;
}

void TrieDichotomique(float tab[], int taille) {
    for (int i = 1; i < taille; ++i) {
        float elementActuel = tab[i];
        int j = i - 1;
        while (j >= 0 && tab[j] > elementActuel) {
            tab[j + 1] = tab[j];
            j = j - 1;
        }
        tab[j + 1] = elementActuel;
    }
}

void TrieParSelection(float tab[], int taille) {
    for (int i = 0; i < taille - 1; ++i) {
        int indiceMinimum = i;

        for (int j = i + 1; j < taille; ++j) {
            if (tab[j] < tab[indiceMinimum]) {
                indiceMinimum = j;
            }
        }
        echanger(&tab[i], &tab[indiceMinimum]);
    }
}

void TrieParInsertion(float tab[], int taille) {
    for (int i = 1; i < taille; ++i) {
        float elementActuel = tab[i];
        int j = i - 1;
        while (j >= 0 && tab[j] > elementActuel) {
            tab[j + 1] = tab[j];
            j = j - 1;
        }
        tab[j + 1] = elementActuel;
    }
}  
void TrieBulles(float tab[], int taille) {
    for (int i = 0; i < taille - 1; ++i) {
        for (int j = 0; j < taille - i - 1; ++j) {
            if (tab[j] > tab[j + 1]) {
                echanger(&tab[j], &tab[j + 1]);
            }
        }
    }
}