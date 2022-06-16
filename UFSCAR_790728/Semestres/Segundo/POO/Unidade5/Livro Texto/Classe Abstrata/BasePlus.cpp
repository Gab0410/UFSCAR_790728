#include <iostream>

using namespace std;

#include "BasePlus2.h"

BasePlus::BasePlus(const string &first, const string &last, const string &ssn, double sales, double rate, double salary)
    : EmpregadoCom(first,last,ssn,sales,rate)
{
    cout<<"Construtor baseplus de "<<getFname()<<" chamado\n";
    setBsal(salary);
}
void BasePlus::setBsal(double salary){
    bSal = (salary>0?salary:0);
}
double BasePlus::getBsal() const{
    return bSal;
}

double BasePlus::earnings() const{
    return bSal + EmpregadoCom::earnings();
}
void BasePlus::print() const{
 
    EmpregadoCom::print();
    cout<<"\nbase salary: "<<getBsal()<<"\n";
}

