#include "Pess.h"

namespace poo {
    int Pess::contador = 0;

    Pess::Pess(string n,int c)
        :nome(n),CPF(c)
        {
            contador++;
            cout<<"Construtor de ("<<nome<<", "<<CPF<<") inicializado."
            <<endl;
            cout<<"Quantidade: "<<contador<<endl;
        }
    Pess::~Pess(){
        cout<<"Destrutor de ("<<nome<<", "<<CPF<<") inicializado."
            <<endl;
            cout<<"Quantidade: "<<--contador<<endl;
    }
    int Pess::getCPF() const{
        return CPF;
    }
    string Pess::getNome() const{
        return nome;
    }
    void Pess::imprime() const{
        cout << "Nome: " << nome << endl;
        cout << "CPF: " << CPF << endl;
    }

}