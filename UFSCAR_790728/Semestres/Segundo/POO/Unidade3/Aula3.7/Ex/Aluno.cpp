#include <iostream>
#include<cstring>
#include<string>
using namespace std;

#include "Aluno.h"

int Aluno::contador =0;
Aluno::Aluno(string s, int tam){
    setNome(s);
    notas = new double[tam];
    contador++;
    cout<<"Construtor do Aluno:\nNome: "<<nome<<"\nRA: "<<RA<<endl;
    tamanho = tam;

}
Aluno::~Aluno(){
    cout<<"Destrutor do Aluno:\nNome: "<<nome<<"\nRA: "<<RA<<endl;
    delete [] notas;

}
void Aluno::setNota(){
    for(int i=0;i<tamanho;i++){
        cout<<"Digite a nota {"<<i+1<<"}: ";
        cin>>notas[i];
    }
}
void Aluno::setNome(string namer){
    nome = namer;
}
int Aluno::getRa() const{
    return RA;
}
double Aluno::getNota(int x) const{
    return notas[x];
}
string Aluno::getNome() const{
    return nome;
}
void Aluno::imprime() const{
    cout<<"O aluno -> "<<getNome()<<" de RA -> "<<getRa()<<" teve as seguintes notas ->"<<endl;
    for(int i=0;i<tamanho;i++){
        cout<<"N{"<<i+1<<"} = "<<getNota(i)<<endl;
        
        
    }
}