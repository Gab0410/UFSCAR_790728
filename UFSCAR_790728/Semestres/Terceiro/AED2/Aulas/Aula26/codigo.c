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


typedef struct noh Noh;
struct noh{
    int rotulo;
    int custo;
    Noh *prox;
};


typedef struct grafo *Grafo;

struct grafo{

    Noh **A; //vetor de nós
    int n;
    int m;
};

typedef struct fila{

    int *vetor;
    int tamanho;
    int elementos;

}Fila;

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
void insereArcoGrafo(Grafo G,int v,int w,int custo){

    Noh *p;
    for(p = G->A[v];p != NULL;p = p->prox)
        if(p->rotulo == w)
            return;//vertice ja existe

    p = malloc(sizeof(Noh));
    p->rotulo = w;
    p->custo = custo;

    p->prox = G->A[v];
    G->A[v] = p;

    G->m++;
}
//Coidog da busca em profundidade recursiva
void buscaProfOrdTopoR(Grafo G,int v,int *visitado,int *ordTopo,int *prot_atual){

    int w;
    Noh *p;

    //VErtice V acabou de ser visitado
    visitado[v] = 1;

    p = G->A[v];
    /*Para cada vizinho de v que ainda nao foi visitado*/
    while(p != NULL){
        w = p->rotulo;
        if(visitado[w] == 0)
            buscaProfOrdTopoR(G,w,visitado,ordTopo,prot_atual);
        
        p = p->prox;
    }

    ordTopo[*prot_atual] = v;
    (*prot_atual)--;
}
void ordenacaoTopologica(Grafo G,int *ordTopo){

    int v, root_atual,*visitado;

    visitado = malloc(G->n * sizeof(int));

    for(v=0;v<G->n;v++){
        visitado[v] = 0;
    }

    root_atual = G->n;

    for(v=0;v<G->n;v++){
        if(visitado[v] == 0) //nao foi visitado
            buscaProfOrdTopoR(G,v,visitado,ordTopo,&root_atual);
    }

    free(visitado);
}

void distanciasDAG(Grafo G,int origem,int *dist,int *pred){
    int i, *ordTopo;
    int v,w,custo;

    Noh *p;

    for(i=0;i<G->n;i++){
        dist[i] = __INT_MAX__-1000;
        pred[i] = -1;
    }

    dist[origem] = 0;
    ordTopo = malloc((G->n+1) * sizeof(int));
    ordenacaoTopologica(G,ordTopo);

    for(i=1;i<=G->n;i++){
        v = ordTopo[i];
        p = G->A[v];
        while(p != NULL){
            w = p->rotulo;

            custo = p->custo;
            if(dist[w] > dist[v] + custo){
                dist[w] = dist[v] + custo;
                pred[w] = v;
            }

            p = p->prox;
        }
    }

    free(ordTopo);
}

void imprimeGrafo(Grafo G){
    int i;
    Noh *p;

    printf("%d %d\n",G->n,G->m);

    for(i=0;i<G->n;i++){
        printf("%d:",i);
        for(p = G->A[i];p != NULL;p = p->prox)
            printf(" %d",p->rotulo);
        printf("\n");
    }
}

int main(){

    Grafo G = inicializaGrafo(8);

    //a=0,b=1,c=2,d=3,e=4,f=5,g=6,h=7

    insereArcoGrafo(G,0,1,1);
    insereArcoGrafo(G,0,4,4);
    insereArcoGrafo(G,0,5,8);


    insereArcoGrafo(G,1,2,2);
    insereArcoGrafo(G,1,6,6);
    insereArcoGrafo(G,1,5,6);


    insereArcoGrafo(G,2,3,1);
    insereArcoGrafo(G,2,6,2);

    insereArcoGrafo(G,3,6,1);
    insereArcoGrafo(G,3,7,4);

    insereArcoGrafo(G,4,5,5);

    insereArcoGrafo(G,6,5,1);
    insereArcoGrafo(G,6,7,1);

    imprimeGrafo(G);

    int *dist,*pred;

    dist = malloc(G->n*sizeof(int));
    pred = malloc(G->n*sizeof(int));

    int origem = 2;

    distanciasDAG(G,origem,dist,pred);

    for(int i=0;i<G->n;i++){
        if(dist[i] == __INT_MAX__-1000)
            printf("%d -> infinito\n",i);
        else
        printf("%d -> %d\n",i,dist[i]);
    }
    
    printf("\n");

    for(int i=0;i<G->n;i++){
        printf("%d -> %d\n",i,pred[i]);
    }

    return 0;
    


}