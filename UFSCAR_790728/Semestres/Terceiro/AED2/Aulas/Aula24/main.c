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

//Inicializa o grafo cm a ordem de O(n)
Grafo inicializaGrafo(int n){

    int i;
    Grafo G = malloc(sizeof *G);

    G->n = n;
    G->m = 0;

    G->A = malloc(n * sizeof(Noh *));

    for(i=0;i<n;i++)
        G->A[i] = NULL;

    return G;
}

//Insere no grafo
void insereArcoGrafo(Grafo G,int v,int w){

    Noh *p;
    for(p = G->A[v];p != NULL;p = p->prox)
        if(p->rotulo == w)
            return;//vertice ja existe

    p = malloc(sizeof(Noh));
    p->rotulo = w;

    p->prox = G->A[v];
    G->A[v] = p;

    G->m++;
}

void imprimeArquivoGrafo(Grafo G,FILE *saida){
    int i;
    Noh *p;
    saida = fopen("grafo.txt","wb+");

    fprintf(saida,"Nro vertices: %d\nNro arcos: %d\n",G->n,G->m);

    for(i=0;i<G->n;i++){
        fprintf(saida,"%d:",i);
        for(p = G->A[i];p != NULL;p = p->prox)
            fprintf(saida," %d",p->rotulo);
        fprintf(saida," -1");
        fprintf(saida,"\n");
    }
    fclose(saida);
}

void buscaProfTempTermR(Grafo G,int v,int *visitado,int *tempTerm,int *tempo){

    visitado[v] = 1;
    int w;
    Noh *p;
    p = G->A[v];
    while(p != NULL){
        w = p->rotulo;
        if(visitado[w] == 0)
            buscaProfTempTermR(G,w,visitado,tempTerm,tempo);
        
        p = p->prox;
    }   

    tempTerm[*tempo] = v;//saber qual o maior tempo de término, dessa forma, é desnecessário ordenar esse vetor
    (*tempo)++;

}
void loopBuscaProfTempoTerm(Grafo G,int *tempTerm){
    int v,tempo,*visitado;

    visitado = malloc(G->n*sizeof(int));

    for(v=0;v<G->n;v++){
        visitado[v] = 0;
        tempTerm[v] = -1;
    }

    tempo = 0;
    for(v=0;v<G->n;v++){
        if(visitado[v] == 0)
            buscaProfTempTermR(G,v,visitado,tempTerm,&tempo);
    }

    free(visitado);
}

void buscaProfIdentCompR(Grafo G, int v, int *comp, int num_comp) {
    int w;
    Noh *p;
    comp[v] = num_comp; // coloca v no componente atual

    // para cada vizinho de v que ainda não foi visitado

    p = G->A[v];
    while (p != NULL) {
        w = p->rotulo;

        if (comp[w] == -1)
            buscaProfIdentCompR(G, w, comp, num_comp);

        p = p->prox;
    }
}

void loopBuscaProfIdentComp(Grafo G, int *tempoTermino, int *comp) {
    int v, i, num_comp;
    // inicializa todos como não pertencentes
    for (v = 0; v < G->n; v++)
        comp[v] = -1;
    
    num_comp = 0;

    // inicia buscas a partir de vértices não visitados
    // seguindo a ordem decrescente dos tempos de término
    for (i = G->n - 1; i >= 0; i--) {

        v = tempoTermino[i];

        if (comp[v] == -1) {
            num_comp++;
            buscaProfIdentCompR(G, v, comp, num_comp);
        }
    }
}

Grafo liberaGrafo(Grafo G){
    int i;
    Noh *p;
    for(i=0;i<G->n;i++){
        p = G->A[i];
        while(p != NULL){
            G->A[i] = p;
            p = p->prox;
            free(G->A[i]);
        }
        G->A[i] = NULL;
    }
    free(G->A);
    G->A = NULL;
    free(G);
    return NULL;
}

void identCompForteConexo(Grafo G, int *comp) {

    int u, v, *tempoTermino;
    Noh *p;
    Grafo Grev;
    Grev = inicializaGrafo(G->n);

    // reverte os arcos do grafo G
    for (u = 0; u < G->n; u++) {
        p = G->A[u];
        while (p != NULL) {
            v = p->rotulo;
            insereArcoGrafo(Grev, v, u);
            p = p->prox;
        }
    }

    
    tempoTermino = malloc(G->n * sizeof(int));

    loopBuscaProfTempoTerm(Grev, tempoTermino);

    for(int i=0;i<Grev->n;i++)
        printf("%d -> %d\n",i,tempoTermino[i]);

    Grev = liberaGrafo(Grev);

    loopBuscaProfIdentComp(G, tempoTermino, comp);
    free(tempoTermino);
}


int main(){


    Grafo G = inicializaGrafo(11);

    insereArcoGrafo(G,0,1);

    insereArcoGrafo(G,1,2);

    insereArcoGrafo(G,2,0);

    insereArcoGrafo(G,1,3);

    insereArcoGrafo(G,3,8);

    insereArcoGrafo(G,3,9);

    insereArcoGrafo(G,2,5);

    insereArcoGrafo(G,2,4);

    insereArcoGrafo(G,5,7);

    insereArcoGrafo(G,7,6);

    insereArcoGrafo(G,5,6);

    insereArcoGrafo(G,6,4);

    insereArcoGrafo(G,4,5);

    insereArcoGrafo(G,5,8);

    insereArcoGrafo(G,7,10);

    insereArcoGrafo(G,10,8);

    insereArcoGrafo(G,8,9);

    insereArcoGrafo(G,9,10);
   



    printf("O grafo tem %d vertices e %d arcos\n",G->n,G->m);

    FILE *arquivo = malloc(sizeof(FILE*));


    imprimeArquivoGrafo(G,arquivo);


    int *comp = malloc(G->n*sizeof(int));


    identCompForteConexo(G,comp);


    imprimeArquivoGrafo(G,arquivo);

    arquivo = NULL;
    free(arquivo);

    for(int i=0;i<G->n;i++){
        printf("Vertice %d está na componente de numero %d\n",i,comp[i]);
    }




    return 0;
}