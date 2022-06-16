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
#include <string.h>
#include <math.h>

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

    fprintf(saida,"%d %d\n",G->n,G->m);

    for(i=0;i<G->n;i++){
        fprintf(saida,"%d:",i);
        for(p = G->A[i];p != NULL;p = p->prox){
            
            if(p->prox != NULL)
                fprintf(saida,"%d ",p->rotulo);
            else
                fprintf(saida,"%d",p->rotulo);
        }
        fprintf(saida,"\n");
    }
    fclose(saida);
}

void imprimeGrafo(Grafo G){
    int i;
    Noh *p;

    printf("%d %d\n",G->n,G->m);

    for(i=0;i<G->n;i++){
        printf("%d:",i);
        for(p = G->A[i];p != NULL;p = p->prox)
            printf("%d ",p->rotulo);
        printf("\n");
    }
}

Fila* criaFila(int n){

    Fila *nova = malloc(sizeof(Fila*));
    nova->tamanho = n;
    nova->elementos = 0;
    nova->vetor = malloc(sizeof(int)*n);

    return nova;
}

int filaCheia(Fila *fila){

    return fila->tamanho == fila->elementos;
}
void insereFila(Fila *fila,int valor){

    if(filaCheia(fila))
        return;
    
    int pos_insercao = fila->elementos;
    fila->vetor[pos_insercao] = valor;

    fila->elementos++;
}
int filaVazia(Fila *fila){

    return fila->elementos == 0;
}

int removeFila(Fila *fila){

    if(filaVazia(fila))
        return -1;
    
    //Remover o inicio, diminuir 1 elemento, e reorganizar a fila
    int removido = fila->vetor[0];
    int i=1;
    while(i < fila->elementos){
        fila->vetor[i-1] = fila->vetor[i];
        i++;
    }
    fila->elementos--;

    return removido;
}

Fila* liberaFila(Fila *fila){

    if(fila == NULL)
        return NULL;

    free(fila->vetor);
    free(fila);

    return fila;
}

void mostraFila(Fila *fila){

    for(int i=0;i<fila->elementos;i++){
        if(i==fila->elementos-1)
            printf("%d\n",fila->vetor[i]);
        else
            printf("%d ",fila->vetor[i]);
    }
}
int *distancias(Grafo G, int origem) {

    int v, w, *dist;

    Fila *fila;
    Noh *p;

    dist = malloc(G->n * sizeof(int));

    fila = criaFila(G->n);


    /* inicializa todos como não encontrados, exceto pela origem */
    for (v = 0; v < G->n; v++)
        dist[v] = -1;
    
    dist[origem] = 0;

    insereFila(fila, origem);


    while (!filaVazia(fila)) {

        v = removeFila(fila);

        /* para cada vizinho de v que ainda não foi encontrado */
        p = G->A[v];
        while (p != NULL) {

            w = p->rotulo;

            if (dist[w] == -1) {
                /* calcule a distância do vizinho e o coloque na fila */
                dist[w] = dist[v] + 1;
                insereFila(fila, w);
            }

            p = p->prox;
        }
    }

    
    fila = liberaFila(fila);
    return dist;
}
void insereArcoNaoSeguraGrafo ( Grafo G , int v , int w ) {

    Noh * p ;
    p = malloc (sizeof( Noh ));
    p -> rotulo = w ;
    p -> prox = G -> A [ v ];
    G -> A [ v ] = p ;
    G -> m ++;
} 

Grafo lerGrafoMostra(FILE *entrada) {
    int n, m, v, w, tam;
    Grafo G;
    char *str, *aux;

    fscanf(entrada, "%d %d\n", &n, &m);

    G = inicializaGrafo(n);

    tam = ((G->n * ((int)log10((double)G->n) + 1)) + 3) * sizeof(char); 

    str = malloc(tam);

    for (v = 0; v < G->n; v++) {

        fgets(str, tam, entrada);
        
        aux = strtok(str, ":");
        aux = strtok(NULL, " \n");

        while (aux != NULL) {
            w = atoi(aux);
            insereArcoNaoSeguraGrafo(G, v, w);
            aux = strtok(NULL, " \n");
        }
        
    }
    free(str);
    return G;
}


//Função auxiliar para ler grafo do arquivo

int main(){

    Grafo G = inicializaGrafo(6);

    int l0[3] = {2,4,3};
    int l2[2] = {4,1};
    int l3[2] = {4,5};
    int l4[3] = {0,1,5};
    int l5 = 1;
    int l1 = 5;

    for(int i=0;i<3;i++)
        insereArcoGrafo(G,0,l0[i]);

    for(int i=0;i<1;i++)
        insereArcoGrafo(G,1,l1);
    
    for(int i=0;i<2;i++)
        insereArcoGrafo(G,2,l2[i]);

    for(int i=0;i<2;i++)
        insereArcoGrafo(G,3,l3[i]);

    for(int i=0;i<3;i++)
        insereArcoGrafo(G,4,l4[i]);

    for(int i=0;i<3;i++)
        insereArcoGrafo(G,5,l5);


    int *v = malloc(G->n * sizeof(int));

    v = distancias(G,0);

    for(int i=0;i<G->n;i++)
        printf("%d -> %d\n",i,v[i]);


    printf("O grafo tem %d vertices e %d arcos\n",G->n,G->m);

    FILE *arquivo = malloc(sizeof(FILE*));


    imprimeArquivoGrafo(G,arquivo);

    arquivo = fopen("grafo.txt","r");
    Grafo G2 = lerGrafoMostra(arquivo);
    fclose(arquivo);

    imprimeGrafo(G2);

    return 0;

}
