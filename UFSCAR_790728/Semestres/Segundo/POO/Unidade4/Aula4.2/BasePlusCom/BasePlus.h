#ifndef BASEPLUS_H
#define BASEPLUS_H

#include <string>
using namespace std;

#include "Comissao.h"

class BasePlus : public Comissao{

    public:
        BasePlus(const string &, const string &, const string &, double =0.0, double=0.0,double=0.0);
        ~BasePlus();

        void setBsal(double);
        double getBsal() const;

        double lucro() const;
        void printd() const;
    private:
        double bSal;

};



#endif