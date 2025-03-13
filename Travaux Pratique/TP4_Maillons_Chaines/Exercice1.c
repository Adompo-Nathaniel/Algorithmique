#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int power(int x,int n);
int power2(int acc,int x,int n);
int throwerPower2(int x,int n);

int main(){
    int n,x;
    clock_t debut, fin;
    printf("Entrez le chiffre:\n");
    scanf("%d",&x);
    printf("Entrez la puissance à laquelle vous souhaitez le mettre :\n");
    scanf("%d",&n);
    debut = clock();
    printf("%d puissance %d donne %d avec power 1\n",x,n,power(x,n));
    fin = clock();
    printf("Temps d'execution pour  power 1: %f secondes\n", ((double) (fin - debut)) / CLOCKS_PER_SEC);
    debut = clock();
    printf("%d puissance %d donne %d avec le lanceur et power 2\n",x,n,throwerPower2(x,n));
    fin = clock();
    printf("Temps d'execution pour  power 2: %f secondes\n", ((double) (fin - debut)) / CLOCKS_PER_SEC);

    return 0;
}

int power(int x,int n){
    if(n==0){
        return 1;
    }else if(n%2==0){
        return power(x*x,n/2);
    }else{
        return x * power(x,n-1);
    }
}
int power2(int acc, int x,int n){
    if(n==0){
        return acc;
    }else{
        return power2(acc*x,x,n-1);
    }
}
int throwerPower2(int x,int n){
    return power2(1,x,n);
}