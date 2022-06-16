#ifndef ALU_H
#define ALU_H
using namespace std;
#include <cstring>
#include<string>
#include <iostream>

#include "Pessoas.h"

class Alunos: public Pessoas{

    private:
        int RA;
    public:
        Alunos(int, string, int);
        int getRa() const;
        void setRA(int ra);
        void imprime() const;
};

#endif