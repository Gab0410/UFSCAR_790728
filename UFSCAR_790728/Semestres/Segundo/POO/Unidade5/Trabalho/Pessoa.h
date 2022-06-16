#ifndef PESSOA_H
#define PESSOA_H
#include <string>
#include <iostream>
#include <vector>
#include "Animal.h"
#include "Cachorro.h"
#include "Peixe.h"
using namespace std;
namespace poo{


    class Pessoa{

        friend Animal;
        friend Cachorro;
        friend Peixe;

        private:
            string nome;
            int idade;
            vector<Animal*> listaAnimais;

        public:

            Pessoa(string,int);
            virtual ~Pessoa();

            void setIdade(int);
            int getIdade() const;

            void setNome(string);
            string getNome() const;

            bool adicionaAnimal(Animal*) ;
            bool removeAnimal(string) ;

            Animal* obtemAnimal(string);

            int qtdeAnimais();
            int qtdePeixes();
            int qtdCachorros();

            void imprime(int=0);

            static bool comparaNome(const Animal*, const Animal*);

    };
}
#endif