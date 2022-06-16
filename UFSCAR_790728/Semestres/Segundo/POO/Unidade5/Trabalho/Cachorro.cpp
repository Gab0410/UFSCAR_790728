#include "Cachorro.h"
#include <string>
#include <vector>

using namespace std;
namespace poo{

    Cachorro::Cachorro(string nome,double peso,string r)
        :Animal(nome,peso)
        {
            setRaca(r);
        }
    Cachorro::~Cachorro(){}

    void Cachorro::setRaca(string r){
        raca = (r.length() > 0?r:"Sem raca");
    }
    string Cachorro::getRaca() const{
        return raca;
    }
    string Cachorro::getEspecie() const{
        return "Cachorro";
    }

    void Cachorro::imprime()const{
        Animal::imprime();
        cout<<"\nRaca: "<<raca<<"\n\n";
    }



}



