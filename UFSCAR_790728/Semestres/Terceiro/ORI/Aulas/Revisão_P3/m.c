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
#include <math.h>

int main(){


    long long unsigned int v_principal[2021];
    for(int i=0;i<2021;i++)
        v_principal[i] = (long long int)i;
    
    int a[10]= {0};
    int b[10] = {0};
    int c[10] = {0};
    int d[10] = {0};
    int e[10] = {0};

    for(int i=0;i<2021;i++)
        a[(v_principal[i] * v_principal[i]) % 10]++;

    for(int i=0;i<2021;i++)
        b[(v_principal[i] * v_principal[i] * v_principal[i]) % 10]++;
    
    for(int i=0;i<2021;i++)
        c[(v_principal[i] * v_principal[i] * v_principal[i] * v_principal[i]) % 10]++;

    for(int i=0;i<2021;i++)
        d[(11 * v_principal[i] * v_principal[i]) % 10]++;

    for(int i=0;i<2021;i++)
        e[(v_principal[i] * 12) % 10]++;

    for(int i=0;i<10;i++)
        printf("%d -> %d\n",i,a[i]);
    printf("\n");

    for(int i=0;i<10;i++)
        printf("%d -> %d\n",i,b[i]);
    printf("\n");

    for(int i=0;i<10;i++)
        printf("%d -> %d\n",i,c[i]);
    printf("\n");

    for(int i=0;i<10;i++)
        printf("%d -> %d\n",i,d[i]);
    printf("\n");

    for(int i=0;i<10;i++)
        printf("%d -> %d\n",i,e[i]);
    printf("\n");
    


}