#ifndef BASEPLUS_H
#define BASEPLUS_H

#include <string>
using namespace std;

#include "EmpregadoCom.h"

class BasePlus : public EmpregadoCom{

    public:
        BasePlus(const string &, const string &, const string &, double =0.0, double=0.0,double=0.0);

        void setBsal(double);
        double getBsal() const;

        virtual double earnings() const;
        virtual void print() const;
    private:
        double bSal;

};



#endif