#include <iostream>
#include<string.h>
#include "empregado.h"

using namespace std;

int Empregado::contador =0;

int Empregado::getContador(){
    return contador;
}
Empregado::Empregado(const char *p,const char *s){
    prim_nome = new char[strlen(p) +1];
    strcpy(prim_nome,p);

    seg_nome = new char[strlen(s) +1];
    strcpy(seg_nome,s);

    contador++;

    cout<<"Construtor de "<<prim_nome<<" "<<seg_nome<<" chamado"<<endl;

}
Empregado::~Empregado(){
    cout<<"Destrutor de "<<prim_nome<<" "<<seg_nome<<" chamado"<<endl;
    delete [] prim_nome;
    delete [] seg_nome;
    contador --;
}
const char*Empregado::getPnome() const{
    return prim_nome;
}
const char*Empregado::getSnome() const{
    return seg_nome;
}