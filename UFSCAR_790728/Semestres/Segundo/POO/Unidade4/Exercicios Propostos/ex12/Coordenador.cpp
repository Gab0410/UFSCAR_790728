#include "Coordenador.h"

namespace poo {

   Coordenador::Coordenador(string n,int cpf,double sal,string cur)
    :Professor(n,cpf,sal),curso(cur)
    {}
    double Coordenador::getSal() const{
        return (Professor::getSal()+2000.00);
    }
    string Coordenador::getCurso() const{
        return curso;
    }
    void Coordenador::imprime() const{
        Professor::imprime();
        cout<<"Curso: "<<getCurso();
    }

}
