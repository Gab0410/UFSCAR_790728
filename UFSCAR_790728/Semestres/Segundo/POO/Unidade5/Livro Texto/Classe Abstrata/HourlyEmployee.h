#ifndef HOUR_H
#define HOUR_H


#include "Employee.h"

class hourEmployee:public Comissao{
    public:
        hourEmployee(const string &,const string &, const string &, double =0.0, double =0.0);


        void setWage(double);
        double getWage() const;

        void setHoras(double);
        double getHoras() const;

        virtual double earnings() const;
        virtual void print() const;
    private:
        double horas,wage;
};


#endif