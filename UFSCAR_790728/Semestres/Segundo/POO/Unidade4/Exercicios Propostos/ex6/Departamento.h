#ifndef DEPARTAMENTO_H
#define DEPARTAMENTO_H
#include <string>
using namespace std;
class Universidade;
class Departamento{
    public:
        Departamento(string n,string sig, Universidade* univ);
        virtual ~Departamento();
        
        void setNome(string);
        string getNome() const;

        void setSigla(string);
        string getSigla() const;

        void setUniv(Universidade*);
        Universidade* getUniv() const;

        void imprime() const;
    private:
        string nome,sigla;
        Universidade* universidade;
};
#endif /* DEPARTAMENTO_H */