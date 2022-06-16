#include <iostream>
#include "vetor.h"
#include <stdbool.h>

using namespace std;

//Primeiro construtor
VETOR::VETOR(int T){
    
    tam = (T>0?T:10);
    ptr = new int[tam];
    for(int i=0;i<tam;i++)
        ptr[i] = 0;
}

//Construtor de copia
VETOR::VETOR(const VETOR &v):tam(v.tam){
    ptr = new int[tam];
    for(int i=0;i<tam;i++)
        ptr[i] = v.ptr[i];
}

VETOR::~VETOR(){
    delete [] ptr;
}
bool VETOR::operator!=(const VETOR &direita) const{
    return !(*this == direita);
}
int VETOR::getTam() const{
    return tam;
}
const VETOR &VETOR::operator=(const VETOR &direita){
    if(&direita != this){
        if(tam != direita.tam){
            delete [] ptr;
            tam = direita.tam;
            ptr = new int[tam];
        }
        for(int i=0;i<tam;i++)
            ptr[i] = direita.ptr[i];
    }
    return *this;
}
/* objeto1 = objeto2*/

bool VETOR::operator==(const VETOR &direita) const{
    if(this->tam != direita.tam)
        return false;
    
    for(int i=0;i< this->tam;i++)
        if(this->ptr[i] != direita.ptr[i])
            return false;
    return true;
}

istream &operator>>(istream &in, VETOR &a){
    cout<<"Entre com os valores do objeto\n";
    for(int i=0;i<a.tam;i++){
        cout<<"Digite o valor da posicao "<<i<<": ";
        in>>a.ptr[i];
    }
    return in;
}
ostream &operator<<(ostream &out, const VETOR &a){
    for(int i=0;i<a.tam;i++)
        out<<"Na posicao "<<i<<" o valor = "<<a.ptr[i]<<endl;
    out<<"\n";
    return out;
}
void VETOR::setVal(const int x){
    for(int i=0;i<tam;i++){
        ptr[i] = x;
    }
}