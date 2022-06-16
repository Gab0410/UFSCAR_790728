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

typedef struct elem {

    int chave ; // vamos guardar dist aqui
    int conteudo ; // vamos guardar o vértice aqui

} Elem ;

# define PAI(i) (( i - 1 )/2)
# define FILHO_ESQ(i) ( 2 * i + 1 )
# define FILHO_DIR(i) ( 2 * i + 2 )


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



/*Essa implementação do algoritmo de Disjkstra é mais avançada, pois faz uso de um heap de valores, a eficiencia do algoritmo depende fortemente da estrutura
de dados que usamos para implementar as operações de escolha do vértice, com menor valor de dist[], como fazemos repetidas operações de remoção do mínimo 
de um conjunto a escolha natural é ultilizar um heap de mínimo, sendo n o número de elementos armazenados, um heap de mínimo suporta as operações de remover
o mínimo e de inserir em tempo log n, também é possível construir um heap em tempo O(n), além disso é possível atualizar o valor de elementos no meio do heap
em tempo log n, que é particularmente relevante nesta aplicação*/


//O pseudocódigo com heap

/*

DijskatraComHeap(G,c,v){

    para todo v E V faça dist[v] = + infinito e pred[v] = NULL

    dist[s] = 0


    //Colocar no heap
    H = constroiHeap(V,dist)

    enquanto(H != vazio){

        v = removeMinHeap(H)
        para cada arco (v,w)
            se dist[w] > dist[v] + c(v,w)
                dist[w] = dist[v] + c(v,w)
                pred[w] = v
                atualizaHeap(H,w,dist[w])
    }
}
*/

//Funções relacionadas ao Heap
void troca(Elem *a,Elem *b){

    Elem aux;
    aux = *a;

    *a = *b;
    *b = aux;
}
void troca_pos(int *a,int *b){

    int aux;
    aux = *a;

    *a = *b;
    *b = aux;
}


void sobeHeap ( Elem v [] , int pos_v [] , int pos_elem_v ) {
    int f = pos_elem_v ;

    while ( f > 0 && v [ PAI ( f )]. chave > v [ f ]. chave ) {

        troca (& v [ f ], & v [ PAI ( f )]);
        troca_pos (& pos_v [ v [ f ]. conteudo ], & pos_v [ v [ PAI ( f )]. conteudo ]);

        f = PAI ( f );
    }
}
int insereHeap ( Elem v [] , int pos_v [] , int m , Elem x ) {
    
    v [ m ] = x ;
    pos_v [ x.conteudo ] = m ;
    sobeHeap ( v , pos_v , m );
    return m + 1 ;

} 
// desce o elemento em v[pos_elem_v] até restaurar a prop. do heap
void desceHeap ( Elem v [] , int pos_v [] , int m , int pos_elem_v ) {
    int p = pos_elem_v , f ;

    while ( FILHO_ESQ ( p ) < m && ( v [ FILHO_ESQ ( p )]. chave < v [ p ]. chave
    || ( FILHO_DIR ( p ) < m && v [ FILHO_DIR ( p )]. chave < v [ p ]. chave ))) {

        f = FILHO_ESQ ( p );
        if ( FILHO_DIR ( p ) < m && v [ FILHO_DIR ( p )]. chave < v [ f ]. chave )
        f = FILHO_DIR ( p );
        troca (& v [ p ], & v [ f ]);
        troca_pos (& pos_v [ v [ p ]. conteudo ], & pos_v [ v [ f ]. conteudo ]);
        p = f ;
    }
}
int removeHeap ( Elem v [] , int pos_v [] , int m , Elem * px ) {
    
    *px = v [ 0 ];
    troca (& v [ 0 ], & v [ m - 1 ]);
    troca_pos (& pos_v [ v [ 0 ]. conteudo ], & pos_v [ v [ m - 1 ]. conteudo ]);
    desceHeap ( v , pos_v , m , 0 );
    return m - 1 ;

}
void atualizaHeap ( Elem v [] , int pos_v [] , Elem x ) {

    int pos_x_v = pos_v [ x . conteudo ]; // pega a posição de x em v
    v [ pos_x_v ]. chave = x . chave ; // atualiza a chave de x em v
    sobeHeap ( v , pos_v , pos_x_v ); // Quiz3: por que mando subir e não
}


void DijkstraHeap ( Grafo G , int origem , int * dist , int * pred ) {
    
    int i , * pos_H, v , w , custo , tam_H ;
    Elem * H , elem_aux ;
    Noh * p ;
    // inicializando distâncias e predecessores
    for ( i = 0 ; i < G -> n ; i ++) {
        dist [ i ] = __INT_MAX__ ;
        pred [ i ] = - 1 ;
    }

    dist [ origem ] = 0 ;

    // criando um min heap em H com vetor de posições pos_H
    H = malloc ( G -> n * sizeof( Elem ));
    pos_H = malloc ( G -> n * sizeof( int ));


    for ( i = 0 ; i < G -> n ; i ++) {

        H [ i ]. chave = dist [ i ]; // chave é a "distância" do vértice
        H [ i ]. conteudo = i ; // conteúdo é o rótulo do vértice
        pos_H [ i ] = i ; // vértice i está na posição i do heap H
    }

    troca (& H [ 0 ], & H [ origem ]); // coloca origem no início do heap H
    troca_pos (& pos_H [ 0 ], & pos_H [ origem ]); // atualiza posição

    tam_H = G -> n ;

    while ( tam_H > 0 ) { // enquanto não visitar todo vértice
        // buscando vértice v que minimiza dist[v]
        tam_H = removeHeap ( H , pos_H , tam_H , & elem_aux );

        v = elem_aux.conteudo ;
        // percorrendo lista com vizinhos de v
        for ( p = G -> A [ v ]; p != NULL; p = p -> prox ) {

            w = p -> rotulo ;
            custo = p -> custo ;

            // e atualizando as distâncias e predecessores quando for o caso
            if ( dist [ w ] > dist [ v ] + custo ) {

                dist [ w ] = dist [ v ] + custo ;
                pred [ w ] = v ;
                elem_aux . chave = dist [ w ];
                elem_aux . conteudo = w ;
                atualizaHeap ( H , pos_H , elem_aux );
            }

        }
    } 
    free ( H );
    free ( pos_H );
    
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

    DijkstraHeap(G,0,distancias,pred);

    for(int i=0;i<G->n;i++){

        printf("%d -> dist = %d || pred = %d\n",i,distancias[i],pred[i]);
    }

}