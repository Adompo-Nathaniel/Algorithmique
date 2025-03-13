#ifndef ELEMENT_H
#define ELEMENT_H
typedef struct Element{
    int a;
    double b;
}Element;

int egaliteElement(Element h1,Element h2);
int valeurEntiere(Element h);
void saisieElement(Element *ph);
void afficherElement(Element h);
double valeurRellee(Element h);

#endif

