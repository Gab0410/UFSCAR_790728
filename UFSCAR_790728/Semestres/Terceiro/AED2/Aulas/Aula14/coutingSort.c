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

//Implementação do algoritmo para o método de ordenação couting sort

void coutingSort(int v[],int n,int R){

    int valor,i;
    int *ocorr_pred,*aux;

    ocorr_pred = malloc((R+1)*sizeof(int));

    aux = malloc(n*sizeof(int));

    for(valor=0;valor<R;valor++)
        ocorr_pred[valor] = 0;
    
    for(i=0;i<n;i++){
        valor = v[i];
        ocorr_pred[valor+1] += 1;
    }

    //ocorr_pred[valor] é o num de ocorrencias de valor-1
    for(valor=1;valor<=R;valor++)
        ocorr_pred[valor] += ocorr_pred[valor-1];

    //Insere no vetor ordenado
    for(i=0;i<n;i++){
        valor = v[i];
        aux[ocorr_pred[valor]] = v[i];
        ocorr_pred[valor]++; //atualiza o numero de predecessores
    }

    for(i=0;i<n;i++) v[i] = aux[i];

    free(ocorr_pred);
    free(aux);

}