#include <stdio.h>
#include <stdlib.h>
void echanger(double *x,double *y);
void ordonner2(double *x,double *y);
void ordonner3(double *x,double *y,double *z);

int main(){
    double x,y,z;
    double *p,*f,*g;
    printf("Entrez 3 valeurs reel x,y,z :\n");
    scanf("%lf",&x);
    scanf("%lf",&y);
    scanf("%lf",&z);
    p=&x;
    f=&y;
    g=&z;
    ordonner3(p,f,g);
    return 0;
}

void echanger(double *x,double *y){
    *x= *x + *y;
    *y= *x - *y;
    *x= *x - *y;
}
void ordonner3(double *x, double *y, double *z) {
    while (!(*x < *y && *y < *z)) {
        if (*x > *y)
            echanger(x, y);
        if (*y > *z)
            echanger(y, z);
        if (*x > *z)
            echanger(x, z);
    }
    printf("Les valeurs sont rangées dans l'ordre croissant : %2.1lf < %2.1lf < %2.1lf\n", *x, *y, *z);
}