#include "Carro.h"

Carro::Carro(){
    cout<<"Construtor carro criado"<<endl;
}
Carro::~Carro(){
    cout<<"Destrutor carro acionado"<<endl;
}
void Carro::anda() const{
    cout<<"Andando em superficie terrestre"<<endl;
}