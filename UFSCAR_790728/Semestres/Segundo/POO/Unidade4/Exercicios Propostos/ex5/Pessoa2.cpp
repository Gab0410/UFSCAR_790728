#include "Pessoa2.h"

namespace ns2{
    Pessoa::Pessoa(string n, string e)
        :nome(n),endereco(e){}
    void Pessoa::imprime() const{
        cout << "Nome: " << nome << endl;
        cout << "Endereco: " << endereco << endl;
    }
}