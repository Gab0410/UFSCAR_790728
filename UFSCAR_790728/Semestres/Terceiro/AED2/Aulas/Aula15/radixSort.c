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



typedef unsigned char byte;

//W comprimento em digitos de cada chave(Word)
//R é o universo de valores que cada dígito pode assumir
//R<256, maior valor que se pode representar usando 1 byte.


void ordenacaoDigital(byte *v[],int n,int W){
    int *ocorr_pred,digito,valor,i,R=256;

    byte **aux;

    //Para o couting sort
    ocorr_pred = malloc(sizeof(int)*(R+1));
    aux = malloc(n*sizeof(byte*));

    for(digito=W-1;digito>=0;digito--){
        for(valor=0;valor<=R;valor++) ocorr_pred[valor] = 0;

        for(i=0;i<n;i++){
            valor = v[i][digito];
            ocorr_pred[valor+1] += 1;
        }

        for(valor=1;valor <=R;valor++)
            ocorr_pred[valor] += ocorr_pred[valor-1];

        for(i=0;i<n;i++){
            valor = v[i][digito];
            aux[ocorr_pred[valor]] = v[i];
            ocorr_pred[valor]++;
        }

        for(i=0;i<n;i++) v[i] = aux[i];

    }

    free(ocorr_pred);free(aux);
}

int main(){

    byte *v[5] = {"KNG","FFU","KDV","RFD","KDA"};

    ordenacaoDigital(v,5,3);

    for(int i =0;i<5;i++)
        printf("%s\n",v[i]);

    return 0;

}