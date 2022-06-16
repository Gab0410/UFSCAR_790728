#include "Departamento.h"
#include "Universidade.h"
#include <iostream>
using namespace std;

Departamento::Departamento(string n,string sig,Universidade* univ)
    :nome(n),sigla(sig),universidade(univ)
    {
        cout<<"Construindo o departamento "<<sigla<<" da faculdade "
        <<universidade->getNome()<<endl;
    }
Departamento::~Departamento(){
    cout<<"Destruindo o departamento "<<sigla<<endl;
}
string Departamento::getNome() const{
    return nome;
}
void Departamento::setNome(string n){
    this->nome = n;
}
string Departamento::getSigla() const{
    return sigla;
}
void Departamento::setSigla(string s){
    this->sigla = s;
}
Universidade* Departamento::getUniv() const{
    return universidade;
}
void Departamento::setUniv(Universidade* u){
    this->universidade = u;
}
void Departamento::imprime() const{
    cout<<"Departamento: "<<nome
    <<"\nSigla: "<<sigla
    <<"\nUniversidade: "<<universidade->getNome()<<endl;;
}