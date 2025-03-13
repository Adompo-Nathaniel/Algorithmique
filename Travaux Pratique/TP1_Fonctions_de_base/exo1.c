#include <stdio.h>
#include <stdlib.h>

char* mon_atoi_a_moi(char * mot);
int main(void){
    char string[] ="Bonjour 12, je suis 47";
    char *p=mon_atoi_a_moi(string);
    for()
    int i = 0;

    return 0;
}
char* mon_atoi_a_moi(char * mot){
    int number,etat;
    etat =0;
    char *tab1;
    int i=0;
    while(mot[i]!="\0"){
        if(mot[i]>="1" || mot[i]<="9"){
            if(etat==0){
               number=mot[i];
                etat=1;
            }
            if(etat == 1){
                number+=mot[i]*10;
            }
        }
        if(etat==3){
            exit(EXIT_SUCCESS);
        }
    }
}
