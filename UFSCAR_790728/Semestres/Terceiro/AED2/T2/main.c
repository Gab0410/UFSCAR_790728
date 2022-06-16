/* 
NOME: Gabriel Meirelles Carvalho Orlando
RA: 790728
CURSO: Ciencia da Computação
DATA: 20/10/2021
FLAGS: -std=c99 -Wall -Werror -Werror=vla -pedantic-errors -g -lm
*/
#include <stdio.h>
#include <stdlib.h>
#define MAX 100

unsigned long long intercala_conta(int v[], int p, int q, int r) {
    
    int tam;

    tam = r - p;
    int *w = malloc(tam * sizeof(int));


    int i, j, k;
    unsigned long long num_inv = 0;
    i = p;
    j = q;
    k = 0;

    //Laço principal
    while (i < q && j < r) {
        //Caso o valor v[j] que posicionalmente está a frente de v[i]
        if (v[i] <= v[j])
            w[k++] = v[i++];

        //Caso seja maior
        else { 
            w[k++] = v[j++];

            //Caso for maior, significa que todos os valores para frente, que estão no intervalo [i,q] são maiores, logo soma isso de vezes
            num_inv += q - i;
        }
    }

    while (i < q) w[k++] = v[i++];
    while (j < r) w[k++] = v[j++];

    for (k = 0; k < tam; k++)
    v[p + k] = w[k];

    //Libera o laço
    free(w);
    return num_inv;

}

unsigned long long contarInversoesR(int v[], int p, int r) {
    int m;
    unsigned long long num_inv = 0;

    //Controla o numero de inversões, com a condição de parada, caso o vetor tenha tamanho lógico de 1 ou menos
    if (r - p > 1) {
        m = (p + r) / 2; 
        num_inv += contarInversoesR(v, p, m);
        num_inv += contarInversoesR(v, m, r);
        num_inv += intercala_conta(v, p, m, r);
    }
    return num_inv;
}

//Função que apenas chama a recursiva
unsigned long long contarInversoes(int v[], int n) {
    return contarInversoesR(v, 0, n);
}






int main(int argc, char *argv[])
{
    char file_name[MAX];
    FILE *entrada;
    int i, n;
    unsigned long long num_inv = 0;

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
    // lendo do arquivo da instância
    fscanf(entrada, "%d", &n);
    int *v = (int *)malloc(n * sizeof(int));
    for (i = 0; i < n; i++)
        fscanf(entrada, "%d", &v[i]);

    num_inv = contarInversoes(v,n);

    fclose(entrada);



    printf("%llu\n",num_inv);
    

    return 0;
}
