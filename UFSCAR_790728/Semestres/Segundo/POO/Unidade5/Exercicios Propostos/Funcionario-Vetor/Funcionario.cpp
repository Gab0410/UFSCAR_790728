#include "Funcionario.h"

Funcionario::Funcionario(int c,string n)
    :cpf(c),nome(n)
    {
        cout<<"Funcionario -> "<<nome<<" criado\n";
    }
Funcionario::~Funcionario(){
    cout<<"Funcionario -> "<<nome<<" destruido\n";
}
void Funcionario::imprime() const{
    cout<<"Nome: "<<nome
    <<"\nCPF: "<<cpf
    <<"\nProfissao: "<<getProfissao()<<"\n";
}


bool Funcionario::comparaNome(const Funcionario* f1, const Funcionario* f2) {
    return f1->nome < f2->nome; // classe string sobrecarregou o operador "<" (ordem alfabética)
}

bool Funcionario::comparaCPF(const Funcionario* f1, const Funcionario* f2) {
    return f1->cpf < f2->cpf; // operador "<" (inteiros)
}
