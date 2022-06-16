#include "Enfermeiro.h"

Enfermeiro::Enfermeiro(int c,string n, int cr)
    :Funcionario(c,n),CRE(cr)
    {
        cout<<"Enfermeiro -> "<<n<<" criado\n";
    }
Enfermeiro::~Enfermeiro()
{
    cout<<"Enfermeiro -> "<<CRE<<" destruido\n";
}
void Enfermeiro::imprime() const{
    Funcionario::imprime();
    cout<<"CRE: "<<CRE<<"\n";
}
string Enfermeiro::getProfissao() const{
    return "Enfermeiro";
}