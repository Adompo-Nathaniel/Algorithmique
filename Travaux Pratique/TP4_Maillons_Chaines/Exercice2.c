#include <stdio.h>
#include <stdlib.h>
#define MAX 100

#define MAX_N 100
#define MAX_M 100
long long memo[MAX];
long long memo2[MAX_M + 1][MAX_N + 1];
int fibo(int n);
int fibo2(int n);

int acker(int m,int n);
int acker2(int m,int n);

int main(){
    for(int i = 0; i < MAX; i++) {
        for(int j = 0; j < MAX; j++ ){
            memo2[i][j] = 0;
        }
    }
    int n,m;
    printf("Entrez un chiffre:\n");
    scanf("%d",&n);
    //n=fibo(n);
    //n=fibo2(n);
    printf("Entrez une autre valeur:\n");
    scanf("%d",&m);
    n=acker2(m,n);
    //n=acker2(m,n);
    printf("Voici le résultat=%d\n",n);    
    return 0;
}

int fibo(int n){
    if(n==0){
        return 0;
    }
    if(n==1){
        return 1;
    }
    if(n>=2){
        return fibo(n-1) + fibo(n-2);
    }
}
int fibo2(int n){
    if (n <= 1) {
        return n;
    }
    if (memo[n] != -1) {
        return memo[n];
    }
    memo[n] = fibo2(n - 1) + fibo2(n - 2);
    return memo[n];
}
int acker(int m,int n){
    if(m==0){
        return n+1;
    }
    if((m>0)&&(n==0)){
        return acker(m-1,1);
    }
    if((m>0)&&(n>0)){
        return acker(m-1,acker(m,n-1));
    }
}
int acker2(int m,int n){
    if(m==0){
        return n+1;
    }
    if(memo2[m][n] != 0){
        return memo2[m][n];
    }
    if((m>0)&&(n==0)){
        memo2[m][n]= acker2(m-1,1);
        return memo2[m][n];
    }
    if((m>0)&&(n>0)){
        memo2[m][n]= acker2(m-1,acker2(m,n-1));
        return memo2[m][n];
    } 
}