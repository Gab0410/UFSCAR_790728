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

void troca(int *v,int *u){

    int aux;
    aux = *v;
    *v = *u;
    *u = aux;

    return;
}

int separa1(int v[],int p,int r){

    int i=p,j=r-1,c=v[r];//c é o pivo
    int continua = 1;
    while(continua){

        while(i < r && v[i] <= c) i++;
        while(j>i && v[j] > c) j--;

        if(i >= j)
            continua = 0;
        if(continua)
            troca(&v[i],&v[j]);
    }

    troca(&v[i],&v[r]);
    return i;
}

int separa2(int v[], int p, int r) {
    int i, j, c = v[r]; // c é o pivô
    i = p;
    for (j = p; j < r; j++)
        
        if (v[j] <= c) {
            troca(&v[i], &v[j]);
                i++;
        }

    troca(&v[i], &v[r]);
    return i;
}

void quickSortR(int v[],int p,int r){

    int i;
    if(p < r){
        i = separa1(v,p,r);//i é posicao do pivo apos a separação

        quickSortR(v,p,i-1);
        quickSortR(v,i+1,r);
    }
}

void quickSortRAleat( int v [] , int p , int r ){
    int desl , i ;
    if ( p < r ) {
        //desl = rand() % (r - p + 1);
        double k = RAND_MAX;
        k = k+1;
        desl = ( int )(((rand () / k)) * ( double )( r- p + 1 ));

       
        troca (& v [ p + desl ], & v [ r ]);
        i = separa2 ( v , p , r );
        quickSortRAleat ( v , p , i-1 );
        quickSortRAleat ( v , i+1, r );
        
    }
} 

void imprimeVetor(int v[],int tam){

    for(int i=0;i<tam;i++){
        printf("%d,",v[i]);
    }
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
    quickSortRAleat(v,0,SIZE);
    t = clock()-t;

    double tempo = ((double)t)/((CLOCKS_PER_SEC/1000));
    printf("TEMPO = %.2lf segundos\n",tempo);

   // imprimeVetor(v,SIZE);
   printf("%d\n",verifica(v,SIZE));

    return 0;
}