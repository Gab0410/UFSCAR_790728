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

typedef struct noh Noh;
struct noh{
    int rotulo;
    Noh *prox;
};


typedef struct grafo *Grafo;

struct grafo{

    Noh **A; //vetor de nós
    int n;
    int m;
};


int verticeAleatorio(Grafo G);
Grafo grafoAleatorio(int n,int m);;
Grafo grafoAleatorio2(int n,int m);

Grafo inicializaGrafo(int n);
void insereArcoGrafo(Grafo G,int v,int w);
void insereArcoNaoSeguraGrafo(Grafo G,int v,int w);
void removeArcoGrafo(Grafo G,int v,int w);
void imprimeArquivoGrafo(Grafo G, FILE *saida);
Grafo liberaGrafo(Grafo G);