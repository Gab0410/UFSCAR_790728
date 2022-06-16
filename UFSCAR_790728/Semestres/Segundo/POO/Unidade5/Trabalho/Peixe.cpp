#include "Peixe.h"
#include <string>
#include <vector>

using namespace std;
namespace poo{

    Peixe::Peixe(string nome,double peso,string tH)
        :Animal(nome,peso)
        {
            setTipoHabitat(tH);
        }
    Peixe::~Peixe(){}

    void Peixe::setTipoHabitat(string t){
        tipoHabitat = (t.length() > 0?t:"Sem habitat");
    }
    string Peixe::getTipoHabitat() const{
        return tipoHabitat;
    }

    string Peixe::getEspecie() const{
        return "Peixe";
    }

    void Peixe::imprime() const{
        Animal::imprime();
        cout<<"\nTipo Habitat: "<<tipoHabitat<<"\n\n";
    }



}














