#include "Pessoa1.h"

namespace ns1{
    Pessoa::Pessoa(string n, int i)
        :nome(n),idade(i){}
    void Pessoa::imprime() const{
        cout << "Nome: " << nome << endl;
        cout << "Idade: " << idade << endl;
    }
}