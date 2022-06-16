#include "Endereco.h"
#include <iostream>
using namespace std;

Endereco::Endereco(string l,int num,string c,string es)
    :logradouro(l),numero(num),cidade(c),estado(es)
    {
        cout<<"Construtor endereco ("<<logradouro<<", "<<numero<<")"<<endl;
    }
Endereco::~Endereco(){
    cout<<"Destrutor endereco ("<<logradouro<<", "<<numero<<")"<<endl;
}
string Endereco::getLog() const{
    return logradouro;
}
void Endereco::setLog(string l){
    this->logradouro = l;
}
string Endereco::getCid() const{
    return cidade;
}
void Endereco::setCid(string c){
    this->cidade = c;
}
int Endereco::getNum() const{
    return numero;
}
void Endereco::setNum(int n){
    this->numero = n;
}
string Endereco::getEst() const{
    return estado;
}
void Endereco::setEst(string e){
    this->estado = e;
}
void Endereco::imprime() const{
    cout << "Logradouro: " << this->getLog() << endl;
    cout << "Numero: " << this->getNum() << endl;
    cout << "Cidade: " << this->getCid() << endl;
    cout << "Estado: " << this->getEst() << endl;
}