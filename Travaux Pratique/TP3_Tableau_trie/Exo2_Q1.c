#include <stdio.h>
#include <stdlib.h>
int EstCroissant(int i,int taille,double tab[]);
int EstDecroissant(int i,int taille,double tab[]);
int lanceurCroissant(double tab[],int taille);
int lanceurDecroissant(double tab[],int taille);
int main(){
    double tab1[]={1.2,1.8,1.6,1.9,2.78,5.74};
    double tab2[]={1.2,1.6,1.8,1.9,2.78,5.74};
    if(lanceurCroissant(tab1,6)){
        printf("Le tableau 1 est triee de façon croissante");
    }else{
        printf("Le tableau 1 n'est pas triee de façon croissante");
    }

    if(lanceurDecroissant(tab1,6)){
        printf("Le tableau 1 est triee de façon decroissante");
    }else{
        printf("Le tableau 1 est triee de façon croissante");
    }
    if(lanceurCroissant(tab2,6)){
        printf("Le tableau 2 est triee de façon croissante");
    }
    if(lanceurDecroissant(tab2,6)){
        printf("Le tableau 2 est triee de façon decroissante");
    }

    return 0;
}
int EstCroissant(int i,int taille,double tab[]){
    if(tab[i]>tab[i+1]){
        return 0;
    }
    if(i==taille){
        return 1;
    }else{
        return EstCroissant(i,taille,tab);
    }
}
int EstDecroissant(int i,int taille,double tab[]){
        if(tab[i]<tab[i+1]){
        return 0;
    }
    if(taille==0){
        return 1;
    }else{
        return EstDecroissant(i,taille,tab);
    }
}
int lanceurCroissant(double tab[],int taille){
    return EstCroissant(0,taille,tab);
}
int lanceurDecroissant(double tab[],int taille){
    return EstCroissant(0,taille,tab);
}