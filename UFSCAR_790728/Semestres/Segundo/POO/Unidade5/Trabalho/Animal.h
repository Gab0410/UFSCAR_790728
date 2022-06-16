#ifndef ANIMAL_H
#define ANIMAL_H
#include <string>
#include <iostream>
using namespace std;
namespace poo{



    class Animal{

        private:
            string nome;
            double peso;

        public:

            Animal(string,double);
            virtual ~Animal();

            void setPeso(double);
            double getPeso() const;

            void setNome(string);
            string getNome() const;

            virtual string getEspecie() const = 0;

            virtual void imprime() const;

    };
}
#endif