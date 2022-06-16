#include "Medico.h"

Medico::Medico(int c,string n, string espe)
    :Funcionario(c,n),especialidade(espe)
    {
        cout<<"Medico -> "<<n<<" criado\n";
    }
Medico::~Medico(){
    cout<<"Medico -> "<<especialidade<<" destruido\n";
}
void Medico::imprime() const{
    Funcionario::imprime();
    cout<<"Especialidade: "<<especialidade<<"\n";
}
string Medico::getProfissao() const{
    return "Medico";
}