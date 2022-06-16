using namespace std;
#include <cstring>
#include<string>
#include <iostream>

#include "Pessoas.h"

Pessoas::Pessoas(int i, string n){
    idade = (i>0 && i<120?i:1);
    nome = n;
}
string Pessoas::getNome() const{
    return nome;
}
int Pessoas::getIdade() const{
    return idade;
}
void Pessoas::setIdade(int i){
    idade = (i>0 && i<120?i:1);
}
void Pessoas::setNome(string n){
    nome = n;
}
void Pessoas::imprime() const{
    cout<<"Nome: "<<getNome()
    <<"\nIdade: "<<getIdade()<<endl;
}
int Pessoas::compare(Pessoas &p){
    if(this->idade > p.idade)
        return 1;
    else if(this->idade == p.idade)
        return 0;
    return -1;
}