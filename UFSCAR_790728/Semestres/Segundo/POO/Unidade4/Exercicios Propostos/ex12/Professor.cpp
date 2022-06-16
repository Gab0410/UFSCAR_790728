#include "Professor.h"

namespace poo {

    Professor::Professor(string n,int cpf,double sal)
        :Pess(n,cpf),salario(sal)
        {
            
        }
    double Professor::getSal() const{
        return salario;
    }
    void Professor::imprime() const{
        Pess::imprime();
        cout << "Salario: " << getSal() << endl;
    }


}