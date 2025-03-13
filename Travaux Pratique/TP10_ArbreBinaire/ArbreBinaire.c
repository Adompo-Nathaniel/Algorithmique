#include <stdlib.h>
#include <stdio.h>

#include "ArbreBinaire.h"

//On cherche le minimum, or le minimum est la valeur la plus à gauche de l'ABR,
// on va donc à gauche jusqu'à ce qu'il n'y est plus de noeud
Noeud* Minimum(ABR abr){
    printf("On cherche la plus petite valeur dans l'arbre\n");
    Noeud *tmp=abr;
    if(tmp != NULL){
        while(tmp!= NULL){
            tmp = abr->filsG;
        }
    }
    return tmp;
}

//Exactement pareil que pour le minimum, à la différence que ici on va à droite
Noeud* Maximum(ABR abr){
    printf("On cherche la plus grande valeur dans l'arbre\n");
    Noeud *tmp=abr;
    if(tmp != NULL){
        while(tmp != NULL){
            tmp = abr->filsD;
        }
    }
    return tmp;
}

Noeud* ABR_recherche(ABR a,int cle){
    printf("On recherche la valeur : %d\n",cle);
    if(a == NULL){
        return NULL;
    }else{
        if(a->cle == cle){
            return a;
        }else{
            if(a->cle > cle){
                return ABR_recherche(a->filsD,cle);
            }else{
                return ABR_recherche(a->filsG,cle);
            }
        }
    }
}

Noeud* ABR_predececeur(ABR abr,Noeud* noeud){
    if(noeud == NULL){
        return NULL;
    }else{
        if(noeud->filsG != NULL){
            return ABR_Maximum(noeud->filsG);
        }else{
            while (noeud->pere->filsG == noeud){
                noeud = noeud->pere;
            }
            return noeud->pere;
        }
    }
}

Noeud* ABR_succeseur(ABR abr,Noeud* noeud){
    if(noeud == NULL){
        return NULL;
    }else{
        if(noeud->filsD !=NULL){
            return ABR_Minimum(noeud->filsD);
        }else{
            while(noeud->pere->filsD == noeud){
                noeud = noeud->pere->filsD;
            }
            return noeud->pere;
        }
    }
}




void Supprimer(ABR* abr,Noeud* noeud){
    
    if(noeud == NULL){
        return;
    }

    if((noeud->filsD== NULL) && (noeud->filsG ==NULL)){
        printf("Cas avec aucun fils\n");
        if(noeud->pere ==NULL){
            printf("Je suis la racine \n");
            abr=NULL;
            free(noeud);
        }else if(noeud == noeud->pere->filsD){
            printf("Je suis le SAD\n");
            noeud->pere->filsD=NULL;
            free(noeud);
        }else{
            printf("Je suis le SAG\n");
            noeud->pere->filsG=NULL;
            free(noeud);
        }
    
    }else{
        printf("Cas avec un unique fils\n");
        if((noeud->filsD != NULL )&&(noeud->filsG == NULL)){
            printf("Son unique fils est à droite\n");
            if(noeud == noeud->pere->filsD){
                printf("Je suis le fils droit de mon père\n");
                Noeud *tmp1 = noeud->filsD;
                Noeud *tmp2 = noeud->pere;
                tmp2->filsD=tmp1;
                tmp1->pere=tmp2;
                free(noeud);
            }else{
                printf("Je suis le fils gauche de mon père\n");
                Noeud *tmp1 = noeud->filsG;
                Noeud *tmp2 = noeud->pere;
                tmp2->filsD=tmp1;
                tmp1->pere=tmp2;
                free(noeud);
            }
        }else{
            if((noeud->filsD == NULL )&&(noeud->filsG != NULL)){
                printf("Son unique fils est à gauche\n");
                if(noeud == noeud->pere->filsD){
                    printf("Je suis le fils droit de mon père\n");
                    Noeud *tmp1 = noeud->filsD;
                    if(noeud->pere ==NULL){
                        return;
                    }
                    Noeud *tmp2 = noeud->pere;

                    tmp2->filsD=tmp1;
                    tmp1->pere=tmp2;
                    free(noeud);
                }else{
                    printf("Je suis le fils gauche de mon père\n");
                    Noeud *tmp1 = noeud->filsG;
                    if(noeud->pere ==NULL){
                        return;
                    }
                    Noeud *tmp2 = noeud->pere;
                    tmp2->filsD=tmp1;
                    tmp1->pere=tmp2;
                    free(noeud);
                }
            }else{
                printf("Cas ou il y'a 2 fils\n");
                if((noeud->filsD != NULL )&&(noeud->filsG != NULL)){
                    printf("Je cherche mon succeseur\n");
                    Noeud* succ = ABR_succeseur(*abr,noeud);
                    noeud->cle= succ->cle;
                    Supprimer(*abr,succ);
                }
            }
        }
    }
}
void Ajouter(ABR *pabr,int*val){
    pabr=(Noeud*)malloc(sizeof(Noeud*));
    if(pabr == NULL){
        (*pabr)->filsD=NULL;
        (*pabr)->filsG=NULL;
        (*pabr)->pere=NULL;
        (*pabr)->cle=val;
    }else if( (*pabr) > val){
        Ajouter(&((*pabr)->filsD),val);
        (*pabr)->pere= (*pabr)->pere->filsD;
    }else{
        Ajouter(&((*pabr)->filsG),val);
        (*pabr)->pere=(*pabr)->pere->filsG;
    }
}
void AffichagePrefixe(ABR* abr);
void AffichageInfixe(ABR* abr);
void AffichagePostfixe(ABR* abr);