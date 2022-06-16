#ifndef SALARIED_H
#define SALARIED_H

#include "Employee.h"

class SalariedEmployee:public Comissao{
    public:
        SalariedEmployee(const string &, const string &, const string &,double = 0.0);
        
        void setWeeklySalary(double);
        double getWeeklySalary() const;

        virtual double earnings() const;
        virtual void print() const;

    private:
        double wSal;
};
#endif