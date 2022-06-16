#ifndef MEDICO_H
#define MEDICO_H
#include "Funcionario.h"

class Medico:public Funcionario{
    public:
        Medico(int CPF, string nome, string especialidade);
        virtual ~Medico();
        virtual void imprime() const;
        virtual string getProfissao() const;
    private:
    string especialidade;
};
#endif