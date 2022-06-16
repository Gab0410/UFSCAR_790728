#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H
#include <string>
#include <iostream>
using namespace std;

class Funcionario{

    public:
        Funcionario(int , string);
        virtual ~Funcionario();
        virtual void imprime() const;
        virtual string getProfissao() const=0;

    private:
        string nome;
        int cpf;


};

#endif