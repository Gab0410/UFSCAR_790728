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
#include <string.h>
#include <ctype.h>

#define MAX 40

int compara(char n[10],char p[10]){

    char aux1[10];
    char aux2[10];
    int espaco=0;

    //Deixar os nomes iguais, tirando espaço e letras maiusculas
    int i=0;
    while(n[i] != '\0'){

        if(n[i] == '_'){
            aux1[i-espaco] = tolower(n[i+1]);
            espaco++;
            i++;
        }
        
        else
            aux1[i-espaco] = tolower(n[i]);
        printf("%c\n",n[i]);
        i++;
    }
    aux1[i-espaco] = '\0';

    i=0;
    espaco =0;
    while(p[i] != '\0'){
        if(p[i] == '_'){
            aux2[i-espaco] = tolower(p[i+1]);
            i++;
            espaco++;
        }
        
        else
            aux2[i-espaco] = tolower(p[i]);
        i++;
    }
    aux2[i-espaco] = '\0';

    printf("%s e %s\n",aux1,aux2);


    return strcmp(aux1,aux2);

}
typedef struct endereco{
    char rua[21];
    int nro;
    char complemento[10];
}add;

typedef struct Registro
{
    long int key;
    char lName[11];
    char nome[10];
    add adress;
    char city[24];
    char state[3];
    char cep[10];//cep, dps trocar
    char phone[15];//phone, dps trocar
}Reg;

void print_add(add registro){
    printf("ENDERECO = %s, %d, %s\n\n",registro.rua,registro.nro,registro.complemento);
}
void print_reg(Reg registro){

    printf("KEY = %ld\nLAST NAME = %s\nFIRST NAME = %s\nCITY = %s\nSTATE = %s\nCEP = %s\nPHONE = %s\n",registro.key,registro.lName,registro.nome,registro.city,registro.state,registro.cep,registro.phone);
    print_add(registro.adress);
}
 int maxLname(Reg registro[],int n){
     int maior=0;
    for(int i=0;i<n;i++){
        long int atual = strlen(registro[i].lName);
        if(i==0)
            maior = atual;
        else if(maior < atual)
            maior = atual;

    }

    return maior;

}
int maxName(Reg registro[],int n){
     int maior=0;
    for(int i=0;i<n;i++){
        long int atual = strlen(registro[i].nome);
        if(i==0)
            maior = atual;
        else if(maior < atual)
            maior = atual;

    }

    return maior;

}
int maxCity(Reg registro[],int n){
     int maior=0;
    for(int i=0;i<n;i++){
        long int atual = strlen(registro[i].city);
        if(i==0)
            maior = atual;
        else if(maior < atual)
            maior = atual;

    }

    return maior;

}
int maxState(Reg registro[],int n){
     int maior=0;
    for(int i=0;i<n;i++){
        long int atual = strlen(registro[i].state);
        
        if(i==0)
            maior = atual;
        else if(maior < atual){
            maior = atual;
        }

    }

    return maior;

}
int maxCEP(Reg registro[],int n){
     int maior=0;
    for(int i=0;i<n;i++){
        long int atual = strlen(registro[i].cep);
        if(i==0)
            maior = atual;
        else if(maior < atual)
            maior = atual;

    }

    return maior;

}
int maxPhone(Reg registro[],int n){
     int maior=0;
    for(int i=0;i<n;i++){
        long int atual = strlen(registro[i].phone);
        if(i==0)
            maior = atual;
        else if(maior < atual)
            maior = atual;

    }

    return maior;

}

int maxRUA(Reg reg[],int n){

    int maior=0;
    int indice =0;
    for(int i=0;i<n;i++){
        long int atual = strlen(reg[i].adress.rua);
        if(i==0)
            maior = atual;
        else if(maior < atual){
            maior = atual;
            indice = i;
        }

    }
    return maior;
}
int maxComple(Reg reg[],int n){
    int maior=0;
    int indice=0;
    for(int i=0;i<n;i++){
        long int atual = strlen(reg[i].adress.complemento);
        if(i==0)
            maior = atual;
        else if(maior < atual){
            maior = atual;
            indice = i;
        }

    }

    printf("%d\n",indice);
    print_add(reg[indice].adress);
    return maior;
}

int main(){

    /*char nome[10];
    char nome2[10];


    scanf("%s",nome);
    scanf("%*c%s",nome2);

    printf("%d\n",compara(nome,nome2));

    printf("%s e %s\n",nome,nome2);*/

    Reg registro[100];
    add reg;

    char string[sizeof(Reg)];
    scanf("%[^\n]",string);
    sscanf(string,"%ld %s %s %s %s %s %s %d %s %s",&registro[0].key,registro[0].nome,registro[0].lName,registro[0].city,registro[0].state,registro[0].cep,registro[0].phone,&reg.nro,reg.rua,reg.complemento);  
    registro[0].adress = reg ;

    for(int i=1;i<100;i++){
        scanf("%*c%[^\n]",string);
        sscanf(string,"%ld %s %s %s %s %s %s %d %s %s",&registro[i].key,registro[i].nome,registro[i].lName,registro[i].city,registro[i].state,registro[i].cep,registro[i].phone,&reg.nro,reg.rua,reg.complemento);  
        registro[i].adress = reg ;
    }

    //Funções que definem o tamanho maximo de cada coisa

    /*printf("Lname -> %d\n",maxLname(registro,100));
    printf("Name -> %d\n",maxName(registro,100));
    printf("State -> %d\n",maxState(registro,100));
    printf("CEP -> %d\n",maxCEP(registro,100));
    printf("City -> %d\n",maxCity(registro,100));
    printf("Phone -> %d\n\n",maxPhone(registro,100));
    printf("RUA -> %d\n",maxRUA(registro,100));
    printf("COMPLEMENTO -> %d\n\n",maxComple(registro,100));*/
    for(int i=99;i>-1;i--)
        printf("%ld %s %s %s %s %s %s %d %s %s\n1\n",registro[i].key,registro[i].nome,registro[i].lName,registro[i].city,registro[i].state,registro[i].cep,registro[i].phone,registro[i].adress.nro,registro[i].adress.rua,registro[i].adress.complemento);


    /*char string[sizeof(add)];
    add registro[100];
    scanf("%[^\n]",string);
    sscanf(string,"%d %s %s",&registro[0].nro,registro[0].rua,registro[0].complemento);

    for(int i=1;i<100;i++){
        scanf("%*c%[^\n]",string);
        sscanf(string,"%d %s %s",&registro[i].nro,registro[i].rua,registro[i].complemento);
    }

    printf("RUA -> %d\n",maxRUA(registro,100));
    printf("COMPLEMENTO -> %d\n\n",maxComple(registro,100));

    for(int i=0;i<100;i++)
        print_add(registro[i]);*/

    
     
  





    return 0;
}