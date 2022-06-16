#ifndef DERIVADA_H
#define DERIVADA_H

#include <iostream>
#include "base1.h"
#include "base2.h"

using namespace std;

class Derivada:public Base1, public Base2{
    friend ostream &operator<<(ostream &, const Derivada &);

    public:
        Derivada(int,char,double);
        double getReal() const;
    private:
        double real;
};
#endif