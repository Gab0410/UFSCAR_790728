#ifndef ALU_H
#define ALU_H

#include<string>
#include<cstring>

using namespace std;

class Aluno{
  public:
        Aluno(string ,int );
        ~Aluno();
        void setNome(string );
        void setNota();
        double getNota(int) const;
        int getRa() const;
        string getNome() const;
        void imprime() const;
    private:
        static int contador;
        const int RA = contador;
        string nome;
        double *notas;
        int tamanho;
};













#endif