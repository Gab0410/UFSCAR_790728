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
