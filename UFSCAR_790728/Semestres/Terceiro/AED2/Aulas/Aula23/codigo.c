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

void insereArcoNaoSeguraGrafo ( Grafo G , int v , int w ) {
    Noh * p ;
    p = malloc (sizeof( Noh ));
    p -> rotulo = w ;
    p -> prox = G -> A [ v ];
    G -> A [ v ] = p ;
    G -> m ++;
} 

//Coidog da busca em profundidade recursiva
void buscaProfOrdTopoR(Grafo G,int v,int *visitado,int *ordTopo,int *prot_atual){

    int w;
    Noh *p;

    //VErtice V acabou de ser visitado
    visitado[v] = 1;

    /*Para cada vizinho de v que ainda nao foi visitado*/
    for(p = G->A[v];p != NULL;p = p->prox){
        w = p->rotulo;
        if(visitado[w] == 0)//w nao foi visitado ainda
            buscaProfOrdTopoR(G,w,visitado,ordTopo,prot_atual);
    }

    ordTopo[v] = (*prot_atual)--;
}
void ordenacaoTopologica(Grafo G,int *ordTopo){

    int v, root_atual,*visitado;

    visitado = malloc(G->n * sizeof(int));

    for(v=0;v<G->n;v++){
        visitado[v] = 0;
        ordTopo[v] = -1;
    }

    root_atual = G->n;
    for(v=0;v<G->n;v++){
        if(visitado[v] == 0) //nao foi visitado
            buscaProfOrdTopoR(G,v,visitado,ordTopo,&root_atual);
    }

    free(visitado);
}

//Metodo
int verticeAleatorio(Grafo G){
    double r = (double)rand() / ((double)RAND_MAX+1.0);

    return (int)(r * G->n);
}

//Método 1
Grafo DAGaleatorio(int n,int m,int *perm){

    Grafo G = inicializaGrafo(n);

    while(G->m < m){
        int v = verticeAleatorio(G);
        int w = verticeAleatorio(G);

        //Verificar se o arco respeita a ordenação do DAG dada por perm[]
        if(perm[v] < perm[w])
            insereArcoGrafo(G,v,w);
    }

    return G;
}

//Método 2
Grafo DAGaleatorio2(int n,int m,int *perm){

    double prob = (double)m/n / (n-1) *2;
    Grafo G = inicializaGrafo(n);

    for(int v=0;v<n;v++){
        for(int w=0;w<n;w++){

            if(perm[v] < perm[w])
                if(rand() < prob * (RAND_MAX+1.0))
                    insereArcoNaoSeguraGrafo(G,v,w);
        }
    }

    return G;
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

//Troca a posição das variaveis na memoria
void troca(int *v,int *u){

    int aux;
    aux = *v;
    *v = *u;
    *u = aux;

    return;
}

//Embaralhamento de Knught
int uniformeAleat(int n){

    int r = ((double)rand() / (double)(RAND_MAX+1.0));

    return r*n;
}

//Knuth shuffle
int *permAleat(int *perm,int n){
    int i,j;

    for(i=0;i<n-1;i++){
        j = i + uniformeAleat(n-1);
        troca(&perm[i],&perm[j]);
    }

    return perm;
}


int main(){

    srand(time(NULL));

    int i,n,m;
    printf("Digite o numero de vertices e o numero de arcos: ");
    scanf("%d %d",&n,&m);
    printf("Criando as permutações\n");
    int *perm = malloc(n*sizeof(int));
    for(i=0;i<n;i++)
        perm[i] = i+1;
    perm = permAleat(perm,n);

    printf("Permutações criadas, grafo sera criado\n");

    Grafo G = inicializaGrafo(6);
    insereArcoGrafo(G,0,1);
    insereArcoGrafo(G,0,3);
    insereArcoGrafo(G,1,2);
    insereArcoGrafo(G,3,4);
    insereArcoGrafo(G,2,5);

    printf("O grafo tem %d vertices e %d arcos\n",G->n,G->m);

    FILE *arquivo = malloc(sizeof(FILE*));

    imprimeArquivoGrafo(G,arquivo);

    arquivo = NULL;
    free(arquivo);
    free(perm);

    int *ordTopo = malloc(6*sizeof(int));
    ordenacaoTopologica(G,ordTopo);

    for(int i=0;i<6;i++){

        printf("%d -> %d\n",i,ordTopo[i]);
    }



    return 0;

}




