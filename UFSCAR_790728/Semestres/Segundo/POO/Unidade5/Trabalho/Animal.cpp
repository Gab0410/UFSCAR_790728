#include "Animal.h"
#include <string>
#include <vector>

using namespace std;
namespace poo{

    Animal::Animal(string n,double p){
        setNome(n);
        setPeso(p);
    }
    
    Animal::~Animal(){}

    void Animal::setPeso(double p){
        peso = (p>0?p:0);
    }
    double Animal::getPeso() const{
        return peso;
    }

    void Animal::setNome(string n){
        nome = (n.length() > 0?n:"Sem Nome");
    }

    string Animal::getNome() const{
        return nome;
    }


    void Animal::imprime()const{
        cout<<"Nome: "<<getNome()
        <<"\nPeso: "<<getPeso()
        <<"\nEspecie: "<<getEspecie();
    }


}



