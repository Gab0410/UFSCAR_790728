#ifndef COMISSION_H
#define COMISSION_H

#include "Employee.h"

class EmpregadoCom:public Comissao{
    public:

        EmpregadoCom(const string &,const string &, const string &, double=0.0, double =0.0);

        void setVbruta(double);
        double getVbruta() const;

        void setTaxaCom(double);
        double getTaxaCom() const;

        virtual double lucro() const;
        virtual void print() const;
    private:
        double vBruta,taxaCom;

};

#endif