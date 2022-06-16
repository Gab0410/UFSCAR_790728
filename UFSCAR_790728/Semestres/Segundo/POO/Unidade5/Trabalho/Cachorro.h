#ifndef CACHORRO_H
#define CACHORRO_H
#include <string>
#include "Animal.h"
#include <iostream>
using namespace std;
namespace poo{



    class Cachorro:public Animal{

        private:
            string raca;
        public:

            Cachorro(string,double,string);
            virtual ~Cachorro();

            void setRaca(string);
            string getRaca() const;

            virtual string getEspecie() const;

            virtual void imprime() const;

    };
}
#endif