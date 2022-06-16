#include<iostream>
#include <stdlib.h>
#include<string.h>
#include <stdbool.h>

#define MAX 200
using namespace std;
int palindromo(char *palavra){
    char *inicio, *fim;
    int tamanho;
    tamanho = strlen(palavra);

    inicio = &palavra[0];
    fim = &palavra[tamanho-1];

    while(inicio < fim && *inicio == *fim){
        inicio++;
        fim--;
    }
    if(inicio>=fim)
        return 1;
    return 0;
}
int main(){
    char p[MAX];

    cout<<"Digite uma palavra: ";
    cin>>p;
    

    if(palindromo(p))
        cout<<"A palavra "<<p<<" e um palindromo"<<endl;
    else  
        cout<<"A palavra "<<p<<" nao e um palindromo"<<endl;

}