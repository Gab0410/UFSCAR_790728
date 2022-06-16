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

#define TAMMAX 10

typedef struct arvb{

    int ordem;
    int elems;
    int info[TAMMAX+1];
    struct arvb *filhos[TAMMAX+2];
}ArvB;

ArvB *ArvBCria(int ordem);
int ArvBDestroi(ArvB **arvore);
int ArvBBusca(ArvB *arvore,int valor);
int ArvBInsereRec(ArvB **arvore,ArvB **aux,int *valor,int *quebrou);
int ArvBRemoveRec(ArvB **arv,int chave,int *underflow);