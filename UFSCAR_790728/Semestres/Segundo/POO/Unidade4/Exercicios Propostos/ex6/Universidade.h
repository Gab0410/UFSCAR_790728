#ifndef UNIVERSIDADE_H
#define UNIVERSIDADE_H
#include <iostream>
#include "Departamento.h"
using namespace std;
class Universidade {
    public:
        Universidade(string n);
        virtual ~Universidade();

        void setNome(string);
        string getNome() const;

        void adicionaDepto(string, string);
        void removeDepto(string sigla);
        void imprime() const;
    private:
        string nome;
        int qntd,max;
        void realoca(int);
        Departamento** deptos;
};
#endif /* UNIVERSIDADE_H */