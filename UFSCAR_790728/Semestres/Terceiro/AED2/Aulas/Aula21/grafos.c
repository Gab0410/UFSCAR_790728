#include "grafos.h"

//Constroi um gafo com vertices 0 1... n-1 e nenhum arco

Grafo inicializaGrafo ( int n ) {
    int i , j ;
    Grafo G = malloc (sizeof * G );
    G -> n = n ;
    G -> m = 0 ;
    G -> A = malloc ( n * sizeof( int *));
    for ( i = 0 ; i < n ; i ++)
        G -> A [ i ] = malloc ( n * sizeof( int ));
    for ( i = 0 ; i < n ; i ++)
        for ( j = 0 ; j < n ; j ++)
            G -> A [ i ][ j ] = 0 ;
    return G ;
} 

/*Insere arco v-w no grafo G, suponde que v e w são inteiros, distintos entre 0 e n-1, se o grafo já tem o arco v-w não faz nada
*/

void insereArcoGrafo(Grafo G,int v,int w){
    if(G->A[v][w] == 0){
        G->A[v][w] = 1;
        G->m++;
    }
}

//Versão da insereArcoCrafo que nao testa se v-w já está presente
void insereArcoNaoSeguraGrafo(Grafo G,int v,int w){

    G->A[v][w] = 1;
    G->m++;
}

//Remoção de um arco v-w
void removeArcoGrafo(Grafo G,int v,int w){
    if(G->A[v][w] == 1){
            G->A[v][w] = 0;
            G->m--;
    }
}

//Imprime cada vertice v, os vertices adjacentes a v
void mostraGrafo ( Grafo G ) {
    int i , j ;
    for ( i = 0 ; i < G->n ; i ++) {
        printf (" %2d : ", i );
        for ( j = 0 ; j < G -> n ; j ++)
            if ( G -> A [ i ][ j ] == 1 )
                printf (" %2d ", j );
        printf ("\n");
    }
} 

Grafo liberaGrafo(Grafo G){

    int i;
    for(i=0;i<G->n;i++){
        free(G->A[i]);
        G->A[i] = NULL;
    }

    free(G->A);
    G->A = NULL;
    free(G);
    return NULL;
}

int verticeAleatorio(Grafo G){

    double r;
    r = (double)rand() / ((double)RAND_MAX + 1.0);

    return (int)(r*G->n); //retorna um vertice aleatorio de G, tal que G->n <= RAND_MAX
}


//Cria um grafo aleatorio com m arcos
Grafo grafoAleatorio(int n,int m){

    Grafo G = inicializaGrafo(n);
    while(G->m < m){
        int v = verticeAleatorio(G);
        int w = verticeAleatorio(G);

        if(v != w)
            insereArcoGrafo(G,v,w);
    }

    return G;
}

Grafo grafoAleatorio2(int n,int m){
    int v,w;
    double prob = (double)m/ n / (n-1);

    Grafo G = inicializaGrafo(n);

    for(v=0;v<n;v++)
        for(w=0;w<n;w++)
            if(v != w)
                if(rand() < prob * (RAND_MAX + 1.0))
                    insereArcoGrafo(G,v,w);

    return G;
}
//Matriz de adjacencia
void buscaProfR(Grafo G,int origem,int *ordem_chegada,int *ordem_saida,int *tempo){

    int w;
    ordem_chegada[origem] = (*tempo)++;

    //Para cada vizinho de v que ainda não foi visitado
    for(w=0;w<G->n;w++){
        if(G->A[origem][w] == 1 && ordem_chegada[w] == -1)
            buscaProfR(G,w,ordem_chegada,ordem_saida,tempo);
    }

    ordem_saida[origem] = (*tempo)++;

}

void buscaProf(Grafo G,int origem,int *ordem_chegada,int *ordem_saida){

    int i,tempo;
    //Inicializa como não encontrados, com tempo linear no número de vértices
    for(i=0;i<G->n;i++){
        ordem_chegada[i] = -1;
        ordem_saida[i] = -1;
    }

    tempo = 1;
    buscaProfR(G,origem,ordem_chegada,ordem_saida,&tempo);
}


int main(){

    srand(time(NULL));
    Grafo G = grafoAleatorio(50,100);


    mostraGrafo(G);
    int m = G->m;
    while(G->m == m){
        int v = verticeAleatorio(G);
        int w = v;
        while(v == w)
            w = verticeAleatorio(G);
        
        printf("Removendo o arco (%d,%d)\n",v,w);
        removeArcoGrafo(G,v,w);
    }

    mostraGrafo(G);

    int *ordem_chegada = malloc(sizeof(int) * G->n);
    int *ordem_saida = malloc(sizeof(int) * G->n);
   
    buscaProf(G,0,ordem_chegada,ordem_saida);
    for(int i=0;i<G->n;i++)
        printf("%d -> (%d,%d)\n",i,ordem_chegada[i],ordem_saida[i]);
    G = liberaGrafo(G);

    return 0;
}