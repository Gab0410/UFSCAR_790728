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

#define SIZE 100000

void intercala1(int v[],int p,int q,int r){

    int i,j,k,tam;

    i=p; j=q; k=0; tam = r-p;
    int *w = malloc(tam*sizeof(int));
    if(!w){
        printf("DEU MERDA\n");
        exit(1);
    }

    while(i<q && j < r){

        if(v[i] <= v[j])//Caso o valor do primeiro subvetor seja menor que o do segundo, entao k aumenta, e i também
            w[k++] = v[i++];
        else//Caso o valor do segundo subvetor seja menor que o do primeiro, entao k aumenta, e j também
            w[k++] = v[j++];
    }

    while(i<q){ w[k++] = v[i++];} //Serve para colocar o restante do subvetor, caso j tenha terminado antes de i
    while(j<r){w[k++] = v[j++];} //Serve para colocar o restante do subvetor, caso i tenha terminado antes de j

    //Passa todos os valores do vetor V para o vetor w
    for(k=0;k<tam;k++)
        v[p+k] = w[k];

    //Libera o vetor w
    free(w);
}

void intercala2(int v[], int p, int q, int r) {
    int i, j, k, *w;
    w = malloc((r - p) * sizeof(int));

    for (i = p; i < q; ++i)
        w[i - p] = v[i];

    for (j = q; j < r; ++j)
        w[(r - p - 1) - (j - q)] = v[j];

    i = 0;
    j = r - p - 1;

    for (k = p; k < r; ++k)

        if (w[i] <= w[j])
            v[k] = w[i++];
            
        else
            v[k] = w[j--];


    free(w);
}

void mergeSortR(int v[],int p,int r){

    int m;
    if(p < r-1){
        m= (p+r+1)/2;

        mergeSortR(v,p,m);
        mergeSortR(v,m,r);
        intercala1(v,p,m,r);
    }

    return;
}

int verifica(int vetor[],int n){

    for (int i = 1; i < n; i++) {
        if (vetor[i - 1] > vetor[i]) {
            return 0;
        }
    }
    return 1;
}

int main(){

    int v[SIZE];

    srand(time(NULL));
    for(int i=0;i<SIZE;i++){
        v[i] = rand() % RAND_MAX;
    }


    printf("Vamos começar\n");
    clock_t t = clock();

    mergeSortR(v,0,SIZE);

    t = clock()-t;
    double tempo = ((double)t)/((CLOCKS_PER_SEC/1000));
    printf("TEMPO = %.2lf segundos\n",tempo);

    printf("%d\n",verifica(v,SIZE));


    return 0;
}