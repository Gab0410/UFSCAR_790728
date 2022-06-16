#include "Aluno.h"
#include <iostream>
using namespace std;

Aluno::Aluno(string n,int num,Endereco* e)
    :nome(n),RA(num),endereco(e)
    {
        cout<<"Construtor do aluno: "
        <<"\nNome: "<<nome
        <<"\nRA: "<<RA<<endl;
    }
Aluno::~Aluno(){
     cout<<"Destrutor do aluno: "
    <<"\nNome: "<<nome
    <<"\nRA: "<<RA<<endl;
}
string Aluno::getNome() const{
    return nome;
}
void Aluno::setNome(string s){
    this->nome = s;
}
int Aluno::getRA() const{
    return RA;
}
void Aluno::setRA(int r){
    this->RA = r;
}
Endereco* Aluno::getEndereco() const{
    return endereco;
}
void Aluno::setEndereco(Endereco* e){
    endereco = e;
}
void Aluno::imprime() const {
    cout << "-------------------------------------" << endl;
    cout << "Nome: " << this->getNome() << endl;
    cout << "RA: " << this->getRA() << endl;
    cout << "<Endereco>" << endl;
    this->getEndereco()->imprime();
}