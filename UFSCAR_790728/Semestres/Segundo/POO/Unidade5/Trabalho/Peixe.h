#ifndef PEIXE_H
#define PEIXE_H
#include <string>
#include "Animal.h"
#include <iostream>
using namespace std;
namespace poo{



    class Peixe:public Animal{

        private:
            string tipoHabitat;
        public:

            Peixe(string,double,string);
            virtual ~Peixe();

            void setTipoHabitat(string);
            string getTipoHabitat() const;

            virtual string getEspecie() const;

            virtual void imprime() const;

    };
}
#endif