#include "grafos2.h"


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
void removeArcoGrafo(Grafo G,int v,int w){

    Noh *p,*aux;
    p = G->A[v];
    if(p == NULL)
        return;
    //Dois casos, no nó cabeça e no corpo
    if(p->rotulo == w){
        G->A[v] = p->prox;
        free(p);
        G->m--;
        return;
    }


    while(p->prox != NULL && p->prox->rotulo != w)
        p = p->prox;

    //Se o proximo é o valor
    if(p->prox != NULL){
        aux = p->prox;
        p->prox = aux->prox;
        free(aux);

        G->m--;        

        return;
    }

    return;


}

void imprimeArquivoGrafo(Grafo G,FILE *saida){
    int i;
    Noh *p;
    fprintf(saida,"Nro vertices: %d\nNro arcos: %d\n",G->n,G->m);

    for(i=0;i<G->n;i++){
        fprintf(saida,"%d:",i);
        for(p = G->A[i];p != NULL;p = p->prox)
            fprintf(saida," %d",p->rotulo);
        fprintf(saida," -1");
        fprintf(saida,"\n");
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
                if(rand() < prob * (RAND_MAX + 1.0)){
                    printf("%d - %d\n",v,w);
                    insereArcoGrafo(G,v,w);
                    insereArcoGrafo(G,w,v);
                }

    return G;
}

void buscaProfR(Grafo G,int v,int *ordem_chegada,int *ordem_saida,int *ptempo){

    int w;
    Noh *p;
    ordem_chegada[v] = (*ptempo)++;

    p = G->A[v];

    while (p != NULL)
    {
        w = p->rotulo;
        if(ordem_chegada[w] == -1)
            buscaProfR(G,w,ordem_chegada,ordem_saida,ptempo);
        p = p->prox;
    }

    ordem_saida[v] = (*ptempo)++;
    
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

void buscaCompR(Grafo G,int v,int *comp,int comp_atual){

    int w;
    Noh *p;
    comp[v] = comp_atual;
    p = G->A[v];

    while(p != NULL){
        w = p->rotulo;
        if(comp[w] == -1)
            buscaCompR(G,w,comp,comp_atual);
        p = p->prox;
    }
}
void identComponentes(Grafo G,int *comp){

    int v,num_comps;

    for(v=0;v<G->n;v++)
        comp[v] = -1;
    num_comps = 0;

    for(v=0;v<G->n;v++){
        if(comp[v] == -1){
            num_comps++;
            buscaCompR(G,v,comp,num_comps);
        }
    }
}

int main(){

    srand(time(NULL));
    Grafo G = grafoAleatorio2(10,10);

    FILE *arquivo = fopen("grafo.txt","w+");

    imprimeArquivoGrafo(G,arquivo);

    fclose(arquivo);

    int m = G->m;
    while(G->m == m){
        int v = verticeAleatorio(G);
        int w = v;
        while(v == w)
            w = verticeAleatorio(G);
        
        printf("Removendo o arco (%d,%d)\n",v,w);
        removeArcoGrafo(G,v,w);
        removeArcoGrafo(G,w,v);
    }

    arquivo = fopen("grafo2.txt","w+");
    imprimeArquivoGrafo(G,arquivo);
    fclose(arquivo);

   /* int *ordem_chegada = malloc(sizeof(int) * G->n);
    int *ordem_saida = malloc(sizeof(int) * G->n);
   
    buscaProf(G,0,ordem_chegada,ordem_saida);
    for(int i=0;i<G->n;i++)
        printf("%d -> (%d,%d)\n",i,ordem_chegada[i],ordem_saida[i]);*/
    int *comp = malloc(sizeof(int)*G->n);

    identComponentes(G,comp);
    for(int i=0;i<G->n;i++)
        printf("%d -> %d\n",i,comp[i]);


    G = liberaGrafo(G);

    return 0;
}