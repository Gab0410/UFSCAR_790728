#ifndef ALUNO_H
#define ALUNO_H
#include "Endereco.h"
#include <string>
using namespace std;
class Aluno {
     public:
        Aluno(string n,int r,Endereco* e);
        virtual ~Aluno();

        string getNome() const;
        void setNome(string);

        int getRA() const;
        void setRA(int);

        Endereco* getEndereco() const;
        void setEndereco(Endereco*);

        void imprime() const;
    private:
        string nome;
        int RA;
        Endereco* endereco;
};
#endif // ALUNO_H