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

void hash(int v){

    int m = v % 12;

    printf("Para a chave %d, a pos = %d\n",v,m);
}

int main(){

    //17, 21, 19, 4, 26, 30 e 37
    int vetor[7] = {17, 21, 19, 4, 26, 30 , 37};
    

    for(int i=0;i<7;i++)
        hash(vetor[i]);

    return 0;


}