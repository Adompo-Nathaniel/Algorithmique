#include <stdio.h>
#include <stdlib.h>
#include "cellule2.h"
#include "ListeC_ch2.h"


void creerListeC(ListeC *list){
    printf("Création de la list\n");
    list->deb=NULL;
    list->crt=NULL;
    list->fin=NULL;
}
void allerDebut(ListeC *list){
    list->crt= list->deb;
}
void allerFin (ListeC *list){
    list->crt= list->fin;
}
int estDebut(ListeC list){
    return list.crt == list.deb;
}
int estFin (ListeC list){
    return list.crt == list.fin;
}
void avancer(ListeC *list){
    list->crt =(list->crt)->succ;
}
int listeCVide(ListeC list){
    return list.crt == NULL;
}

void inserer(ListeC *list,Element e){
    cellule2 *ptr= creerCellule2(e,NULL,NULL);//On créée la cellule 1)
    if(listeCVide(*list)){
        printf("La liste est vide\n");
        printf("Insertion d'un nouvelle élément : %lf ,%d\n",e.b,e.a);
        list->deb=ptr;
        list->crt=ptr;
        list->fin=ptr;
    }else{
        printf("La liste n'est pas vide\n");
        printf("Est-ce qu'on est à la fin ?\n");
        if(estFin(*list)){
            printf("Oui, on est à la fin\n");
            ptr->pred = list->fin;
            ptr->succ = list->fin->succ;
            list->fin = ptr;
        }else{
            if(estDebut(*list)){
                printf("Non, on est au debut\n");
                ptr->pred= list->deb->pred;
                ptr->succ= list->deb;
                list->deb = ptr;
            }else{
                printf("Ni à la fin, ni au début :On est quelque part dans la list\n");
                ptr->pred = list->crt->pred;
                ptr->succ = list->crt->succ;
                list->crt->succ->pred = ptr;
                list->crt->pred->succ = ptr;
                list->crt =list->crt->succ;
            }
        }
    }
}
void supprimer(ListeC *list){
    cellule2 *tmp,*tmp2;
    if(listeCVide(*list)){
        //On ne supprime rien si il n'y a rien 
        printf("Rien a supprimer \n");
    }else{
        //si il y'a quelque chose...
        //... est que le curseur est au début alors
        if(estDebut(*list)){
            //On garde en mémoire l'adresse de la cellule qui succède la cellule courante
            tmp = list->crt->succ;
            //On change en conséquence la cellule de début qui devient la cellule après la cellule courante 
            list->deb=tmp;
            //on remet bien le pointeur de cellule précéde la cellule du début à NULL
            tmp->pred=NULL;
            //On supprime la case courante
            free(list->crt);
            //La case courante devient la case qui succèdé la case courante
            list->crt = tmp;
        }else{
            //... est que le curseur est à la fin alors
            if(estFin(*list)){
                //On garde en mémoire l'adresse de la cellule qui précéde la cellule courante
                tmp = list->crt->pred;
                //On change en conséquence
                list->fin = tmp;
                //idem
                tmp->succ = NULL;
                //puis on libère
                free(list->crt);
                list->crt = tmp;
            }else{
                tmp = list->crt->pred;
                tmp2 = list->crt->succ;
                tmp->succ = tmp2;
                tmp2->pred = tmp;
                free(list->crt);
                list->crt = tmp2;
            }
        }
    }
}

Element valeurCourante(ListeC list){
    return list.crt->val;
}