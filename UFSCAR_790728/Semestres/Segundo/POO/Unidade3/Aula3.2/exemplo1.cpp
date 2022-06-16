#include <iostream>
#include <stdlib.h>
#include<malloc.h>


int main(){
    int *p;
    p = (int*)malloc(10*sizeof(int)); //como malloc retorna um um valor do tipo void*, deve se converter
    //para (int*)

    int *inicio = p;

    for(int i=0;i<10;i++)
        p[i] = i;
    p = inicio;
    for(int j=0;j<10;j++){
        printf("%d\n",*p);
        p++; // o endereço que de memoria que esta alocado o numero i, é increnmentando em 1
    }

    p = inicio;
    printf("Posição inicial: %p\n",inicio);
    free(p);

}