#ifndef PESS_H
#define PESS_H

#include <iostream>
#include <string>

using namespace std;

namespace poo {

    class Pess {
    public:
      Pess(string,int);
      virtual ~Pess();
      int getCPF() const;
      string getNome() const;
      virtual void imprime() const;
    private:
        string nome;
        int CPF;
        static int contador;
    };

}

#endif /* PESSOA_H */