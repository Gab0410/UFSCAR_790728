#ifndef ENFERMEIRO_H
#define ENFERMEIRO_H

#include "Funcionario.h"

class Enfermeiro : public Funcionario{
    public:
        Enfermeiro(int CPF, string nome, int CRE);
        virtual ~Enfermeiro();
        virtual void imprime() const;
        virtual string getProfissao() const;
    private:
        int CRE; // Numero de registro no Conselho Regional de Enfermagem
};
#endif /* ENFERMEIRO_H */