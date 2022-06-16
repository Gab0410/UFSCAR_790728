#include "Jogador.h"
#include "Time.h"
#include <iostream>
using namespace std;

Jogador::Jogador(string n, int i, string p)
    :nome(n),idade(i),posicao(p){
        cout<<"Jogaodor "<<n<<" criado"<<endl;
    }
Jogador::~Jogador(){
    cout<<"Destruindo o jogador "<<nome<<endl;
}
string Jogador::getNome() const{
    return this->nome;
}
void Jogador::setNome(string n){
    this->nome = n;
}
int Jogador::getIdade() const{
    return this->idade;
}
void Jogador::setIdade(int i){
    this->idade = i;
}
void Jogador::setPosicao(string p){
    this->posicao = p;
}
string Jogador::getPosicao() const{
    return this->posicao;
}
Time *Jogador::getTime()const{
    return this->time;
}
void Jogador::setTime(Time *time){
    this->time = time;
}
void Jogador::imprime() const{
    cout << nome << ", " << posicao << ", " << idade << " anos";
    if (time != NULL) {
    cout << " (Joga no " << time->getNome() << ")";
    } else {
    cout << " (Aposentado/Desempregado)";
    }
    cout << endl;
}