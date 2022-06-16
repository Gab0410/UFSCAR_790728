#include "avl.h"
#define SIZE 7

int main(){

    int vetor[SIZE] = {70, 90, 30, 60, 20, 80 , 50};

    Arvore raiz = NULL;
    raiz = inserir(raiz, vetor[0],vetor[0]);

    //int v2[6] = {4,3,7,6,10,5};
    for(int i=1;i <SIZE;i++){

        printf("Insercao nro -> [%d]\n\n",i);
        raiz = inserir(raiz,vetor[i],vetor[i]);
        em_ordem(raiz);
        printf("\n\n"); 
    }

    int tamanho = alturaAR(raiz);
    printf("a altura eh: %d\n",tamanho);

    int verificar = verifica(raiz);
    if(verificar)
        printf("Arvore eh AVL\n");
    else
        printf("Arvore nao eh AVL\n");

    raiz = remover(raiz,0);

    em_ordem(raiz);



    return 0;

}