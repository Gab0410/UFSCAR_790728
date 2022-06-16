#ifndef V_H
#define V_H
#include <iostream>
using namespace std;

class VETOR{
    friend ostream &operator<<(ostream &, const VETOR &);
    friend istream &operator>>(istream &, VETOR &);

    public:
        VETOR(int=10);
        VETOR(const VETOR &);
        ~VETOR();
        int getTam() const;
        void setVal(const int );

        //operador de atribuiçaõ
        const VETOR &operator=(const VETOR &);

        //operador de igualdade
        bool operator==(const VETOR &) const;

        //operador de diferença
        bool operator!=(const VETOR &) const;

        //operador de subcript para objetos nao constantes
        int &operator[](int);

        //operador de subscript para objetos constantes
        const int &operator[](int) const;

    private:
        int tam;
        int *ptr;

};
#endif