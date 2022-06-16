#include <iostream>

using namespace std;

#include "SalariedEmployee.h"

SalariedEmployee::SalariedEmployee(const string &first, const string &last, const string &ssn,double salary)
    : Comissao(first,last,ssn)
{
    cout<<"Construtor baseplus de "<<getFname()<<" chamado\n";
    setWeeklySalary(salary);
}
void SalariedEmployee::setWeeklySalary(double salary){
    wSal = (salary>0?salary:0);
}
double SalariedEmployee::getWeeklySalary() const{
    return wSal;
}

double SalariedEmployee::earnings() const{
    return getWeeklySalary();
}
void SalariedEmployee::print() const{
 
    Comissao::print();
    cout<<"\nbase salary: "<<getWeeklySalary()<<"\n";
}