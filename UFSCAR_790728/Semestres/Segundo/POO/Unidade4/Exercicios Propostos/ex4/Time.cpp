#include "Time.h"
#include <iostream>
#include <cstring>
using namespace std;

Time::Time(string name)
    :nome(name)
    {
        cout<<"Criando time "<<nome<<endl;
        elenco = new Jogador* [22];
        memset (elenco,0,22*sizeof(Jogador*));
    }
Time::~Time(){
    cout<<"Destrutor do time "<<nome<<endl;
    delete [] elenco;
}
string Time::getNome() const{
    return nome;
}
void Time::setNome(string n){
    this->nome = n;
}
void Time::adicionaJogador(int numero,Jogador* jogador){
    elenco[numero-1] = jogador;
    jogador->setTime(this);
}
void Time::removeJogador(int numero){
    elenco[numero -1 ]->setTime(NULL);
    elenco[numero -1] = NULL;
}
void Time::imprime() const{
    cout << "Elenco do " << nome << endl;
    for (int i = 0; i < 22; i++) {
        if (elenco[i] != NULL) {
            cout << "(" << (i + 1) << ") ";
            elenco[i]->imprime();
        }
    }
}
