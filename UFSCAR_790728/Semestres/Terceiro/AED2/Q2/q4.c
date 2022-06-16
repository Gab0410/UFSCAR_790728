/* 
NOME: Gabriel Meirelles Carvalho Orlando
RA: 790728
CURSO: Ciencia da Computação
DATA: XX/XX/2021
FLAGS: -std=c99 -Wall -Werror -Werror=vla -pedantic-errors -g -lm
*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10


void ordena(int v[],int n){

    int aux;
    int o = 0;
    for(int j=1;j<n;j++){
        aux = v[j];
        int i = j-1;

        while(i >= 0 && aux < v[i]){
            v[i+1] = v[i];
            i--;
            o++;
        }
        

        v[i+1] = aux;
    }

    printf("%d\n",o);

}

void imprime(int v[],int n){

    for(int i=0;i<n;i++){

        printf("%d ",v[i]);
    }
    printf("\n");
}

int busca(int v[],int n,int elemento){

    int index;
    for(int i=0;i<n;i++){
        if(v[i] == elemento){
            index = i;
            i = n+1;
        }
    }

    return index;
}

int main(){

    int v[SIZE+1];
    int j=0;
    for(int i=SIZE;i>=0;i--){
        v[j] = i;
        j++;
    }

    imprime(v,SIZE+1);
    ordena(v,SIZE+1);
    imprime(v,SIZE+1);
    

    
    //imprime(v,SIZE+1);

   /* clock_t t2 = clock();

    if(busca(v,SIZE+1,SIZE) == SIZE)
    t2 = clock() - t2;
    double tempo = ((double)t2)/((CLOCKS_PER_SEC/1000));
    printf("TEMPO = %.2lf segundos\n",tempo);
*/

    return 0;

}

//O(n) = 1.03 segundos