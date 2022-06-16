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
//#include <time.h>

#define MAX 100


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

    Noh *inicio;
    Noh *fim;

}Fila;

typedef struct elem{

    int *grupo;
    //int n_grupo;
  

}Elementos;


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
/*
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
*/
Fila* criaFila(int n){

    Fila *nova = malloc(sizeof(Fila*));
    nova->inicio = NULL;
    nova->fim = NULL;

    return nova;
}

Noh *novoNOH(int valor){

    Noh *novo = malloc(sizeof(Noh*));
    novo->prox = NULL;
    novo->rotulo = valor;

    return novo;
}

int filaVazia(Fila *fila){

    return fila->inicio == NULL;
}


void insereFila(Fila *fila,int valor){
    
    Noh *insere = novoNOH(valor);

    //Insere caso a fila estiver vazia
    if(filaVazia(fila)){
        fila->inicio = insere;
        fila->fim = insere;
    }

    //Caso a fila tiver mais de um valor
    else{
        fila->fim->prox = insere;
        fila->fim = insere;
    }

    return;


}
int removeFila(Fila *fila){

    if(filaVazia(fila))
        return -1;
    
    //Remover o inicio, diminuir 1 elemento, e reorganizar a fila
    int removido = fila->inicio->rotulo;
    Noh *lixo;
    //Tem apenas um noh
    if(fila->inicio == fila->fim){
        lixo = fila->inicio;

        fila->inicio = NULL;
        fila->fim = NULL;

        
    }
    else{
        lixo = fila->inicio;
        fila->inicio = fila->inicio->prox;
    }

    free(lixo);

    return removido;
}

Fila* liberaFila(Fila *fila){

    if(fila == NULL)
        return NULL;

    free(fila->inicio);
    free(fila->fim);

    free(fila);

    fila = NULL;
    
    return fila;
}

int *distancias(Grafo G, int origem) {

    int v, w, *dist;

    Fila *fila;
    Noh *p;

    dist = malloc(G->n * sizeof(int));

    fila = criaFila(G->n);


    /* inicializa todos como não encontrados, exceto pela origem */
    for (v = 0; v < G->n; v++){
        dist[v] = -1;
    }
    
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

int interseccao(int *g,int *f,int n){


    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(g[i] != -1 && g[i] == f[j]){
                return 1;
            }
        }
    }
        
    return 0;
    
}

Elementos* inicializaElementos(int n){

    Elementos *e = malloc(n*sizeof(Elementos));
    for(int i=0;i<n;i++){
        e[i].grupo = malloc(sizeof(int)*n);

        for(int j=0;j<n;j++)
            e[i].grupo[j] = -1;

    }


    return e;
}

//Decide se o vertice v de G, tem a cor C, e decide se seus vizinhos nao tem cor semelhante a ele, basicamente uma busca em profundidade com cores
int Coloracao( Grafo G, int v, int c,int *cor)
{ 
   cor[v] = c;
   Noh *a;

   for (a = G->A[v]; a != NULL; a = a->prox) {
      int w = a->rotulo;

      if (cor[w] == -1) {
        int color;

        if(c == 0)
            color = 1;
        else
            color = 0;

        if (Coloracao( G, w, color,cor) == 0) 
            return 0; 
      }
      //A aresta v-w pode ser de avanço ou retorno
      else {
        //Condição de parada recursão
        if (cor[w] == c)
            return 0;
      }
   }
   return 1;
}

int ehBipartido(Grafo G)
{ 
    int vertice;
    int *cor = malloc(sizeof(int)*G->n);

    //Inicializa todos os vértices como sem cor
   for (vertice = 0; vertice < G->n; vertice++) 
      cor[vertice] = -1;

    
   for (vertice = 0; vertice < G->n; vertice++)
      if (cor[vertice] == -1) // Caso vértice nao tenha cor
         if (Coloracao( G, vertice, 0,cor) == 0) 
            return 0;
   return 1;
}

int main(int argc, char *argv[]){



    char file_name[MAX];
    FILE *entrada;

    if (argc != 1)
    {
        printf("Numero incorreto de parametros. Ex: .\\nome_arquivo_executavel\n");
        return 0;
    }
    scanf("%s", file_name);


    entrada = fopen(file_name, "r");
    if (entrada == NULL)
    {
        printf("\nNao encontrei o arquivo! Informe o nome da instancia\n");
        exit(EXIT_FAILURE);
    }

    int alunos;
    fscanf(entrada, "%d\n", &alunos);
    Grafo G = inicializaGrafo(alunos);
    int debate = 1;
    for(int i=0;i<alunos;i++){
        int qntd;

        fscanf(entrada, "%d", &qntd);
        int j=0;
        while(j < qntd){
            int nro_aluno;
            fscanf(entrada," %d",&nro_aluno);
            insereArcoGrafo(G,i,nro_aluno);
            insereArcoGrafo(G,nro_aluno,i);

            j++;
        }
    }
    //imprimeGrafo(G);
    if(!ehBipartido(G)){
        debate = 0;
    }

    int *v = malloc(sizeof(int) * alunos);

    Elementos *e = inicializaElementos(alunos);
    
    for(int i=0;i<alunos && debate;i++){

        v = distancias(G,i);
    
        //Se a distancia for par, significa que estão no mesmo grupo, caso a distância for impar, significa que não estão no mesmo grupo
        for(int j=0;j<alunos;j++){
            //int w = e[i].n_grupo;

            if(v[j] % 2 == 0){//Isso singifca que devem ser do mesmo grupo
                e[i].grupo[j] = j;
            }
                
        }

    }

    //Agora será realizada a analise bonita dos dados obtidos, como ela será feita:
    /*A analise será feita com dois laços pinricpais, ambos vao de 0 até n-1
    Caso j nao esta no grupo de i, a interseccção entre seus vetores grupo, deve ser vazia
    */
   int impossivel=0;
   for(int i=0;i<alunos && !impossivel && debate;i++){

       for(int j=0;j<alunos && !impossivel;j++){

           if(e[i].grupo[j] != j && e[j].grupo[i] != i){
               //A interseccção entre os grupos deve ser vazia
                if(interseccao(e[i].grupo,e[j].grupo,alunos)){
                    impossivel = 1;
               }
           }
       }
   }

    if(impossivel || !debate)
        printf("Impossivel\n");
    else
        printf("Vai ter debate\n");
    
   
    fclose(entrada);

    return 0;
}
