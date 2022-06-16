
#include <iostream>
#include "Jogador.h"

#include <string>
using namespace std;

int Jogador::camisa[20] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};

Jogador::Jogador(string name,int age,int shirNu,string shirNa, Habilidade over){
    
    posicao = over.getPos();
    overall = over.calcOver();
    nCamisa = shirNa;
    nome = name;
    idade = age;
    numCamisa = verifica(shirNu);
    over.limpa();
}
Jogador::~Jogador(){
}

int Jogador::verifica(int numero){
    if(camisa[numero-1] != 0){
        camisa[numero-1] = 0;
        cout<<"Numero valido."<<endl;
    }
    else{
        while(camisa[numero-1] == 0){
        cout<<"Numero invalido, digite outro numero: ";
        cin>>numero;
        }
        cout<<"Numero valido"<<endl;
    }
    return numero;
}

int Jogador::getCamisa() const{
    return numCamisa;
}
string Jogador::getNome() const{
    return nome;
}
int Jogador::getOver() const{
    return overall;
}
string Jogador::getnCamis() const{
    return nCamisa;
}
int Jogador::getIdade() const{
    return idade;
}
void Jogador::dadosJog() const{
    cout<<"Jogador: "<<getNome()<<"\nPosicao: "<<posicao<<"\nNum Camisa: "<<getCamisa()<<"\nOver: "<<getOver()<<"\nIdade: "<<getIdade()<<"\nNom Camisa: "
    <<getnCamis()<<endl;
}