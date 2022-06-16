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


/*O objetivo desse algoritmo é encontrar o valor do caminho mínimo de s até cada vértice v em V, isto é, a distância de s a v, e também é util que os caminhos
mínimos fossem devolvidos*/

void Dijkstra(Grafo G,int origem,int *dist,int *pred){

    int i,*R;
    int v,w, custo, tam_R,min_dist;

    Noh *p;

    //Inicizalizando distancias e predecessores
    for(i =0;i<G->n;i++){
        dist[i] = __INT_MAX__-1000;
        pred[i] = -1;
    }

    dist[origem] = 0;
    R = malloc(sizeof(int)*G->n);

    for(i=0;i<G->n;i++){
        R[i] = 0;
    }

    tam_R = 0;

    //Enquanto nao encontrar o caminho mínimo para todo vértice

    while(tam_R < G->n){

        //Buscando vertice v em V/ R que minimiza  dist[v]
        min_dist = __INT_MAX__-1000;

        v = -1;

        for(i=0;i<=G->n;i++)
            if(R[i] == 0 && dist[i] < min_dist){
                v = i;
                min_dist = dist[i];
            }

        //Adicionando v a R e atualizando o conjunto R
        R[v] = 1; tam_R++;

        //Percorrer a lista com vizinhos de v
        p = G->A[v];

        while(p != NULL){
            w = p->rotulo;
            custo = p->custo;

            //atualiza as distancias e predecessores quando for o caso
            if(R[w] == 0 && dist[w] > dist[v] + custo){
                dist[w] = dist[v] + custo;
                pred[w] = v;
            }

            p = p->prox;
        }
    }

    free(R);
}

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

    int *distancias = malloc(sizeof(int)*8);
    int *pred = malloc(sizeof(int)*8);

    Dijkstra(G,0,distancias,pred);

    for(int i=0;i<G->n;i++){

        printf("%d -> dist = %d || pred = %d\n",i,distancias[i],pred[i]);
    }
    int origem,chegada;

    printf("Vertice de origem: ");
    scanf("%d",&origem);
    printf("Vertice de chegada: ");
    scanf("%d",&chegada);

    printf("Qual o menor caminho de %d ate %d:\n",origem,chegada);

    int i = chegada;

    int *caminho = malloc(sizeof(int)*100);
    int contador=0;
    while(i != pred[origem]){

        caminho[contador] = i;
        i = pred[i];
        contador++;

        if(contador == 100){
            printf("Nao ha caminho existente entre esses dois vértices\n");
            contador=-1;
            return 0;
        }
    }

    caminho[contador-1] = origem;

    for(int j=contador-1;j>=0;j--)
        if(j == 0)
            printf("%d\n",caminho[j]);
        else
        printf("%d -> ",caminho[j]);
}