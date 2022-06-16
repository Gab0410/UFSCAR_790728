#include<iostream>
#include <stdlib.h>
#include<string.h>
#include <stdbool.h>

using namespace std;

typedef struct datas{
    int ano,mes,dia;
}datas;

int main(){
    int *vet;

    vet = (int*)malloc(10*sizeof(int));
    if(vet==NULL){
        cout<<"Memoria nao alocada, programa encerrado!"<<endl;
        exit(1);
    }
    for(int i=0;i<10;i++)
        vet[i] = i;
    for(int i=0;i<10;i++){
        cout<<"O vetor na posicao {"<<i<<"} = "<<vet[i]<<endl;
    }
    free(vet);
    vet = NULL;

    datas *feriado;
    feriado = (datas*)malloc(sizeof(datas));
    if(feriado == NULL){
        cout<<"Memoria nao alocada, programa encerrado!"<<endl;
        exit(1);    
    }
    feriado->dia = 7;
    feriado->mes = 9;
    feriado->ano = 2021;

    cout<<"O feriado esse ano será em: "<<feriado->dia<<"/"<<feriado->mes<<"/"<<feriado->ano<<endl;
}
